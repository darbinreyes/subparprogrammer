/*
    Can a struct tag and its typedef have the same name?
    ANS: Yes.
*/


typedef struct Point {
    int x;
    int y;
} Point;

int main(void) {
    Point pt;

    pt.x = 0;
    pt.y = 7;

    return 0;
}