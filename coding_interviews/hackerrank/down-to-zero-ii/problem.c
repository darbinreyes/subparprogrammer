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

// Euclid's Algorithm. Given two numbers, to find their greatest command measure.
// If the two given numbers do not have common measure, returns 1, else returns the greatest common measure/a.k.a greatest common divisor.
int gcm(int a, int b) { // FYI: Is this slower than the typical implementation using modulus?
    // If the lesser be continually subtracted from the greater until an unit is left the original numbers will be prime to one another.
    int t;

    if (!(a > 1 && b > 1))
        return -1;

    while (a > 1) {
        if (a < b) { // `a` shall be the greater.
            t = a;
            a = b;
            b = t;
        }
        a = a - b;
    }

    if (a == 0)
        return b;

    if (a != 1)
        return -1;

    return 1;
}

// Returns 1 if n is prime, 0 otherwise.
int is_prime(int n) {
    int sq;
  /*
    ******* Scratch work.
    i < sqrt(n) // Trick: We only need to test for divisors up to the square root.
    i^2 < n

    n = 13
          2  3   4   5
    i^2 = 4, 9, 16, 25 < 13
    FYI Improvement: We could skip the gcd test when i*i == n.
  */
    sq = (int)sqrt(n);
    for (int i = 2; i <= sq; i++) {
        if (gcm(i, n) != 1)
            return 0; // Not prime.
    }

    return 1; // Is prime.
}

// For non-prime n, returns a factor of n which reduces n then most according to rule #1 in the problem statement.
int best_factor(int n) {
    int gm;
    int of;
    int tgm;
    int sq;

    gm = 1000001;
    tgm = 1;

    sq = (int) sqrt(n);
    for (int i = 2; i <= sq; i++) { // TODO: This can be faster if we make use of the work done by function is_prime().
        if (n % i == 0) {
            of = n / i;
            // assert n = i * of
            printf("%d = %d x %d.\n", n, i, of);
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

int downToZero(int N) {
    int mcount = 0;
    int t;

    if (N == 0)
        return 0;

    if (N == 1)
        return 1;

    while (N > 0) {
        if(is_prime(N)) {
            N--;
        } else {
            N = best_factor(N);
        }
        printf("N = %d\n", N);
        mcount++;
    }

    return mcount;
}

int main(void) {
    int N = 812849;

    printf("N = %d\n", N);
    printf("mcount = %d\n", downToZero(N));
    return 0;
}