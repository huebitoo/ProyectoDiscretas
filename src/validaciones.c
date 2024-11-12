#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../include/validaciones.h"

bool conexidadSimple(int **grafo, const int numero_nodos){
    if (numero_nodos == 1) return true;
    int contador;
    for(int i = 0; i < numero_nodos; i++){
        contador = 0;
        for(int j = 0; grafo[i][j] != -1; j++)
            contador++;
        if(contador == 0) return false;
    }
    return true;
}

bool vecinosValidos(int **grafo, const int numero_nodos){
    int contador;
    for(int i = 0; i < numero_nodos; i++){
        contador = 0;
        for(int j = 0; grafo[i][j] != -1; j++)
            contador++;
        if(contador >= numero_nodos) return false;
    }
    return true;
}
