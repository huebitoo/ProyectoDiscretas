#include <stdlib.h>
#include <stdbool.h>
#include "../include/freeMemoria.h"

/**
 * @brief Metodo para liberar memoria de la lista de adyacencia
 * @param grafo Lista de adyacencia
 * @param numero_nodos Numero de nodos del grafo
 */
void liberarMemoria(int **grafo, const int numero_nodos){
    for(int i = 0; i < numero_nodos; i++){
        free(grafo[i]);
    }
    free(grafo);
}

/**
 * @brief Metodo para liberar memoria de la lista de visitados
 * @param visitados Lista con los nodos visitados
 */
void liberarMemoriaVisitados(bool *visitados){
    free(visitados);
}