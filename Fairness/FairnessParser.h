//
// Created by pazhamalai on 15/07/21.
//

#ifndef MODELCHECKINGINPUTPARSER_FAIRNESSPARSER_H
#define MODELCHECKINGINPUTPARSER_FAIRNESSPARSER_H

#include "../MCIP.h"

struct Formula** readFairnessConstraints(FILE* fp, char** variables, int numberOfVariables, int* numberOfFairnessConstraints);

#endif //MODELCHECKINGINPUTPARSER_FAIRNESSPARSER_H
