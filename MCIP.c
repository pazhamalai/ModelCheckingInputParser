#include "MCIP.h"
#include "FormulaParser//FormulaParser.h"
#include "Fairness/FairnessParser.h"
#include "VariablesParser/variablesReader.h"

#include <stdio.h>
#include "stdlib.h"

struct InputInfo* readInput(FILE* fp) {
    int numberOfVariables;
    int numberOfFairnessConstraints;
    struct InputInfo* info = (struct InputInfo*) malloc(sizeof(struct InputInfo));

    info->variables = readInputVariables(fp, &numberOfVariables);
    info->transitionFormula = readFormula(fp, info->variables, numberOfVariables, 1);
    info->initialStatesFormula = readFormula(fp, info->variables, numberOfVariables, 0);
    info->ctlFormula = readFormula(fp, info->variables, numberOfVariables, 0);
    info->fairnessConstraints = readFairnessConstraints(fp, info->variables, numberOfVariables, &numberOfFairnessConstraints);
    info->numberOfVariables = numberOfVariables;
    info->numberOfFairnessConstraints = numberOfFairnessConstraints;

    return info;
}