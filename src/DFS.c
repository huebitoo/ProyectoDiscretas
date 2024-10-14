#include <stdio.h>
#include "DFS.h"
#include <stdlib.h>
#include <stdbool.h>

// Struct vector
struct {
    int indice; // Ultimo elemento
    int tamaño_vector;
    int *vector; // Pila
} typedef Pila;

// Constructor Pila
void constructorPila(Pila *pila){
    pila->indice = -1;
    pila->tamaño_vector = 0;
    pila->vector = NULL;
}

// Metodo insertar a la pila
int insertElemento(Pila *pila, int numero){
    if(pila->indice == pila->tamaño_vector - 1) 
        pila->vector = (int*) realloc(pila->vector, (++pila->tamaño_vector) * sizeof(int));
    
    if (pila->vector != NULL){
        pila->vector[++pila->indice] = numero;
        return 0;
    }
    else return 1;
}

// Retorna ultimo valor y decrementa el indice. Indice -1 = lista vacia
int quitarElemento(Pila *pila){
    return pila->vector[pila->indice--];
}

// Pila vacía
bool vaciaPila(Pila *pila){
    return pila->indice == -1;
}

// Algoritmo DFS

int DFS(int **grafo, int numero_nodos){
    Pila pila;

    bool visitados[numero_nodos];
    for(int i = 0; i < numero_nodos; i++)
        visitados[i] = false;

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