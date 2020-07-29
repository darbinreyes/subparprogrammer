#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>

/* ******* My includes ******* */
#include <linux/sched.h> // `for_each_process()`, `struct task_struct`.

void dfs_task_iter(struct task_struct *t) {
    struct list_head *list;
    struct task_struct *c;
    list_for_each(list, &t->children) {
        c = list_entry(list, struct task_struct, children);
        printk(KERN_INFO "%ld %d %s\n", c->state, c->pid, c->comm);
        dfs_task_iter(c);
    }
}
/* This function is called when the module is loaded. */
int simple_init(void)
{
    struct task_struct *t = &init_task;
    printk(KERN_INFO "Dijkstra Loading Module\n");

    printk(KERN_INFO "%ld %d %s\n", t->state, t->pid, t->comm);
    dfs_task_iter(t);
    return 0;
}

/* This function is called when the module is removed. */
void simple_exit(void) {
    printk(KERN_INFO "Dijkstra Removing Module\n");
}

/* Macros for registering module entry and exit points. */
module_init( simple_init );
module_exit( simple_exit );

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Simple Module");
MODULE_AUTHOR("SGG");

