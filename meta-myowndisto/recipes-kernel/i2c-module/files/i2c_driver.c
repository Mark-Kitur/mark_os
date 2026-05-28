#include <linux/module.h>
#include <linux/init.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/i2c.h>
#include <linux/delay.h>


MODULE_LICENSE("GPL");
MODULE_AUTHOR("MARK-KITUR");
MODULE_DESCRIPTION("all in one module for rasdru. this facilitates I2C. This will later be transferred to module using YOCTO");


static char * device = "I2C_IOCTL";
static dev_t dev_num; 
static struct cdev char_cdev;
static struct class *chardev_class; 
static struct i2c_adapter *I2C_adapter;
static struct i2c_client *I2C_client;
#define ARDUINO 0x55

void collect_data(struct i2c_client *client);


static struct i2c_device_id known_ids[]= {
    {"rasdru", 0},
    {/* essential */},
};

MODULE_DEVICE_TABLE(i2c, known_ids);


void collect_data(struct i2c_client *client){
        // read data
    int read;
    u8 reg= 0x00;
    u8 val;

    read = i2c_smbus_read_byte_data(client, reg);
    if(read<0){
        pr_err("%s: read failed\n", device);
    }
    else val =read;
    pr_info("%s: read::: %hhu\n",device, val);
}

static int the_probe(struct i2c_client *client){
    const struct i2c_device_id *id= i2c_client_get_device_id(client);
    pr_info("%s: Arduino client registered at %s\n", device, id->name);

    for(int y=0; y<100;y++){
        collect_data(client);
        msleep(200);}
    return 0;
}

static void the_remove(struct i2c_client *client){
    //arduino_client = NULL;
    pr_info("%s: Removing client\n",device);
}

static struct i2c_board_info I2C_device_info ={
    I2C_BOARD_INFO("rasdru", ARDUINO),
};


static struct file_operations fops={
};

static struct i2c_driver the_driver={
    .probe = the_probe,
    .remove = the_remove,
    .id_table = known_ids,
    .driver = {
        .name = "I2C_driver",
        .owner = THIS_MODULE,
    }
};

static int __init main_func(void){
    // initialise fops
    cdev_init(&char_cdev, &fops);
    char_cdev.owner = THIS_MODULE;

    int ret;
    ret = alloc_chrdev_region(&dev_num, 0,MINORMASK+1,device);
    if(ret){
        pr_err("%s: Falied to allocate region for device\n",device);
        goto free_device_num;
        return ret;
    }
    pr_info("%s: Successfully allocated region for char_dev",device);

    ret = cdev_add(&char_cdev,dev_num,MINORMASK+1);
    if(ret){
        pr_err("%s: failed to create cdev\n",device);
        goto delete_cdev;}

    chardev_class = class_create("chardev_class");
    if(!chardev_class){
        pr_err("%s: Failed to create class\n",device);
        ret=ENOMEM;
        goto delete_class;}

    if(!device_create(chardev_class,NULL,dev_num, NULL,"IOCTL_I2C%d",0)){
        pr_err("%s: could not create a device IOCTL_I2C0\n ",device);
        ret = ENOMEM;
        goto delete_class;}

    pr_info("%s:Successfully created a device node\n", device);


    // Create driver for I2C
    int res = i2c_add_driver(&the_driver);
    if(res){
        pr_err("%s: Failed to create I2C driver\n", device);
        return res;
    }
    pr_info("%s: Successfully added I2C driver\n",device);

    I2C_adapter = i2c_get_adapter(1);
    if(IS_ERR(I2C_adapter)){
        pr_err("%s: Failed to get adapter on i2c bus 1\n",device);
        i2c_del_driver(&the_driver);
        return PTR_ERR(I2C_adapter);
    }
    pr_info("%s: Adapter is created\n",device);

    I2C_client = i2c_new_client_device(I2C_adapter, &I2C_device_info);
    if(IS_ERR(I2C_client)){
        pr_err("%s: Falied to create new client\n", device);
        i2c_del_driver(&the_driver);
        return PTR_ERR(I2C_client);
    }
    i2c_put_adapter(I2C_adapter);
    pr_info("%s: successfully created I2C client\n",device);


    return 0;


delete_class:
    class_destroy(chardev_class);

delete_cdev:
    cdev_del(&char_cdev);

free_device_num:
    unregister_chrdev_region(dev_num,MINORMASK+1);
    return ret;

}

static void  __exit exit_plan(void){
    device_destroy(chardev_class,dev_num);
    class_destroy(chardev_class);
    cdev_del(&char_cdev);
    unregister_chrdev_region(dev_num, MINORMASK+1);

    if(I2C_client){
        i2c_unregister_device(I2C_client);
    }
    i2c_del_driver(&the_driver);
    pr_info("%s: Exitting kernel\n",device);
}


module_init(main_func);
module_exit(exit_plan);


