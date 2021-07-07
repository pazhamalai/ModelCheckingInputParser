//
// Created by pazhamalai on 05/07/21.
//

#include <string.h>
#include "fileReaderUtils.h"
#include "stdlib.h"
#include "../commonUtils.h"
#include "ctype.h"

int is_last_term(int c) {
    return c == ',' || c == NEWLINE || c == ')' || isspace(c);
}

char *read_string(FILE *fp, int *c) {
    int len = 0;
    char buffer[BUFFER_MAX + 1];

    while (!is_last_term(*c = fgetc(fp)) && len < BUFFER_MAX) {
        buffer[len] = *c;
        len++;
    }
    ungetc(*c, fp);
    buffer[len] = '\0';

    char *str = malloc((len + 1) * sizeof(char));
    return strcpy(str, buffer);
}

void skipSpaces(FILE *fp, int *c) {
    while (isspace(*c = getc(fp)));

    ungetc(*c, fp);
}