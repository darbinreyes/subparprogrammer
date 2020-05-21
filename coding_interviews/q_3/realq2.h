typedef struct BoundedArrayChar {
    int size;
    char *arr;
} charboundedarray;

typedef struct boundedarrayInt {
    int size;
    int* arr;
} boundedarray;

boundedarray* lengthEachScene(charboundedarray* inputList);