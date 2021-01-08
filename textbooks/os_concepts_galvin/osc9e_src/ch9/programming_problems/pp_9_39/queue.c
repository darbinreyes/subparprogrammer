#include "queue.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


int alloc_queue(queue_t *q, int qlen) {

    assert(q != NULL && qlen > 0);

    if (q == NULL || qlen <= 0) {
        return 1;
    }

    q->headi = 0;
    q->taili = 0;
    /*
        qlen + 1 allows us to distinguish between empty and full queue in an
        array based queue implementation.
    */
    q->arr_len = qlen + 1;

    q->queue_arr = calloc(q->arr_len, sizeof(int));

    if (q->queue_arr == NULL) {
        printf("calloc() returned NULL!\n");
        return 2;
    }

    q->num_entries = 0;

    return 0;
}

int free_queue(queue_t *q) {

    assert(q != NULL && q->queue_arr != NULL);

    if (q == NULL || q->queue_arr == NULL) {
        return 1;
    }

    free(q->queue_arr);

    return 0;
}

int queue_is_full(queue_t *q) {

    assert(q != NULL);

    if (q == NULL)
        return -1;

    return (q->taili + 1) % q->arr_len == q->headi;
}

int enq(queue_t *q, int e) {
    int r;

    assert(q != NULL);

    if (q == NULL) {
        return 1;
    }

    r = queue_is_full(q);

    if (r == -1) {
        printf("Queue is NULL!\n");
        return 2;
    }

    if (r == 1) {
        printf("Queue is full!\n");
        return 3;
    }

    q->queue_arr[q->taili] = e;

    q->taili = (q->taili + 1) % q->arr_len;

    assert(q->num_entries < q->arr_len - 1);

    if (q->num_entries >= q->arr_len - 1) {
        printf("enq: Queue invalid num_entries!\n");
        return 4;
    }

    q->num_entries++;

    return 0;
}

int queue_is_empty(queue_t *q) {

    assert(q != NULL);

    if (q == NULL)
        return -1;

    return q->headi == q->taili;
}

int deq(queue_t *q, int *e) {
    int r;

    assert(q != NULL && e != NULL);

    if (q == NULL || e == NULL) {
        return 1;
    }

    r = queue_is_empty(q);

    if (r == -1) {
        printf("Queue is NULL!\n");
        return 2;
    }

    if (r == 1) {
        printf("Queue is empty!\n");
        return 3;
    }

    *e = q->queue_arr[q->headi];

    q->queue_arr[q->headi] = -1;

    q->headi = (q->headi + 1) % q->arr_len;

    assert(q->num_entries > 0);

    if (q->num_entries <= 0) {
        printf("deq: Queue invalid num_entries!\n");
        return 4;
    }

    q->num_entries--;

    return 0;
}

int queue_contains(queue_t *q, int e) {
    int i = 0;
    int t;

    if (q == NULL) {
        return -1;
    }

    for(i = 0; i < q->num_entries; i++) {
        t = (q->headi + i) % q->arr_len;
        if(q->queue_arr[t] == e)
            return 1;
    }

    return 0;
}

void test_queue(void) {
    queue_t q;
    int e = -1;
    int r;

    alloc_queue(&q, 3);

    enq(&q, 2);
    enq(&q, 6);
    enq(&q, 0);

    r = queue_contains(&q, 6);

    if(r == 1)
        printf("queue contains 6\n");

    for (int i = 0; i < 3; i++) {
        if (deq(&q, &e) == 0)
            printf("%d\n", e);
    }

    free_queue(&q);
}