//
// Created by pazhamalai on 15/07/21.
//

#include "FairnessParser.h"
#include "../FileReaderUtils/fileReaderUtils.h"
#include "../FormulaParser/FormulaParser.h"
#include "stdlib.h"

struct Formula** readFairnessConstraints(FILE* fp, char** variables, int numberOfVariables, int* numberOfFairnessConstraints) {
    int c;
    skipSpaces(fp, &c);

    c = getc(fp);
    if(c != '(') {
        *numberOfFairnessConstraints = 0;
        return NULL;
    }

    ungetc(c, fp);

    int numberOfConstraints = 1;
    struct Formula** formulas = (struct Formula**) malloc(sizeof(struct Formula*));
    formulas[0] = readFormula(fp, variables, numberOfVariables, 0);
    skipSpaces(fp, &c);

    while ((c = getc(fp)) == ',') {
        skipSpaces(fp, &c);
        ++numberOfConstraints;
        formulas = realloc(formulas, (sizeof(struct Formula*)) * numberOfConstraints);
        formulas[numberOfConstraints - 1] = readFormula(fp, variables, numberOfVariables, 0);
        skipSpaces(fp, &c);
    }

    *(numberOfFairnessConstraints) = numberOfConstraints;
    return formulas;
}