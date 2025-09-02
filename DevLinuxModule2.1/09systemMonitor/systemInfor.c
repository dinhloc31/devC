#include "systemInfor.h"

// ========== CPU Information Functions ==========

void getCpuInfo(CPUInfo* cpuInfo) {
    getCpuUsage(cpuInfo);
    getCpuCoresUsage(cpuInfo);
    getCpuFrequency(cpuInfo);
    getCpuTemperature(cpuInfo);
    getTopCpuProcesses(cpuInfo);
    printf("[DEBUG] CPU info collected successfully\n");
}

void getCpuUsage(CPUInfo* cpuInfo) {
    // Simulate CPU usage between 15-85%
    cpuInfo->totalUsage = 25.5 + (rand() % 60);
    printf("[CPU] Total CPU usage: %.1f%%\n", cpuInfo->totalUsage);
}

void getCpuCoresUsage(CPUInfo* cpuInfo) {
    cpuInfo->numCores = 4; // Simulate 4 cores
    printf("[CPU] Number of cores: %d\n", cpuInfo->numCores);
    
    for (int i = 0; i < cpuInfo->numCores; i++) {
        cpuInfo->coreUsage[i] = 10.0 + (rand() % 80);
        printf("[CPU] Core %d usage: %.1f%%\n", i, cpuInfo->coreUsage[i]);
    }
}

void getCpuFrequency(CPUInfo* cpuInfo) {
    // Simulate frequency between 1.8-3.2 GHz
    cpuInfo->frequency = 1800.0 + (rand() % 1400);
    printf("[CPU] Current frequency: %.0f MHz\n", cpuInfo->frequency);
}

void getCpuTemperature(CPUInfo* cpuInfo) {
    // Simulate temperature between 35-75°C
    cpuInfo->temperature = 35.0 + (rand() % 40);
    printf("[CPU] Temperature: %.1f°C\n", cpuInfo->temperature);
}

void getTopCpuProcesses(CPUInfo* cpuInfo) {
    const char* processNames[] = {"firefox", "chrome", "code", "gcc", "make", "node", "python", "java"};
    
    printf("[CPU] Top 5 CPU-consuming processes:\n");
    for (int i = 0; i < 5; i++) {
        strcpy(cpuInfo->topProcesses[i].name, processNames[rand() % 8]);
        cpuInfo->topProcesses[i].cpuUsage = 80.0 - (i * 15) + (rand() % 10);
        cpuInfo->topProcesses[i].processId = 1000 + rand() % 9000;
        printf("[CPU]   %d. %s (PID: %d) - %.1f%%\n", 
               i+1, cpuInfo->topProcesses[i].name, 
               cpuInfo->topProcesses[i].processId, 
               cpuInfo->topProcesses[i].cpuUsage);
    }
}

// ========== Memory Information Functions ==========

void getMemoryInfo(MemoryInfo* memoryInfo) {
    getMemoryUsage(memoryInfo);
    getSwapUsage(memoryInfo);
    getCacheInfo(memoryInfo);
    getTopMemoryProcesses(memoryInfo);
    printf("[DEBUG] Memory info collected successfully\n");
}

void getMemoryUsage(MemoryInfo* memoryInfo) {
    // Simulate 8GB RAM
    memoryInfo->totalMemory = 8192 * 1024; // KB
    memoryInfo->usedMemory = 3500 * 1024 + (rand() % (2000 * 1024));
    memoryInfo->freeMemory = memoryInfo->totalMemory - memoryInfo->usedMemory;
    
    printf("[MEMORY] Total RAM: %lu MB\n", memoryInfo->totalMemory / 1024);
    printf("[MEMORY] Used RAM: %lu MB (%.1f%%)\n", 
           memoryInfo->usedMemory / 1024,
           (float)memoryInfo->usedMemory / memoryInfo->totalMemory * 100);
    printf("[MEMORY] Free RAM: %lu MB\n", memoryInfo->freeMemory / 1024);
}

void getSwapUsage(MemoryInfo* memoryInfo) {
    // Simulate 4GB swap
    memoryInfo->swapTotal = 4096 * 1024; // KB
    memoryInfo->swapUsed = 512 * 1024 + (rand() % (1000 * 1024));
    
    printf("[MEMORY] Total Swap: %lu MB\n", memoryInfo->swapTotal / 1024);
    printf("[MEMORY] Used Swap: %lu MB (%.1f%%)\n", 
           memoryInfo->swapUsed / 1024,
           (float)memoryInfo->swapUsed / memoryInfo->swapTotal * 100);
}

