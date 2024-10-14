TARGET = main

CC = gcc

CFLAGS = -Wall -g 

OBJDIR = obj
SRCDIR = src
OBJ = $(OBJDIR)/main.o $(OBJDIR)/DFS.o $(OBJDIR)/manejoArchivo.o

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(OBJDIR)/main.o: $(SRCDIR)/main.c $(SRCDIR)/DFS.h $(SRCDIR)/manejoArchivo.h | $(OBJDIR)
	$(CC) -c $(SRCDIR)/main.c -o $@ $(CFLAGS)

$(OBJDIR)/DFS.o: $(SRCDIR)/DFS.c $(SRCDIR)/DFS.h | $(OBJDIR)
	$(CC) -c $(SRCDIR)/DFS.c -o $@ $(CFLAGS)

$(OBJDIR)/manejoArchivo.o: $(SRCDIR)/manejoArchivo.c $(SRCDIR)/manejoArchivo.h | $(OBJDIR)
	$(CC) -c $(SRCDIR)/manejoArchivo.c -o $@ $(CFLAGS)

compile: $(OBJ)
	$(CC) $(OBJ) -o $(TARGET) $(CFLAGS)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(OBJDIR)/*.o $(TARGET)

