#include <stdio.h>

int check(void);

void main() {
    int depth = check();
    if (depth != 0)
        printf(
            "got depth %d but expected a depth of 0.\n"
            "there is at least one unmatched"
            "parenthesis, bracket, or brace somewhere\n",
            depth
        );
}

int check() {
    int c, depth;

    depth = 0;
    while ((c = getchar()) != EOF) {
        switch (c) {
            case '(': /* parenthesis */
                ++depth;
                break;
            case ')':
                --depth;
                break;
            case '[': /* bracket */
                ++depth;
                break;
            case ']':
                --depth;
                break;
            case '{': /* brace */
                ++depth;
                break;
            case '}':
                --depth;
                break;
            /* not doing double quotes, apotrophes, escape sequences, or comments */
        }
    }
    return depth;
}