void getCacheInfo(MemoryInfo* memoryInfo) {
    memoryInfo->cacheMemory = 1024 * 1024 + (rand() % (500 * 1024)); // KB
    memoryInfo->bufferMemory = 256 * 1024 + (rand() % (200 * 1024)); // KB
    
    printf("[MEMORY] Cache: %lu MB\n", memoryInfo->cacheMemory / 1024);
    printf("[MEMORY] Buffers: %lu MB\n", memoryInfo->bufferMemory / 1024);
}

void getTopMemoryProcesses(MemoryInfo* memoryInfo) {
    const char* processNames[] = {"firefox", "chrome", "thunderbird", "libreoffice", "gimp", "vlc", "mysql", "docker"};
    
    printf("[MEMORY] Top 5 Memory-consuming processes:\n");
    for (int i = 0; i < 5; i++) {
        strcpy(memoryInfo->topProcesses[i].name, processNames[rand() % 8]);
        memoryInfo->topProcesses[i].memoryUsage = 1500.0 - (i * 200) + (rand() % 100);
        memoryInfo->topProcesses[i].processId = 1000 + rand() % 9000;
        printf("[MEMORY]   %d. %s (PID: %d) - %.1f MB\n", 
               i+1, memoryInfo->topProcesses[i].name, 
               memoryInfo->topProcesses[i].processId, 
               memoryInfo->topProcesses[i].memoryUsage);
    }
}

// ========== Storage Information Functions ==========

void getStorageInfo(StorageInfo* storageInfo, int numberOfDevices) {
    for (int i = 0; i < numberOfDevices; i++) {
        getDiskUsage(&storageInfo[i]);
        getDiskSpeed(&storageInfo[i]);
        getDiskIoStats(&storageInfo[i]);
        getDiskIops(&storageInfo[i]);
    }
    printf("[DEBUG] Storage info collected for %d devices\n", numberOfDevices);
}

void getDiskUsage(StorageInfo* storageInfo) {
    const char* devices[] = {"/dev/sda1", "/dev/sda2", "/dev/nvme0n1p1"};
    strcpy(storageInfo->device, devices[rand() % 3]);
    
    // Simulate different disk sizes
    storageInfo->totalSpace = 250000 + (rand() % 500000); // MB
    storageInfo->usedSpace = storageInfo->totalSpace * (30 + rand() % 50) / 100;
    storageInfo->freeSpace = storageInfo->totalSpace - storageInfo->usedSpace;
    
    printf("[STORAGE] Device: %s\n", storageInfo->device);
    printf("[STORAGE] Total: %lu MB, Used: %lu MB (%.1f%%), Free: %lu MB\n",
           storageInfo->totalSpace, storageInfo->usedSpace,
           (float)storageInfo->usedSpace / storageInfo->totalSpace * 100,
           storageInfo->freeSpace);
}

void getDiskSpeed(StorageInfo* storageInfo) {
    // Simulate read/write speeds (MB/s)
    storageInfo->readSpeed = 100.0 + (rand() % 400);
    storageInfo->writeSpeed = 80.0 + (rand() % 300);
    
    printf("[STORAGE] Read speed: %.1f MB/s, Write speed: %.1f MB/s\n",
           storageInfo->readSpeed, storageInfo->writeSpeed);
}

void getDiskIoStats(StorageInfo* storageInfo) {
    storageInfo->readOps = 10000 + (rand() % 50000);
    storageInfo->writeOps = 5000 + (rand() % 30000);
    
    printf("[STORAGE] Read operations: %lu, Write operations: %lu\n",
           storageInfo->readOps, storageInfo->writeOps);
}

void getDiskIops(StorageInfo* storageInfo) {
    storageInfo->iops = 1000.0 + (rand() % 5000);
    printf("[STORAGE] IOPS: %.0f operations/second\n", storageInfo->iops);
}

// ========== Network Information Functions ==========

