//
// Created by pazhamalai on 05/07/21.
//

#ifndef MODELCHECKINGINPUTPARSER_FILEREADERUTILS_H
#define MODELCHECKINGINPUTPARSER_FILEREADERUTILS_H

#include "stdio.h"

char *read_string(FILE *fp, int *c);
void skipSpaces(FILE *fp, int *c);

#endif //MODELCHECKINGINPUTPARSER_FILEREADERUTILS_H
