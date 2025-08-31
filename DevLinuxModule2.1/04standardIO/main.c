#include "logger.h"

int main()
{
    Logger logger;
    loggerInitStruct(&logger);
    if (logger.init(&logger, LOG_INFO, "log.txt") != 0)
    {
        fprintf(stderr, "Failed to initialize logger\n");
        return 1;
    }

    logger.log(&logger, LOG_INFO, "log Infor - program started");
    logger.log(&logger, LOG_WARNING, "Log warning - I2C signal not stable");
    logger.log(&logger, LOG_ERROR, "log error - Wrong configuration");
    logger.log(&logger, LOG_ALERT, "log alert - Critical issue - Low VBAT");
    logger.log(&logger, LOG_DEBUG, "This debug message will be filtered out if level >= INFO");
    logger.setLevel(&logger, LOG_DEBUG);
    logger.log(&logger, LOG_DEBUG, "log debug - Now debug messages are visible");

    logger.close(&logger);
    return 0;
}