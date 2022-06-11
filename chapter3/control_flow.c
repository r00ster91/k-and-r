#include <limits.h>
#include <stdio.h>

main() {
    printf(
        "%d\n",
        binsearch(
            9,
            (int[]){ 1,  2,  3,  4,  5,
                     6,  7,  8,  9, 10,
                    11, 12, 13, 14, 15}, /* this is how you can
                                          * inline arrays
                                          */
            15
        )
    );
}

/* this binary search relies on `v` being sorted! */
int binsearch(int x, int v[], int n) {
    int i, offset = 0;

    for (;;) {
        i = n / 2;
        if (i >= n) return -1;
        if (x > v[i]) {
            v += i;
            offset += i;
            n -= i;
        } else if (x < v[i]) {
            n = i;
        } else {
            return offset + i;
        }
        if (n == 1) return -1;
    }
}
