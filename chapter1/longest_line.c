#include <stdio.h>

#define MAX_LINE_LENGTH 10
#define MAX_LINE_LENGTH2 200

/* only the declarations need to be in order,
   the definitions can go anywhere they want */
int getline(char line[], int maxline);
void copy(char a[], char b[]);
void alternateCopy(char[], char[]);
void reverse(char string[], int length);

test() {
    /* a little test */
    char x[1];
    char y[1];
    x[0] = 5;
    y[0] = 10;
    return printf(
        "%d\n",
        (x[0] = y[0]) /* this expression results in `y[0]` value (rhs)! */
    );
}

print_lines_longer_than_80() {
    char line[MAX_LINE_LENGTH2];
    int c, i;

    i = 0;
    while ((c = getchar()) != EOF) {
        if (c == '\n') {
            if (i > 80) {
                /* this allows us to print a non-zero-terminated string
                   with a known length */
                printf("%.*s\n", i, line);
            }
            i = 0;
            continue;
        }
        line[i++] = c;
        if (i == MAX_LINE_LENGTH2) {
            printf("too long! ignoring this line and starting over!\n");
            i = 0;
        }
    }
}

cleanup_line() {
    /* trim trailing whitespace from a line */

    char line[MAX_LINE_LENGTH2];
    int c, i, length;

    i = 0;
    while ((c = getchar()) != EOF) {
        /* this could use some improvements */
        if (c == '\n') {
            --i;
            length = i;
            for (; i > 0; --i) {
                c = line[i];
                if (c != ' ' && c != '\n' && c != '\t') {
                    length = i + 1;
                    i = 0;
                    break;
                }
            }

            printf("`%.*s`\n", length, line);
            continue;
        }
        line[i++] = c;
        if (i == MAX_LINE_LENGTH2)
            break;
    }
}

reverse_lines() {
    char line[MAX_LINE_LENGTH2];
    int c, i;
    while ((c = getchar()) != EOF) {
        if (c == '\n') {
            reverse(line, i);
            printf("%.*s\n", i, line);
            i = 0;
            continue;
        }
        line[i++] = c;
    }
}

main() {
    int some_boolean = 1; /* if this is anything but 0, it works,
                             not only 1 works */
    if (some_boolean)
        printf("got some boolean\n");

    /* return reverse_lines(); */

    return cleanup_line();

    return print_lines_longer_than_80();

    /* return test(); */

    /* side note: `++i`, `i += 1`, and `i = i + 1` are the exact same,
                  but `i++` is different */

    int line_length;
    int max_len;
    char line[MAX_LINE_LENGTH]; /* current string */
    char longest[MAX_LINE_LENGTH]; /* longest string so far */

    max_len = 0;
    while ((line_length = getline(line, MAX_LINE_LENGTH)) > 0) {
        if (line_length > max_len) {
            max_len = line_length;
            copy(line, longest);
        }
    }
    if (max_len > 0) /* was there a line? */
        printf("longest line: \"%s\"... with length %d", longest, max_len);
    return 0;
}

int getline(char string[], int limit) {
    int c, i;

    for (
        i = 0;
        i < limit - 1 && (c = getchar()) != EOF && c != '\n';
        ++i
    )
        string[i] = c;
    if (c != EOF && c != '\n') {
        /* the actual reason we broke out of `for` is that we reached the limit
           so let's stop storing the characters and only count the length */
        string[i] = 0;
        for (; (c = getchar()) != EOF && c != '\n'; ++i);
        return i;
    }
    if (c == '\n')
        /* postfix increment here makes sure the increment happens
           after this line */
        string[i++] = c;
    string[i] = 0; /* '\0' would also work */
    return i;
}

/* the following functions are only for effect and return no useful value */

/* copy from `a` to `b`.
   thsi does *not* need `a` to be zero-terminated.
   we are getting pointers to arrays here. */
void copy(char a[], char b[]) {
    int i, c;
    for (i = 0; (c = a[i]) != 0; ++i)
        b[i] = c;
    b[i] = 0;
}

/* same as `copy` but requires `a` to be zero-terminated */
void alternateCopy(char a[], char b[]) {
    int i, c;

    i = 0;
    while ((b[i] = a[i]) != 0) /* the expression results in the RHS */
        ++i;
}

void reverse(char string[], int length) {
    int i, start, end, temp;
    for (i = 0; i < length / 2; ++i) {
        start = i;
        end = length - i - 1;

        temp = string[start];
        string[start] = string[end];
        string[end] = temp;
    }
}
