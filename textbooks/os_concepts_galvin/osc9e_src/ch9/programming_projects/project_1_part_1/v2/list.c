/*!
    @header Linked list.
    Mostly copied from the Linux open source:
    linux-headers-3.16.0-4-common/include/linux/types.h
    linux-headers-3.16.0-4-common/include/linux/list.h
    /Users/darbinreyes/dev/private_dev/subparprogrammer/textbooks/os_concepts_galvin/osc9e_src/linux-headers-3.16.0-4-common/include/linux/kernel.h
    /Users/darbinreyes/dev/private_dev/subparprogrammer/textbooks/os_concepts_galvin/osc9e_src/linux-headers-3.16.0-4-common/include/linux/stddef.h
*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct list_head {
    struct list_head *next, *prev;
};

#define LIST_HEAD_INIT(name) { &(name), &(name) }

#define LIST_HEAD(name) \
    struct list_head name = LIST_HEAD_INIT(name)

static inline void INIT_LIST_HEAD(struct list_head *list)
{
    list->next = list;
    list->prev = list;
}
/*
 * Insert a new entry between two known consecutive entries.
 *
 * This is only for internal list manipulation where we know
 * the prev/next entries already!
 */
static inline void __list_add(struct list_head *new,
                  struct list_head *prev,
                  struct list_head *next)
{
    next->prev = new;
    new->next = next;
    new->prev = prev;
    prev->next = new;
}

/**
 * list_add_tail - add a new entry
 * @new: new entry to be added
 * @head: list head to add it before
 *
 * Insert a new entry before the specified head.
 * This is useful for implementing queues.
 */
static inline void list_add_tail(struct list_head *new, struct list_head *head)
{
    __list_add(new, head->prev, head);
}

#undef offsetof
#ifdef __compiler_offsetof
#define offsetof(TYPE,MEMBER) __compiler_offsetof(TYPE,MEMBER)
#else
#define offsetof(TYPE, MEMBER) ((size_t) &((TYPE *)0)->MEMBER)
#endif

/**
 * container_of - cast a member of a structure out to the containing structure
 * @ptr:    the pointer to the member.
 * @type:    the type of the container struct this is embedded in.
 * @member:    the name of the member within the struct.
 *
 */
#define container_of(ptr, type, member) ({            \
    const typeof( ((type *)0)->member ) *__mptr = (ptr);    \
    (type *)( (char *)__mptr - offsetof(type,member) );})

/**
 * list_entry - get the struct for this entry
 * @ptr:    the &struct list_head pointer.
 * @type:    the type of the struct this is embedded in.
 * @member:    the name of the list_struct within the struct.
 */
#define list_entry(ptr, type, member) \
    container_of(ptr, type, member)

/**
 * list_first_entry - get the first element from a list
 * @ptr:    the list head to take the element from.
 * @type:    the type of the struct this is embedded in.
 * @member:    the name of the list_struct within the struct.
 *
 * Note, that list is expected to be not empty.
 */
#define list_first_entry(ptr, type, member) \
    list_entry((ptr)->next, type, member)

/**
 * list_next_entry - get the next element in list
 * @pos:    the type * to cursor
 * @member:    the name of the list_struct within the struct.
 */
#define list_next_entry(pos, member) \
    list_entry((pos)->member.next, typeof(*(pos)), member)

/**
 * list_for_each_entry    -    iterate over list of given type
 * @pos:    the type * to use as a loop cursor.
 * @head:    the head for your list.
 * @member:    the name of the list_struct within the struct.
 */
#define list_for_each_entry(pos, head, member)                \
    for (pos = list_first_entry(head, typeof(*pos), member);    \
         &pos->member != (head);                    \
         pos = list_next_entry(pos, member))

struct bday {
    int year;
    struct list_head list;
};

static LIST_HEAD(pages_list);

int main(void) {
    printf("Hello linux list\n");
    struct bday *t, *t2, *ptr;

    t = malloc(sizeof(*t));

    assert(t);

    t->year = 1988;
    INIT_LIST_HEAD(&t->list);
    list_add_tail(&t->list, &pages_list);

    t2 = malloc(sizeof(*t2));

    assert(t2);

    t2->year = 2000;
    INIT_LIST_HEAD(&t2->list);
    list_add_tail(&t2->list, &pages_list);

    list_for_each_entry(ptr, &pages_list, list) {
        printf("year = %d\n", ptr->year);
    }

    // @TODO !!! call free()
    return 0;
}