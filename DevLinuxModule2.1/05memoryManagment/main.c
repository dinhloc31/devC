
#include <stdio.h>
#include "main.h"

systemConfig config;


int main()
{
    hardwareInit();

    sensor* tempSensor = createSensor(SENSOR_TEMP);
    sensor* humiditySensor = createSensor(SENSOR_HUMIDITY);
    sensor* lightSensor = createSensor(SENSOR_LIGHT);

    tempSensor->initSensor();
    humiditySensor->initSensor();
    lightSensor->initSensor();

    SensorData sensorData;
    sensorData.bufIndex = 0;
    sensorData.dataCount = 0;
    
    systemDefaultInit(&config);

    while (1)
    {
        addSensorData(&sensorData, humiditySensor->readSensorData(), tempSensor->readSensorData());
        float avgHumidity = getHumidityAverage(&sensorData);
        float avgTemperature = getTemperatureAverage(&sensorData);

        if (config.currentMode == MODE_AUTO)
        {
            if (avgHumidity < config.humidityMin)
            {
                config.pumpState = PUMP_ON;
                config.ledState = LED_LOW_MOISTURE_ALERT;
            }
            else if (avgHumidity > config.humidityMax)
            {
                config.pumpState = PUMP_OFF;
                config.ledState = LED_NORMAL;
            }
        }

        setPumpState(config.pumpState);
        setLedState(config.ledState);
        delay_ms(10000);
    }
    return 0;
}

void hardwareInit()
{
    printf("GPIO init done\n");
    printf("ADC init done\n");
    printf("I2C init done\n");
    printf("SPI init done\n");
}

void systemDefaultInit(systemConfig* config)
{
    config->humidityMin = HUMIDITY_MIN;
    config->humidityMax = HUMIDITY_MAX;
    config->maxWateringTime = MAX_WATERING_TIME;
    config->sensorCheckInterval = SENSOR_CHECK_INTERVAL;
    config->currentMode = DEFAULT_OPERATION_MODE;
}

void addSensorData(SensorData *data, float humidity, float temperature) {
    data->humidityBuffer[data->bufIndex] = humidity;
    data->temperatureBuffer[data->bufIndex] = temperature;
    data->bufIndex = (data->bufIndex + 1) % SENSOR_BUF_SIZE;
    if (data->dataCount < SENSOR_BUF_SIZE) data->dataCount++;
}

void ExternalInterruptHandlerButton0(void) {
    config.currentMode = (config.currentMode == MODE_AUTO) ? MODE_MANUAL : MODE_AUTO;
    printf("Current Mode: %s\n", (config.currentMode == MODE_AUTO) ? "AUTO" : "MANUAL");
}

void ExternalInterruptHandlerButton1(void) {
    if (config.currentMode == MODE_MANUAL) {
        setPumpState(PUMP_ON);
        setLedState(LED_WATERING);
        setPumpState(PUMP_OFF);
        setLedState(LED_NORMAL);
    }
}

void setPumpState(PumpState state) 
{
    if (state == PUMP_ON) {
        printf("Pump is ON\n");
    } else {
        printf("Pump is OFF\n");
    }
}

void setLedState(LedState state) 
{
    switch (state)
    {
    case LED_NORMAL:
        printf("LED State: NORMAL\n");
        break;
    case LED_WATERING:
        printf("LED State: WATERING\n");
        break;
    case LED_LOW_MOISTURE_ALERT:
        printf("LED State: LOW MOISTURE ALERT\n");
        break;
    case LED_ERROR:
        printf("LED State: ERROR\n");
        break;
    default:
        break;
    }
}


float getHumidityAverage(SensorData *data) {
    if (data->dataCount == 0) return 0.0f;
    float sum = 0.0f;
    for (int i = 0; i < data->dataCount; i++) {
        sum += data->humidityBuffer[i];
    }
    return sum / data->dataCount;
}

float getTemperatureAverage(SensorData *data) {
    if (data->dataCount == 0) return 0.0f;
    float sum = 0.0f;
    for (int i = 0; i < data->dataCount; i++) {
        sum += data->temperatureBuffer[i];
    }
    return sum / data->dataCount;
}