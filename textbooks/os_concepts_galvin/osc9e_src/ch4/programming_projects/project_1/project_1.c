/* A multithreaded sudoku puzzle solution checker. */
#include <stdio.h>
#include <assert.h>
#include <pthread.h>

#define PUZ_SIZE      9 // A puzzle is a 9x9 grid.
#define PUZ_MIN_ENTRY 1
#define PUZ_MAX_ENTRY 9
#define PUZ_SUBGRID_SIZE 3 // The sub-grids are 3x3.

/* Puzzle solution checking results. */
/*

    Index 0 in rowr[], colr[], subgridr[] is unused for convenience since we are interested in. For i in [1,9], rowr[i]
    == 0 means all digits were present in the i-th row. The meaning of colr[] and
    subgridr[] is analogous to that of rowr[] and correspond to the puzzle's columns
    and 3x3 sub-grids, respectively.

*/
static int rowr[PUZ_SIZE];
static int colr[PUZ_SIZE];
static int subgridr[PUZ_SIZE];

/* This struct is used to pass to each thread the information it needs to check it's part of the puzzle. */
typedef
struct _sudoku_puz_t {
    const int (*sudoku_puz)[PUZ_SIZE]; // Points to the sudoku puzzle solution to be checked.
    int row; // Remaining members are used only for sub-grid checking.
    int col;
    int i;  // Used for sub-grid result index.
} sudoku_puz_t;

static void zero_arr(int a[]) {
    for (int i = 1 /* Index 0 unused. */; i < PUZ_SIZE + 1; i++) {
        a[i] = 0;
    }
}

/*

    Returns 1 if a digit was missing, otherwise, returns 0 if all digits were
    present. Hence, 0 means that the particular row, column, or sub-grid was
    valid.

*/
static int digit_is_missing(const int a[]) {
    for (int i = 1 /* Index 0 unused. */; i < PUZ_SIZE + 1; i++) {
        if (a[i] == 0)
            return 1;
    }
    return 0;
}

static void *row_checker(void *param) {
    int digits[PUZ_SIZE + 1] = {0}; // + 1 for convenience.
    int i, j, d;

    sudoku_puz_t *puz;

    puz = (sudoku_puz_t *) param;

    for (i = 0; i < PUZ_SIZE; i++) {

        for (j = 0; j < PUZ_SIZE; j++) {
            assert(puz->sudoku_puz[i][j] >= PUZ_MIN_ENTRY && puz->sudoku_puz[i][j] <= PUZ_MAX_ENTRY);
            d = puz->sudoku_puz[i][j];
            digits[d] = 1;
        }

        if(digit_is_missing(digits)) // Save result.
            rowr[i] = 1;

        zero_arr(digits);
    }

    return NULL;
}

static void *col_checker(void *param) {
    int digits[PUZ_SIZE + 1] = {0}; // + 1 for convenience.
    int i, j, d;

    sudoku_puz_t *puz;

    puz = (sudoku_puz_t *) param;

    for (i = 0; i < PUZ_SIZE; i++) {

        for (j = 0; j < PUZ_SIZE; j++) {
            assert(puz->sudoku_puz[j][i] >= PUZ_MIN_ENTRY && puz->sudoku_puz[j][i] <= PUZ_MAX_ENTRY);
            d = puz->sudoku_puz[j][i];
            digits[d] = 1;
        }

        if(digit_is_missing(digits)) // Save result.
            colr[i] = 1;

        zero_arr(digits);
    }

    return NULL;
}

static void *subgrid_checker(void *param) {
    int digits[PUZ_SIZE + 1] = {0}; // + 1 for convenience.
    int i, j, d;
    sudoku_puz_t *puz;

    puz = (sudoku_puz_t *) param;

    /* To check a 3x3 sub-grid, we start at the upper left element of the sub-grid. */
    for (i = 0 + puz->row; i < puz->row + PUZ_SUBGRID_SIZE; i++) {

        for (j = 0 + puz->col; j < puz->col + PUZ_SUBGRID_SIZE; j++) {
            assert(puz->sudoku_puz[i][j] >= PUZ_MIN_ENTRY && puz->sudoku_puz[i][j] <= PUZ_MAX_ENTRY);
            d = puz->sudoku_puz[i][j];
            digits[d] = 1;
        }
    }

    if(digit_is_missing(digits)) // Save result.
        subgridr[puz->i] = 1; // Note the use of `puz->i` as the index here. The reason is that this function checks 1 sub-grid only, compared to the row checker, which checks all rows in a single call. Using `puz->i` allows us to remember where to store the next result between calls.

    //zero_arr(digits); // Not necessary here.

    return NULL;
}

