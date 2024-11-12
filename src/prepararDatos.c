#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "../include/manejoArchivo.h"

#define MAXBUFFER 1024

void prepararValoresIniciales(bool **visitados, int *numero_nodos, char *ruta_archivo, int ***matriz){
    int contador_indice = 0;
    char BUFFER[MAXBUFFER];

    FILE *archivo = fopen(ruta_archivo, "r");
    
    // Extraer numero de nodos
    *numero_nodos = extraerNumeroNodos(archivo);

    // Saltar el primer numero
    fgets(BUFFER, sizeof(BUFFER), archivo);
        
    // Declaracion con memoria dinamica
    *matriz = malloc(*numero_nodos * sizeof(int *));
    for(int i = 0; i < *numero_nodos; i++){
        (*matriz)[i] = NULL;
    }

    // Obtener la matriz
    while(fgets(BUFFER, sizeof(BUFFER), archivo) != NULL && contador_indice < *numero_nodos){
        obtenerMatriz(*matriz, BUFFER, contador_indice++);
    }

    // for(int i = 0; i < *numero_nodos; i++){
    //     for(int j = 0; (*matriz)[i][j] != -1; j++){
    //         printf("Hola %d: %d", i + 1, (*matriz)[i][j] + 1);
    //     }
    //     printf("\n");
    // }

    // Rellenar los visitados
    *visitados = malloc(*numero_nodos * sizeof(bool));
    for(int i = 0; i < *numero_nodos; i++) (*visitados)[i] = false;

    // Cerrar el archivo
    fclose(archivo);
    
}

void limpiarVisitados(bool *visitados, const int numero_nodos){
    for(int i = 0; i < numero_nodos; i++)
        visitados[i] = false;
}