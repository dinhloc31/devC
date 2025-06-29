#ifndef CURTAINSYSTEM_H
#define CURTAINSYSTEM_H

#include <stdio.h>
#include <stdlib.h>

typedef enum
{
    CURTAIN_CLOSE,
    CURTAIN_OPEN
}curtainState;

typedef struct 
{
    void (*curtainSet)(curtainState state);
}curtainSystem;

curtainSystem* createCurtainSystem();

#endif
