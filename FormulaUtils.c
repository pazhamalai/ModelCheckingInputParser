//
// Created by pazhamalai on 13/07/21.
//

#include "FormulaUtils.h"
#include "stdlib.h"
struct Formula *Formula_Not(struct Formula *formula) {
    struct Formula* notNode = (struct Formula*) malloc(sizeof(struct Formula));
    notNode->type = NOT;
    notNode->firstArgument = formula;
    notNode->secondArgument = NULL;
    notNode->variableValue = -1;
    return notNode;
}

struct Formula* Formula_And(struct Formula* firstArgument, struct Formula* secondArgument) {
    struct Formula* andNode = (struct Formula*) malloc(sizeof(struct Formula));
    andNode->type = AND;
    andNode->firstArgument = firstArgument;
    andNode->secondArgument = secondArgument;
    andNode->variableValue = -1;
    return andNode;
}

