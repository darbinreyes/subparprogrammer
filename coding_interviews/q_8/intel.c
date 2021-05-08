// GPIO

Test
Test2
Given an  array of numbers, remove the duplicates in-place such that each element appears only once and returns the new length.
Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory
Input: nums = [0,1,1,1,0,2,3,3,2,4]
Output: 5, nums = [0,1,2,3,4,x,x]
int mark_duplicates(int *a, int v, int len) {
    Int num_dups = 0;
// argos checks
    for (int i = 0; i < len; i++) {
    if(a[i] == v) {
        a[i] = -1;
        num_dups++;
    }
}

Return num_dups;
}

int rm_duplicates(int *a, int len) {
// args checks
assert(a != NULL && len > 0);

    Int i, j, out_len;

    Out_len = len;

for(i = 0; i < len - 1; i++) {
Out_len = out_len - mark_duplicates(&a[i + 1], a[i], len - i );
}

//  [0,1,1,1,
     0,2,3,3,
    2,4]
//  [0,1,-1,-1,-1,2,3,-1,-1,4]
//  [0,1,2,3,4]



}
}

Return out_len;
}


Given a linked list, swap every two adjacent nodes and return its head.
You may not modify the values in the list's nodes. Only nodes itself may be changed.
Input: head = [1,2,3,4,5, 6, 7]:
Output: [2,1,4,3]
Typedef struct _list_node_t {
    Int v;
    Struct _list_node_t *next;
} list_node_t;

List_node_t  *swap_adj(list_node_t *head) {
// Assume end of list is marked with ->next == NULL.
// Make sure work correctly with odd and even number of nodes.

    assert(head != NULL);
    List_node_t *n0, *n1;

/*
scratch work.
1->2

2->1
n0->next = NULL; // n1->next;
n1->next = n0;

1->2->3



*/

    n0 = head;
    n1 = head->next;
    r = NULL;

    while (n1 != NULL) {
    //
        r = n1->next; // Remainder of list
n0->next = n1->next; // Swap pointers
        n1->next = n0;

        if(r != NULL) {
            R
}
        n0 = n1;
        n1 = n1->next;

}

return n0; // return the head

}

2 4 6 // not 6

Int is_power(int v) {
    Int done;
    if(v & 0x01) { // odd numbers are not powers of 2
        Return 0;
}

Done = 0;

while(!done) {
    If ( v > 0) {
        v /= 2;
    }

// x 3/2 = 1;
//  4/2 = 2
// 6/2 = 3
// 3/2 = 1
// ½ = 0
// 10B = 2
// 11B = 3
// 100 = 4
// 1000 = 8
// 1001 = 9
// 1010 = A = 10 // not a power o 2
}

         // better?
    Int num_bits = sizeof(int) * 8;

    for(int i = 0; i < num_bits; i++) {
        // v & (0x01 << i)
        if(v &
}

}

// Chain of trust
// Secure boot
// measured
// TXT - non-UEFI.
// Intel - Boot Guard.

// NEXT: First round selection - second round.