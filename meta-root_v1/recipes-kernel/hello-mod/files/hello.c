#include <linux/module.h>
#include <linux/kernel.h>

static int __init hello_init(void)
{
    pr_info("Hello, Mark! Your kernel module is loaded.\n");
    return 0;
}

static void __exit hello_exit(void)
{
    pr_info("Goodbye, Mark! Module unloaded.\n");
}

module_init(hello_init);
module_exit(hello_exit);

MODULE_LICENSE("MIT");
MODULE_AUTHOR("Mark");
MODULE_DESCRIPTION("Simple Hello World kernel module");
MODULE_VERSION("1.0");