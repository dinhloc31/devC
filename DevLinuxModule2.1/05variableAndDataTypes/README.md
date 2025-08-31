
## Project Description
Smart Plant Watering System (SPWS) is an embedded C application that simulates automatic plant watering management. The system uses soil moisture and temperature sensors, a mini water pump, status LEDs, and physical buttons to automate watering and allow manual user intervention.

## Main Features
- Read soil moisture and temperature sensor data
- Automatic watering based on configurable thresholds
- Switch between auto/manual mode via button
- Manual watering on user request
- Show system status via LED
- Print status notifications to console
- Manage system state using enums and structs

## Directory Structure
```
05memoryManagment/
├── main.c                # Main loop, system state management
├── main.h                # Main header file
├── Makefile              # Build script
├── README.md             # Project documentation
├── inc/                  # Header files for sensors
│   ├── humiditysensor.h
│   ├── lightSensor.h
│   ├── sensor.h
│   ├── tempSensor.h
├── src/                  # Source files for sensors
│   ├── humiditysensor.c
│   ├── lightSensor.c
│   ├── sensor.c
│   ├── tempSensor.c
```

## Build & Run Instructions
1. Open terminal in `05memoryManagment` folder
2. Build project:
  ```
  make all
  ```
3. Run program:
  ```
  ./main
  ```
4. Clean build files:
  ```
  make clean
  ```

## Data Structures
- **enum**: Manage system, pump, and LED states
- **struct**: Store sensor data, system configuration
- **extern/static**: Share variables between modules appropriately

## Hardware Simulation
- Sensors, pump, LED, and buttons are simulated by printing to console
