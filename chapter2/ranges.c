/* while many data types in C are machine-dependent
   (with at least some guaranteed lower bound) the constants
   in these headers lets us check all these properties */
#include <stdio.h>
#include <math.h>
#include <limits.h>
#include <float.h>

test() {
    extern int a2[5]; /* a2[] works too */
    printf("%ls\n", a2);
}

/* when initializing arrays and you specify the initial values,
   all indices that you didn't specify a value for will be 0,
   therefore `a1` will be 5 zeroes */
int a1[5] = {}; /* this is the same as `{ 0 }`

/* the remaining two elements are guaranteed to be 0 */
int a2[5] = { 'a', 'b', 'c' };

void main() {
    test();

    printf(
        "%d is exactly the same as %d\n",
        (int)pow(2, 8),
        2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 /* a trailing comma here is disallowed! */
    );

    printf("signed char:\t\t\t%d to %d\n", SCHAR_MIN, SCHAR_MAX);
    printf("unsigned char:\t\t\t%d to %d\n", 0, UCHAR_MAX);
    printf(
        "computed signed char:\t\t%d to %d\n",
        -(int)pow(2, 8 - 1),
        (int)pow(2, 8 - 1) - 1
    );
    printf(
        "computed unsigned char:\t\t%d to %d\n",
        0,
        (int)pow(2, 8) - 1
    );

    putchar('\n');

    printf("signed short:\t\t\t%d to %d\n", SHRT_MIN, SHRT_MAX);
    printf("unsigned short:\t\t\t%d to %d\n", 0, USHRT_MAX);
    printf(
        "computed signed short:\t\t%d to %d\n",
        -(int)pow(2, 16 - 1),
        (int)pow(2, 16 - 1) - 1
    );
    printf(
        "computed unsigned short:\t%d to %d\n",
        0,
        (int)pow(2, 16) - 1
    );

    putchar('\n');

    printf("signed int:\t\t\t%d to %d\n", INT_MIN, INT_MAX);
    printf("unsigned int:\t\t\t%d to %ld\n", 0, (unsigned long)UINT_MAX);
    printf(
        "computed signed int:\t\t%d to %d\n",
        -(int)pow(2, 32) - 1,
        (int)pow(2, 32)
    );
    printf(
        "computed unsigned int:\t\t%d to %d\n",
        0,
        (int)pow(2, 32) - 1
    );

    putchar('\n');

    printf("signed long:\t\t\t%ld to %ld\n", LONG_MIN, LONG_MAX);
    printf("unsigned long:\t\t\t%d to %lu\n", 0, ULONG_MAX);
    printf(
        "computed signed long:\t\t%ld to %ld\n",
        -(long)pow(2, 64) - 1,
        (long)pow(2, 64)
    );
    printf(
        "computed unsigned long:\t\t%d to %lu\n",
        0,
        (unsigned long)pow(2, 64)
    );

    /* not doing floating point data types */
}
