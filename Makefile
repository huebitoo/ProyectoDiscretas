TARGET = main

CC = gcc

CFLAGS = -Wall -g 

OBJDIR = obj
SRCDIR = src
OBJ = $(OBJDIR)/main.o $(OBJDIR)/funciones.o

$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET) $(CFLAGS)

$(OBJDIR)/main.o: $(SRCDIR)/main.c $(SRCDIR)/funciones.h | $(OBJDIR)
	$(CC) -c $(SRCDIR)/main.c -o $@ $(CFLAGS)

$(OBJDIR)/funciones.o: $(SRCDIR)/funciones.c $(SRCDIR)/funciones.h | $(OBJDIR)
	$(CC) -c $(SRCDIR)/funciones.c -o $@ $(CFLAGS)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(OBJDIR)/*.o $(TARGET)

