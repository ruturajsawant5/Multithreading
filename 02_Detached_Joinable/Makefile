CC = gcc
CFLAGS = -g
LDFLAGS = -lpthread

SRC = joinable.c
OBJ = joinable.o
EXE = joinable.exe

all: $(EXE)

$(EXE): $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)

$(OBJ): $(SRC)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(EXE)