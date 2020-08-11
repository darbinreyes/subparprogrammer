/*

    https://www.hackerrank.com/challenges/down-to-zero-ii/problem

    Success Rate: 43.63%

*/

/*

    If N is prime, our only choice is to reduce N by 1.
    Otherwise it is possible to reduce N by more than 1, i.e. reduce N down
    to best_factor.(N)

    opcount = 0

    repeat while N > 0

        if N is prime
            N = N - 1
        else
            N = best_factor(N)

        opcount++

*/

#include <stdio.h>
#include <math.h>
#include <assert.h>

// For non-prime n, returns a factor of n which reduces n then most according to rule #1 in the problem statement.
int best_factor(int n) {
    int gm;
    int of;
    int tgm;
    int sq;

    gm = n;
    tgm = 1;

    sq = (int) sqrt(n);
    for (int i = 2; i <= sq; i++) { // TODO: This can be faster if we make use of the work done by function is_prime().
        if (n % i == 0) {
            of = n / i;
            // assert n = i * of
            //printf("%d = %d x %d.\n", n, i, of);
            tgm = (i > of) ? i : of;
            if (tgm < gm)
                gm = tgm;
        }
    }

    return gm;
}

/* Scratch Work

    N = 5,
    oc = 0
    ---
    N = 4,
    oc = 1
    N = 2,
    oc = 2
    N = 1,
    oc = 3
    N = 0,
    oc = 4


    Consider the case N = 12.

    12 = 2 * 6, max(2,6) = 6
    but
    12 = 3 * 4, max(3,4) = 4, so N = 4 is better than N = 6.


    For N = 812849, my output is 12 moves, the correct output is claimed to be 10 moves.

    This suggests that one try every possible set of moves. When N is prime, the
only possible move is to decrease by 1. When N is not prime, we have a choice
between decreasing by 1,  or decreasing down to the "best factor". Apparently,
when we have a choice,  decreasing by 1 instead of decreasing to the "best
factor" may lead to fewer  moves in the end. Alternatively, there is probably
some mathematical fact, which if known, allows you to avoid this brute force method.

*/

#define ARRAY_SIZE 1000000

static int a[ARRAY_SIZE+1];

int downToZero(int N, int use_a) {
    int mcount = 0;
    int t;

    if (N <= 3)
        return N;

    while (N > 0) {
        t = best_factor(N);

        if (t == N) {
            N--;
        } else {
            if (use_a == 0)
                N = t;
            else {
                //assert(a[t] != a[N-1]);
                if (a[t] < a[N-1])
                    N = t;
                else
                    N--;
            }
        }
        //printf("N = %d\n", N);
        mcount++;
    }

    return mcount;
}

int main(void) {
    int N = 808707;

    for (int i = 1; i <= ARRAY_SIZE; i++) {
        a[i] = downToZero(i, 0);
    }

    //printf("a[7273] = %d\n", a[7273]);

    //printf("N = %d\n", N);
    printf("mcount = %d\n", downToZero(N, 1));
    return 0;
}