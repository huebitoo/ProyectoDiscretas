#include <stdio.h>

int gradoMax(int **grafo, const int numero_nodos){
    int contador, grado_max = 0;
    for(int i = 0; i < numero_nodos; i++){
        contador = 0;
        for(int j = 0; grafo[i][j] != -1; j++) contador++;

        grado_max = (contador > grado_max) ? contador : grado_max; // If ternario para el valor del grado máximo
        
        contador = 0;
    }
    return grado_max;
}

int gradoMin(int **grafo, const int numero_nodos){
    int contador, grado_min = numero_nodos - 1;
    for(int i = 0; i < numero_nodos; i++){
        contador = 0;
        for(int j = 0; grafo[i][j] != -1; j++) contador++;

        grado_min = (contador < grado_min) ? contador : grado_min; // If ternario para el valor del grado máximo
        
        contador = 0;
    }
    return grado_min;
}