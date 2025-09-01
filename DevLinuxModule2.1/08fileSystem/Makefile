CC = gcc
CFLAGS = -Wall -o0 -g -I./inc
TARGET = main
SRCS = $(wildcard *.c) $(wildcard src/*.c)
OBJS = $(SRCS:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -g -o $@ $^

clean:
	rm -f $(TARGET) *.o *.txt *.exe *.vscode src/*.o inc/*.o