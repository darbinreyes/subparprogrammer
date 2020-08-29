#include <stdio.h>
#include <stdlib.h>


/*

    The unit circle described in the problem is has a radius of 1 and is
    inscribed in a square whose sides equal 2. Therefore, to generate a
    random x coordinate, we can multiply a random fraction by 2 (the size of the
    square's side) and add the product to the lesser x coordinate, which is -1.
    We can generate a random y coordinate in exactly the same way.

    Next, we must determine if the randomly generated point falls within the
    circle. Since the radius of the circle is 1, all we need to do is compute
    the distance of the random point from the the origin (x,y) = (0,0), we can
    use Pythagoras theorem for that, finally, if that distance is less than 1
    we know that the point has fallen within the circle. We shall consider
    points that are exactly a distance 1 from the origin to be outside of the
    circle.

    Finally, we compute the estimation of pi with:

    4.0*num_inside/num_outside.


*/


long get_rand_fraction(void) {
    float frn;
    float frd;

    frn = (float) rand();
    frd = (float) RAND_MAX;


    frn = 10000000.0 * (frn/frd);

    return (long) frn;
}

int main(int argc, char **argv) {
     sranddev(); // Use a fresh seed for rand().
    return 0;
}