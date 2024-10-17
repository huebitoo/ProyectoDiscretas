#pragma once

#include <stdbool.h>
#include "DFS.h"

#define RESETCOLOR   "\033[0m"   // Restablece el color
#define RED     "\033[31m"  // Rojo
#define GREEN   "\033[32m"  // Verde
#define YELLOW  "\033[33m"  // Amarillo
#define BLUE    "\033[34m"  // Azul

int kConexidad(int **grafo, const int numero_nodos, bool *visitados, int *conexidad);

bool modificarVisitados(bool *visitados, int primer_indice, int segundo_indice, int tercer_indice, int cuarto_indice, int *conexidad);

void cambiarVisitados(bool *visitados, int numero_nodos);