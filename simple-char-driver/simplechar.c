#include <linux/cdev.h>
#include <linux/fs.h>
#include <linux/init.h>
#include <linux/module.h>
#include <linux/types.h>
MODULE_LICENSE("Dual BSD/GPL");

dev_t dev;
const int NUMBER_OF_DEVICES = 1;

struct cdev cdev;

static int simplechar_open(struct inode *inode, struct file *file)
{
  printk(KERN_ALERT "open called\n");

  return 0;
}

struct file_operations simple_fops = {
  .owner = THIS_MODULE,
  .open = simplechar_open
};

static int simplechar_init(void)
{
  int result = alloc_chrdev_region(&dev, 0, NUMBER_OF_DEVICES, "simplechar");

  if (result < 0) {
    printk(KERN_ALERT "Couldn't allocate device numbers for simplechar\n");
    return result;
  }

  cdev_init(&cdev, &simple_fops);
  cdev.owner = THIS_MODULE;

  result = cdev_add(&cdev, dev, 1);

  if (result < 0) {
    printk(KERN_ALERT "Couldn't register simplechar device\n");
    return result;
  }

  printk(KERN_ALERT "simplechar loaded\n");

  return 0;
}

static void simplechar_exit(void)
{
  unregister_chrdev_region(dev, NUMBER_OF_DEVICES);

  printk(KERN_ALERT "simplechar unloaded\n");
}

module_init(simplechar_init);
module_exit(simplechar_exit);
