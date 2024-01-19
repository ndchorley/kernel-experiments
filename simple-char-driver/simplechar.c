#include <linux/init.h>
#include <linux/module.h>
MODULE_LICENSE("Dual BSD/GPL");

static int simple_init(void)
{
  printk(KERN_ALERT "simplechar loaded\n");
  return 0;
}

static void simple_exit(void)
{
  printk(KERN_ALERT "simplechar unloaded\n");
}

module_init(simple_init);
module_exit(simple_exit);
