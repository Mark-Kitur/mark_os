#include <linux/module.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("MARK-KITUR");

static const char *module_name= "log_levels";


static int __init my_init(void)
{
    printk(KERN_INFO "%s:hello Mark is getting started\n", module_name);
    printk(KERN_NOTICE "%s: I will build a system everyone would want to be part of");

    return 0;
}

static void __exit my_exit(void)
{
    pr_info("%s: Goodbye but it is not over\n", module_name);
    pr_notice("%s: MARCOS will one day rue the wolrd\n", module_name);

}

module_init(my_init)
module_exit(my_exit)