# Decorator Pattern C Example

This project demonstrates the Decorator design pattern in C with a coffee shop example. You can create a basic beverage and decorate it with additional components such as milk.

## Project Structure
```
decorator-pattern-c  
├── inc  
│   ├── beverage.h  
│   ├── beverageDecorator.h  
│   ├── coffee.h  
│   └── milkDecorator.h  
├── src  
│   ├── coffee.c  
│   └── milkDecorator.c  
├── Makefile  
├── main.c  
└── README.md  
```
## Build and Run Instructions

1. **Build the project**  
   make all

2. **Clean the project**  
   make clean

## Decorator Pattern Overview

- `beverage`: Interface defining basic operations for beverages.
- `coffee`: Concrete implementation for coffee beverages.
- `milkDecorator`: Decorator that adds extra functionality (price and description) to beverages.

This design pattern allows you to flexibly extend the functionality of objects without modifying the original source code.