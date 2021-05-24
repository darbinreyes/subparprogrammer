   int arr[8][8] =               { {0, 0, 1, 0, 0, 0, 0, 1},
                                   {0, 0, 0, 0, 0, 0, 0, 1},
                                   {0, 1, 1, 0, 1, 0, 0, 0},
                                   {0, 1, 0, 0, 1, 1, 0, 0},
                                   {0, 1, 0, 0, 1, 1, 0, 0},
                                   {0, 0, 0, 0, 0, 0, 0, 0},
                                   {0, 0, 0, 0, 0, 0, 0, 1},
                                   {0, 0, 0, 0, 0, 0, 0, 1} };

/*

int maxIslandSize = 0;

scan the array,

if you encounter a 1, then calculateIslandSize(int i, int j)

t = calculateIslandSize(int i, int j) //

if (t > maxIslandSize)
    maxIslandSize = t;

// return max size island // duplicates don't matter

*/

int calculateIslandSize(int **arr, int i, int j, int r, int c) {
    // TODO
    // while there is a 1 to the left or right, count++
    int sz = 1;
    int offset = 1;

    while (arr[i][j+offset] == 1) { // count adjacent 1's to right of center
        sz++;
        offset++;
        if (j + offset >= c) {
            break;
        }
    }

    offset = -1;

    while (arr[i][j+offset] == 1) { // to left
        sz++;
        offset--;
        if (j + offset < 0) {
            break;
        }
    }

    offset = 1;

    while (arr[i+offset][j] == 1) { // below
        sz++;
        offset++;
        if (i + offset >= r) {
            break;
        }
    }

    offset = -1;

    while (arr[i+offset][j] == 1) { // above
        sz++;
        offset--;
        if (i + offset < 0) {
            break;
        }
    }

    // x TODO need to make sure offset doesn't go out of bounds!!

    // TODO account for "diagonal" 1's - recursive call?

    return sz;
}

int maxIslandSize(int **arr, int r, int c) { // arr, size rows, cols
    int max = 0;
    int i, j;
    int t;

    if (arr == NULL || r < 0 || c < 0) {
        return -1; //err
    }

    for (i = 0; i < r; i++) { // scan array
        for (j = 0; j < c; j++) {
            if (arr[i][j] == 1) {
                t = calculateIslandSize(arr, i, j, r, c);
                if (t > max)
                    max = t;
            }
        }
    }

    return max;
}