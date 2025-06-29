
#include "inc/sensor.h"
#include <stdio.h>

int main()
{
    sensor* tempSensor = createSensor(SENSOR_TEMP);
    sensor* humiditySensor = createSensor(SENSOR_HUMIDITY);
    sensor* humiditySensor2 = createSensor(SENSOR_HUMIDITY); // Test singleton
    sensor* lighSensor = createSensor(SENSOR_LIGHT);

    tempSensor->initSensor();
    humiditySensor->initSensor();
    lighSensor->initSensor();
    
    printf("Temp Data = %.2f.\n", tempSensor->readSensorData());
    printf("Humidity Data = %.2f.\n", humiditySensor->readSensorData());
    printf("Light Data = %.2f.\n", lighSensor->readSensorData());

}

