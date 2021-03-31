/*

Interviewer: Uma

* My questions:
    * what percentage of your time is spent on programming, debugging, and reading technical documentation? What if any, activities do you do outside of these broad categories.
    * what programming language do you use the most?
    * what was the last program you wrote?
    * Most challenging tech. problem worked on. // Trigger job - job ID - 500 internal error. // Jobs in infinite loop.
    * How often - interface with BIOS team.
*/


/*
Scratch

global python GAL

Work prev. work

Strengths - C

How do you scale your script ? 100's of server.

Uma - Familiar with.


Tries to write DP

LDAP
 1. eliminate
 2. wants - write

 3. instance from same - how do you -
 4.
 SR
 BMC IP

*/

/*

3! = 3 * 2 * 1

*/
int factorial (unsigned int n) {
    int r = 1;

    for ( ;n > 0; n--)
        r *= n;

    return r;
}


/*

test case 2

n = 2

// return 2 * f(1)

// f(1)

// 1 * f(0)

// return 1

// works for n = 2.

*/
int factorial2 (unsigned int n) {
    if (n > 0)
        return n * factorial2 (n--);

    return 1;
}


