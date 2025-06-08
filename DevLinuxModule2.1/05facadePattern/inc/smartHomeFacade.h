#ifndef MAIN_H
#define MAIN_H

#include "../inc/brightSystem.h"
#include "curtainSystem.h"
#include "hvacSystem.h"
#include "securitySystem.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
    brightSystem* brightSystem;
    curtainSystem* curtainSystem;
    hvacSystem* hvacSystem;
    securitySystem* securitySystem;
}smartHomeFacade;

smartHomeFacade* createSmartHomeFacade();
void activateMorningRoutine(smartHomeFacade* smarthomeFacade);
void activateAwayMode(smartHomeFacade* smarthomeFacade);
void setMovieNightScene(smartHomeFacade* smarthomeFacade);

#endif
