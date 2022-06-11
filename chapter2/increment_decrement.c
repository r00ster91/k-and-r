#include <assert.h>
#include <string.h>

char* squeeze(char[], const char[]);

void main() {
    char s[] = "hello world";
    char expected[] = "hll wrld";
    assert(memcmp(squeeze(s, "oe"), expected, strlen(expected)) == 0);

    assert(any("hello", "xl") == 2);
    assert(any("hello", "o") == 4);
    assert(any("hello", "x") == -1);
}

char* squeeze(char s1[], const char s2[]) {
    int i, j, k = 0, c1, c2;

    for (i = 0; (c1 = s1[i]) != 0; ++i) {
        int retain = 1;
        for (j = 0; (c2 = s2[j]) != 0; ++j) {
            if (c1 == c2) {
                retain = 0;
                break;
            }
        }
        if(retain)
            s1[k++] = c1;
    }
    s1[k] = 0;

    return s1;
}

int any(const char s1[], const char s2[]) {
    int i, j, k = 0, c1, c2;

    for (i = 0; (c1 = s1[i]) != 0; ++i) {
        for (j = 0; (c2 = s2[j]) != 0; ++j) {
            if (c1 == c2)
                return k;
        }
        ++k;
    }

    return -1;
}
