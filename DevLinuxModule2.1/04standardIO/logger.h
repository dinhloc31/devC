#ifndef LOGGER_H
#define LOGGER_H

#include <stdio.h>
#include <stdarg.h>

typedef enum 
{
    LOG_EMERGENCY = 0,
    LOG_ALERT,
    LOG_CRITICAL,
    LOG_ERROR,
    LOG_WARNING,
    LOG_NOTICE,
    LOG_INFO,
    LOG_DEBUG
} logLevel;

typedef struct Logger Logger;

struct Logger 
{
    logLevel level;
    FILE *logFile;
    int (*init)(Logger *selflogger, logLevel logLevel, const char *filePath);
    void (*setLevel)(Logger *selflogger, logLevel logLevel);
    void (*close)(Logger *selflogger);
    void (*log)(Logger *selflogger, logLevel logLevel, const char *formatString, ...);
};

void loggerInitStruct(Logger *logger);

#endif