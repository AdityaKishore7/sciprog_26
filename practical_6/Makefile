CC = gcc
CFLAGS = -Wall -Wextra -O2 -std=c99
TARGET = matmult_exe
OBJS = main.o matmult.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

main.o: main.c matmult.h
	$(CC) $(CFLAGS) -c $< -o $@

matmult.o: matmult.c matmult.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean
