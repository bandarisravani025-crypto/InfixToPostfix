
CC = gcc
CFLAGS = -Wall -Wextra
TARGET = infix
OBJ = main.o declaration.o

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

main.o: main.c defines.h
	$(CC) $(CFLAGS) -c main.c

declaration.o: declaration.c defines.h
	$(CC) $(CFLAGS) -c declaration.c

clean:
	rm -f $(OBJ) $(TARGET) a.out

