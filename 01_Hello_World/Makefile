CC = gcc
CFLAGS = -g
LDFLAGS = -lpthread

SRC = hello_world.c
OBJ = hello_world.o
EXE = hello_world.exe

all: $(EXE)

$(EXE): $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)

$(OBJ): $(SRC)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(EXE)