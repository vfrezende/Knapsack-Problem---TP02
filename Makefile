CC = g++
CFLAGS = -c -std=c++11
OBJ = tp2

all: $(OBJ)

$(OBJ): main.o ilhas.o
		$(CC) main.o ilhas.o -o $(OBJ)

main.o: main.cpp
		$(CC) $(CFLAGS) main.cpp -o main.o

ilhas.o: ilhas.cpp
		$(CC) $(CFLAGS) ilhas.cpp -o ilhas.o
		
clean:
		rm -rf *.o $(OBJ)
