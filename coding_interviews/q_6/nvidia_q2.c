/* July 30, 2020 */

/* This was done in hackerrank. All 16 test cases passed. */

#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readline();

/*
 * Complete the 'compressedString' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING message as parameter.
 */

/*
 * To return the string from the function, you should either do static allocation or dynamic allocation
 *
 * For example,
 * char* return_string_using_static_allocation() {
 *     static char s[] = "static allocation of string";
 *
 *     return s;
 * }
 *
 * char* return_string_using_dynamic_allocation() {
 *     char* s = malloc(100 * sizeof(char));
 *
 *     s = "dynamic allocation of string";
 *
 *     return s;
 * }
 *
 */
 int num_repeat(char *s) {
     int n;
     char c;

     if (s == NULL)
        return -1;

    if (*s == '\0') // Nothing to count.
        return -2;

     // "abaasass"

     n = 0;
     c = *s;

     while (*s == c && *s !=  '\0') {
      n++;
      s++;
     }

    return n;
 }
char* compressedString(char* message) {
    static char s[100000]; // TODO: make sure this size is OK.
    char *t, *ss;
    int n;

    if (message == NULL)
        return NULL;

    if (*message == '\0') { // Empty message, return empty string.
        s[0] = '\0';
        return s;
    }

    t = message;
    ss = s;

    while (*t != '\0') {
        n = num_repeat(t);
        *ss = *t;

        // "abaasass"
        // "aba2sas2"
        if (n > 1) { // Append count char *  itoa ( int value, char * str, int base );
            //itoa(n)
            //
            ss++;
            ss += sprintf(ss, "%d", n); // "10" ret. 2.
        } else {
            ss++;
        }

        t += n;
    }

    return s;
}

int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    char* message = readline();

    char* result = compressedString(message);

    fprintf(fptr, "%s\n", result);

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

        if (!line) {
            break;
        }

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') {
            break;
        }

        alloc_length <<= 1;

        data = realloc(data, alloc_length);

        if (!data) {
            data = '\0';

            break;
        }
    }

    if (data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';

        data = realloc(data, data_length);

        if (!data) {
            data = '\0';
        }
    } else {
        data = realloc(data, data_length + 1);

        if (!data) {
            data = '\0';
        } else {
            data[data_length] = '\0';
        }
    }

    return data;
}
