#ifndef LEDDRIVER_H
#define LEDDRIVER_H

#include <stdint.h>
#include <stddef.h>

int ledInit(size_t num_pixels);
void ledShutdown();
void ledSetPixelColor(size_t index, uint8_t r, uint8_t g, uint8_t b);
void ledFill(uint8_t r, uint8_t g, uint8_t b);
void ledClear();
const uint32_t* ledGetBuffer();
size_t ledGetPixelCount();

#endif // LEDDRIVER_H