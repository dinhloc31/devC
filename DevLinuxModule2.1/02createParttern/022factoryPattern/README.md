# 📚 Library Management System in C

A simple command-line library management program written in C to manage students and books. The program allows adding/searching/removing books and students, borrowing books, and displaying lists.

---

## 1. 📦 Requirement

### Exercise 1: Singleton Pattern for SensorManager

In a sensor data management system, it is required that only **one instance** of the `SensorManager` object exists throughout the entire system. The main responsibilities of the `SensorManager` are:
- Managing and collecting data from sensor nodes (`SensorNode`).
- Efficiently and consistently uploading data to the database.

If the system does not guarantee a single instance of `SensorManager`, several serious issues may arise:
- **Data Duplication:** Multiple `SensorManager` objects may collect the same data from sensors, leading to duplicate entries in the database.
- **Resource Conflicts:** Different `SensorManager` instances may access and manipulate shared resources simultaneously, causing conflicts or unexpected errors.
- **Difficult Control:** Managing and tracking the behavior of multiple `SensorManager` objects becomes complex, reducing the system's stability and maintainability.

**Requirement:**
- Propose and implement a solution to ensure that only one instance of the `SensorManager` object is created in the entire system.
- Explain how your solution addresses the issues mentioned

---

## 3. 🔧 Build & Run

### Option 1: build

make all

### Option 2: clean 

make clean

### Option 3: run

./main

---

## 4. Test Follow

- Create new sensor node with 2 sensors.
- Trying to add new sensor to exited sensor node.
- Show sensor list in sensor node.

---


