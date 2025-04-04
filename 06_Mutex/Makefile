# Compiler and flags
CC = gcc
CFLAGS = -g
LDFLAGS = -lpthread

# Targets and files
TARGETS = mutex_example.exe mutex_example_with_mutex.exe
OBJ_FILES = mutex_example.o mutex_example_with_mutex.o

# Default target
all: $(TARGETS)

# Compile the mutex_example.o
mutex_example.o: mutex_example.c
	$(CC) $(CFLAGS) -c mutex_example.c -o mutex_example.o

# Compile the mutex_example_with_mutex.o
mutex_example_with_mutex.o: mutex_example_with_mutex.c
	$(CC) $(CFLAGS) -c mutex_example_with_mutex.c -o mutex_example_with_mutex.o

# Link mutex_example.exe
mutex_example.exe: mutex_example.o
	$(CC) $(CFLAGS) mutex_example.o -o mutex_example.exe $(LDFLAGS)

# Link mutex_example_with_mutex.exe
mutex_example_with_mutex.exe: mutex_example_with_mutex.o
	$(CC) $(CFLAGS) mutex_example_with_mutex.o -o mutex_example_with_mutex.exe $(LDFLAGS)

# Clean up object files and executables
clean:
	rm -f $(OBJ_FILES) $(TARGETS)
