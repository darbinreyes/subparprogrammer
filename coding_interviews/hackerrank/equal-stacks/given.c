#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readline();
char** split_string(char*);

/*
 * Complete the equalStacks function below.
 */
int equalStacks(int h1_count, int* h1, int h2_count, int* h2, int h3_count, int* h3) {
    /*
     * Write your code here.
     */

}

int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    char** n1N2N3 = split_string(readline());

    char* n1_endptr;
    char* n1_str = n1N2N3[0];
    int n1 = strtol(n1_str, &n1_endptr, 10);

    if (n1_endptr == n1_str || *n1_endptr != '\0') { exit(EXIT_FAILURE); }

    char* n2_endptr;
    char* n2_str = n1N2N3[1];
    int n2 = strtol(n2_str, &n2_endptr, 10);

    if (n2_endptr == n2_str || *n2_endptr != '\0') { exit(EXIT_FAILURE); }

    char* n3_endptr;
    char* n3_str = n1N2N3[2];
    int n3 = strtol(n3_str, &n3_endptr, 10);

    if (n3_endptr == n3_str || *n3_endptr != '\0') { exit(EXIT_FAILURE); }

    char** h1_temp = split_string(readline());

    int h1[n1];

    for (int h1_itr = 0; h1_itr < n1; h1_itr++) {
        char* h1_item_endptr;
        char* h1_item_str = h1_temp[h1_itr];
        int h1_item = strtol(h1_item_str, &h1_item_endptr, 10);

        if (h1_item_endptr == h1_item_str || *h1_item_endptr != '\0') { exit(EXIT_FAILURE); }

        h1[h1_itr] = h1_item;
    }

    char** h2_temp = split_string(readline());

    int h2[n2];

    for (int h2_itr = 0; h2_itr < n2; h2_itr++) {
        char* h2_item_endptr;
        char* h2_item_str = h2_temp[h2_itr];
        int h2_item = strtol(h2_item_str, &h2_item_endptr, 10);

        if (h2_item_endptr == h2_item_str || *h2_item_endptr != '\0') { exit(EXIT_FAILURE); }

        h2[h2_itr] = h2_item;
    }

    char** h3_temp = split_string(readline());

    int h3[n3];

    for (int h3_itr = 0; h3_itr < n3; h3_itr++) {
        char* h3_item_endptr;
        char* h3_item_str = h3_temp[h3_itr];
        int h3_item = strtol(h3_item_str, &h3_item_endptr, 10);

        if (h3_item_endptr == h3_item_str || *h3_item_endptr != '\0') { exit(EXIT_FAILURE); }

        h3[h3_itr] = h3_item;
    }

    int result = equalStacks(h1_count, h1, h2_count, h2, h3_count, h3);

    fprintf(fptr, "%d\n", result);

    fclose(fptr);

    return 0;
}

char* readline() {
    size_t alloc_length = 1024;
    size_t data_length = 0;
    char* data = malloc(alloc_length);

    while (true) {
        char* cursor = data + data_length;
        char* line = fgets(cursor, alloc_length - data_length, stdin);

        if (!line) { break; }

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') { break; }

        size_t new_length = alloc_length << 1;
        data = realloc(data, new_length);

        if (!data) { break; }

        alloc_length = new_length;
    }

    if (data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';
    }

    data = realloc(data, data_length);

    return data;
}

char** split_string(char* str) {
    char** splits = NULL;
    char* token = strtok(str, " ");

    int spaces = 0;

    while (token) {
        splits = realloc(splits, sizeof(char*) * ++spaces);
        if (!splits) {
            return splits;
        }

        splits[spaces - 1] = token;

        token = strtok(NULL, " ");
    }

    return splits;
}
