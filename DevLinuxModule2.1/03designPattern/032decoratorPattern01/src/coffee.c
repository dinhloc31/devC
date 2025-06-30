// plain_coffee.c
#include <stdlib.h>
#include <string.h>
#include "../inc/beverage.h"
#include "../inc/coffee.h"

static float plainCoffeeGetPrice(beverage* self) 
{
    plainCoffee *newPlainCoffee = (plainCoffee*)self;
    return newPlainCoffee->price;
}

static const char* plainCoffeeGetDescription(beverage* self) 
{
    plainCoffee *newPlainCoffee = (plainCoffee*)self;
    return newPlainCoffee->description;
}

beverage *createPlainCoffee() 
{
    plainCoffee *newPlainCoffee = (plainCoffee*)malloc(sizeof(plainCoffee));
    newPlainCoffee->price = COFFEE_PRICE;
    newPlainCoffee->description = COFFEE_DESCRIPTION;
    newPlainCoffee->base.getPrice = plainCoffeeGetPrice;
    newPlainCoffee->base.getDescription = plainCoffeeGetDescription;
    return (beverage*)newPlainCoffee;
}
