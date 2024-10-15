TARGET = main

CC = gcc

CFLAGS = -Wall -g -O2

OBJDIR = obj
SRCDIR = src
INCLDIR = include
OBJ = $(OBJDIR)/main.o $(OBJDIR)/DFS.o $(OBJDIR)/manejoArchivo.o $(OBJDIR)/validaciones.o $(OBJDIR)/freeMemoria.o

$(OBJDIR)/main.o: $(SRCDIR)/main.c $(INCLDIR)/DFS.h $(INCLDIR)/manejoArchivo.h | $(OBJDIR)
	@$(CC) -c $(SRCDIR)/main.c -o $@ $(CFLAGS)

$(OBJDIR)/DFS.o: $(SRCDIR)/DFS.c $(INCLDIR)/DFS.h | $(OBJDIR)
	@$(CC) -c $(SRCDIR)/DFS.c -o $@ $(CFLAGS)

$(OBJDIR)/manejoArchivo.o: $(SRCDIR)/manejoArchivo.c $(INCLDIR)/manejoArchivo.h | $(OBJDIR)
	@$(CC) -c $(SRCDIR)/manejoArchivo.c -o $@ $(CFLAGS)

$(OBJDIR)/validaciones.o: $(SRCDIR)/validaciones.c $(INCLDIR)/validaciones.h | $(OBJDIR)
	@$(CC) -c $(SRCDIR)/validaciones.c -o $@ $(CFLAGS)
$(OBJDIR)/freeMemoria.o: $(SRCDIR)/freeMemoria.c $(INCLDIR)/freeMemoria.h | $(OBJDIR)
	@$(CC) -c $(SRCDIR)/freeMemoria.c -o $@ $(CFLAGS)


all: $(TARGET)

$(TARGET): $(OBJ)	| $(OBJDIR)
	@$(CC) $(OBJ) -o $(TARGET) $(CFLAGS)

$(OBJDIR):
	@mkdir -p $(OBJDIR)

run: $(TARGET)
	@./$(TARGET)

clean:
	@rm -rf $(OBJDIR) $(TARGET)

memoria: $(TARGET)
	@valgrind --leak-check=full --track-origins=yes ./$(TARGET)


