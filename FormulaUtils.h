//
// Created by pazhamalai on 13/07/21.
//

#ifndef MODELCHECKINGINPUTPARSER_FORMULAUTILS_H
#define MODELCHECKINGINPUTPARSER_FORMULAUTILS_H

#include "MCIP.h"

#ifdef __cplusplus
extern "C" {
#endif

struct Formula* Formula_Not(struct Formula* formula);

struct Formula* Formula_And(struct Formula* firstArgument, struct Formula* secondArgument);

struct Formula* Formula_True();

struct Formula* Formula_EG(struct Formula* argument);

#ifdef __cplusplus
}
#endif

#endif //MODELCHECKINGINPUTPARSER_FORMULAUTILS_H
