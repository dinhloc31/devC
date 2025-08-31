#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void causeStackOverflow(int depth) 
{
    printf("Recursion depth: %d\n", depth);
    causeStackOverflow(depth + 1);
}

void causeMemoryLeakAndOutOfMemory() 
{
    size_t block_size = 1024*1024; // test 1MB per time
    size_t count = 0;

    while (1) 
    {
        void *ptr = malloc(block_size);
        if (!ptr) 
        {
            fprintf(stderr, "Out of memory after %zu MB allocated.\n", count);
            exit(EXIT_FAILURE);
        }
        count++;
    }
}

int main(int argumentCount, char *argumentValues[]) 
{
    if (argumentCount != 2) {
        printf("Usage: %s <stack_overflow|memory_leak>\n", argumentValues[0]);
        return 1;
    }

    if (strcmp(argumentValues[1], "stack_overflow") == 0) 
    {
        causeStackOverflow(1);
    } 
    else if (strcmp(argumentValues[1], "memory_leak") == 0) 
    {
        causeMemoryLeakAndOutOfMemory();
    } 
    else {
        printf("Unknown option: %s\n", argumentValues[1]);
        return 1;
    }
    return 0;
}
