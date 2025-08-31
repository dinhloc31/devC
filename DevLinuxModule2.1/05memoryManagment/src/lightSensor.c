
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
