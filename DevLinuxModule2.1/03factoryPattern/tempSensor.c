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
