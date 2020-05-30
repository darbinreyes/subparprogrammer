#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>

#include <linux/list.h> // list
#include <linux/types.h> // list_head
#include <linux/slab.h> // kmalloc(), kfree()

struct birthday {
  char *name;
  int year;
  struct list_head list;
};

static LIST_HEAD(birthday_list);

/* This function is called when the module is loaded. */
int simple_init(void)
{
  struct birthday *tn;
  char names_arr[] = {"Edsgar Dijkstra", "Tony Hoare", "Donald Knuth", "Derek Decker", "Euclid"};
  int years_arr[] = {1965, 1977, 1979, 1981, 323};
  printk(KERN_INFO "Loading Module\n");

  // Create linked list of 5 nodes.

  for (int i = 0; i < 5; i++) {
    tn = kmalloc(sizeof(*tn), GFP_KERNEL);
    tn->name = names_arr[i];
    tn->year = years_arr[i];
    INIT_LIST_HEAD(&tn->list);
    list_add_tail(&tn->list, birthday_list);
  }

  return 0;
}

/* This function is called when the module is removed. */
void simple_exit(void) {
  printk(KERN_INFO "Removing Module\n");
}

/* Macros for registering module entry and exit points. */
module_init( simple_init );
module_exit( simple_exit );

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Simple Module");
MODULE_AUTHOR("SGG");

