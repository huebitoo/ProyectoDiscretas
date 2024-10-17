#pragma once

#include <stdbool.h>

typedef struct {
    int indice;
    int tamaño_vector;
    int *vector;
} Pila;

int DFS(int **grafo, bool *visitados, int numero_nodos);