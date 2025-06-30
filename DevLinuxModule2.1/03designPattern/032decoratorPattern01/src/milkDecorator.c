#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "../inc/milkDecorator.h"
#include "../inc/beverageDecorator.h"

float milkGetPrice(beverage *self) 
{
    milkDecorator *newMilkDecorator = (milkDecorator*)self;
    return newMilkDecorator->milkBase.beverageWrapped->getPrice(newMilkDecorator->milkBase.beverageWrapped) + newMilkDecorator->extraPrice;
}

const char *milkGetDescription(beverage* self) 
{
    milkDecorator *newMilkDecorator = (milkDecorator*)self;
    static char buffer[128];
    snprintf(buffer, sizeof(buffer), "%s + %s",
             newMilkDecorator->milkBase.beverageWrapped->getDescription(newMilkDecorator->milkBase.beverageWrapped),
             newMilkDecorator->extraDescription);
    return buffer;
}

beverage* createMilkDecorator(beverage *wrapped) 
{
    milkDecorator *newMilkDecorator = (milkDecorator*)malloc(sizeof(milkDecorator));
    newMilkDecorator->milkBase.beverageWrapped = wrapped;
    newMilkDecorator->extraPrice = MILK_PRICE;
    newMilkDecorator->extraDescription = MILK_DESCRIPTION;
    newMilkDecorator->milkBase.beverageBase.getPrice = milkGetPrice;
    newMilkDecorator->milkBase.beverageBase.getDescription= milkGetDescription;
    return (beverage*)newMilkDecorator;
}
