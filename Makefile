###############################################
# Makefile for compiling the Latin Square Solver project
# 'make' builds the executable file 'latinsolver'
# 'make doxy' builds the project documentation with Doxygen
# 'make all' builds the project and generates the documentation
# 'make clean' removes all .o, executable, and doxy log
###############################################

PROJ = latinsolver            # name of the executable
CC = gcc                      # compiler
DOXYGEN = doxygen             # doxygen binary
CFLAGS = -std=c99 -Wall -O -Wuninitialized -Wunreachable-code -pedantic
LFLAGS = -lm                  # additional flags for linking math library

# source files and object files
C_FILES := $(wildcard *.c)    # all .c files in the directory
OBJS := $(patsubst %.c, %.o, $(C_FILES))

# Build the executable from object files
$(PROJ): $(OBJS)
	$(CC) $(LFLAGS) -o $(PROJ) $(OBJS)

# Compile each .c file into an object file
.c.o:
	$(CC) $(CFLAGS) -c $<

# Build project and documentation
all: $(PROJ) doxy

# Generate Doxygen documentation
doxy:
	$(DOXYGEN) doxygen.conf &> doxygen.log

# Clean up compiled files and logs
clean:
	rm -rf *.o doxygen.log html $(PROJ)
