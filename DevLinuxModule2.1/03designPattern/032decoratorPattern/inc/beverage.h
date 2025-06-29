
#ifndef BEVERAGE_H
#define BEVERAGE_H

typedef struct beverage 
{
    float (*getPrice)(struct beverage* self);
    const char* (*getDescription)(struct beverage* self);
} beverage;

#endif
