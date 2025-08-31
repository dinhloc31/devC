#include "logger.h"
#include <string.h>
#include <time.h>
#include <stdarg.h>

static const char *levelToString(logLevel level) 
{
    switch (level) 
    {
        case LOG_EMERGENCY: return "EMERGENCY";
        case LOG_ALERT:     return "ALERT";
        case LOG_CRITICAL:  return "CRITICAL";
        case LOG_ERROR:     return "ERROR";
        case LOG_WARNING:   return "WARNING";
        case LOG_NOTICE:    return "NOTICE";
        case LOG_INFO:      return "INFO";
        case LOG_DEBUG:     return "DEBUG";
        default:            return "UNKNOWN";
    }
}

static int loggerInit(Logger *selflogger, logLevel level, const char *filePath) 
{
    selflogger->level = level;
    if (filePath == NULL || filePath[0] == '\0') {
        fprintf(stderr, "[logger] Don't have Log File!\n");
        return -1;
    }
    selflogger->logFile = fopen(filePath, "a");
    if (!selflogger->logFile) {
        perror("[logger] Can't Open Log File");
        return -1;
    }
    return 0;
}

static void loggerSetLevel(Logger *selflogger, logLevel level) 
{
    selflogger->level = level;
}

static void loggerClose(Logger *selflogger) 
{
    if (selflogger->logFile) {
        fclose(selflogger->logFile);
        selflogger->logFile = NULL;
    }
}

static void loggerLog(Logger *selflogger, logLevel level, const char *fmt, ...) 
{
    if (level > selflogger->level) return;

    va_list args;
    va_start(args, fmt);

    time_t now = time(NULL);
    struct tm *timer = localtime(&now);

    char timeStamp[32];
    strftime(timeStamp, sizeof(timeStamp), "%Y-%m-%d %H:%M:%S", timer);

    char message[1024];
    vsnprintf(message, sizeof(message), fmt, args);

    char finalMessage[1200];
    snprintf(finalMessage, sizeof(finalMessage), "[%s] [%s] - %s\n", timeStamp, levelToString(level), message);
    
    FILE *out = (level <= LOG_WARNING) ? stderr : stdout;
    fputs(finalMessage, out);
    fflush(out);
    if (selflogger->logFile) {
        fputs(finalMessage, selflogger->logFile);
        fflush(selflogger->logFile);
    }

    va_end(args);
}

void loggerInitStruct(Logger *logger) 
{
    logger->level = LOG_DEBUG;
    logger->logFile = NULL;
    logger->init = loggerInit;
    logger->setLevel = loggerSetLevel;
    logger->close = loggerClose;
    logger->log = loggerLog;
}