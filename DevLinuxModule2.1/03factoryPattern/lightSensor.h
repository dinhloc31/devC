#ifndef LIGHTSENSOR_H
#define LIGHTSENSOR_H

#include "sensor.h"

void lightSensorInit();
float lightSensorReadData();
sensor* createLightSensor();

#endif