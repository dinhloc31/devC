#ifndef DECORATORS_H
#define DECORATORS_H

#include "beverage.h"

#define MILK_PRICE 5500.0
#define SUGAR_PRICE 2000.0
#define SYRUP_PRICE 10000.0


typedef struct 
{
    beverage* beverageInstance;
    float price;
    char* description;
} milkDecorator;

typedef struct 
{
    beverage* beverageInstance;
} sugarDecorator;

typedef struct 
{
    beverage* beverageInstance;
} syrupDecorator;

milkDecorator* createMilkDecorator(beverage* beverageInstance);
sugarDecorator* createSugarDecorator(beverage* beverageInstance);
syrupDecorator* createSyrupDecorator(beverage* beverageInstance);

void freeMilkDecorator(milkDecorator* milkDecoratorInstance);
void freeSugarDecorator(sugarDecorator* sugarDecoratorInstance);
void freeMiSyrupDecorator(syrupDecorator* syrupDecoratorInstance);

#endif