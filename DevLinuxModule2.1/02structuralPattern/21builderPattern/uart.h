#ifndef UART_H
#define UART_H

#include <stdlib.h>
#include <stdio.h>

typedef enum 
{
    PARITY_NONE,
    PARITY_EVEN,
    PARITY_ODD
} parityType;

typedef enum 
{
    BAUDRATE_1200    = 1200,
    BAUDRATE_2400    = 2400,
    BAUDRATE_4800    = 4800,
    BAUDRATE_9600    = 9600,
    BAUDRATE_14400   = 14400,
    BAUDRATE_19200   = 19200,
    BAUDRATE_38400   = 38400,
    BAUDRATE_57600   = 57600,
    BAUDRATE_115200  = 115200,
    BAUDRATE_230400  = 230400,
    BAUDRATE_460800  = 460800,
    BAUDRATE_921600  = 921600,
    BAUDRATE_1000000 = 1000000
} baudRateBps;

typedef struct 
{
    baudRateBps baudrate;
    parityType Parity;
    float stopBits;
    int dataBits;
} uartConfig;

//Builder Structure
typedef struct uartConfigBuilder
{
    uartConfig feedbackUArtConfig;
    struct uartConfigBuilder* (*setUartBaud)(struct uartConfigBuilder*, baudRateBps);
    struct uartConfigBuilder* (*setUartParity)(struct uartConfigBuilder*, parityType);
    struct uartConfigBuilder* (*setUartStopbits)(struct uartConfigBuilder*, float);
    struct uartConfigBuilder* (*setUartDatabits)(struct uartConfigBuilder*, int);
    uartConfig (*build)(struct uartConfigBuilder*);
} uartConfigBuilder;

//Builder functions 
uartConfigBuilder uartDefaultConfig_create();
// uartConfigBuilder* setUartBaud(uartConfigBuilder* builder, baudRateBps baudrateConfig);
// uartConfigBuilder* setUartParity(uartConfigBuilder* builder, parityType ParityConfig);
// uartConfigBuilder* setUartStopbits(uartConfigBuilder* builder, float stopBitsConfig);
// uartConfigBuilder* setUartDatabits(uartConfigBuilder* builder, int dataBitsConfig);
// uartConfig build(uartConfigBuilder* uartConfig);

#endif