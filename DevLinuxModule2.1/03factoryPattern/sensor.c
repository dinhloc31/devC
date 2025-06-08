<<<<<<< HEAD
#include "sensor.h"
#include "humiditysensor.h"
#include "tempSensor.h"
#include "lightSensor.h"
#include <stdlib.h>
#include <stdio.h>

sensor *createSensor(sensorType type)
{
    sensor* newSensor = (sensor*)malloc(sizeof(sensor));
    if (newSensor == NULL)
    {
        printf ("Sensor allocation fail.\n");
        return NULL;
    }

    switch (type)
    {
    case SENSOR_TEMP:
        newSensor = createTempSensor();
        break;
    case SENSOR_HUMIDITY:
        newSensor = createHumiditySensor();
        break;    
    case SENSOR_LIGHT:
        newSensor = createLightSensor();
        break;     
    default:
        free (newSensor);
        printf("Don't have this sensor on this board.\n ");
        break;
    }
    
    return newSensor;
    
=======
#include "sensor.h"
#include "humiditysensor.h"
#include "tempSensor.h"
#include "lightSensor.h"
#include <stdlib.h>
#include <stdio.h>

sensor *createSensor(sensorType type)
{
    sensor* newSensor = (sensor*)malloc(sizeof(sensor));
    if (newSensor == NULL)
    {
        printf ("Sensor allocation fail.\n");
        return NULL;
    }

    switch (type)
    {
    case SENSOR_TEMP:
        newSensor = createTempSensor();
        break;
    case SENSOR_HUMIDITY:
        newSensor = createHumiditySensor();
        break;    
    case SENSOR_LIGHT:
        newSensor = createLightSensor();
        break;     
    default:
        free (newSensor);
        printf("Don't have this sensor on this board.\n ");
        break;
    }
    
    return newSensor;
    
>>>>>>> 3681142e36234c7b0d7ac233f8ca3ed166ac83b8
}