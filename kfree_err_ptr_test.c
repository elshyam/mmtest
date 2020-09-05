#include <linux/module.h>
#include <linux/mm.h>
#include <linux/slab.h>
#include <linux/err.h>

static unsigned char *ptr;
static unsigned int pa;
int init_module(void)
{
	ptr = kmalloc(4096, GFP_KERNEL);
	pr_info("Value of ptr (Linear Address) = %p\n",ptr);
	
	return 0;
}

void cleanup_module(void)
{
	kfree((void *)0xfffffffffffff001);
	kfree(ptr);
	dump_stack();
	pr_info("Unloading\n");
}

MODULE_LICENSE("GPL");
MODULE_AUTHOR("mayhs11saini@gmail.com");
