#include <linux/module.h>
#include <linux/init.h>
#include <linux/gpio/consumer.h>
#include <linux/interrupt.h>
#include <linux/delay.h>
#include <linux/timer_types.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("MARK-KITUR");
MODULE_DESCRIPTION("Handled interrupts plus deboucing");

static const char *device_name = "gpio_intrupt";


#define LED_GPIO 26
#define BUTTON_GPIO 20

#define GPIOOFFSET 569

// intializing descriptor method
static struct gpio_desc *led,  *button;

static int led_gpio = LED_GPIO + GPIOOFFSET;
static int button_gpio = BUTTON_GPIO + GPIOOFFSET;

// varible containg irq number
unsigned int irq_number;
 
// debouncing
#define DEBOUNCE_DELAY 50
static int last_button_state;
static struct timer_list debounce_timer;

// GPIO ISR
static irqreturn_t button_irs(int irq, void *dev_id){
    pr_info("%s: Interrupt occur on PIO 26\n", device_name);
    last_button_state = gpiod_get_value(button);
    mod_timer(&debounce_timer,jiffies + msecs_to_jiffies(DEBOUNCE_DELAY));
    return IRQ_HANDLED;
}

static void debounce_timer_callback(struct timer_list *t){
    int state = gpiod_get_value(button);
    if (state == last_button_state){
        pr_info("%s: Valid button pressed detected\n", device_name);
        gpiod_set_value(led, !gpiod_get_value(led));
    }
} 


static int __init my_init(void){
    int status ;
    // initliase GPIO 
    led = gpio_to_desc(led_gpio);
    if (!led){
        pr_err("%s: Failed to request led gpio 26\n", device_name);
        return -1;
    }

    button = gpio_to_desc(button_gpio);
    if (!button){
        pr_err("%s: Unabled to get to buton GPIO 20\n", device_name);
        return -1;
    }

    // set directions
    status = gpiod_direction_output(led,0);
    if (status){
        pr_err("%s: Unabled to set GPIO20 as output\n", device_name);
        return -1;
    }

    status = gpiod_direction_input(button);
    if(status){
        pr_err("%s: Unabled to set GPIO26 as input", device_name);
        return -1;
    }

    // initialise interrupt; linking it with GPIO
    irq_number = gpiod_to_irq(button);
    status = request_irq(irq_number, button_irs, IRQF_TRIGGER_RISING, "btn_irq_handler", NULL);
    if(status){
        pr_err("%s: IRQ request failed\n",device_name);
        return -status;
    }

    pr_info("%s: irq_number: %d\n", device_name, irq_number);
    timer_setup(&debounce_timer, debounce_timer_callback,0);
    pr_info("%s: IRQ request loaded\n", device_name);

    return 0;

}


static void __exit my_exit(void){
    gpiod_set_value(led,0);
    free_irq(irq_number, NULL);
    timer_delete_sync(&debounce_timer);
    pr_info("%s: Bye Kernel my job is done!", device_name);
}

module_init(my_init);
module_exit(my_exit);


