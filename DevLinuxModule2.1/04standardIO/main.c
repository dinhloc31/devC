#include "logger.h"

int main() 
{
    if (loggerInit(LOG_INFO, "log.txt") != 0) 
    {
        fprintf(stderr, "Failed to initialize logger\n");
        return 1;
    }

    logMessage(LOG_INFO, "log Infor - program started");
    logMessage(LOG_WARNING, "Log warning - I2C signal not stable");
    logMessage(LOG_ERROR, "log error - Wrong configuration");
    logMessage(LOG_ALERT, "log alert - Critical issue - Low VBAT");
    logMessage(LOG_DEBUG, "This debug message will be filtered out if level >= INFO");
    loggerSetLevel(LOG_DEBUG);
    logMessage(LOG_DEBUG, "log debug - Now debug messages are visible");

    loggerClose();
    return 0;
}