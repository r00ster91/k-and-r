/* pipe input to the program */

#include <stdio.h>
#include <limits.h>

#define INSIDE_WORD  1
#define OUTSIDE_WORD 0

print_digits_whitespace_other() {
    signed i; /* defaults to `signed int` */

    int digits[10];
    int digits_length = sizeof(digits) / sizeof(int);
    for (i = 0; i < digits_length; ++i)
        digits[i] = 0;

    int c = 0;
    int whitespaces = 0;
    int others = 0;
    while ((c = getchar()) != EOF) {
        if (c >= '0' && c <= '9') {
            ++digits[c - '0'];
        } else if (c == ' ' || c == '\n' || c == '\t') {
            ++whitespaces;
        } else {
            ++others;
        }
    }

    printf("digits: ");
    for (i = 0; i < digits_length; ++i)
        printf("%d, ", digits[i]);
    printf("whitespaces: %d, others: %d", whitespaces, others);
}

print_words() {
    int c;
    while ((c = getchar()) != EOF) {
        if (c == ' ') {
            putchar('\n');
            continue;
        }
        putchar(c);
    }
}

#define MAX_WORDS 1000

/* this could definitely be improved */
print_word_length_histrogram() {
    int i;
    int word_lengths[MAX_WORDS];
    for (i = 0; i < MAX_WORDS; ++i)
        word_lengths[i] = 0; /* no word occurrences */

    int word_length = 0;
    int c;
    while ((c = getchar()) != EOF) {
        if (c == ' ') {
            ++word_lengths[word_length];
            word_length = 0;
        } else {
            ++word_length;
        }
    }

    for (i = 0; i < MAX_WORDS; ++i) {
        int length = word_lengths[i];
        if (length == 0)
            continue;
        printf("words with length %d: ", i);
         int length_i;
         for (length_i = 0; length_i < length; ++length_i)
             putchar('=');
        putchar('\n');
    }
}

/* this works very nicely */
print_character_frequencies_histogram() {
    int frequencies[UCHAR_MAX];
    int i;
    for (i = 0; i < UCHAR_MAX; ++i)
        frequencies[i] = 0;

    int c;
    while ((c = getchar()) != EOF)
        ++frequencies[c];

    int occurrence_i;
    for (i = 0; i < UCHAR_MAX; ++i) {
        const occurrences = frequencies[i];
        if (occurrences == 0)
            continue;
        printf("character %c: ", i);
        for (occurrence_i = 0; occurrence_i < occurrences; ++occurrence_i)
            putchar('=');
        putchar('\n');
    }
}

main() {
    return print_character_frequencies_histogram();

    return print_word_length_histrogram();

    return print_digits_whitespace_other();

    return print_words();

    int c, state;
    int newlines, words, characters;

    /* we start outside a word */
    state = OUTSIDE_WORD;
    newlines = words = characters = 0;
    while ((c = getchar()) != EOF) {
        ++characters;
        if (c == '\n')
            ++newlines;
        if (c == ' ' || c == '\n' || c == '\t')
            state = OUTSIDE_WORD;
        else if (state == OUTSIDE_WORD) {
            state = INSIDE_WORD;
            ++words;
        }
    }
    printf("%d %d %d\n", newlines, words, characters);
}
