#ifndef SYSTEM_INFOR_H
#define SYSTEM_INFOR_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

typedef struct {
    char name[256];
    float cpuUsage;
    float memoryUsage;
    int processId;
} ProcessInfo;

typedef struct {
    float totalUsage;
    float coreUsage[16];  // Support up to 16 cores
    int numCores;
    float frequency;
    float temperature;
    ProcessInfo topProcesses[5];
} CPUInfo;

typedef struct {
    unsigned long totalMemory;
    unsigned long usedMemory;
    unsigned long freeMemory;
    unsigned long swapTotal;
    unsigned long swapUsed;
    unsigned long cacheMemory;
    unsigned long bufferMemory;
    ProcessInfo topProcesses[5];
} MemoryInfo;

typedef struct {
    char device[64];
    unsigned long totalSpace;
    unsigned long usedSpace;
    unsigned long freeSpace;
    float readSpeed;
    float writeSpeed;
    unsigned long readOps;
    unsigned long writeOps;
    float iops;
} StorageInfo;

typedef struct {
    char interface[64];
    char ipAddress[64];
    float uploadSpeed;
    float downloadSpeed;
    unsigned long bytesSent;
    unsigned long bytesReceived;
    unsigned long packetsSent;
    unsigned long packetsReceived;
    int connections;
} NetworkInfo;

typedef struct {
    unsigned long uptimeSeconds;
    char currentTime[64];
    char kernelVersion[128];
    float loadAvg1min;
    float loadAvg5min;
    float loadAvg15min;
    int runningServices;
    char services[10][64];  
} SystemInfo;


void getCpuInfo(CPUInfo* cpuInfo);
void getCpuUsage(CPUInfo* cpuInfo);
void getCpuCoresUsage(CPUInfo* cpuInfo);
void getCpuFrequency(CPUInfo* cpuInfo);
void getCpuTemperature(CPUInfo* cpuInfo);
void getTopCpuProcesses(CPUInfo* cpuInfo);

void getMemoryInfo(MemoryInfo* memoryInfo);
void getMemoryUsage(MemoryInfo* memoryInfo);
void getSwapUsage(MemoryInfo* memoryInfo);
void getCacheInfo(MemoryInfo* memoryInfo);
void getTopMemoryProcesses(MemoryInfo* memoryInfo);

void getStorageInfo(StorageInfo* storageInfo, int numberOfDevices);
void getDiskUsage(StorageInfo* storageInfo);
void getDiskSpeed(StorageInfo* storageInfo);
void getDiskIoStats(StorageInfo* storageInfo);
void getDiskIops(StorageInfo* storageInfo);

void getNetworkInfo(NetworkInfo* networkInfo, int numberOfInterfaces);
void getNetworkSpeed(NetworkInfo* networkInfo);
void getNetworkBandwidth(NetworkInfo* networkInfo);
void getNetworkConnections(NetworkInfo* networkInfo);
void getNetworkIpAddresses(NetworkInfo* networkInfo);
void getPacketStatistics(NetworkInfo* networkInfo);

void getSystemInfo(SystemInfo* systemInfo);
void getSystemUptime(SystemInfo* systemInfo);
void getSystemTime(SystemInfo* systemInfo);
void getKernelVersion(SystemInfo* systemInfo);
void getRunningServices(SystemInfo* systemInfo);
void getLoadAverage(SystemInfo* systemInfo);

void displayCpuInfo(const CPUInfo* cpuInfo);
void displayMemoryInfo(const MemoryInfo* memoryInfo);
void displayStorageInfo(const StorageInfo* storageInfo, int numberOfDevices);
void displayNetworkInfo(const NetworkInfo* networkInfo, int numberOfInterfaces);
void displaySystemInfo(const SystemInfo* systemInfo);
void displayAllSystemInfo(void);

void clearScreen(void);
void formatBytes(unsigned long bytes, char* buffer, size_t bufferSize);
void formatTime(unsigned long seconds, char* buffer, size_t bufferSize);

#endif // SYSTEM_INFOR_H
