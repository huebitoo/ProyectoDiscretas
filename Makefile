TARGET = main

CC = gcc

CFLAGS = -Wall -g 

OBJDIR = obj
SRCDIR = src
OBJ = $(OBJDIR)/main.o $(OBJDIR)/funciones.o

# Crear el directorio de objetos si no existe
$(OBJDIR):
	mkdir -p $(OBJDIR)

$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET) $(CFLAGS)

# Main
$(OBJDIR)/main.o: $(SRCDIR)/main.c $(SRCDIR)/funciones.h | $(OBJDIR)
	$(CC) -c $(SRCDIR)/main.c -o $@ $(CFLAGS)

# Funciones
$(OBJDIR)/funciones.o: $(SRCDIR)/funciones.c $(SRCDIR)/funciones.h | $(OBJDIR)
	$(CC) -c $(SRCDIR)/funciones.c -o $@ $(CFLAGS)

run:
	./$(TARGET)

clean:
	rm -f obj/*.o $(TARGET)
