#include "ledDriver.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

static uint32_t* ledBuffer = NULL;
static size_t ledPixelCount = 0;

int ledInit(size_t numPixels) 
{
	if (numPixels == 0) return -1;

	ledShutdown(); 
	ledBuffer = (uint32_t*)malloc(numPixels * sizeof(uint32_t));
	if (!ledBuffer) 
    {
		ledPixelCount = 0;
		return -1;
	}
	memset(ledBuffer, 0, numPixels * sizeof(uint32_t));
	ledPixelCount = numPixels;
	return 0;
}

void ledShutdown() 
{
	if (ledBuffer) 
    {
		free(ledBuffer);
		ledBuffer = NULL;
		ledPixelCount = 0;
	}
}

void ledSetPixelColor(size_t index, uint8_t red, uint8_t green, uint8_t blue) 
{
	if (index >= ledPixelCount) 
    {
        printf("Invalid LED index\n");
        return;
    }
	ledBuffer[index] = ((uint32_t)red << 16) | ((uint32_t)green << 8) | (uint32_t)blue;
}

void ledFill(uint8_t red, uint8_t green, uint8_t blue) 
{
	if (!ledBuffer)
    {
        printf("LED buffer not initialized\n");
        return;
    }

	for (size_t i = 0; i < ledPixelCount; i++) 
    {
		ledBuffer[i] = ((uint32_t)red << 16) | ((uint32_t)green << 8) | (uint32_t)blue;
	}
}

void ledClear() 
{
	if (!ledBuffer)
    {
        printf("LED buffer not initialized\n");
        return;
    }

	for (size_t i = 0; i < ledPixelCount; i++) 
    {
		ledBuffer[i] = 0;
	}
}

const uint32_t* ledGetBuffer()
{
    if (!ledBuffer)
    {
        printf("LED buffer not initialized\n");
        return NULL;
    }
    return ledBuffer;
}

size_t ledGetPixelCount()
{
    return ledPixelCount;
}