#include "../inc/curtainSystem.h"
#include <stdio.h>
#include <stdlib.h>

static void curtainControl (curtainState state)
{
     printf("Curtaint is now %s\n", state == CURTAIN_CLOSE ? "CLOSE" : "OPEN");
}

curtainSystem* createCurtainSystem()
{
    curtainSystem* newCurtainSystem = (curtainSystem*)malloc(sizeof(curtainControl));
    newCurtainSystem->curtainSet = curtainControl;
    return newCurtainSystem;
}