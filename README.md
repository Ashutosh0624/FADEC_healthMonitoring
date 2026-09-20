# 🛠️ FADEC Health Monitoring System (Avionics RTOS Project)
C++ avionics health monitor — EGT, RPM, altimeter & bleed valve fault detection with BITE logging, inspired by Rolls-Royce Trent 900 FADEC. DO-178C philosophy.**.

---

## 🚀 Project Overview

- 🧠 Real-time polling of critical engine sensors
- 🏗️ Lightweight cooperative task scheduling (RTOS-style)
- 🛑 Fault detection logic via sensor health checks
- 📋 Centralized **BITE (Built-In Test Equipment)** logging
- 🔁 Expandable for additional sensors and FADEC behavior

---

## 🔧 System Architecture

- **Sensors Implemented:**
  - ✅ EGT Sensor (Exhaust Gas Temperature)
  - ✅ Altimeter (Altitude)
  - ✅ RPM Sensor (Fan Shaft Speed)
  - ✅ Bleed Valve Position Sensor

- **Core Modules:**
  | Module | Responsibility |
  |--------|----------------|
  | `SensorTypes.h` | Defines sensor structures and their `read()` / `status()` functions |
  | `SensorInterface.h` | Generic interface using function pointers |
  | `TaskScheduler.h` | Defines `SensorTask` for periodic execution |
  | `BITELogger.h` | Singleton logger for centralized fault tracking |
  | `main.cpp` | RTOS-style loop for sensor execution, fault detection, and logging |

---

## 📦 Design Patterns Used

- ✅ **Singleton Pattern** for `BITELogger`
- ✅ **Interface Abstraction** via function pointers (C-style polymorphism)
- ✅ **RTOS Simulation** using cooperative polling and timestamps

---

## ⚠️ Fault Detection Logic (Example)

- EGT over 950°C triggers a **“FAULT: EGT Overtemperature”** log
- Similar logic can be extended for:
  - Bleed Valve mismatch
  - Altitude stagnation
  - RPM overspeed

---

## 🧪 Sample Output (Console)

![image](https://github.com/user-attachments/assets/c96d813b-a4cd-4a49-95a3-666107fc08b0)



---

## 🧠 Learning Objectives

This project demonstrates real-world concepts of:

- Embedded C++ sensor polling
- Avionics health monitoring (aligned with DO-178C philosophy)
- Fault injection and detection
- Logging and diagnostics (BITE-style)
- Modular and testable RTOS-like architecture

---

## 👨‍💻 Author

**Ashutosh Tiwari**  
- Embedded Systems | Avionics | Qt | C++  
- GitHub: [@Ashutosh0624](https://github.com/Ashutosh0624)

---

## 📌 License

This project is released under the MIT License.

