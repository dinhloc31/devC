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

// Initialize logger
int loggerInit(logLevel level, const char *file_path);
void loggerSetLevel(logLevel level);
void loggerClose();

// Internal log function
void loggerLog(logLevel level, const char *file, int line, const char *fmt, ...);

// User-friendly macro
#define logMessage(level, ...) loggerLog(level, __FILE__, __LINE__, __VA_ARGS__)

#endif 