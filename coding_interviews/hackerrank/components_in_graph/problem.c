/*

    https://www.hackerrank.com/challenges/components-in-graph/problem

    Success Rate: 83.16%
*/

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
 * Complete the componentsInGraph function below.
 */

/*
 * Please store the size of the integer array to be returned in result_count pointer. For example,
 * int a[3] = {1, 2, 3};
 *
 * *result_count = 3;
 *
 * return a;
 *
 */
int* componentsInGraph(int gb_rows, int gb_columns, int** gb, int* result_count) {
    /*
     * Write your code here.
     */

}

int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    char* n_endptr;
    char* n_str = readline();
    int n = strtol(n_str, &n_endptr, 10);

    if (n_endptr == n_str || *n_endptr != '\0') { exit(EXIT_FAILURE); }

    int** gb = malloc(n * sizeof(int*));

    for (int gb_row_itr = 0; gb_row_itr < n; gb_row_itr++) {
        gb[gb_row_itr] = malloc(2 * (sizeof(int)));

        char** gb_item_temp = split_string(readline());

        for (int gb_column_itr = 0; gb_column_itr < 2; gb_column_itr++) {
            char* gb_item_endptr;
            char* gb_item_str = gb_item_temp[gb_column_itr];
            int gb_item = strtol(gb_item_str, &gb_item_endptr, 10);

            if (gb_item_endptr == gb_item_str || *gb_item_endptr != '\0') { exit(EXIT_FAILURE); }

            gb[gb_row_itr][gb_column_itr] = gb_item;
        }
    }

    int result_count;
    int* result = componentsInGraph(gb_rows, gb_columns, gb, &result_count);

    for (int SPACE_itr = 0; SPACE_itr < SPACE_count; SPACE_itr++) {
        fprintf(fptr, "%d", SPACE[SPACE_itr]);

        if (SPACE_itr != SPACE_count - 1) {
            fprintf(fptr, " ");
        }
    }

    fprintf(fptr, "\n");

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
