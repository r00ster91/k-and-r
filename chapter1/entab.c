#include <stdio.h>
#include <string.h>

#define SPACES_PER_TAB 4
#define MAX_INPUT_LEN 100

void main() {
    int i, c; /* as always we need `int` instead of `char`
                 to be able to handle EOF which is -1 */

    int input_len;
    char input[MAX_INPUT_LEN];
    i = 0;
    while ((c = getchar()) != EOF)
        input[i++] = c;
    input_len = i;

    /* we need this for comparison */
    char spaces[SPACES_PER_TAB];
    for (i = 0; i < SPACES_PER_TAB; ++i)
        spaces[i] = ' ';

    i = 0;
    while (i < input_len) {
        if (input_len - i >= 4 && memcmp(input + i, spaces, 4) == 0) {
            printf("\t");
            i += 4;
        } else {
            putchar(input[i]);
            ++i;
        }
    }
}
