#include <linux/fs.h>
#include <linux/init.h>
#include <linux/module.h>
#include <linux/types.h>
MODULE_LICENSE("Dual BSD/GPL");

dev_t dev;
const int NUMBER_OF_DEVICES = 1;

static int simple_init(void)
{
  int result = alloc_chrdev_region(&dev, 0, NUMBER_OF_DEVICES, "simplechar");

  if (result < 0) {
    printk(KERN_ALERT "Couldn't allocate device numbers for simplechar\n");
    return result;
  }

  printk(KERN_ALERT "simplechar loaded\n");

  return 0;
}

static void simple_exit(void)
{
  unregister_chrdev_region(dev, NUMBER_OF_DEVICES);

  printk(KERN_ALERT "simplechar unloaded\n");
}

module_init(simple_init);
module_exit(simple_exit);
