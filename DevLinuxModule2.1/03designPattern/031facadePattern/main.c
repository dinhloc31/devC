#include <stdio.h>
#include <stdlib.h>
#include "./inc/smartHomeFacade.h"

int main() 
{
    smartHomeFacade* smartHome = createSmartHomeFacade();

    printf(">>> Activating morning routine...\n");
    activateMorningRoutine(smartHome);
    
    printf("\n>>> Activating away mode...\n");
    activateAwayMode(smartHome);
    
    printf("\n>>> Setting movie night scene...\n");
    setMovieNightScene(smartHome);
    
    printf("\nFreeing allocated memory...\n");
    free(smartHome->brightSystem);
    free(smartHome->curtainSystem);
    free(smartHome->hvacSystem);
    free(smartHome->securitySystem);
    free(smartHome);
    
    return 0;
}

