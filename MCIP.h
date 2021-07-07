#ifndef MODELCHECKINGINPUTPARSER_MCIP_H
#define MODELCHECKINGINPUTPARSER_MCIP_H

#include "stdio.h"

enum NodeType {
    VAR, EQUALS, AND, OR, IMPLIES, NOT, EX, AX, EG, AG, EU, AU, EF, AF
};

struct Node {
    struct Node* firstArgument;
    struct Node* secondArgument;

    enum NodeType type;
    int variableValue;
};


struct InputInfo {
    char **variables;
    struct Node* transitionFormula;
    struct Node* initialStatesFormula;
    struct Node* ctlFormula;
    int numberOfVariables;
};

struct InputInfo* readInput(FILE* fp);

#endif //MODELCHECKINGINPUTPARSER_MCIP_H