void getNetworkInfo(NetworkInfo* networkInfo, int numberOfInterfaces) {
    for (int i = 0; i < numberOfInterfaces; i++) {
        getNetworkSpeed(&networkInfo[i]);
        getNetworkBandwidth(&networkInfo[i]);
        getNetworkConnections(&networkInfo[i]);
        getNetworkIpAddresses(&networkInfo[i]);
        getPacketStatistics(&networkInfo[i]);
    }
    printf("[DEBUG] Network info collected for %d interfaces\n", numberOfInterfaces);
}

void getNetworkSpeed(NetworkInfo* networkInfo) {
    const char* interfaces[] = {"eth0", "wlan0", "lo", "docker0"};
    strcpy(networkInfo->interface, interfaces[rand() % 4]);
    
    // Simulate network speeds (KB/s)
    networkInfo->uploadSpeed = (rand() % 1000) / 10.0;
    networkInfo->downloadSpeed = (rand() % 5000) / 10.0;
    
    printf("[NETWORK] Interface: %s\n", networkInfo->interface);
    printf("[NETWORK] Upload: %.1f KB/s, Download: %.1f KB/s\n",
           networkInfo->uploadSpeed, networkInfo->downloadSpeed);
}

void getNetworkBandwidth(NetworkInfo* networkInfo) {
    networkInfo->bytesSent = 1000000 + (rand() % 10000000);
    networkInfo->bytesReceived = 5000000 + (rand() % 50000000);
    
    printf("[NETWORK] Bytes sent: %lu, Bytes received: %lu\n",
           networkInfo->bytesSent, networkInfo->bytesReceived);
}

void getNetworkConnections(NetworkInfo* networkInfo) {
    networkInfo->connections = 10 + (rand() % 100);
    printf("[NETWORK] Active connections: %d\n", networkInfo->connections);
}

void getNetworkIpAddresses(NetworkInfo* networkInfo) {
    // Simulate IP addresses
    sprintf(networkInfo->ipAddress, "192.168.%d.%d", 
            1 + rand() % 10, 10 + rand() % 240);
    printf("[NETWORK] IP Address: %s\n", networkInfo->ipAddress);
}

void getPacketStatistics(NetworkInfo* networkInfo) {
    networkInfo->packetsSent = 50000 + (rand() % 100000);
    networkInfo->packetsReceived = 80000 + (rand() % 200000);
    
    printf("[NETWORK] Packets sent: %lu, Packets received: %lu\n",
           networkInfo->packetsSent, networkInfo->packetsReceived);
}

// ========== System Information Functions ==========

void getSystemInfo(SystemInfo* systemInfo) {
    getSystemUptime(systemInfo);
    getSystemTime(systemInfo);
    getKernelVersion(systemInfo);
    getRunningServices(systemInfo);
    getLoadAverage(systemInfo);
    printf("[DEBUG] System info collected successfully\n");
}

void getSystemUptime(SystemInfo* systemInfo) {
    // Simulate uptime (seconds)
    systemInfo->uptimeSeconds = 3600 + (rand() % 86400); // 1 hour to 1 day
    
    int hours = systemInfo->uptimeSeconds / 3600;
    int minutes = (systemInfo->uptimeSeconds % 3600) / 60;
    
    printf("[SYSTEM] Uptime: %d hours, %d minutes\n", hours, minutes);
}

void getSystemTime(SystemInfo* systemInfo) {
    time_t currentTime = time(NULL);
    strcpy(systemInfo->currentTime, ctime(&currentTime));
    // Remove newline
    systemInfo->currentTime[strlen(systemInfo->currentTime)-1] = '\0';
    
    printf("[SYSTEM] Current time: %s\n", systemInfo->currentTime);
}

void getKernelVersion(SystemInfo* systemInfo) {
    strcpy(systemInfo->kernelVersion, "Linux 5.15.0-78-generic #85-Ubuntu");
    printf("[SYSTEM] Kernel version: %s\n", systemInfo->kernelVersion);
}

void getRunningServices(SystemInfo* systemInfo) {
    const char* services[] = {"systemd", "NetworkManager", "ssh", "cron", "dbus", 
                             "bluetooth", "apache2", "mysql", "docker", "nginx"};
    
    systemInfo->runningServices = 6 + (rand() % 4);
    printf("[SYSTEM] Running services (%d):\n", systemInfo->runningServices);
    
    for (int i = 0; i < systemInfo->runningServices; i++) {
        strcpy(systemInfo->services[i], services[i]);
        printf("[SYSTEM]   - %s\n", systemInfo->services[i]);
    }
}

