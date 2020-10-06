#include <stdio.h>
#include <assert.h>

#define PUZ_SIZE      9
#define PUZ_MIN_ENTRY 1
#define PUZ_MAX_ENTRY 9

int sudoku_puz[][PUZ_SIZE] = {
    {6, 2, 4, 5, 3, 9, 1, 8, 7},
    {5, 1, 9, 7, 2, 8, 6, 3, 4},
    {8, 3, 7, 6, 1, 4, 2, 9, 5},
    {1, 4, 3, 8, 6, 5, 7, 2, 9},
    {9, 5, 8, 2, 4, 7, 3, 6, 1},
    {7, 6, 2, 3, 9, 1, 4, 5 ,8},
    {3, 7, 1, 9, 5, 6, 8, 4, 2},
    {4, 9, 6, 1, 8, 2, 5, 7, 3},
    {2, 8, 5, 4, 7, 3, 9, 1, 6}
};

static int rowr[PUZ_SIZE]; // rowr[0] == 1 means row 0 was missing a digit.
static int colr[PUZ_SIZE];
/*

    subgridr order, by upper left corner.

    r,c = 0, 0
    r,c = 0, 3
    r,c = 0, 6

    r,c = 3, 0
    r,c = 3, 3
    r,c = 3, 6

    r,c = 6, 0
    r,c = 6, 3
    r,c = 6, 6

*/
static int subgridr[PUZ_SIZE];

void zero_dp(int dp[]) {
    for (int i = 1; i < PUZ_SIZE + 1; i++) {
        dp[i] = 0;
    }
}

// Returns 1 if a digit was missing, 0 if all digits were present.
int digit_missing(int dp[]) {
    for (int i = 1; i < PUZ_SIZE + 1; i++) {
        if (dp[i] == 0)
            return 1;
    }
    return 0;
}

void *row_checker(void *param) {
    int digit_present[PUZ_SIZE + 1] = {0}; // + 1 for convenience.
    int i, j, d;

    for (i = 0; i < PUZ_SIZE; i++) {

        for (j = 0; j < PUZ_SIZE; j++) {
            assert(sudoku_puz[i][j] >= PUZ_MIN_ENTRY && sudoku_puz[i][j] <= PUZ_MAX_ENTRY);
            d = sudoku_puz[i][j];
            digit_present[d] = 1;
        }

        if(digit_missing(digit_present))
            rowr[i] = 1;

        zero_dp(digit_present);
    }

    return NULL;
}

void *col_checker(void *param) {
    int digit_present[PUZ_SIZE + 1] = {0}; // + 1 for convenience.
    int i, j, d;

    for (i = 0; i < PUZ_SIZE; i++) {

        for (j = 0; j < PUZ_SIZE; j++) {
            assert(sudoku_puz[j][i] >= PUZ_MIN_ENTRY && sudoku_puz[j][i] <= PUZ_MAX_ENTRY);
            d = sudoku_puz[j][i];
            digit_present[d] = 1;
        }

        if(digit_missing(digit_present))
            colr[i] = 1;

        zero_dp(digit_present);
    }

    return NULL;
}

#define PUZ_SUBGRID_SIZE 3

typedef
struct _grid_position_t {
    int row;
    int col;
    int i; // subgrid index.
} grid_position_t;

void *subgrid_checker(void *param) {
    int digit_present[PUZ_SIZE + 1] = {0}; // + 1 for convenience.
    int i, j, d;
    grid_position_t *gpos;

    gpos = (grid_position_t *) param;

    /*

    r,c = 0, 0
    r,c = 0, 3
    r,c = 0, 6

    r,c = 3, 0
    r,c = 3, 3
    r,c = 3, 6

    r,c = 6, 0
    r,c = 6, 3
    r,c = 6, 6

    // add r/c offset accordingly.

    */

    printf("r, c, i = %d, %d, %d.\n", gpos->row, gpos->col, gpos->i);
    for (i = 0 + gpos->row; i < gpos->row + PUZ_SUBGRID_SIZE; i++) {

        for (j = 0 + gpos->col; j < gpos->col + PUZ_SUBGRID_SIZE; j++) {
            assert(sudoku_puz[i][j] >= PUZ_MIN_ENTRY && sudoku_puz[i][j] <= PUZ_MAX_ENTRY);
            d = sudoku_puz[i][j];
            digit_present[d] = 1;
        }
    }

    if(digit_missing(digit_present))
        subgridr[gpos->i] = 1; // Bail?

    gpos->i++;

    //zero_dp(digit_present);

    return NULL;
}

// Returns 1 if the solution was valid. 0 if the solution contained an error.
int sol_valid(void) {
    int i;

    for (i = 0; i < PUZ_SIZE; i++) {
        if (rowr[i] == 1)
            return 0;
    }

    for (i = 0; i < PUZ_SIZE; i++) {
        if (colr[i] == 1)
            return 0;
    }

    for (i = 0; i < PUZ_SIZE; i++) {
        if (subgridr[i] == 1)
            return 0;
    }

    return 1;
}

int main(void) {
    int i, j;
    grid_position_t gpos;

    row_checker(NULL);
    col_checker(NULL);

    gpos.i = 0;

    for (gpos.row = 0; gpos.row < PUZ_SIZE; gpos.row += PUZ_SUBGRID_SIZE) {
        for (gpos.col = 0; gpos.col < PUZ_SIZE; gpos.col += PUZ_SUBGRID_SIZE) {
            subgrid_checker(&gpos);
        }
    }

    if (sol_valid())
        printf("Solution is valid.\n");
    else
        printf("Solution contains an error.\n");

    return 0;
}