#include <stdlib.h>
#include <stdbool.h>
#include "../include/freeMemoria.h"


void liberarMemoria(int **grafo, const int numero_nodos){
    for(int i = 0; i < numero_nodos; i++){
        free(grafo[i]);
    }
    free(grafo);
}

void liberarMemoriaVisitados(bool *visitados){
    free(visitados);
}