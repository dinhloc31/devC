#include "../inc/beverage.h"
#include <string.h>

beverage* createPlainCoffee()
{
    beverage *coffee = (beverage*)malloc(sizeof(beverage));
    coffee->description = strdup("Plain Coffee");
    coffee->price = COFFEE_PRICE;
    return coffee;
}

beverage* createPlainSoda()
{
    beverage *soda = (beverage*)malloc(sizeof(beverage));
    soda->description = strdup("Plain soda");
    soda->price = SODA_PRICE;
    return soda; 
}

void freeBevarage(beverage* beverageInstance)
{
    if (beverageInstance != NULL)
    {
        free(beverageInstance->description);
        free(beverageInstance);
    }
    
}