void getLoadAverage(SystemInfo* systemInfo) {
    systemInfo->loadAvg1min = (rand() % 300) / 100.0;
    systemInfo->loadAvg5min = (rand() % 250) / 100.0;
    systemInfo->loadAvg15min = (rand() % 200) / 100.0;
    
    printf("[SYSTEM] Load average: %.2f (1min), %.2f (5min), %.2f (15min)\n",
           systemInfo->loadAvg1min, systemInfo->loadAvg5min, systemInfo->loadAvg15min);
}

// ========== Display Functions ==========

void displayCpuInfo(const CPUInfo* cpuInfo) {
    printf("\n========== CPU INFORMATION ==========\n");
    printf("Total CPU Usage: %.1f%%\n", cpuInfo->totalUsage);
    printf("CPU Frequency: %.0f MHz\n", cpuInfo->frequency);
    printf("CPU Temperature: %.1f°C\n", cpuInfo->temperature);
    printf("Number of Cores: %d\n", cpuInfo->numCores);
    
    printf("Core Usage:\n");
    for (int i = 0; i < cpuInfo->numCores; i++) {
        printf("  Core %d: %.1f%%\n", i, cpuInfo->coreUsage[i]);
    }
    
    printf("Top CPU Processes:\n");
    for (int i = 0; i < 5; i++) {
        printf("  %d. %s (PID: %d) - %.1f%%\n", 
               i+1, cpuInfo->topProcesses[i].name,
               cpuInfo->topProcesses[i].processId,
               cpuInfo->topProcesses[i].cpuUsage);
    }
}

void displayMemoryInfo(const MemoryInfo* memoryInfo) {
    printf("\n========== MEMORY INFORMATION ==========\n");
    printf("Total RAM: %lu MB\n", memoryInfo->totalMemory / 1024);
    printf("Used RAM: %lu MB (%.1f%%)\n", 
           memoryInfo->usedMemory / 1024,
           (float)memoryInfo->usedMemory / memoryInfo->totalMemory * 100);
    printf("Free RAM: %lu MB\n", memoryInfo->freeMemory / 1024);
    printf("Cache: %lu MB\n", memoryInfo->cacheMemory / 1024);
    printf("Buffers: %lu MB\n", memoryInfo->bufferMemory / 1024);
    printf("Swap Total: %lu MB\n", memoryInfo->swapTotal / 1024);
    printf("Swap Used: %lu MB\n", memoryInfo->swapUsed / 1024);
    
    printf("Top Memory Processes:\n");
    for (int i = 0; i < 5; i++) {
        printf("  %d. %s (PID: %d) - %.1f MB\n", 
               i+1, memoryInfo->topProcesses[i].name,
               memoryInfo->topProcesses[i].processId,
               memoryInfo->topProcesses[i].memoryUsage);
    }
}

void displayStorageInfo(const StorageInfo* storageInfo, int numberOfDevices) {
    printf("\n========== STORAGE INFORMATION ==========\n");
    for (int i = 0; i < numberOfDevices; i++) {
        printf("Device: %s\n", storageInfo[i].device);
        printf("  Total: %lu MB\n", storageInfo[i].totalSpace);
        printf("  Used: %lu MB (%.1f%%)\n", 
               storageInfo[i].usedSpace,
               (float)storageInfo[i].usedSpace / storageInfo[i].totalSpace * 100);
        printf("  Free: %lu MB\n", storageInfo[i].freeSpace);
        printf("  Read Speed: %.1f MB/s\n", storageInfo[i].readSpeed);
        printf("  Write Speed: %.1f MB/s\n", storageInfo[i].writeSpeed);
        printf("  IOPS: %.0f\n", storageInfo[i].iops);
        printf("  Read Ops: %lu, Write Ops: %lu\n", 
               storageInfo[i].readOps, storageInfo[i].writeOps);
        if (i < numberOfDevices - 1) printf("\n");
    }
}

