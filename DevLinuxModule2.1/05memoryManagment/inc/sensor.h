
#ifndef SENSOR_H
#define SENSOR_H

#include <stdio.h>
#include <stdint.h>

#define SENSOR_BUF_SIZE 50

typedef struct 
{
   void (*initSensor)(void);
   float (*readSensorData)(void);
}sensor;

typedef struct 
{
    float humidityBuffer[SENSOR_BUF_SIZE];
    float temperatureBuffer[SENSOR_BUF_SIZE];
    int bufIndex;
    int dataCount; 
} SensorData;

typedef enum
{
    SENSOR_TEMP,
    SENSOR_HUMIDITY,
    SENSOR_LIGHT,
}sensorType;

sensor* createSensor(sensorType type);


#endif