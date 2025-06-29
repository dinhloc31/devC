#include "../inc/brightSystem.h"
#include <stdio.h>
#include <stdlib.h>

static void lightControl(lightState state)
{
    printf("Light is now %s\n", state == LIGHT_ON ? "ON" : "OFF");
}

brightSystem* createBrightSystem()
{
    brightSystem* newBrightSystem = (brightSystem*)malloc(sizeof(brightSystem));
    newBrightSystem->lightSet = lightControl;
    return newBrightSystem;
}