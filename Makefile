# Makefile for compiling main.c and readLatin.c into an executable named 're'

CC = gcc
CFLAGS = -Wall -Wextra -Werror
TARGET = re
SOURCES = main.c readLatin.c LatinSquareMethods.c

all: $(TARGET)

$(TARGET): $(SOURCES)
	$(CC) $(CFLAGS) $(SOURCES) -o $(TARGET)

clean:
	rm -f $(TARGET)
