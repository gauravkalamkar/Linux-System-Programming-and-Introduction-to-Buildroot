

# CROSS_COMPILE = aarch64-none-linux-gnu-
CC = $(CROSS_COMPILE)gcc

# Target binary and source
TARGET = writer
SRC = writer.c
OBJ = writer.o

# Default target: build the writer application
all: $(TARGET)

# Compile object file
$(OBJ): $(SRC)
	$(CC) $(CFLAGS) -c -o $@ $<

# Link to create the final executable
$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

# Clean target: remove binaries and object files
clean:
	rm -f $(TARGET) *.o