//NASM

Label:
Jmp Label

----
Rodrigo:

Write a program which takes as input a sorted array and updates it so that all duplicates have been removed and the remaining elements have been shifted left to fill the emptied indices. Return number of valid elements.


[ 1  4  4  4 4 4 4 5 6 ]
[ 1 4 5 6 0 ]

// maybe use helper function to give me the next unique element.

Int next_un(int j, int v, int *a, int len, int *ov) {
    for(int i = j ; i < len; i++) {
        if(a[j -1] != a[j])
Return a[j];
    }
}

Int rm_dups(int *a, int len) { // negative return values indicate error.
// a is already sorted.
    Int i;
    If (a == NULL) {
        assert(0);
        Return -1;
}

If (len == 0) // nothing to do.
    Return 0;

    For (i = 0; i < len; i++) {
        if(next_un() != 0)
            break;
    }

Return i;
}


Write a program which takes as input two sorted arrays, and returns a new array containing the elements from both input arrays (intersection).

[ 1 2 3 4]

[ 2 100 101 ]

Int


Write a program which takes as input two sorted arrays of integers and updates the first to the combined entries of the two arrays in sorted order. *Assume the first array has enough empty entries.*

For a in a1
    For a

Void merge_arrs(int  *a1, int len1, int *a2, int len2) {

    For (int i =0 ; i < len1; i++) {
        For (int j = 0; j < len2; j++) {
            If (a2[j] is not in a1[i]) {
                make_space(a1)
                Insert a2[j] in a1
            }
        }
}

}

Implement an integer to string conversion function. Input: 314 -> Output: "314"

Void itoa(int v, ) {
    Int
}

Implement a string to integer conversion function. Input: "314" -> Output 314

Int atoi(char *s) {
    Int sum = 0;
    Int sign = 1;

    // could also move past preceding spaces. Also handle negative.

    While (isspace(*s))
s++;

if(*s = ‘-’)
    Sign = -1;

    If ( s == NULL)
        Return 0;
    While (*s != ‘\0’) {
        If (!isdigit(*s))
            Return 0;
        Sum = 10*sum + (*s - ‘0’);
        s++;
    }

    Return sum*sign;
}
