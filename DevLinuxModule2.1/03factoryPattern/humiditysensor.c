<<<<<<< HEAD
#include "humiditysensor.h"



void humiditySensorInit()
{
    printf("Init Humidity Sensor....\n");
}

float humiditySensorReadData()
{
    return 3.0f;
}

sensor* createHumiditySensor()
{
    static sensor humiditySensor;
    static int initialized =0;

    if(initialized == 0)
    {
        humiditySensor.initSensor = humiditySensorInit;
        humiditySensor.readSensorData = humiditySensorReadData;
        initialized = 1;
    }
    else
        printf("Humidity sensor initialized. \n");
    
    return &humiditySensor;
}
=======
#include "humiditysensor.h"



void humiditySensorInit()
{
    printf("Init Humidity Sensor....\n");
}

float humiditySensorReadData()
{
    return 3.0f;
}

sensor* createHumiditySensor()
{
    static sensor humiditySensor;
    static int initialized =0;

    if(initialized == 0)
    {
        humiditySensor.initSensor = humiditySensorInit;
        humiditySensor.readSensorData = humiditySensorReadData;
        initialized = 1;
    }
    else
        printf("Humidity sensor initialized. \n");
    
    return &humiditySensor;
}
>>>>>>> 3681142e36234c7b0d7ac233f8ca3ed166ac83b8
