#ifndef SENSOR_H
#define SENSOR_H

#include <stdio.h>
#include <stdint.h>

typedef struct 
{
   void (*initSensor)(void);
   float (*readSensorData)(void);
}sensor;

typedef enum
{
    SENSOR_TEMP,
    SENSOR_HUMIDITY,
    SENSOR_LIGHT,
}sensorType;

sensor* createSensor(sensorType type);


#endif