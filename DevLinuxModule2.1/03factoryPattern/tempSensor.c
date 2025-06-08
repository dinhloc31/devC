<<<<<<< HEAD
#include "tempSensor.h"
#include <stdio.h>
#include <stdint.h>

void tempSensorInit()
{
    printf("Init Temp Sensor....\n");
}

float tempSensorReadData()
{
    return 3.0f;
}

sensor* createTempSensor()
{
    static sensor tempSensor;
    static int initialized =0;

    if(initialized == 0)
    {
        tempSensor.initSensor = tempSensorInit;
        tempSensor.readSensorData = tempSensorReadData;
        initialized = 1;
    }
    else 
    printf("Temp sensor is initialized. \n");

    return &tempSensor;
}
=======
#include "tempSensor.h"
#include <stdio.h>
#include <stdint.h>

void tempSensorInit()
{
    printf("Init Temp Sensor....\n");
}

float tempSensorReadData()
{
    return 3.0f;
}

sensor* createTempSensor()
{
    static sensor tempSensor;
    static int initialized =0;

    if(initialized == 0)
    {
        tempSensor.initSensor = tempSensorInit;
        tempSensor.readSensorData = tempSensorReadData;
        initialized = 1;
    }
    else 
    printf("Temp sensor is initialized. \n");

    return &tempSensor;
}
>>>>>>> 3681142e36234c7b0d7ac233f8ca3ed166ac83b8
