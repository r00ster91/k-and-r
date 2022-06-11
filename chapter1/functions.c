#include <stdio.h>

int power(int m, int n);

main() {
    int i;

    for (i = 0; i < 10; ++i)
        printf("%d %d %d\n", i, power(2, i), power(-3, i));
    return 0;
}

power(int base, int n) {
    /* int i, p;

    p = 1;
    for (i = 1; i <= n; ++i)
        p *= base; /*

    /* alternative approach utilizing mutable `n`
       while not mutating the outer `n` (call by value/copy): */
    int p;

    for (p = 1; n > 0; --n)
        p *= base;

    return p;
}
