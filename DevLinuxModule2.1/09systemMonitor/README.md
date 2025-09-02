# System Information Monitor

A comprehensive system monitoring application written in C that provides detailed information about CPU, memory, storage, network, and system statistics on Linux systems.

## Table of Contents

- [Features](#features)
- [System Requirements](#system-requirements)
- [Installation](#installation)
- [Usage](#usage)
- [Project Structure](#project-structure)
- [Code Documentation](#code-documentation)
- [Clean Code Principles](#clean-code-principles)
- [Building from Source](#building-from-source)
- [Troubleshooting](#troubleshooting)
- [Contributing](#contributing)
- [License](#license)

## Features

### 🖥️ CPU Information
- Total CPU usage percentage
- Per-core CPU usage statistics
- Current CPU frequency
- CPU temperature monitoring
- Top 5 CPU-consuming processes

### 💾 Memory Information
- Total, used, and free RAM
- Swap memory usage statistics
- Cache and buffer memory information
- Top 5 memory-consuming processes

### 💿 Storage Information
- Disk usage for multiple devices
- Read/write speeds
- I/O operations statistics
- IOPS (Input/Output Operations Per Second)

### 🌐 Network Information
- Network interface details
- Upload/download speeds
- Bytes and packets transferred
- Active network connections
- IP address information

### 🔧 System Information
- System uptime
- Current system time
- Kernel version
- Running services
- Load averages (1, 5, 15 minutes)

## System Requirements

- **Operating System**: Linux (Ubuntu, Debian, CentOS, etc.)
- **Compiler**: GCC with C99 support
- **Dependencies**: Standard C library (libc)
- **Memory**: Minimal memory footprint (~1MB)
- **Permissions**: No root permissions required for basic monitoring

## Installation

### Quick Install

```bash
# Clone or download the project
cd 09systemMonitor

# Build the application
make all

# clean code
make clean
```

# Run the system monitor
./system_monitor
```

The application will display a comprehensive report including:
- Real-time CPU statistics
- Memory usage details
- Storage information
- Network interface data
- System information

### Example Output

```
==============================================
          SYSTEM MONITOR - FULL REPORT       
==============================================

[CPU] Total CPU usage: 32.5%
[CPU] Number of cores: 4
[CPU] Core 0 usage: 10.0%
[CPU] Core 1 usage: 16.0%
[CPU] Core 2 usage: 62.0%
[CPU] Core 3 usage: 57.0%
[CPU] Current frequency: 2010 MHz
[CPU] Temperature: 44.0°C
[CPU] Top 5 CPU-consuming processes:
[CPU]   1. gcc (PID: 8654) - 84.0%
[CPU]   2. code (PID: 6186) - 66.0%
...

========== MEMORY INFORMATION ==========
Total RAM: 8192 MB
Used RAM: 4160 MB (50.8%)
Free RAM: 4031 MB
...
```

## Project Structure

```
09systemMonitor/
├── README.md                 # This file
├── Makefile                  # Build configuration
├── main.c                    # Main application entry point
├── systemInfor.h            # Header file with data structures and function declarations
└── systemInfor.c            # Implementation of system monitoring functions
```

### File Descriptions

- **`main.c`**: Entry point of the application, handles user interaction
- **`systemInfor.h`**: Contains all data structures (CPUInfo, MemoryInfo, etc.) and function declarations
- **`systemInfor.c`**: Implementation of all system monitoring functions
- **`Makefile`**: Build configuration with targets for compilation, installation, and cleanup

## Code Documentation

### Data Structures

#### ProcessInfo
```c
typedef struct {
    char name[256];          // Process name
    float cpuUsage;          // CPU usage percentage
    float memoryUsage;       // Memory usage in MB
    int processId;           // Process ID (PID)
} ProcessInfo;
```

#### CPUInfo
```c
typedef struct {
    float totalUsage;        // Total CPU usage percentage
    float coreUsage[16];     // Per-core usage (supports up to 16 cores)
    int numCores;            // Number of CPU cores
    float frequency;         // Current CPU frequency in MHz
    float temperature;       // CPU temperature in Celsius
    ProcessInfo topProcesses[5]; // Top 5 CPU-consuming processes
} CPUInfo;
```

### Key Functions

- **`getCpuInfo()`**: Collects comprehensive CPU information
- **`getMemoryInfo()`**: Gathers memory and swap statistics
- **`getStorageInfo()`**: Retrieves disk usage and performance data
- **`getNetworkInfo()`**: Collects network interface information
- **`getSystemInfo()`**: Gathers system-wide information
- **`displayAllSystemInfo()`**: Main function that orchestrates data collection and display

