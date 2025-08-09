#include "logger.h"
#include <string.h>
#include <time.h>

static logLevel currentLevel = LOG_DEBUG;
static FILE *logFile = NULL;

const char *levelToString(logLevel level) 
{
    switch (level) {
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

int loggerInit(logLevel level, const char *filePath) 
{
    currentLevel = level;

    if (filePath == NULL || filePath[0] == '\0') 
    {
        fprintf(stderr, "[logger] Don't have Log File!\n");
        return -1;
    }
    logFile = fopen(filePath, "a");
    if (!logFile) 
    {
        perror("[logger] Can't Open Log File");
        return -1;
    }
    return 0;
}

void loggerSetLevel(logLevel level) {
    currentLevel = level;
}

void loggerClose() 
{
    if (logFile) 
    {
        fclose(logFile);
        logFile = NULL;
    }
}

void loggerLog(logLevel level, const char *file, int line, const char *formatString, ...) 
{
    if (level > currentLevel) return;

    // Get and convert localTime to timeStamp
    time_t now = time(NULL);
    struct tm *timer = localtime(&now);
    char timeStamp[32];
    strftime(timeStamp, sizeof(timeStamp), "%Y-%m-%d %H:%M:%S", timer);

    // Format message
    char message[1024];
    va_list arguments;
    va_start(arguments, formatString);
    vsnprintf(message, sizeof(message), formatString, arguments);
    va_end(arguments);

    // Compose final log string
    char finalMessage[1200];
    snprintf(finalMessage, sizeof(finalMessage), "[%s] [%s] [%s:%d] - %s\n",
             timeStamp, levelToString(level), file, line, message);

    // Write to console
    FILE *out = (level <= LOG_WARNING) ? stderr : stdout;
    fputs(finalMessage, out);
    fflush(out);

    // Write to file if available
    if (logFile) 
    {
        fputs(finalMessage, logFile);
        fflush(logFile);
    }
}
