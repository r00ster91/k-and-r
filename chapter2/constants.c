#include <stdio.h>
#include <assert.h>

long htoi(const char[]);
int strlen(const char[]);
void squeeze(char[], int);

void main() {
    /* default integer type is `int` so `123` will be an `int`
     * however, if an integer constant is too big to fit in `int`, it will
     * be taken as a `long`
     */

    long a = 123L;
    long b = 123l;

    unsigned long x = 123ul;
    unsigned long y = 123ul;

    printf("%lu\?\n", 123ul);

    int year;

    for (year = 2020; year <= 2050; ++year) {
        const int year_is_leap_year = is_leap_year(year);
        if (year_is_leap_year)
            printf("%d is a leap year\n", year);
        else
            printf("%d is not a leap year\n", year);
    }

    int i, c;
    int lim = 10;

    /* the following two are the same:
     * `i < lim - 1 && (c = getchar()) != '\n' && c != EOF`
     * for (i = 0;
            (i < lim - 1 + (c = getchar()) != '\n' + c != EOF) == 3;
            ++i);
     */

    printf("10 < 20: %d\n", 10 < 20);

    assert(htoi("0xFF") == 255);
    assert(htoi("0X123") == 291);
    assert(htoi("0xdEaDbEeF") == 3735928559);

    char before[] = "hello world";
    char after[] = "hell wrld";
    squeeze(before, 'o');
    assert(strlen(before) == strlen(after));
    assert(memcmp(before, after, strlen(before)) == 0);
}

void squeeze(char s[], int c) {
    int i, j;

    for (i = j = 0; s[i] != 0; ++i)
        if (s[i] != c)
            s[j++] = s[i];
    s[j] = 0;
}

long htoi(const char s[]) {
    int i, len = strlen(s);

    if (len >= 2 &&
        /* `&&` has higher precedence than `||` */
        (s[0] == '0' && (s[1] == 'x' || s[1] == 'X'))) {
        i = 2;
    } else i = 0;

    int c;
    long val = 0;

    for (; i < len; ++i) {
        c = s[i];
        val *= 16;
        if (c >= '0' && c <= '9') {
            val += c - '0';
        } else if (c >= 'a' && c <= 'f') {
            val += 10 + (c - 'a');
        } else if (c >= 'A' && c <= 'F') {
            val += 10 + (c - 'A');
        } else return -1;
    }

    return val;
}

int strlen(const char s[]) {
    int i;
    for (i = 0; s[i] != 0; ++i);
    return i;
}

int is_leap_year(int year) {
    return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
}

enum X{
    A,
    B
};

enum A{
    A2, B2
};
