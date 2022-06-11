#include <stdio.h>

#define MAXLINE 1000

/* trivia:
   * definition: assigning a value (or garbage)
   * declaration: defining the nature of the variable itself (what it is) */

int max;
char longest[MAXLINE];

int getline(void);
void copy(void);

void x();

void x() {}

main() {
    x(1, 2, 3); /* we are able to pass arguments
                   because we didn't specify `x` as `void x(void)`! */

    int len;
    /* using `extern` we need to make external variables known to the function
       unless the definition occurs before usage so in this case it's
       redundant */
    extern int max;
    extern char longest[];

    max = 0;
    while ((len = getline()) > 0) {
        if (len > max) {
            max = len;
            copy();
        }
    }
    if (max > 0)
        printf("%s", longest);
    return 0;
}

int getline(void) {
    int c, i;
    extern char line[]; /* this extern however is required because the
                           definition of `line` is below */

    for (i = 0; i < MAXLINE - 1
         && (c = getchar()) != EOF && c != '\n'; ++i) {
        line[i] = c;
    }
    if (c == '\n')
        line[i++] = c;
    line[i] = '\0';
    return i;
}

char line[MAXLINE];

void copy(void) {
    int i;
    extern char line[], longest[];

    i = 0;
    while ((longest[i] = line[i]) != '\0')
        ++i;
}
