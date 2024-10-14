#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "../include/DFS.h"
#include "../include/manejoArchivo.h"


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

    fclose(archivo); // Asegúrate de cerrar el archivo después de leer

    bool visitados[numero_nodos];
    for(int i = 0; i < numero_nodos; i++) visitados[numero_nodos] = false;

    if(DFS(matriz, visitados, numero_nodos)) printf("Grafo conexo \n");
    else printf("Grafo no conexo \n");

    for(int i = 0; i < numero_nodos; i++){
        free(matriz[i]);
    }
    free(matriz);
}