TARGET = main

CC = gcc

CFLAGS = -Wall -g 

OBJDIR = obj
SRCDIR = src
OBJ = $(OBJDIR)/main.o $(OBJDIR)/funciones.o

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(OBJDIR)/main.o: $(SRCDIR)/main.c $(SRCDIR)/funciones.h | $(OBJDIR)
	$(CC) -c $(SRCDIR)/main.c -o $@ $(CFLAGS)

$(OBJDIR)/funciones.o: $(SRCDIR)/funciones.c $(SRCDIR)/funciones.h | $(OBJDIR)
	$(CC) -c $(SRCDIR)/funciones.c -o $@ $(CFLAGS)

compile: $(OBJ)
	$(CC) $(OBJ) -o $(TARGET) $(CFLAGS)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(OBJDIR)/*.o $(TARGET)

