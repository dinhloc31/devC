
#include "../inc/smartHomeFacade.h"

smartHomeFacade* createSmartHomeFacade()
{
    smartHomeFacade* newSmarthomeFacade = (smartHomeFacade*)malloc(sizeof(smartHomeFacade));
    newSmarthomeFacade->brightSystem = createBrightSystem();
    newSmarthomeFacade->curtainSystem = createCurtainSystem();
    newSmarthomeFacade->hvacSystem = createHvacSystem();
    newSmarthomeFacade->securitySystem = createSecuritySystem();
    return newSmarthomeFacade;
}

void activateMorningRoutine(smartHomeFacade* smarthomeFacade)
{
    smarthomeFacade->brightSystem->lightSet(LIGHT_ON);
    smarthomeFacade->curtainSystem->curtainSet(CURTAIN_OPEN);
    smarthomeFacade->hvacSystem->hvacSet(HVAC_OFF, 27.1);
    smarthomeFacade->securitySystem->securitySet(SECURITY_OFF);
    printf("Morning routine activated.\n");
}

void activateAwayMode(smartHomeFacade* smarthomeFacade)
{
    smarthomeFacade->brightSystem->lightSet(LIGHT_OFF);
    smarthomeFacade->curtainSystem->curtainSet(CURTAIN_CLOSE);
    smarthomeFacade->hvacSystem->hvacSet(HVAC_OFF, 27.1);
    smarthomeFacade->securitySystem->securitySet(SECURITY_ON);
    printf("activateAwayMode routine activated.\n");
}

void setMovieNightScene(smartHomeFacade* smarthomeFacade)
{
    smarthomeFacade->brightSystem->lightSet(LIGHT_OFF);
    smarthomeFacade->curtainSystem->curtainSet(CURTAIN_CLOSE);
    smarthomeFacade->hvacSystem->hvacSet(HVAC_ON, 27.1);
    smarthomeFacade->securitySystem->securitySet(SECURITY_ON);
    printf("Night Mode routine activated.\n");
}
    