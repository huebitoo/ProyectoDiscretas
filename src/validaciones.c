#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../include/validaciones.h"

/**
 * @brief Metodo para analizar una conexidad simple, o sea, que no haya vertices aislados
 * @param grafo Lista de adyacencia
 * @param numero_nodos Numero de nodos
 * @return Retorna true si es conexo, false si es disconexo
 * @note Le puse conexidad simple personalmente, pero no tiene nombre como tal
 */
bool conexidadSimple(int **grafo, const int numero_nodos){
    int contador;
    for(int i = 0; i < numero_nodos; i++){
        contador = 0;
        for(int j = 0; grafo[i][j] != -1; j++)
            contador++;
        if(contador == 0) return false;
    }
    return true;
}

/**
 * @brief Metodo para analizar numero de vecinos validos
 * @param grafo Lista de adyacencia
 * @param numero_nodos Numero de nodos
 */
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
