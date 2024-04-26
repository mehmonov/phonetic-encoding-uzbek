#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int isvowel(char c) {
    c = toupper(c);
    return (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
}

char * encode(char * word) {
    char * s = strdup(word);
    int len = strlen(s);
    int pos = 0;

    for (int i = 0; i < len; i++) {
        s[i] = toupper(s[i]);
    }

    char * result = malloc((len * 2 + 1) * sizeof(char));

    if (result == NULL) {
        return NULL;
    }

    int resultPos = 0;

    while (pos < len) {
        char c = s[pos];
        char next = pos < len - 1 ? s[pos + 1] : '\0';
        char nextnext = pos < len - 2 ? s[pos + 2] : '\0';

        switch (c) {
            case 'C':
                if (next == 'H') {
                    result[resultPos++] = 'J';
                    pos++;
                } else {
                    result[resultPos++] = 'S';
                }
                break;

            case 'A':
                if (pos == 0 || pos == len - 1) {
                    result[resultPos++] = 'A';
                } else if (next == 'O') {
                    result[resultPos++] = 'O';
                    pos++;
                } else if (next == 'I') {
                    result[resultPos++] = 'Y';
                    pos++;
                }
                break;

            case 'E':
                if (pos == 0 || pos == len - 1) {
                    result[resultPos++] = 'I';
                }
                break;

            case 'I':
                if (pos == 0) {
                    result[resultPos++] = 'I';
                } else if (next == 'A' || next == 'O') {
                    result[resultPos++] = 'Y';
                    pos++;
                }
                break;

            case 'O':
                if (pos == 0) {
                    if (next == '\'') {
                        result[resultPos++] = 'U';
                        pos++;
                    } else if (next == 'I') {
                        result[resultPos++] = 'O';
                        result[resultPos++] = 'Y';
                        pos++;
                    } else {
                        result[resultPos++] = 'O';
                    }
                } else if (next == 'I') {
                    result[resultPos++] = 'Y';
                    pos++;
                } else if (pos == len - 1) {
                    result[resultPos++] = 'O';
                }
                break;

            case 'B':
            case 'P':
                result[resultPos++] = 'P';
                if (next == c) pos++;
                break;

            case 'F':
            case 'V':
                result[resultPos++] = 'F';
                if (next == c) pos++;
                break;

            case 'D':
                result[resultPos++] = 'T';
                if (next == c) pos++;
                break;

            case 'Q':
            case 'K':
                result[resultPos++] = 'K';
                if (next == c) pos++;
                break;

            case 'G':
                result[resultPos++] = 'K';
                if (next == '\'') {
                    pos++;
                } else if (next == c) {
                    pos++;
                }
                break;

            case 'H':
            case 'X':
                result[resultPos++] = 'X';
                if (next == 'T' && !isvowel(nextnext)) {
                    pos++;
                } else if (next == c) {
                    pos++;
                }
                break;

            case 'J':
                result[resultPos++] = 'J';
                if (next == c) pos++;
                break;

            case 'L':
            case 'M':
            case 'N':
            case 'R':
                result[resultPos++] = c;
                if (next == c) pos++;
                break;

            case 'S':
                result[resultPos++] = 'S';
                if (next == 'H' || next == c) pos++;
                break;

            case 'T':
                if (next == 'S') {
                    result[resultPos++] = 'S';
                    pos++;
                } else {
                    result[resultPos++] = 'T';
                    if (next == c) pos++;
                }
                break;

            case 'U':
                if (pos == 0 || pos == len - 1) {
                    result[resultPos++] = 'U';
                }
                break;

            case 'Y':
                if (pos > 0 && (next == 'A' || next == 'U' || next == 'O' || next == 'E')) {
                    result[resultPos++] = next;
                    pos++;
                } else {
                    result[resultPos++] = 'Y';
                    if (next == c) pos++;
                }
                break;

            case 'Z':
                result[resultPos++] = 'S';
                if (next == c) pos++;
                break;

            case ' ':
                result[resultPos++] = ' ';
                if (next == c) pos++;
                break;
        }
        pos++;
    }

    result[resultPos] = '\0';
    return result;
}