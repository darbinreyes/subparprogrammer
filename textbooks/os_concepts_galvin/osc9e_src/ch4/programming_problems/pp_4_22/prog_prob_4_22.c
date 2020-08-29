#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

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


double get_rand_fraction(void) {
    double frn;
    double frd;

    frn = (double) arc4random_uniform(UINT32_MAX);
    frd = (double) UINT32_MAX;


    frn = (frn/frd);

    return frn;
}

typedef struct _point_t {
    double x;
    double y;
} point_t;

void get_rand_point(point_t *p) {
    p->x = -1.0 + 2.0 * get_rand_fraction();
    p->y = -1.0 + 2.0 * get_rand_fraction();
}

int is_inside_circle(point_t *p){
    double xs, ys, s;

    xs = p->x * p->x;
    ys = p->y * p->y;

    s = sqrt(xs + ys);

    return s < 1.0;
}

double inside = 0.0;

void inside_count(long n) {
    point_t p;

    while (n-- > 0) {
        get_rand_point(&p);
        if (is_inside_circle(&p))
            inside++;
    }
}

int main(int argc, char **argv) {
    long num_points;
    double t;

    if (argc <= 1 || argc > 2) {
        printf("Usage: Provide 1 positive integer. Example: ./a.out 7.\n");
        return -1;
    }

    num_points = strtol(argv[1], NULL, 10);

    if (num_points < 1) {
        printf("Failed to convert \"%s\" to a positive integer.\n", argv[1]);
        return -1;
    }

    t = (double) num_points;

    inside_count(num_points);

    t = 4.0 * inside / t;

    printf("Pi ~= %.12f. It should be close to 3.141592653589793.\n", t);

    return 0;
}