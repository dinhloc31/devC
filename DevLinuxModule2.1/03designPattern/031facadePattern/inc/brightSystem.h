#ifndef BRIGHTSYSTEM_H
#define BRIGHTSYSTEM_H

#include <stdio.h>
#include <stdlib.h>

typedef enum
{
    LIGHT_OFF,
    LIGHT_ON
}lightState;

typedef struct 
{
    void (*lightSet)(lightState state);
}brightSystem;

brightSystem* createBrightSystem();


#endif
