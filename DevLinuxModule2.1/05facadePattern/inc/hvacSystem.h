#ifndef HVACSYSTEM_H
#define HVACSYSTEM_H

#include <stdio.h>
#include <stdlib.h>

typedef enum
{
    HVAC_OFF,
    HVAC_ON
}hvacState;

typedef struct 
{
    float tempSet;
    void (*hvacSet)(hvacState state, float tempSet);
}hvacSystem;

hvacSystem* createHvacSystem();


#endif