void displayNetworkInfo(const NetworkInfo* networkInfo, int numberOfInterfaces) {
    printf("\n========== NETWORK INFORMATION ==========\n");
    for (int i = 0; i < numberOfInterfaces; i++) {
        printf("Interface: %s\n", networkInfo[i].interface);
        printf("  IP Address: %s\n", networkInfo[i].ipAddress);
        printf("  Upload: %.1f KB/s\n", networkInfo[i].uploadSpeed);
        printf("  Download: %.1f KB/s\n", networkInfo[i].downloadSpeed);
        printf("  Bytes Sent: %lu\n", networkInfo[i].bytesSent);
        printf("  Bytes Received: %lu\n", networkInfo[i].bytesReceived);
        printf("  Packets Sent: %lu\n", networkInfo[i].packetsSent);
        printf("  Packets Received: %lu\n", networkInfo[i].packetsReceived);
        printf("  Active Connections: %d\n", networkInfo[i].connections);
        if (i < numberOfInterfaces - 1) printf("\n");
    }
}

void displaySystemInfo(const SystemInfo* systemInfo) {
    printf("\n========== SYSTEM INFORMATION ==========\n");
    printf("Current Time: %s\n", systemInfo->currentTime);
    
    int hours = systemInfo->uptimeSeconds / 3600;
    int minutes = (systemInfo->uptimeSeconds % 3600) / 60;
    printf("Uptime: %d hours, %d minutes\n", hours, minutes);
    
    printf("Kernel Version: %s\n", systemInfo->kernelVersion);
    printf("Load Average: %.2f (1min), %.2f (5min), %.2f (15min)\n",
           systemInfo->loadAvg1min, systemInfo->loadAvg5min, systemInfo->loadAvg15min);
    
    printf("Running Services (%d):\n", systemInfo->runningServices);
    for (int i = 0; i < systemInfo->runningServices; i++) {
        printf("  - %s\n", systemInfo->services[i]);
    }
}

void displayAllSystemInfo(void) {
    // Initialize random seed
    srand(time(NULL));
    
    printf("==============================================\n");
    printf("          SYSTEM MONITOR - FULL REPORT       \n");
    printf("==============================================\n");
    
    // Collect and display CPU info
    CPUInfo cpuInfo;
    getCpuInfo(&cpuInfo);
    displayCpuInfo(&cpuInfo);
    
    // Collect and display Memory info
    MemoryInfo memoryInfo;
    getMemoryInfo(&memoryInfo);
    displayMemoryInfo(&memoryInfo);
    
    // Collect and display Storage info (2 devices)
    StorageInfo storageInfo[2];
    getStorageInfo(storageInfo, 2);
    displayStorageInfo(storageInfo, 2);
    
    // Collect and display Network info (2 interfaces)
    NetworkInfo networkInfo[2];
    getNetworkInfo(networkInfo, 2);
    displayNetworkInfo(networkInfo, 2);
    
    // Collect and display System info
    SystemInfo systemInfo;
    getSystemInfo(&systemInfo);
    displaySystemInfo(&systemInfo);
    
    printf("\n==============================================\n");
    printf("              END OF REPORT                  \n");
    printf("==============================================\n");
}

// ========== Utility Functions ==========

void clearScreen(void) {
    printf("\033[2J\033[H");
}

void formatBytes(unsigned long bytes, char* buffer, size_t bufferSize) {
    if (bytes >= 1024 * 1024 * 1024) {
        snprintf(buffer, bufferSize, "%.2f GB", bytes / (1024.0 * 1024.0 * 1024.0));
    } else if (bytes >= 1024 * 1024) {
        snprintf(buffer, bufferSize, "%.2f MB", bytes / (1024.0 * 1024.0));
    } else if (bytes >= 1024) {
        snprintf(buffer, bufferSize, "%.2f KB", bytes / 1024.0);
    } else {
        snprintf(buffer, bufferSize, "%lu B", bytes);
    }
}

void formatTime(unsigned long seconds, char* buffer, size_t bufferSize) {
    int days = seconds / 86400;
    int hours = (seconds % 86400) / 3600;
    int minutes = (seconds % 3600) / 60;
    int secs = seconds % 60;
    
    if (days > 0) {
        snprintf(buffer, bufferSize, "%d days, %d hours, %d minutes", days, hours, minutes);
    } else if (hours > 0) {
        snprintf(buffer, bufferSize, "%d hours, %d minutes", hours, minutes);
    } else {
        snprintf(buffer, bufferSize, "%d minutes, %d seconds", minutes, secs);
    }
}
