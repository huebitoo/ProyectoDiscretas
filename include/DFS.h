#pragma once

#include <stdbool.h>

/** 
 * @brief Constructor de la pila
 * @param pila Pila para el DFS 
 */
typedef struct {
    int indice;
    int tamaño_vector;
    int *vector;
} Pila;

/**
 * @brief Algoritmo de busqueda profunda en grafos (DFS) y verificar conexidad
 * @param grafo Es la lista de adyacencia o matriz de adyacencia
 * @param visitados Es un array con todos los nodos que luego marcaremos como visitados
 * @param numero_nodos Indica el numero de nodos
 * @return Retorna 1 si el grafo es conexo, en caso contrario retorna 0
 */
int DFS(int **grafo, bool *visitados, int numero_nodos);