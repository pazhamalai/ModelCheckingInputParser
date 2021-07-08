#ifndef MODELCHECKINGINPUTPARSER_MCIP_H
#define MODELCHECKINGINPUTPARSER_MCIP_H

#include "stdio.h"

enum NodeType {
    VAR, EQUALS, AND, OR, IMPLIES, NOT, EX, AX, EG, AG, EU, AU, EF, AF
};

struct Formula {
    struct Formula* firstArgument;
    struct Formula* secondArgument;

    enum NodeType type;
    int variableValue;
};


struct InputInfo {
    char **variables;
    struct Formula* transitionFormula;
    struct Formula* initialStatesFormula;
    struct Formula* ctlFormula;
    int numberOfVariables;
};

struct InputInfo* readInput(FILE* fp);

#endif //MODELCHECKINGINPUTPARSER_MCIP_H
