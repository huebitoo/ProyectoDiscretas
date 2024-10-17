#include <stdlib.h>
#include "../include/freeMemoria.h"

void liberarMemoria(int **grafo, const int numero_nodos){
    for(int i = 0; i < numero_nodos; i++){
        free(grafo[i]);
    }
    free(grafo);
}