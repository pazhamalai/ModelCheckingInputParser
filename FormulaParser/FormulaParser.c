//
// Created by pazhamalai on 05/07/21.
//

#include "FormulaParser.h"
#include "../FileReaderUtils//fileReaderUtils.h"
#include "stdlib.h"
#include "string.h"
#include "../FileReaderUtils/typeFinder.h"


void raiseError(char *reason) {
    printf("%s\n", reason);
    5/0;
}


//If both the chars are not equal, this will raise an error.
void verifyChar(char a, char b, char *reason) {
    if(a != b) {
        raiseError(reason);
    }
}


int streq(char* word1, char* word2) {
    return !strcmp(word1, word2);
}


struct Formula* readFormula(FILE *fp, char** variables, int numberOfVariables, int allowNextState) {

    // End Recursion, if EOF
    int c;
    c = getc(fp);
    if(c == EOF)
        return NULL;

    ungetc(c, fp);


    struct Formula* node = (struct Formula*) malloc(sizeof(struct Formula*));
    skipSpaces(fp, &c);

    // First character should be '('.
    c = getc(fp);
    verifyChar(c, '(', "Every sub formula should start with (");
    skipSpaces(fp, &c);


    char* word = read_string(fp, &c);

    int varValue = getVariableValue(word, variables, numberOfVariables, allowNextState);
    if(varValue != -1) {
        node->type = VAR;
        node->firstArgument = NULL;
        node->secondArgument = NULL;
        node->variableValue = varValue;
    }
    else {
        node->type = getOperatorType(word);
        node->variableValue = -1;

        node->firstArgument = readFormula(fp, variables, numberOfVariables, allowNextState);
        node->secondArgument = NULL;

        if(!isUnaryOperator(node->type)) {
            node->secondArgument = readFormula(fp, variables, numberOfVariables, allowNextState);
        }
    }

    // Last character should be ')'.
    skipSpaces(fp, &c);
    c = getc(fp);
    verifyChar(c, ')', "Every formula should be enclosed by parenthesis");
    return node;
}
