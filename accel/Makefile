# Makefile for ADXL345 I2C program

# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -Wextra

# Linker flags
LDFLAGS =

# Source files
SRCS = ADXL345.c

# Output executable
TARGET = ADXL345

# Default target
all: $(TARGET)
	@$(MAKE) run

# Build target
$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) -o $(TARGET) $(LDFLAGS)

# Clean up build files
clean:
	rm -f $(TARGET)

# Run the executable
run: $(TARGET)
	./$(TARGET)

.PHONY: all clean run
