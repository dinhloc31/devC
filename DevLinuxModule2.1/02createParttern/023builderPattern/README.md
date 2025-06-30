# UART Configuration with Builder Pattern in C

## 1. Overview

This project demonstrates how to configure a UART (Universal Asynchronous Receiver-Transmitter) interface using the **Builder Pattern** in the C programming language.

By using this pattern, we can construct complex UART configuration objects step-by-step, allowing for both default and customized configuration profiles with clean and maintainable code.

---

## 2. Features

- Easily create default UART configurations.
- Customize individual UART parameters (baud rate, parity, stop bits, data bits).
- Output current UART settings in human-readable format.
- Use fluent-style builder syntax in C to simulate object-oriented configuration logic.

---

## 3. Example Output

```
========Default Config========
Applying Uart Config:
Baud Rate: 9600 bps
Parity: 0 bits
Stop bits: 1.00 bits
Data bits: 8 bits

========New Config========
Applying Uart Config:
Baud Rate: 4800 bps
Parity: 1 bits
Stop bits: 1.20 bits
Data bits: 4 bits
```
---

## 4. Project structure

```
uartBuilderProject/
├── inc/
│   └── uart.h                # UART configuration structure and builder interface
├── src/
│   └── uart.c                # Implementation of UART configuration builder
├── main.c                    # Entry point that demonstrates builder usage
├── Makefile                  # Build configuration
└── README.md                 # Project documentation


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
## 5. How It Works

### 5.1 Structures

#### `uartConfig`

Holds the configuration parameters:

- `baudrate`: Baud rate of UART (e.g., 9600, 4800).
- `parity`: Parity configuration (e.g., none, odd, even).
- `stopBits`: Number of stop bits (e.g., 1.0, 1.5, 2.0).
- `dataBits`: Number of data bits per frame (e.g., 8, 7, 4).

#### `uartConfigBuilder`

Builder structure that includes:

- Function pointers for each configuration step:
  - `setUartBaud()`: Set baud rate.
  - `setUartParity()`: Set parity bits.
  - `setUartStopbits()`: Set stop bits.
  - `setUartDatabits()`: Set number of data bits.
- `build()`: Finalize and return `uartConfig` object.

---

### 5.2 Default Initialization

Create a default UART configuration:

```
uartConfigBuilder builder = uartDefaultConfig_create();
uartConfig config = builder.build(&builder);
```
---
### 5.3 Custom Configuration (Fluent API style)
Configure custom UART parameters step-by-step:
```txt
config = builder
    .setUartBaud(&builder, BAUDRATE_4800)
    ->setUartDatabits(&builder, 4)
    ->setUartParity(&builder, PARITY_ODD)
    ->setUartStopbits(&builder, 1.2)
    ->build(&builder);
```
## 6. Pattern Used
```txt
Constructs complex configuration objects (uartConfig) in a clear and fluent manner.

Simulates object-oriented flexibility in C using function pointers and chaining.

Improves readability and reusability for embedded configuration modules.
```