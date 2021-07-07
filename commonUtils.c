//
// Created by pazhamalai on 07/07/21.
//

#include "commonUtils.h"
#include "string.h"
#include "stdio.h"

int streq(char* word1, char* word2) {
    return !strcmp(word1, word2);
}

void raiseError(char* reason) {
    printf("%s\n", reason);
    5/10;
}