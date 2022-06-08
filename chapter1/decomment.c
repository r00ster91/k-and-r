#include <stdio.h>

/* this file contains a lot of comments */
#define MAX_INPUT_LEN 10000
/* so that I can check whether this program works using its source code */

void print_without_comments(char[], int);

void main() /* hello! */ {
    printf("/* I'm not a comment and \" does not terminate this string! */");

    char input[MAX_INPUT_LEN];
    int input_len, c;

    input_len = 0;
    while ((c = getchar()) != EOF) {
        if (input_len > MAX_INPUT_LEN) {
            /* oh no! */ printf("Too long!");
            return;
        }
        input[input_len++] = c;
    }

    print_without_comments(input, input_len);
} /*im a poorly written comment*/

void print_without_comments(char string[], int len) {
    int i, c;
    for (i = 0; i < len; ++i) {
        c = string[i];
        /* check for strings so that we can ignore "comments" inside them */
        if (c == '"') {
            for (; i < len; ++i) {
                c = string[i];
                /* make sure we handle escaped double quotes */
                if (c == '\\' && i + 1 < len && string[i + 1] == '"') {
                    printf("\\\"");
                    continue;
                } else if (c == '"') {
                    /* we found the end */
                    putchar('"');
                    break;
                } else {
                    putchar(c);
                }
            }
        } else if (c == '/' && i + 1 < len && string[i + 1] == '*') {
            for (; i < len; ++i) {
                c = string[i];
                if (c == '*' && i + 1 < len && string[i + 1] == '/') {
                    /* we found the end of the comment */
                    break;
                }
            }
            ++i;
        } else {
            putchar(c);
        }
    }
}