<<<<<<< HEAD
#include "lightSensor.h"

void lightSensorInit()
{
    printf("Init Light Sensor....\n");
}

float lightSensorReadData()
{
    return 6.1f;
}

sensor *createLightSensor()
{
    static sensor lightSensor;
    static int initialized =0;

    if(initialized == 0)
    {
        lightSensor.initSensor = lightSensorInit;
        lightSensor.readSensorData = lightSensorReadData;
        initialized = 1;
    }
    else
        printf("Light sensor initialized. \n");
    
    return &lightSensor;
}
=======
#include "lightSensor.h"

void lightSensorInit()
{
    printf("Init Light Sensor....\n");
}

float lightSensorReadData()
{
    return 6.1f;
}

sensor *createLightSensor()
{
    static sensor lightSensor;
    static int initialized =0;

    if(initialized == 0)
    {
        lightSensor.initSensor = lightSensorInit;
        lightSensor.readSensorData = lightSensorReadData;
        initialized = 1;
    }
    else
        printf("Light sensor initialized. \n");
    
    return &lightSensor;
}
>>>>>>> 3681142e36234c7b0d7ac233f8ca3ed166ac83b8
