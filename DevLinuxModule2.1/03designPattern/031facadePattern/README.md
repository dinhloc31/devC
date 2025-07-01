
# 🏠 Smart Home Control System using Facade Pattern

## 1. 📦 Requirement

### Exercise 3: Applying the Facade Pattern to Simplify Smart Home Integration

You are building an embedded system (or software simulator) to manage various subsystems in a smart home, such as:

- Lighting system  
- Curtain system  
- HVAC (Heating, Ventilation, Air Conditioning)  
- Security system  

Each subsystem is implemented independently and provides its own control API. However, the user (or application logic) must frequently perform **combined operations** (e.g., activate morning mode, leave home mode, movie night mode).

### Problem:
- Client code (main program) must directly manage the complexity of multiple subsystems.
- Hard to maintain and prone to errors due to tight coupling with many components.
- Adding new high-level "scenes" or modes increases system complexity.

### Requirement:
- Use the **Facade Design Pattern** to provide a simplified interface for the main application.
- Client code should only interact with a single unified `SmartHomeFacade`, instead of directly with subsystems.

---

## 2. 🎯 Design Goal

The **Facade Pattern** aims to:
- Provide a unified interface to a set of subsystems.
- Decouple client code from subsystem implementations.
- Group multiple low-level actions into high-level modes (e.g., Morning Routine, Away Mode, Movie Night Scene).

By doing this, we achieve:
- Cleaner main code.
- Better modularity.
- Easier extensibility for new scenes/modes.

---

## 3. 🏗️ Project Structure

```
031facadePattern/
│
├── inc/                        # Header files (interfaces)
│   ├── brightSystem.h          # Lighting control
│   ├── curtainSystem.h         # Curtain control
│   ├── hvacSystem.h            # HVAC system
│   ├── securitySystem.h        # Security system
│   └── smartHomeFacade.h       # Facade header
│
├── src/                        # Implementation files
│   ├── brightSystem.c
│   ├── curtainSystem.c
│   ├── hvacSystem.c
│   ├── securitySystem.c
│   └── smartHomeFacade.c       # Facade implementation
│
├── main.c                      # Entry point
└── Makefile (optional)         # For build automation
```

---

## 4. 🔧 Build & Run

### Build (if using Makefile):

```bash
make all
```

### Run:

```bash
./main
```

### Clean:

```bash
make clean
```

---

## 5. 🏠 How Facade Pattern Works in This Program

### ✅ Role of `SmartHomeFacade`

The `SmartHomeFacade` struct contains instances of all subsystems:

```c
typedef struct {
    BrightSystem* brightSystem;
    CurtainSystem* curtainSystem;
    HVACSystem* hvacSystem;
    SecuritySystem* securitySystem;
} smartHomeFacade;
```

### ✅ High-Level Functions Exposed:

- `activateMorningRoutine()`
- `activateAwayMode()`
- `setMovieNightScene()`

These functions combine multiple subsystem operations. For example:

```c
void activateMorningRoutine(smartHomeFacade* home) {
    openCurtains(home->curtainSystem);
    turnOnLights(home->brightSystem);
    setTemperature(home->hvacSystem, 24);
    disableAlarm(home->securitySystem);
}
```

### ✅ Benefits:
- Client (main.c) doesn't know how subsystems work.
- Just calls high-level scene functions from the facade.

---

## 6. 🧪 Execution Flow in `main.c`

```c
int main() 
{
    smartHomeFacade* smartHome = createSmartHomeFacade();

    activateMorningRoutine(smartHome);
    activateAwayMode(smartHome);
    setMovieNightScene(smartHome);

    // Cleanup
    free(...);
    return 0;
}
```

### Actions performed:
1. Create the smart home facade instance.
2. Activate a series of scenes:
   - **Morning routine**: open curtain, turn on lights, set temperature, disable alarm.
   - **Away mode**: turn off lights, close curtain, turn off HVAC, enable alarm.
   - **Movie night**: dim lights, close curtain, adjust temperature.
3. Free allocated memory for each subsystem.

---

## 7. ✅ Summary

| Design Pattern     | Facade Pattern                        |
|--------------------|----------------------------------------|
| Pattern Purpose    | Simplify usage of complex subsystems   |
| Key Benefit        | Decouples client from subsystem logic  |
| Code Organization  | Clean separation between interface and implementation |
| Extensibility      | Easy to add more modes/scenes in `smartHomeFacade.c` |

---

## 📌 Notes

- This design is scalable: new devices (e.g., speaker system) can be added by updating only `smartHomeFacade`, without touching `main.c`.
- This pattern is especially useful in **embedded systems**, **home automation**, or **UI automation** frameworks.
