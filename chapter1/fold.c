#include <stdio.h>

#define MAX_INPUT_LEN 10000
#define WRAP_COLUMN   8

void print_wrap(char[], int);

void main() {
    /* fun fact: the following string will *not* be automatically
       zero-terminated! It's because we explicitly specified the size */
    char hello[5] = "hello";
    /* but this will. With `[]` we let C decide the size and it will be 6
       because it will add a 0 as well */
    char zero_terminated_hello[] = "hello";

    char input[MAX_INPUT_LEN];
    int i, c, input_len;

    /* this would work too (minus the bounds check) */
    /*i = 0;
    while ((c = getchar()) != EOF)
        input[i++] = c;*/

    for (i = 0; (c = getchar()) != EOF; ++i) {
        if (i > MAX_INPUT_LEN) {
            printf("Sorry, input too long!");
            return;
        }
        input[i] = c; /* it implicitly converts from `int` to `char`! */
    }
    input_len = i;

    print_wrap(input, input_len);
}

void print_wrap(char input[], int len) {
    if (len <= WRAP_COLUMN)
        goto print;

    /* this only assigns to `x` (unused, anyway), `i` is left with garbage */
    int i, x = 0;
    char c;

    /* go backwards */
    for (i = WRAP_COLUMN; i < len; ++i) {
        c = input[i];
        if (c == ' ' || c == '\t') {
            input[i] = '\n';
            i += WRAP_COLUMN;
        }
    }

    print:
    printf("%.*s\n", len, input);
}