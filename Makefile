# Makefile

# Compilador
CC = gcc

# Opcion del compilador
CFLAGS = -Wall -g

# Archivos objeto
OBJS = main.o

# Nombre del ejecutable
TARGET = programa

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# Regla para generar main.o
main.o: main.c
	$(CC) $(CFLAGS) -c main.c

clean:
	del *.o programa.exe