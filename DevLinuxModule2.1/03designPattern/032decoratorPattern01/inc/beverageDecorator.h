#ifndef DECORATOR_H
#define DECORATOR_H

#include "beverage.h"

typedef struct 
{
    beverage beverageBase;
    beverage *beverageWrapped;
} beverageDecorator;

#endif
