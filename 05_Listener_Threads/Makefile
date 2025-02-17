# Define compiler and flags
CC = gcc
CFLAGS = -g -c
LDFLAGS = -lpthread

# Object files
OBJS = network_utils.o udp_listener.o udp_sender.o

# Executables
EXECS = udp_listener.exe udp_sender.exe

# Default target
all: $(EXECS)

# Clean up object files and executables
.PHONY: clean
clean:
	rm -f *.o $(EXECS)

# Build listener_main.o
network_utils.o: network_utils.c
	$(CC) $(CFLAGS) network_utils.c -o network_utils.o

# Build listener_main.o
listener_main.o: listener_main.c
	$(CC) $(CFLAGS) listener_main.c -o listener_main.o

# Build udp_sender.o
udp_sender.o: udp_sender.c
	$(CC) $(CFLAGS) udp_sender.c -o udp_sender.o

# Build listener_main.exe
udp_listener.exe: udp_listener.o network_utils.o
	$(CC) -g udp_listener.o network_utils.o -o udp_listener.exe $(LDFLAGS)

# Build udp_sender.exe
udp_sender.exe: udp_sender.o network_utils.o
	$(CC) -g udp_sender.o network_utils.o -o udp_sender.exe $(LDFLAGS)