
## LED Driver Module

## Description
This module provides an API for controlling an RGB LED strip in C. It supports dynamic memory management, setting individual pixel colors, filling the entire strip with a color, clearing, and buffer access.

## Main Features
- Dynamic initialization and shutdown of the LED buffer
- Set color for individual pixels
- Fill all pixels with a single color
- Clear all pixels (set to black)
- Access the buffer for reading pixel data

## API Functions
- `int ledInit(size_t numPixels);`  
  Initialize the LED buffer with `numPixels` pixels. Returns 0 on success, -1 on failure.
- `void ledShutdown();`  
  Free the buffer memory.
- `void ledSetPixelColor(size_t index, uint8_t red, uint8_t green, uint8_t blue);`  
  Set color for a specific pixel.
- `void ledFill(uint8_t red, uint8_t green, uint8_t blue);`  
  Fill all pixels with the same color.
- `void ledClear();`  
  Set all pixels to black.
- `const uint32_t* ledGetBuffer();`  
  Get a pointer to the buffer for reading pixel data.
- `size_t ledGetPixelCount();`  
  Get the number of pixels in the buffer.

## File Structure
```
07operationAndControlStructures/
├── main.c
├── ledDriver.h
├── ledDriver.c
├── README.md
```
### Build Instructions
1. Open terminal in `07operationAndControlStructures` folder
2. Build project:
  ```
  make all
  ```
3. Run program:
  ```
  ./main
  ```
4. Clean build files:
  ```
  make clean
  ```
