#include <stdio.h>

main() {
    return show_escape_sequences();

    return clean_input();

    return count_lines();

    return double_version();

    printf("EOF: %d\n", EOF);

    long nc;
    int c;

    nc = 0;
    c = getchar();
    while (c != EOF) {
        ++nc;
        if ((c != EOF) != 0 && (c != EOF) != 1)
            printf("c != EOF is not 0 or 1\n");
        putchar(c);
        c = getchar();
    }
    printf("EOF reached and %ld characters read\n", nc);
}

double_version() {
    /* another way to write it */
    double double_nc;

    for (double_nc = 0; getchar() != EOF; ++double_nc);
    printf("EOF reached and %.0f characters read\n", double_nc);
}

count_lines() {
    int c, whitespace_count;

    whitespace_count = 0;
    while ((c = getchar()) != EOF)
        if (c == '\n' || c == ' ' || c == '\t')
            ++whitespace_count;
    printf("found %d whitespace characters", whitespace_count);
}

clean_input() {
    int c, found_blank = 0;
    while ((c = getchar()) != EOF) {
        if (c == ' ') {
            if (found_blank)
                continue;
            found_blank = 1;
        } else {
            found_blank = 0;
        }
        putchar(c);
    }
}

show_escape_sequences() {
    int c, found_blank = 0;
    while ((c = getchar()) != EOF) {
        switch (c) {
        case '\t':
            printf("\\t");
            break;
        case '\b':
            printf("\\b");
            break;
        case '\\':
            putchar('\\');
            break;
        default:
            putchar(c);
            break;
        }
    }
}