#ifndef BEVERAGE_H
#define BEVERAGE_H

#define COFFEE_PRICE 25000.0
#define SODA_PRICE 35000.0

typedef struct 
{
    float price;
    char* description;
}beverage;

beverage* createPlainCoffee();
beverage* createPlainSoda();

void freeBevarage(beverage* beverageInstance);

#endif