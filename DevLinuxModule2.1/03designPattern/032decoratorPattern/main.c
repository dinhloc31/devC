#include <stdio.h>
#include <stdlib.h>
#include "inc/beverage.h"
#include "inc/beverageDecorator.h"
#include "inc/coffee.h"
#include "inc/milkDecorator.h"

int main() 
{
    beverage *myDrink = createPlainCoffee();
    printf("myDrink's Description: %s\n", myDrink->getDescription(myDrink));
    printf("myDrink's Price: %.2f\n", myDrink->getPrice(myDrink));
    
    // Decorate with milk
    beverage *myDrinkWithMilk = createMilkDecorator(myDrink);
    printf("Description with milk: %s\n", myDrinkWithMilk->getDescription(myDrinkWithMilk));
    printf("Price with milk: %.2f\n", myDrinkWithMilk->getPrice(myDrinkWithMilk));

    return 0;
}