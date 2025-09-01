#include "../inc/decorators.h"


milkDecorator* createMilkDecorator(beverage* beverageInstance)
{
    milkDecorator* milkDecoratorInstance = (milkDecorator*)malloc(sizeof(milkDecorator));
    milkDecoratorInstance->beverageInstance = beverageInstance;
    milkDecoratorInstance->price = beverageInstance->price;
    milkDecoratorInstance->description = beverageInstance->description;
    return milkDecoratorInstance;
}

sugarDecorator* createSugarDecorator(beverage* beverageInstance)
{

}

syrupDecorator* createSyrupDecorator(beverage* beverageInstance)
{

}

void addMilk(milkDecorator* milkDecoratorInstance)
{
    milkDecoratorInstance->price += MILK_PRICE;
}
