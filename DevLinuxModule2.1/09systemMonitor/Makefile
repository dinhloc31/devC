# Makefile for System Information Monitor
CC = gcc
CFLAGS = -Wall -Wextra -std=c99
TARGET = system_monitor
SOURCES = main.c systemInfor.c

# Default target
all: $(TARGET)

# Build the main executable
$(TARGET): $(SOURCES)
	$(CC) $(CFLAGS) -o $(TARGET) $(SOURCES)

# Clean up build files
clean:
	rm -f $(TARGET)

# Install (copy to /usr/local/bin)
install: $(TARGET)
	sudo cp $(TARGET) /usr/local/bin/

# Uninstall
uninstall:
	sudo rm -f /usr/local/bin/$(TARGET)

# Run the program
run: $(TARGET)
	./$(TARGET)

# Debug build
debug: CFLAGS += -g -DDEBUG
debug: $(TARGET)

# Help
help:
	@echo "Available targets:"
	@echo "  all      - Build the system monitor (default)"
	@echo "  clean    - Remove build files"
	@echo "  run      - Build and run the program"
	@echo "  debug    - Build with debug information"
	@echo "  install  - Install to /usr/local/bin"
	@echo "  uninstall- Remove from /usr/local/bin"
	@echo "  help     - Show this help message"

.PHONY: all clean install uninstall run debug help
