#include <linux/module.h>
#include <linux/init.h>

void hello_kernel(void);
static int __init my_test_init(void)
{
	printk(KERN_EMERG "test of use export symbol\n");
	hello_kernel();
	return 0;
}

static void __exit my_test_exit(void)
{
	printk("goodbye\n");
}

module_init(my_test_init);
module_exit(my_test_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("JiewenWang");
MODULE_DESCRIPTION("my test kernel module");
