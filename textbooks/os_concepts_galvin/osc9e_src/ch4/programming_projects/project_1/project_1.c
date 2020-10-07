#include <stdio.h>
#include <assert.h>
#include <pthread.h>

#define PUZ_SIZE      9
#define PUZ_MIN_ENTRY 1
#define PUZ_MAX_ENTRY 9
#define PUZ_SUBGRID_SIZE 3

/* Solution checking results. */
static int rowr[PUZ_SIZE]; // rowr[0] == 1 means row 0 was missing a digit.
static int colr[PUZ_SIZE];
/*

    `subgridr` order, by upper left corner.

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

typedef
struct _sudoku_puz_t {
    int (*sudoku_puz)[PUZ_SIZE];
    int row; // Remaining members are used only for sub-grid checking.
    int col;
    int i;  // Used for sub-grid result index.
} sudoku_puz_t;


static void zero_dp(int dp[]) {
    for (int i = 1; i < PUZ_SIZE + 1; i++) {
        dp[i] = 0;
    }
}

// Returns 1 if a digit was missing, 0 if all digits were present.
static int digit_missing(int dp[]) {
    for (int i = 1; i < PUZ_SIZE + 1; i++) {
        if (dp[i] == 0)
            return 1;
    }
    return 0;
}

static void *row_checker(void *param) {
    int digit_present[PUZ_SIZE + 1] = {0}; // + 1 for convenience.
    int i, j, d;

    sudoku_puz_t *puz;

    puz = (sudoku_puz_t *) param;

    for (i = 0; i < PUZ_SIZE; i++) {

        for (j = 0; j < PUZ_SIZE; j++) {
            assert(puz->sudoku_puz[i][j] >= PUZ_MIN_ENTRY && puz->sudoku_puz[i][j] <= PUZ_MAX_ENTRY);
            d = puz->sudoku_puz[i][j];
            digit_present[d] = 1;
        }

        if(digit_missing(digit_present)) // Save result.
            rowr[i] = 1;

        zero_dp(digit_present);
    }

    return NULL;
}

static void *col_checker(void *param) {
    int digit_present[PUZ_SIZE + 1] = {0}; // + 1 for convenience.
    int i, j, d;

    sudoku_puz_t *puz;

    puz = (sudoku_puz_t *) param;

    for (i = 0; i < PUZ_SIZE; i++) {

        for (j = 0; j < PUZ_SIZE; j++) {
            assert(puz->sudoku_puz[j][i] >= PUZ_MIN_ENTRY && puz->sudoku_puz[j][i] <= PUZ_MAX_ENTRY);
            d = puz->sudoku_puz[j][i];
            digit_present[d] = 1;
        }

        if(digit_missing(digit_present)) // Save result.
            colr[i] = 1;

        zero_dp(digit_present);
    }

    return NULL;
}

static void *subgrid_checker(void *param) {
    int digit_present[PUZ_SIZE + 1] = {0}; // + 1 for convenience.
    int i, j, d;
    sudoku_puz_t *puz;

    puz = (sudoku_puz_t *) param;

    /* To check a 3x3 sub-grid, we start at the upper left element of the sub-grid. */
    for (i = 0 + puz->row; i < puz->row + PUZ_SUBGRID_SIZE; i++) {

        for (j = 0 + puz->col; j < puz->col + PUZ_SUBGRID_SIZE; j++) {
            assert(puz->sudoku_puz[i][j] >= PUZ_MIN_ENTRY && puz->sudoku_puz[i][j] <= PUZ_MAX_ENTRY);
            d = puz->sudoku_puz[i][j];
            digit_present[d] = 1;
        }
    }

    if(digit_missing(digit_present)) // Save result.
        subgridr[puz->i] = 1; // Note the use of `puz->i` as the index here. The reason is that this function checks 1 sub-grid only, compared to the row checker, which checks all rows in a single call. Using `puz->i` allows us to remember where to store the next result.

    //zero_dp(digit_present); // Not necessary here.

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

    /* The solution is valid if all 3 result arrays contain only 0's.*/
    for (int i = 0; i < PUZ_SIZE; i++) {
        rowr[i] = 0;
        colr[i] = 0;
        subgridr[i] = 0;
    }
}

#define NUM_THREADS (1 + 1 + 9) // 1 row checker, 1 column checker, 9 sub-grid checkers = 11 threads.

// Returns 1 if the solution was correct. 0 otherwise, the solution is incorrect.
static int check_puz_sol(int (*puz_arr)[9]) {
    pthread_t tid[NUM_THREADS];
    pthread_attr_t attr[NUM_THREADS];
    sudoku_puz_t puz[NUM_THREADS];
    int v, i;

    for (i = 0; i < NUM_THREADS; i++)
        pthread_attr_init(&attr[i]);

    /* Validate the rows. */
    puz[0].sudoku_puz = puz_arr;
    //row_checker(&puz);
    pthread_create(&tid[0], &attr[0], row_checker, &puz);

    /* Validate the columns. */
    puz[1].sudoku_puz = puz_arr;
    //col_checker(&puz);
    pthread_create(&tid[1], &attr[1], col_checker, &puz);

    /*

        Validate each sub-grid in the order given below. A sub-grid is identified by
        its upper left element index. (r,c = row, column).

        r,c = 0, 0, 2
        r,c = 0, 3, 3
        r,c = 0, 6, 4

        r,c = 3, 0, 5
        r,c = 3, 3, 6
        r,c = 3, 6, 7

        r,c = 6, 0, 8
        r,c = 6, 3, 9
        r,c = 6, 6, 10

    */
    i = 2; // thread index.

    for (int row = 0; row < PUZ_SIZE; row += PUZ_SUBGRID_SIZE) {
        for (int col = 0; col < PUZ_SIZE; col += PUZ_SUBGRID_SIZE) {
            puz[i].sudoku_puz = puz_arr;
            puz[i].row = row;
            puz[i].col = col;
            puz[i].i = i - 2;
            //subgrid_checker(&puz);
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

    zero_results();

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

/* [Puzzles with solutions](https://www.puzzles.ca/sudoku/) */
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

/* Same as above but with the first element changed. */
static int sudoku_puz2[][PUZ_SIZE] = {
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