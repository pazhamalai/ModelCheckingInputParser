//
// Created by pazhamalai on 05/07/21.
//

#ifndef MODELCHECKINGINPUTPARSER_FORMULAPARSER_H
#define MODELCHECKINGINPUTPARSER_FORMULAPARSER_H

#include "stdio.h"
#include "../MCIP.h"

struct Node* readFormula(FILE *fp, char** variables, int numberOfVariables, int allowNextState);

#endif //MODELCHECKINGINPUTPARSER_FORMULAPARSER_H
