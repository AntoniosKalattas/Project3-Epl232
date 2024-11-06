# Makefile for compiling main.c and readLatin.c into an executable named 're'

CC = gcc
CFLAGS = -Wall
TARGET = re
SOURCES = main.c readLatin.c LatinSquareMethods.c stack.c

all: $(TARGET)

$(TARGET): $(SOURCES)
	$(CC) $(CFLAGS) $(SOURCES) -o $(TARGET)

clean:
	rm -f $(TARGET)
