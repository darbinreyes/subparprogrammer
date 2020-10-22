#include <stdio.h>
#include <assert.h>
#include "sort.h"
#include <pthread.h>

static int in_a[] = {7, 12, 19, 3, 18, 4, 2, 6, 15, 8};

#define IN_ARRAY_LEN (sizeof(in_a)/sizeof(in_a[0]))

static const int in_len = IN_ARRAY_LEN;

static int out_a[IN_ARRAY_LEN];

typedef
struct _sort_param_t {
    int *a;
    int l;
} sort_param_t;

typedef
struct _merge_param_t {
    int *am;
    int aml;

    int *a0;
    int a0l;

    int *a1;
    int a1l;
} merge_param_t;

void *sort_runner(void *param) {
    sort_param_t *p;

    assert(param != NULL);

    p = (sort_param_t *)param;
    sort(p->a, p->l);

    return NULL;
}

void *merge_runner(void *param) {
    merge_param_t *p;

    assert(param != NULL);

    p = (merge_param_t *) param;

    merge(p->am, p->aml, \
           p->a0, p->a0l, \
           p->a1, p->a1l);
    return NULL;
}

#define NUM_THREADS 3

//#define IN_ARRAY_LEN_2 1024

//static int in_a2[IN_ARRAY_LEN_2];
//static int in_len_a2

int main(int argc, char **argv) {
    pthread_t tid[NUM_THREADS];
    pthread_attr_t attr[NUM_THREADS];
    int *am, *a0, *a1;
    int am_len, a0_len, a1_len;
    int i;
    sort_param_t sp0, sp1;
    merge_param_t mp;



    // TODO: handle len == 1
    assert(in_len > 1);

    printf("Input array: ");
    print_a(in_a, in_len);

    for (i = 0; i < NUM_THREADS; i++)
        pthread_attr_init(&attr[i]);

    sp0.a = in_a;
    sp0.l = in_len/2;
    pthread_create(&tid[0], &attr[0], sort_runner, &sp0);

    sp1.a = in_a + in_len/2;
    sp1.l = in_len - in_len/2;
    pthread_create(&tid[1], &attr[1], sort_runner, &sp1);

    for (i = 0; i < 2; i++)
        pthread_join(tid[i], NULL);

    mp.am = out_a;
    mp.aml = in_len;
    mp.a0 = in_a;
    mp.a0l = in_len/2;
    mp.a1 = in_a + in_len/2;
    mp.a1l = in_len - in_len/2;
    pthread_create(&tid[2], &attr[2], merge_runner, &mp);
    pthread_join(tid[2], NULL);

    print_a(out_a, in_len);
    // am = out_a;
    // am_len = in_len;

    // a0 = in_a;
    // a0_len = in_len/2;

    // a1 = in_a + in_len/2;
    // a1_len = in_len - in_len/2;

    // sort(a0, a0_len);
    // sort(a1, a1_len);

    // print_a(a0, a0_len);
    // print_a(a1, a1_len);

    // merge(am, am_len, \
    //        a0, a0_len, \
    //        a1, a1_len);

    // print_a(am, am_len);
    return 0;
}