// Returns 1 if the solution was valid. 0 if the solution contained an error.
static int sol_valid(void) {
    int i;

    /* The solution is valid if all 3 result arrays contain only 0's.*/
    for (int i = 0; i < PUZ_SIZE; i++) {
        if (rowr[i] == 1 || colr[i] == 1 || subgridr[i] == 1)
            return 0;
    }

    return 1;
}

static void zero_results(void) {

    /* Zero out the result arrays. */
    for (int i = 0; i < PUZ_SIZE; i++) {
        rowr[i] = 0;
        colr[i] = 0;
        subgridr[i] = 0;
    }
}

#define NUM_THREADS (1 + 1 + 9) // 1 row checker, 1 column checker, 9 sub-grid checkers = 11 threads.

// Returns 1 if the solution was correct. 0 otherwise, the solution is incorrect.
static int check_puz_sol(const int (*puz_arr)[9]) {
    pthread_t      tid[NUM_THREADS];
    pthread_attr_t attr[NUM_THREADS];
    sudoku_puz_t   puz[NUM_THREADS]; // Argument passed to each thread's start function.
    int            v, i;

    for (i = 0; i < NUM_THREADS; i++)
        pthread_attr_init(&attr[i]);

    /* Validate the rows. */
    i = 0; // Index used to associate each thread with a corresponding element in tid[], attr[], and puz[].
    puz[i].sudoku_puz = puz_arr;
    pthread_create(&tid[i], &attr[i], row_checker, &puz);

    /* Validate the columns. */
    i = 1;
    puz[i].sudoku_puz = puz_arr;
    pthread_create(&tid[i], &attr[i], col_checker, &puz);

    /*

        Validate each sub-grid in the order given below. A sub-grid is identified by
        its upper left element index. (r,c,i = row, column, thread index).

        r,c,i = 0, 0, 2
        r,c,i = 0, 3, 3
        r,c,i = 0, 6, 4

        r,c,i = 3, 0, 5
        r,c,i = 3, 3, 6
        r,c,i = 3, 6, 7

        r,c,i = 6, 0, 8
        r,c,i = 6, 3, 9
        r,c,i = 6, 6, 10

    */
    i = 2;

    for (int row = 0; row < PUZ_SIZE; row += PUZ_SUBGRID_SIZE) {
        for (int col = 0; col < PUZ_SIZE; col += PUZ_SUBGRID_SIZE) {
            puz[i].sudoku_puz = puz_arr;
            puz[i].row = row;
            puz[i].col = col;
            puz[i].i = i - 2; // Informs the thread where to store it's validation result in subgridr[].
            pthread_create(&tid[i], &attr[i], subgrid_checker, &puz[i]);
            i++;
        }
    }

    for (i = 0; i < NUM_THREADS; i++)
        pthread_join(tid[i], NULL);

    v = sol_valid();

    if (v)
        printf("Solution is valid.\n");
    else
        printf("Solution contains an error.\n");

    zero_results(); // Zeros out rowr[], colr[], and subgridr[] to prepare for validating the next puzzle.

    return v;
}

static int sudoku_puz0[][PUZ_SIZE] = {
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

/* [Puzzles with solutions](https://www.puzzles.ca/sudoku/). */
static int sudoku_puz1[][PUZ_SIZE] = {
    {2, 3, 7, 9, 1, 4, 6, 8, 5},
    {8, 5, 9, 3, 2, 6, 4, 7, 1},
    {1, 4, 6, 5, 7, 8, 3, 9, 2},
    {5, 7, 8, 6, 3, 1, 2, 4, 9},
    {6, 9, 1, 2, 4, 7, 5, 3, 8},
    {3, 2, 4, 8, 9, 5, 1, 6, 7},
    {4, 1, 3, 7, 5, 9, 8, 2, 6},
    {9, 8, 5, 4, 6, 2, 7, 1, 3},
    {7, 6, 2, 1, 8, 3, 9, 5, 4}
};

/* Same as above but with the first element changed. Thus this is an incorrect solution. */
static const int sudoku_puz2[][PUZ_SIZE] = {
    {7, 3, 7, 9, 1, 4, 6, 8, 5},
    {8, 5, 9, 3, 2, 6, 4, 7, 1},
    {1, 4, 6, 5, 7, 8, 3, 9, 2},
    {5, 7, 8, 6, 3, 1, 2, 4, 9},
    {6, 9, 1, 2, 4, 7, 5, 3, 8},
    {3, 2, 4, 8, 9, 5, 1, 6, 7},
    {4, 1, 3, 7, 5, 9, 8, 2, 6},
    {9, 8, 5, 4, 6, 2, 7, 1, 3},
    {7, 6, 2, 1, 8, 3, 9, 5, 4}
};

int main(void) {

    check_puz_sol(sudoku_puz0);
    check_puz_sol(sudoku_puz1);
    check_puz_sol(sudoku_puz2);

    return 0;
}