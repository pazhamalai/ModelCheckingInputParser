//
// Created by pazhamalai on 06/07/21.
//

#include "typeFinder.h"
#include "../commonUtils.h"

char equals[] = "=";
char and[] = "and";
char or[] = "or";
char implies[] = "implies";
char not[] = "not";
char ex[] = "EX";
char ax[] = "AX";
char eg[] = "EG";
char ag[] = "AG";
char eu[] = "EU";
char au[] = "AU";
char ef[] = "EF";
char af[] = "AF";
char true[] = "TRUE";
char false[] = "FALSE";

// Returns the index of the word in variables
// If not, -1
int getVariableValue(char *word, char **variables, int numberOfVariables, int allowNextState) {
    int i;
    for (i = 0; i < numberOfVariables; ++i) {
        if(streq(word, variables[i]))
            break;
    }

    if(i < numberOfVariables)
        return i;

    //word is not a variable
    //Checking for next state variable
    if(allowNextState && word[0] == '_'){
        //Moving a character ahead
        word = word + 1;
        i =  getVariableValue(word, variables, numberOfVariables, 0);
        return i + numberOfVariables;
    }
    else {
        return -1;
    }
}

int isUnaryOperator(enum NodeType type) {
    int val;

    switch (type) {
        case NOT:
        case EX:
        case AX:
        case EG:
        case AG:
        case EF:
        case AF:
            val = 1;
            break;

        default:
            val = 0;
    }

    return val;
}

enum NodeType getOperatorType(char *word) {
    // word may be one of the operators
    // Or, it may belong to variables

    if(streq(word, equals))
        return EQUALS;

    if(streq(word, and))
        return AND;

    if(streq(word, or))
        return OR;

    if(streq(word, implies))
        return IMPLIES;

    if(streq(word, not))
        return NOT;

    if(streq(word, ex))
        return EX;

    if(streq(word, ax))
        return AX;

    if(streq(word, eg))
        return EG;

    if(streq(word, ag))
        return AG;

    if(streq(word, eu))
        return EU;

    if(streq(word, au))
        return AU;

    if(streq(word, ef))
        return EF;

    if(streq(word, af))
        return AF;

    if(streq(word, true))
        return BOOLEAN_TRUE;

    if(streq(word, false))
        return BOOLEAN_FALSE;

    printf("%s\n", word);
    raiseError("word not an operator");
    return AND;
}
