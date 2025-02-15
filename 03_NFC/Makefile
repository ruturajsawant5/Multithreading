# Compiler and flags
CC = gcc
CFLAGS = -g -c
LDFLAGS = -lpthread

# Directories for each module
NOTIF_DIR = notif
UTILS_DIR = utils
RT_DIR = rt
GLTHREAD_DIR = gluethread

# Source files
SRCS = $(NOTIF_DIR)/notif.c \
       $(UTILS_DIR)/utils.c \
       $(RT_DIR)/rt.c \
       threaded_subsciber.c \
       rtm_publisher.c \
       $(GLTHREAD_DIR)/glthread.c

# Object files
OBJS = $(SRCS:.c=.o)

# Include directories
INCLUDES = -I$(NOTIF_DIR) -I$(UTILS_DIR) -I$(RT_DIR) -I$(GLTHREAD_DIR)

# Output executable
OUT = main.exe

# Default target
all: $(OUT)

# Linking the object files into the executable
$(OUT): $(OBJS)
	$(CC) $(OBJS) -o $(OUT) $(LDFLAGS)

# Rule to compile source files into object files
$(NOTIF_DIR)/%.o: $(NOTIF_DIR)/%.c
	$(CC) $(CFLAGS) $(INCLUDES) $< -o $@

$(UTILS_DIR)/%.o: $(UTILS_DIR)/%.c
	$(CC) $(CFLAGS) $(INCLUDES) $< -o $@

$(RT_DIR)/%.o: $(RT_DIR)/%.c
	$(CC) $(CFLAGS) $(INCLUDES) $< -o $@

threaded_subsciber.o: threaded_subsciber.c
	$(CC) $(CFLAGS) $(INCLUDES) $< -o $@

rtm_publisher.o: rtm_publisher.c
	$(CC) $(CFLAGS) $(INCLUDES) $< -o $@

$(GLTHREAD_DIR)/%.o: $(GLTHREAD_DIR)/%.c
	$(CC) $(CFLAGS) $(INCLUDES) $< -o $@

# Clean up build artifacts
clean:
	rm -f $(OUT) $(OBJS)