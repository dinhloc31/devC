#include "ledDriver.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    if (ledInit(10) != 0)
    {
        printf("Failed to initialize LED driver\n");
        return -1;
    }

    const uint32_t* buffer = ledGetBuffer();
    printf("\nCheck initial buffer:\n");
    for (size_t i = 0; i < ledGetPixelCount(); ++i) 
    {
        printf("Pixel %zu: 0x%08X\n", i, buffer[i]);
    }

    ledSetPixelColor(0, 255, 0, 0);     // Pixel 0: Red
    ledSetPixelColor(9, 0, 0, 255);     // Pixel 9: Blue
    ledSetPixelColor(4, 255, 255, 255); // Pixel 4: White

    printf("\nCheck pixel colors:\n");
    printf("Pixel 0: 0x%08X\n", buffer[0]);
    printf("Pixel 9: 0x%08X\n", buffer[9]);
    printf("Pixel 4: 0x%08X\n", buffer[4]);

    ledFill(0, 255, 0);// Fill the entire LED strip with green

    printf("\nCheck buffer after fill:\n");
    for (size_t i = 0; i < ledGetPixelCount(); ++i) 
    {
        printf("Check pixel %lld: 0x%08X, status: %s\n", i, buffer[i], (buffer[i] == 0x00FF00) ? "OK" : "ERROR");
    }

    ledShutdown();

    return 0;
}