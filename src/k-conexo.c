#include <stdio.h>
#include <stdbool.h>
#include <stdbool.h>
#include <stdlib.h>
#include "../include/DFS.h"
#include "../include/k-conexo.h"



// Tiene que ser hasta 4 conexo
int kConexidad(int **grafo, const int numero_nodos, bool *visitados, int *conexidad){
    *conexidad = 0;
    cambiarVisitados(visitados, numero_nodos);

    for(int i = 0; i < numero_nodos; i++){
        for(int j = 0; j < numero_nodos; j++){
            for(int k = 0; k < numero_nodos; k++){
                for(int l = 0; l < numero_nodos; l++){
                    if(modificarVisitados(visitados, i, j, k, l, conexidad)){
                        if(DFS(grafo, visitados, numero_nodos)) // Si es conexo
                            printf(YELLOW "Grafo conexo con %d, %d, %d, %d siendo %d-regular \n" RESETCOLOR, i, j, k, l, *conexidad);
                        else {
                            printf(YELLOW "Grafo no conexo con %d, %d, %d, %d siendo %d-regular \n" RESETCOLOR, i, j, k, l, *conexidad);
                            return 1;
                        }
                        cambiarVisitados(visitados, numero_nodos);
                    }

                }
            }
        }
    }
    *conexidad = 4;
    return 0;    
}

bool modificarVisitados(bool *visitados, int primer_indice, int segundo_indice, int tercer_indice, int cuarto_indice, int *conexidad){
    if(primer_indice == 0){
        if(segundo_indice == 0){
            if(tercer_indice == 0){
                visitados[cuarto_indice] = true;
                *conexidad = 1;
                return true;
            }
            if(cuarto_indice != tercer_indice){
                visitados[cuarto_indice] = true;
                visitados[tercer_indice] = true;
                *conexidad = 2;
                return true;
            }
            return false;
        }
        if(cuarto_indice != tercer_indice && tercer_indice != segundo_indice && segundo_indice != cuarto_indice){
            visitados[cuarto_indice] = true;
            visitados[tercer_indice] = true;
            visitados[segundo_indice] = true;
            *conexidad = 3;
            return true;
        }
        return false;
    }
    if(primer_indice != segundo_indice && primer_indice != tercer_indice && primer_indice != cuarto_indice && segundo_indice != tercer_indice && segundo_indice != cuarto_indice && tercer_indice != cuarto_indice){
        visitados[cuarto_indice] = true;
        visitados[tercer_indice] = true;
        visitados[segundo_indice] = true;
        visitados[primer_indice] = true;
        *conexidad = 4;
        return true;
    }
    return false;
}

void cambiarVisitados(bool *visitados, int numero_nodos){
    for(int i = 0; i < numero_nodos; i++){
        visitados[i] = false;
    }
}