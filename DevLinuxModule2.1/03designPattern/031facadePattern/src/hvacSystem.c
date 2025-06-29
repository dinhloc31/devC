#include "../inc/hvacSystem.h"
#include <stdio.h>
#include <stdlib.h>

static void hvacControl(hvacState state, float tempSet)
{
   if (state == HVAC_ON) 
    {
    printf("HVAC is now ON,  TempSet = %.2f\n", tempSet);
    } else 
    {
    printf("HVAC is now OFF\n");
    }
}

hvacSystem* createHvacSystem()
{
    hvacSystem* newHvacSystem = (hvacSystem*)malloc(sizeof(hvacSystem));
    newHvacSystem->hvacSet = hvacControl;
    return newHvacSystem;
}
