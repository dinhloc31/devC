#include "../inc/securitySystem.h"
#include <stdio.h>
#include <stdlib.h>

static void securityControl(securityState state)
{
     printf("Security is now %s\n", state == SECURITY_ON ? "ON" : "OFF");
}

securitySystem* createSecuritySystem()
{
    securitySystem* newSecuritySystem = (securitySystem*)malloc(sizeof(securitySystem));
    newSecuritySystem->securitySet = securityControl;
    return newSecuritySystem;
}