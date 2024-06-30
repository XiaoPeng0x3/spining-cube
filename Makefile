# Makefile for the project

# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -g

# Linker flags
LDFLAGS = -lm

# Source files directory
SRCDIR = src

# Object files directory
OBJDIR = obj

# Executable name
TARGET = main

# Source files
SRC = $(SRCDIR)/calc_coordinate.c $(SRCDIR)/calc_surface.c $(SRCDIR)/main.c

# Object files
OBJ = $(SRC:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

# Include directories
INCLUDES = -I$(SRCDIR)

# Create object directory if not exists
$(shell mkdir -p $(OBJDIR))

# Default target
all: $(TARGET)

# Build target
$(TARGET): $(OBJ)
	@echo "Linking..."
	$(CC) $(CFLAGS) $(OBJ) $(LDFLAGS) -o $@

# Build object files
$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@echo "Compiling $<..."
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Clean target
clean:
	rm -rf $(OBJDIR) $(TARGET)

# Phony targets
.PHONY: all clean
