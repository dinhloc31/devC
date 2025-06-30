#include "uart.h"
void uartShowConfig(uartConfig uartConfig);


int main()
{
    //Default UART config Init
    uartConfigBuilder uartBuilder = uartDefaultConfig_create();
    uartConfig uart = uartBuilder.build(&uartBuilder);
    printf("========Default Config========\n");
    uartShowConfig (uart);

    //Config with another new Uart parameter
    printf("========New Config========\n");
    uart = uartBuilder
    .setUartBaud(&uartBuilder, BAUDRATE_4800)
    ->setUartDatabits(&uartBuilder, 4)
    ->setUartParity(&uartBuilder, PARITY_ODD)
    ->setUartStopbits(&uartBuilder, 1.2)
    ->build(&uartBuilder);
    uartShowConfig (uart);
}

void uartShowConfig(uartConfig uartConfig)
{
    printf("Applying Uart Config:\n");
    printf("Baud Rate: %d bps\n", uartConfig.baudrate);
    printf("Parity: %d bits\n", uartConfig.Parity);
    printf("Stop bits: %.2f bits\n", uartConfig.stopBits);
    printf("Data bits: %d bits\n", uartConfig.dataBits);
}