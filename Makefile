TARGET = main

CC = gcc

CFLAGS = -Wall -g -O2

OBJDIR = build
SRCDIR = src
INCLDIR = include
OBJ = $(OBJDIR)/main.o $(OBJDIR)/DFS.o $(OBJDIR)/manejoArchivo.o $(OBJDIR)/validaciones.o $(OBJDIR)/freeMemoria.o $(OBJDIR)/grados.o $(OBJDIR)/k-conexo.o $(OBJDIR)/prepararDatos.o $(OBJDIR)/mostrargrafo.o

$(OBJDIR)/main.o: $(SRCDIR)/main.c $(INCLDIR)/DFS.h $(INCLDIR)/manejoArchivo.h $(INCLDIR)/colores.h	| $(OBJDIR)
	@$(CC) -c $(SRCDIR)/main.c -o $@ $(CFLAGS)

$(OBJDIR)/DFS.o: $(SRCDIR)/DFS.c $(INCLDIR)/DFS.h | $(OBJDIR)
	@$(CC) -c $(SRCDIR)/DFS.c -o $@ $(CFLAGS)

$(OBJDIR)/manejoArchivo.o: $(SRCDIR)/manejoArchivo.c $(INCLDIR)/manejoArchivo.h	| $(OBJDIR)
	@$(CC) -c $(SRCDIR)/manejoArchivo.c -o $@ $(CFLAGS)

$(OBJDIR)/validaciones.o: $(SRCDIR)/validaciones.c $(INCLDIR)/validaciones.h	| $(OBJDIR)
	@$(CC) -c $(SRCDIR)/validaciones.c -o $@ $(CFLAGS)

$(OBJDIR)/freeMemoria.o: $(SRCDIR)/freeMemoria.c $(INCLDIR)/freeMemoria.h	| $(OBJDIR)
	@$(CC) -c $(SRCDIR)/freeMemoria.c -o $@ $(CFLAGS)

$(OBJDIR)/grados.o: $(SRCDIR)/grados.c $(INCLDIR)/grados.h	| $(OBJDIR)
	@$(CC) -c $(SRCDIR)/grados.c -o $@ $(CFLAGS)

$(OBJDIR)/k-conexo.o: $(SRCDIR)/k-conexo.c $(INCLDIR)/k-conexo.h $(INCLDIR)/colores.h	| $(OBJDIR)
	@$(CC) -c $(SRCDIR)/k-conexo.c -o $@ $(CFLAGS)

$(OBJDIR)/prepararDatos.o: $(SRCDIR)/prepararDatos.c $(INCLDIR)/prepararDatos.h $(INCLDIR)/manejoArchivo.h	| $(OBJDIR)
	@$(CC) -c $(SRCDIR)/prepararDatos.c -o $@ $(CFLAGS)

$(OBJDIR)/mostrargrafo.o: $(SRCDIR)/mostrargrafo.c $(INCLDIR)/mostrargrafo.h $(INCLDIR)/colores.h
	@$(CC) -c $(SRCDIR)/mostrargrafo.c -o $@ $(CFLAGS)




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


