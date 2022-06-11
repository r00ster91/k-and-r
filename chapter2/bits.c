#include <limits.h>
#include <assert.h>

unsigned getbits(unsigned x, int p, int n) {
    return (x >> (p+1-n)) & ~(~0 << n);
}

unsigned setbits(unsigned x, int p, int n, int y) {
    return 0; /* maybe someday */
}

unsigned invert(unsigned x, int p, int n) {
    return 0; /* maybe someday */
}

unsigned rightrot(unsigned x, int n) {
    return 0; /* maybe someday */
}

unsigned bitcount(unsigned x) {
    int b;
    for (b = 0; x != 0; ++b)
        /* set the rightmost 1 to 0 */
        x &= (x - 1);
    return b;
}

int lower(int c) {
    return (c >= 'A' && c <= 'Z') ? c - '0' : c;
}

main() {
    /* `>>` removes bits from the *right* */
    assert((0b10101111 >> 4) == 0b1010);
    /* assert(invert(0b1010, 1, 2) == 0b01); */

    int x = 0b1010;
    assert((0b1010 & (0b1010 - 1)) == 0b1000);

    assert(bitcount(0b1111) == 4);
    assert(bitcount(0b1010) == 2);
    assert(bitcount(0b1011101) == 5);
}
