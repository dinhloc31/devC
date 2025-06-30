#ifndef COFFEE_H
#define COFFEE_H

#include "beverage.h"

#define COFFEE_PRICE 25000
#define COFFEE_DESCRIPTION "Plain Coffee"

typedef struct  
{
    beverage base; 
    float price; 
    const char* description; 
} plainCoffee;

beverage *createPlainCoffee();

#endif 