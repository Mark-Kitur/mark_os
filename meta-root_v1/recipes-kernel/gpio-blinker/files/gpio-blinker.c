#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/gpio/consumer.h>
#include <linux/delay.h>

static struct gpio_decs *led_gpio = NULL;
static struct timer_list blink_timer;
static bool led_state =false;

static void blink_timer_callback(struct timer_list *t)
{
    led_state = !led_state;
    mod_timer(&blink_timer, jiffies + msecs_to_jiffies(500)) // 500ms blink
}


static int __init gpio_blinker_init(void)
{
    int ret 
    // Get GPIO 17 
    led_gpio = gpiood_get(NULL, "led" , GPIOD_OUT_LOW);
    if (IS_ERR(led_gpio)){
        pr_err("Failed to get GPIO (r=try using device tree instead)\n");

        // fallback: direct request by number (works on Pi 5)
        ret = gpio_request(17, "led");
        if (ret){
            pr_err("Failed to request GPIO 17\n");
            return ret;
        }
        gpio_direction_output(17,0);
        pr_info("GPIO 17 request directly\n");
        led_gpio = NULL;
    }
    else {
        pr_info("GPIPO acquired via descriptor\n");
    }

    // Setup timer
    timer_setup(&blink_timer, blink_timer_callback,0);
    mod_timer(&blink_timer, jiffies + msecs_to_jiffies(500));
    pr_info("GPIO Blinker module loaded - led should blink on GPIO17\n");
    return 0; 
}

static void __exit gpio_blinker_exit(void)
{
    del_timer_sync(&blink_timer);

    if (led_gpio){
        gpio_set_value(led_gpio,0);
        gpio_put(led_gpio);
    }
    else{
        gpio_set_value(17,0);
        gpio_free(17);
    }
    pr_info("GPIO Blinker Module Unloaded\n");
}

module_init(gpio_blinker_init)
module_exit(gpio_blink_exit)


MODULE_LICENSE("MIT");
MODULE_AUTHOR("Mark");
MODULE_DESCRIPTION("Simple LED blinker for Raspberry Pi 5");
MODULE_VERSION("1.0");