#include "uart.h"


static uartConfigBuilder *setUartBaud(uartConfigBuilder *builder, baudRateBps baudrateConfig)
{
    builder->feedbackUArtConfig.baudrate = baudrateConfig;
    return builder;
}

static uartConfigBuilder *setUartParity(uartConfigBuilder *builder, parityType ParityConfig)
{
    builder->feedbackUArtConfig.Parity = ParityConfig;
    return builder;
}

static uartConfigBuilder *setUartStopbits(uartConfigBuilder *builder, float stopBitsConfig)
{
    builder->feedbackUArtConfig.stopBits = stopBitsConfig;
    return builder;
}

static uartConfigBuilder *setUartDatabits(uartConfigBuilder *builder, int dataBitsConfig)
{
    builder->feedbackUArtConfig.dataBits = dataBitsConfig;
    return builder;
}

static uartConfig build(uartConfigBuilder *uartConfig)
{
    return uartConfig->feedbackUArtConfig;
}

uartConfigBuilder uartDefaultConfig_create()
{
    uartConfigBuilder uartConfigBuilder;
    uartConfigBuilder.feedbackUArtConfig.baudrate = BAUDRATE_115200;
    uartConfigBuilder.feedbackUArtConfig.dataBits = 8; // 8bits Data transfer
    uartConfigBuilder.feedbackUArtConfig.Parity = PARITY_NONE;
    uartConfigBuilder.feedbackUArtConfig.stopBits = 2; 
    uartConfigBuilder.setUartBaud = setUartBaud;
    uartConfigBuilder.setUartDatabits = setUartDatabits;
    uartConfigBuilder.setUartParity = setUartParity;
    uartConfigBuilder.setUartStopbits = setUartStopbits;
    uartConfigBuilder.build = build;
    return  uartConfigBuilder;
}

