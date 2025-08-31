# Memory Debugging Lab

## Overview
This project demonstrates three classic memory errors in C: Stack Overflow, Memory Leak, and Out of Memory. You can analyze each error using GDB.

## Usage
Build the project:
```
make all
```
Run with one of the following options:
```
./memory_lab stack_overflow    # Triggers stack overflow via recursion
./memory_lab memory_leak      # Triggers memory leak and eventually out of memory


## GDB Debugging Guide
### Stack Overflow
- Run: `gdb ./memory_lab`
- Set args: `set args stack_overflow`
- Run: `run`
- When segfault occurs:
  - View call stack: `bt`
  - The most repeated function is `cause_stack_overflow`, showing infinite recursion.
  - View current frame: `frame`

### Memory Leak & Out of Memory
- Run: `gdb ./memory_lab`
- Set args: `set args memory_leak` or `set args out_of_memory`
- Run: `run`
- To break when malloc fails:
  - Set breakpoint: `break cause_memory_leak_and_out_of_memory if ptr == 0`
  - When stopped, use `bt` to see which function and line caused the failure.
- The leak is caused by never freeing the allocated memory in the loop.

