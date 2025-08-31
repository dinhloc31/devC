CC = gcc
CFLAGS = -Wall -g
TARGET = memory_lab
SRCS = memory_lab.c

all: $(TARGET)

$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f $(TARGET) *.o *.exe
