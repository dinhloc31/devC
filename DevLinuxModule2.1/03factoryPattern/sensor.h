<<<<<<< HEAD
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


=======
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


>>>>>>> 3681142e36234c7b0d7ac233f8ca3ed166ac83b8
#endif