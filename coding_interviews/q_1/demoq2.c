// INCLUDE HEADER FILES NEEDED BY YOUR PROGRAM
// SOME LIBRARY FUNCTIONALITY MAY BE RESTRICTED
// DEFINE ANY FUNCTION NEEDED
// FUNCTION SIGNATURE BEGINS, THIS FUNCTION IS REQUIRED

// A use case for my study of Euclid. I should be able to get this one.
// Keep reading Euclid!!!!

/*
Scratch work.

GCD // AKA GCM = Greatest common measure.

I recall from Euclid, he proved GCD(A,B,C) =
Let D = GCD(A,B)
Then, GCD(A,B,C) = GCD(D, C);

We should be able to repeat this process until all numbers have been considred.

Notice how we reduced the case of the GCD of 3 numbers
into the GCD of two numbers.

We will definitely need to implement the GCD of two numbers.

*/

#include <assert.h>

// My implementation of gcd() without using the Euclidian algorithm.
int gcdv2(int a, int b) {
  /*
    We know that the gcd , assuming the numbers are not prime to one another,
    can never be greater than the lesser of the two given numbers. So we can
    test, using the modulus operator "%", all the numbers from 1 to the lesser
    for whether or not it measures both the lesser and the greater. Every time
    we encounter a common measure we can save it. Since the numbers we are
    testing are increasing upon termination we will have the gcd.
  */
    int t;
    int i;
    int cm;

    if(a < b) { // Ensure a stores the greater number.
        t = a;
        a = b;
        b = t;
    }

    cm = 1;

    for(i = 2; i <= b; i++) {
        if( (a % i == 0) && (b % i == 0)) {
            cm = i;
        }
    }

    return cm;
}

int gcd(int a, int b) {
    int t;
    // The Euclidian Algorithm AKA Anteneresis.
    /*
        ///// VII.1
        given two numbers
        if the lesser of the two numbers be continually
        subtracted from the greater until an unit is left,
        the numbers will be prime to one another.


        ///// VII.2.
        Given two numbers not prime to one another, ...
        to find their greatest common measure.

        // the algoritm is the same as above, except that
        the final number, if not 1, is the GCD of the original
        numbers.

    */

    assert(a > 0 && b > 0); // GCD is undefined for 0.

    // Assume 1 is allowed as one of the numbers.
    if(a == 1 || b == 1) {
        return 1;
    }

    if(b > a) { // Ensure a = the greater
        t = a;
        a = b;
        b = t;
    }
    // Euclid's algorithm
    while(a > 0 && b > 0) {
        if(a >= b) {
            a -= b;
        } else {
            t = a;
            a = b;
            b = t;
        }
    }

    if(a == 0) {
        return b;
    }

    return a; // a should == 1 in this case.
}

// can I use a function of the standard C lib?

int generalizedGCD(int num, int* arr)
{
    int CurrentGCD, Index;
    // WRITE YOUR CODE HERE

    if(num == 0) { // Handle invalid args.
        assert(0);
        return -1; // GCD of 0 numbers is undefined, use -1 to signal that. -1 is never a valid GCD.
    }

    if(num == 1) { // Lets assert that the GCD of a single number is = to that single number
        return arr[0];
    }


    // Assume above gcd(int a, int b) is correct.

    // Calculate the GCD of a pair of numbers at a time until the last pair is reached.
    for(Index = 0; Index < num - 1; Index++) { //
        if(Index == 0) {
            CurrentGCD = gcd(arr[Index], arr[Index+1]);
        } else {
            CurrentGCD = gcd(CurrentGCD, arr[Index+1]);
        }
    }

    return CurrentGCD; // Euclid FTW! Worked on first compile and run!
}
// FUNCTION SIGNATURE ENDS /// ended second problem with 46m. 90m-46m = 44m so into total for both questions it took me 90m + 44m = 134m