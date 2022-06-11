#include <stdio.h>

#define SPACES_PER_TAB 4

void main() {
    int character; /* as always we need `int` instead of `char`
                      to be able to handle EOF which is -1 */
    int index;
    while ((character = getchar()) != EOF) {
        if (character == '\t')
            for (index = 0; index < SPACES_PER_TAB; ++index)
                putchar(' ');
        else
            putchar(character);
    }
}
