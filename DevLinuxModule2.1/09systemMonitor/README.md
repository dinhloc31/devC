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

### Key Functions

- **`getCpuInfo()`**: Collects comprehensive CPU information
- **`getMemoryInfo()`**: Gathers memory and swap statistics
- **`getStorageInfo()`**: Retrieves disk usage and performance data
- **`getNetworkInfo()`**: Collects network interface information
- **`getSystemInfo()`**: Gathers system-wide information
- **`displayAllSystemInfo()`**: Main function that orchestrates data collection and display

