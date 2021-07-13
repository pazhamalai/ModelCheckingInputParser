#ifndef MODELCHECKINGINPUTPARSER_MCIP_H
#define MODELCHECKINGINPUTPARSER_MCIP_H

#include "stdio.h"

#ifdef __cplusplus
extern "C" {
#endif

enum NodeType {
    VAR, EQUALS, AND, OR, IMPLIES, NOT, EX, AX, EG, AG, EU, AU, EF, AF, BOOLEAN_TRUE, BOOLEAN_FALSE
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

#ifdef __cplusplus
}
#endif

#endif //MODELCHECKINGINPUTPARSER_MCIP_H
