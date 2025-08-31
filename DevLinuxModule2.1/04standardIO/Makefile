CC = gcc
CFLAGS = -Wall -o0 -g
TARGET = main
SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -g -o $@ $^

clean:
	rm -f $(TARGET) *.o *.txt *.exe *.vscode