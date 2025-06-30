#ifndef MILK_DECORATOR_H
#define MILK_DECORATOR_H

#include "beverageDecorator.h"
#define MILK_PRICE 5000
#define MILK_DESCRIPTION "Milk"

typedef struct milkDecorator {
    beverageDecorator milkBase; 
    float extraPrice;            
    const char* extraDescription; 
} milkDecorator;

beverage* createMilkDecorator(beverage *wrapped);

#endif