
#ifndef HUMIDITYSENSOR_H
#define HUMIDITYSENSOR_H

#include "sensor.h"

void humiditySensorInit();
float humiditySensorReadData();
sensor* createHumiditySensor();

#endif