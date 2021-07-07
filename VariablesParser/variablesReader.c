//
// Created by pazhamalai on 29/06/21.
//

#include "variablesReader.h"
#include "../FileReaderUtils/fileReaderUtils.h"
#include "stdio.h"
#include "stdlib.h"
#include "../commonUtils.h"

char** readInputVariables(FILE* fp, int* numberOfVariables)
{
    int c;
    char* variables_buffer[BUFFER_MAX];
    int len = 0;

    skipSpaces(fp, &c);
    while ((c = fgetc(fp)) != NEWLINE) {

        ungetc(c, fp);
        variables_buffer[len++] = read_string(fp, &c);

        //Skip ',' symbol
        if(c == ',')
            c = getc(fp);

        //End of variables declaration
        if(c == NEWLINE)
            break;

        skipSpaces(fp, &c);

        if (c == NEWLINE)
            break;
    }

    char **variables = malloc(sizeof(char*) * len);

    for (int i = 0; i < len ; ++i) {
        variables[i] = (char*) variables_buffer[i];
    }

    *numberOfVariables = len;
    return variables;
}