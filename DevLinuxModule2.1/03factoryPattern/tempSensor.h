#ifndef TEMPSENSOR_H
#define TEMPSENSOR_H

#include "sensor.h"

void tempSensorInit();
float tempSensorReadData();
sensor* createTempSensor();


#endif