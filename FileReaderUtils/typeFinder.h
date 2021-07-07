//
// Created by pazhamalai on 06/07/21.
//

#ifndef MODELCHECKINGINPUTPARSER_TYPEFINDER_H
#define MODELCHECKINGINPUTPARSER_TYPEFINDER_H

#include "../FormulaParser/FormulaParser.h"

int getVariableValue(char *word, char **variables, int numberOfVariables, int allowNextState);
enum NodeType getOperatorType(char *word);
int isUnaryOperator(enum NodeType type);

#endif //MODELCHECKINGINPUTPARSER_TYPEFINDER_H
