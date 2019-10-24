CC = g++
CFLAGS = -c
OBJ = tp2

all: $(OBJ)

$(OBJ): main.o ilhas.o
		$(CC) main.o ilhas.o -o $(OBJ)

main.o: main.cpp
		$(CC) $(CFLAGS) main.cpp

ilhas.o: ilhas.cpp
		$(CC) $(CFLAGS) ilhas.cpp
		
clean:
		rm -rf *.o $(OBJ)

