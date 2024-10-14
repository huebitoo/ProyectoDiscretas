#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "DFS.h"
#include "manejoArchivo.h"


#define MAXBUFFER 1024

// FLAGS -1

int main(){
    char *ruta_archivo = "./grafo.txt";
    FILE *archivo = fopen(ruta_archivo, "r");
    char BUFFER[MAXBUFFER];
    int numero_nodos, contador_indice = 0; 

    // Cantidad de nodos se guarda en numero_nodos
    if(!fscanf(archivo, "%d", &numero_nodos)){
        printf("Numero de nodos invalidos");
        fclose(archivo);
        return EXIT_FAILURE;
    }
    // Saltar el primer numero
    fgets(BUFFER, sizeof(BUFFER), archivo);
        
    // Declaracion con memoria dinamica
    int **matriz = malloc(numero_nodos * sizeof(int *));
    for(int i = 0; i < numero_nodos; i++){
        matriz[i] = NULL;
    }

    while(fgets(BUFFER, sizeof(BUFFER), archivo) != NULL && contador_indice < numero_nodos){
        obtenerMatriz(matriz, BUFFER, contador_indice);
        contador_indice++;
    }

    for(int i = 0; i < numero_nodos; i++){
        for(int j = 0; matriz[i][j] != -1; j++){
            printf("vertice %d: %d \n", i + 1, matriz[i][j]);
        }
    }

    fclose(archivo); // Asegúrate de cerrar el archivo después de leer

    printf("antes del DFS \n");

    if(DFS(matriz, numero_nodos)) printf("Grafo conexo \n");
    else printf("Grafo no conexo \n");

    // printf("despues del DFS");

    // for(int i = 0; i < numero_nodos; i++){
    //     free(matriz[i]);
    // }
    // free(matriz);
}