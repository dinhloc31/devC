#ifndef MAIN_H
#define MAIN_H

#include "inc/sensor.h"

#define HUMIDITY_MIN 30.0f
#define HUMIDITY_MAX 70.0f
#define MAX_WATERING_TIME 60
#define SENSOR_CHECK_INTERVAL 5
#define LIGHT_SENSOR_THRESHOLD 300.0f
#define DEFAULT_OPERATION_MODE MODE_AUTO


typedef enum {
    MODE_AUTO,
    MODE_MANUAL
} OperationMode;

typedef enum {
    PUMP_OFF,
    PUMP_ON
} PumpState;

typedef enum {
    LED_NORMAL,
    LED_WATERING,
    LED_LOW_MOISTURE_ALERT,
    LED_ERROR
} LedState;

typedef struct {
    float humidityMin;
    float humidityMax;
    unsigned int maxWateringTime;
    unsigned int sensorCheckInterval;
    OperationMode currentMode;
    PumpState pumpState;
    LedState ledState;
} systemConfig;

void systemDefaultInit(systemConfig* config);
void hardwareInit();
void addSensorData(SensorData *data, float humidity, float temperature);
float getTemperatureAverage(SensorData *data);
float getHumidityAverage(SensorData *data);
void ExternalInterruptHandlerButton1(void);
void ExternalInterruptHandlerButton0(void);
void setLedState(LedState state);
void setPumpState(PumpState state);

#endif // MAIN_H