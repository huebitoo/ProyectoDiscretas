#include <stdio.h>
#include "../include/DFS.h"
#include <stdlib.h>
#include <stdbool.h>


void constructorPila(Pila *pila){
    pila->indice = -1;
    pila->tamaño_vector = 0;
    pila->vector = NULL;
}

/**
 * @brief Inserta un elemento a la Pila
 * @param pila Pila que usaremos
 * @param numero Numero que insertaremos en la pila
 * @return Retorna 0 si se inserto con exito, 0 en caso contrario
 */
int insertElemento(Pila *pila, int numero){
    if(pila->indice == pila->tamaño_vector - 1) 
        pila->vector = (int*) realloc(pila->vector, (++pila->tamaño_vector) * sizeof(int));
    
    if (pila->vector != NULL){
        pila->vector[++pila->indice] = numero;
        return 0;
    }
    else return 1;
}

/**
 * @brief Quita un elemento de la pila
 * @param pila Pila a la que le quitaremos un elemento
 * @return Retorna el numero que sacamos 
 */
int quitarElemento(Pila *pila){
    return pila->vector[pila->indice--];
}

/**
 * @brief Verifica si la pila está vacia
 * @param pila Pila donde verificaremos esto
 * @return retorna si la pila está vacia o no
 */
bool vaciaPila(Pila *pila){
    return pila->indice == -1;
}

int DFS(int **grafo, bool *visitados, int numero_nodos){
    Pila pila;

    constructorPila(&pila);
    insertElemento(&pila, 0);

    // Mientras no esté vacia la pila
    while(!vaciaPila(&pila)){
        int nodo = quitarElemento(&pila);
        visitados[nodo] = true;
        
        for(int i = 0; grafo[nodo][i] != -1; i++){
            if(!visitados[grafo[nodo][i]])
                insertElemento(&pila, grafo[nodo][i]);
        }
    }
    
    for(int i = 0; i < numero_nodos; i++){
        if(visitados[i] == false) return 0;
    }
    return 1;
}