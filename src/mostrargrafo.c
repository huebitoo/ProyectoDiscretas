#include <stdio.h>
#include "../include/colores.h"

void mostrarGrafo(int **grafo, int numero_nodos){
    int contador = 0;
    for(int i = 0; i < numero_nodos; i++){
        printf(GREEN "(%d) : " RESETCOLOR, contador + 1);
        for(int j = 0; grafo[i][j] != -1; j++)
            printf(YELLOW "%d   " RESETCOLOR, grafo[i][j] + 1);
        contador++;
        printf("\n");
    }
}