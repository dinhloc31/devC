
## 1. 📦 Requirement

### Exercise 2: Applying the Factory Pattern and Open/Closed Principle for Sensor Integration

You are developing an embedded system to communicate with various sensors. Initially, the system was designed only to interact with and retrieve data from a temperature sensor. However, over time, new customer requirements arise: the system must also be able to measure other parameters such as humidity, pressure, or light.

Integrating a new sensor (for example, a humidity sensor) requires modifying the current system structure to add APIs for retrieving data from this new sensor.

This leads to:
- Modifying source code in multiple places, increasing the risk of errors.
- Increased system complexity, making maintenance more difficult.
- Reduced stability and long-term scalability of the system.

The current system does not comply with the Open/Closed Principle (OCP) of software design. Specifically, any extension (adding a new sensor) requires modifying existing source code, which may compromise the system's stability.

**Requirement:**
- Redesign the system following the Open/Closed Principle (OCP), so that:
  - Integrating new sensors (humidity, pressure, light, etc.) only requires extending the system, without modifying the existing codebase.
- Explain how your design addresses the issues mentioned above.

---
## 2. Project structure

```
022factoryPattern/
│
├── Makefile                # Build configuration
├── main.c                  # Entry point of the application
│
├── inc/                    # Header files for sensor interfaces
│   ├── humiditysensor.h    # Interface for humidity sensor
│   ├── lightSensor.h       # Interface for light sensor
│   ├── sensor.h            # Base sensor interface (factory target)
│   └── tempSensor.h        # Interface for temperature sensor
│
├── src/                    # Source files implementing sensor logic
│   ├── humiditysensor.c    # Implementation for humidity 
│   ├── lightSensor.c       # Implementation for light sensor
│   ├── sensor.c            # Factory function and sensor handling
│   └── tempSensor.c        # Implementation for temperature 

```
---

## 3. 🔧 Build & Run

### Option 1: build

make all

### Option 2: clean 

make clean

### Option 3: run

./main

---
### Factory Pattern Operation and Its Usage in This Program

**How the Factory Pattern Works:**
- The Factory Pattern provides a way to create objects without specifying the exact class of the object that will be created.
- In this program, the function `createSensor(sensorType)` acts as a factory. Based on the `sensorType` argument (e.g., `SENSOR_TEMP`, `SENSOR_HUMIDITY`, `SENSOR_LIGHT`), it returns a pointer to a specific sensor instance (temperature, humidity, or light sensor).
- The main program does not need to know the details of how each sensor is created or managed. It simply requests a sensor by type and receives an initialized object that implements a common interface (`sensor`).

**Why Use the Factory Pattern Here:**
- **Extensibility:** New sensor types can be added easily by extending the factory function and implementing new sensor modules, without modifying the main program logic.
- **Encapsulation:** The creation logic and any singleton management (e.g., only one humidity sensor instance) are hidden inside the factory, keeping the main code clean and focused on high-level logic.
- **Open/Closed Principle:** The system can be extended with new sensor types without changing existing code, improving maintainability and reducing the risk of introducing bugs.
- **Consistency:** Ensures that all sensors are created and initialized in a uniform way, and any constraints (like singleton for certain sensors) are enforced centrally.

**Summary:**  
The factory pattern in this program decouples sensor creation from usage, making the codebase more modular, maintainable, and scalable as new sensor types are introduced.

---

## 4. Test Follow
### Workflow for `main()` function

1. **Include Headers**
   - Includes the base sensor interface (`sensor.h`) and standard I/O library.

2. **Create Sensor Instances**
   - Calls `createSensor(SENSOR_TEMP)` to create a temperature sensor instance.
   - Calls `createSensor(SENSOR_HUMIDITY)` to create a humidity sensor instance.
   - Calls `createSensor(SENSOR_HUMIDITY)` again to test singleton behavior for humidity sensor.
   - Calls `createSensor(SENSOR_LIGHT)` to create a light sensor instance.

3. **Initialize Sensors**
   - Calls `initSensor()` for each sensor instance to perform any necessary initialization.

4. **Read and Print Sensor Data**
   - Calls `readSensorData()` for each sensor and prints the returned values to the console.

5. **Program End**
   - The program ends after displaying

---


