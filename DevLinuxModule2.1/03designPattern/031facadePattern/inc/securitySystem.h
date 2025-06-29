#ifndef SECURITY_H
#define SECURITY_H

#include <stdio.h>
#include <stdlib.h>

typedef enum
{
    SECURITY_OFF,
    SECURITY_ON
}securityState;

typedef struct 
{
    void (*securitySet)(securityState state);
}securitySystem;

securitySystem* createSecuritySystem();

#endif
