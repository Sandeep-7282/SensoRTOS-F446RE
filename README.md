# SensoRTOS-F446RE
# 🚀 SensoRTOS - Smart RTOS-based Sensor System with CLI
![STM32](https://img.shields.io/badge/MCU-STM32F446RE-blue?style=flat-square) ![FreeRTOS](https://img.shields.io/badge/RTOS-FreeRTOS-green?style=flat-square) ![Language](https://img.shields.io/badge/Language-C-blue?style=flat-square) ![License](https://img.shields.io/badge/License-MIT-yellow?style=flat-square)
---

## 🔥 Project Overview

Welcome to **SensoRTOS** — a smart, real-time embedded system built on the STM32F446RE Nucleo-64 board 🛠️.  
It’s a **FreeRTOS-based** sensor platform with a UART CLI interface, integrating temperature, humidity, distance, and motion sensors — making it perfect for hobbyists and embedded enthusiasts who love **electronics** and **IoT**!

This project showcases:

- 🕹️ Interactive command-line control for sensors and peripherals  
- 📡 Real-time sensor data acquisition and display  
- 🖥️ OLED display integration with I2C  
- 🎯 Modular FreeRTOS task management  
- 🔔 Motion detection with buzzer alert  

---

## 🔍 What Makes SensoRTOS Unique?

While sensor projects abound, **SensoRTOS goes deeper — combining bare-metal embedded programming with a robust FreeRTOS multitasking framework** to create a highly modular, scalable, and real-time sensor system. This is more than just reading sensors; it’s about *how* the system is designed and built.

### Key Highlights:

- 🎯 **Bare-metal + FreeRTOS Hybrid**  
  Direct hardware manipulation combined with FreeRTOS task management provides low-level control **and** real-time multitasking — a balance rare in hobby projects.

- 🧱 **Modular Project Structure**  
  The codebase is cleanly separated into sensor drivers, tasks, CLI interface, and hardware abstraction layers — making it easy to extend and maintain.

- ⏳ **Real-Time Task Scheduling**  
  Using FreeRTOS preemptive scheduling allows concurrent sensor reads, display updates, and user commands without blocking or delays — a practical example of embedded multitasking.

- 🛠️ **Advanced Timing and Synchronization**  
  DWT-based microsecond delay, proper GPIO handling, and task notifications show how to handle precise timing and inter-task communication.

- 💡 **Command Line Interface (CLI)**  
  A flexible UART-based CLI allows users to dynamically redirect sensor data streams between UART and OLED — demonstrating interactive embedded system design.

- 🚀 **Scalable for IoT and Automation**  
  This project’s architecture can be easily expanded to include more sensors, actuators, or communication protocols (e.g., WiFi, BLE), making it an excellent base for future IoT projects.

---

## 🧠 What You Will Learn

- How to write **bare-metal drivers** for common sensors (DHT11, HC-SR04, PIR) on STM32F4 MCUs  
- How to **integrate FreeRTOS tasks** with sensor drivers and peripheral control  
- How to design a **user-friendly UART CLI** for embedded devices  
- How to use **I2C OLED displays** with SSD1306 and display dynamic sensor data  
- Best practices for **real-time embedded programming** and multitasking systems  
- Handling **precise timing** and interrupts in sensor measurements  
- The importance of **code modularity** and task synchronization in embedded systems  

---

## ⚙️ System Architecture Overview

+---------------------+ +---------------------+
| | | |
| Sensor Drivers <--------> FreeRTOS Tasks |
| (DHT11, HC-SR04, | | (DHT11 Task, |
| PIR, Buzzer) | | HC-SR04 Task, PIR |
| | | Task, UART CLI Task)|
+---------------------+ +---------------------+
| |
v v
+-----------------------------------------------+
| Hardware Abstraction Layer |
| (GPIO, USART, I2C, Delay, NVIC Configuration)|
+-----------------------------------------------+

- Sensors handled by dedicated drivers  
- Each sensor runs in its own FreeRTOS task, enabling true multitasking  
- CLI task listens for UART commands and switches sensor output between UART and OLED

---

## 🧩 Features & Components

| Component          | Description                                                  | Pins (STM32F446RE)              |
|--------------------|-----------------------------------------------------------|---------------------------------|
| 🌡️ **DHT11**       | Temperature & Humidity sensor                             | PB6 (Data)                     |
| 📏 **HC-SR04**     | Ultrasonic distance measurement sensor                    | PA6 (Trig), PA7 (Echo)         |
| 🚶 **HC-SR501**    | PIR motion sensor (Pyroelectric Infrared Detector)        | PB13 (Input)                   |
| 🔊 **Buzzer**      | Passive buzzer for motion alert                           | PA9 (Output)                   |
| 🖥️ **OLED Display**| I2C OLED 128x64 (SSD1306) display                         | PB8 (SCL), PB9 (SDA), Addr 0x3C|
| 🔄 **UART Interface**| UART2 for CLI communication                             | PA2 (TX), PA3 (RX)             |

---

## 🛠️ Technical Specs

| Specification         | Details                           |
|-----------------------|----------------------------------|
| MCU                   | STM32F446RE (Nucleo-64 board)    |
| System Clock          | 180 MHz                         |
| RTOS                  | FreeRTOS (Preemptive scheduling)|
| UART Baud Rate        | 9600                            |
| Stack Size (Tasks)    | LED=128, DHT11=256, HC-SR04=256, PIR=128, UART=128 |
| Heap Size             | 15 KB (configTOTAL_HEAP_SIZE)    |

---

## 📜 CLI Commands

| Command          | Description                                         |
|------------------|-----------------------------------------------------|
| `help`           | Display the command list and usage                   |
| `reboot`         | Reboot the system                                    |
| `oled dht11`     | Redirect DHT11 sensor output to OLED display        |
| `uart dht11`     | Redirect DHT11 sensor output to UART terminal       |
| `oled hcsr04`    | Redirect HC-SR04 sensor output to OLED               |
| `uart hcsr04`    | Redirect HC-SR04 sensor output to UART               |
| `oled pir`       | Redirect PIR sensor output to OLED                   |
| `uart pir`       | Redirect PIR sensor output to UART                    |
| `oled off`       | Clear OLED and redirect all sensor outputs to UART  |

---

## 🚩 Challenges & Solutions

- **Precise Timing for HC-SR04 Echo Pulse:**  
  Used DWT cycle counter for microsecond delays and timing measurement, improving accuracy over blocking delays.

- **Task Synchronization:**  
  Avoided race conditions between sensor reads and CLI commands by using FreeRTOS task notifications and semaphores.

- **Resource Management:**  
  Efficient stack and heap allocation ensured stable operation on a constrained MCU.

- **Dynamic Output Routing:**  
  CLI allows switching sensor data output dynamically — achieved by using function pointers and task-safe flags.

---

## 🧑‍💻 Author

**Sandeep** — Embedded Systems & Electronics enthusiast 🔧💡

---

## 📄 License

This project is licensed under the **MIT License** — see the [LICENSE](LICENSE) file for details.

---

