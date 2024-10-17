#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "../include/DFS.h"
#include "../include/manejoArchivo.h"
#include "../include/validaciones.h"
#include "../include/freeMemoria.h"
#include "../include/grados.h"


#define MAXBUFFER 1024

// FLAGS -1

int main(){
    // Extraer datos importantes e inicializacion de variables
    char *ruta_archivo = "./grafo.txt";
    FILE *archivo = fopen(ruta_archivo, "r");
    char BUFFER[MAXBUFFER];
    int numero_nodos, contador_indice = 0; 
    
    // Extraer numero de nodos
    numero_nodos = extraerNumeroNodos(archivo);

    // Saltar el primer numero
    fgets(BUFFER, sizeof(BUFFER), archivo);
        
    // Declaracion con memoria dinamica
    int **matriz = malloc(numero_nodos * sizeof(int *));
    for(int i = 0; i < numero_nodos; i++){
        matriz[i] = NULL;
    }

    // Obtener la matriz
    while(fgets(BUFFER, sizeof(BUFFER), archivo) != NULL && contador_indice < numero_nodos){
        obtenerMatriz(matriz, BUFFER, contador_indice++);
    }

    // Cerrar el archivo
    fclose(archivo); 

    // Validar que no hayan vertices aislados
    if(conexidadSimple(matriz, numero_nodos)){
        
        // Validacion de si el grafo es valido
        if(vecinosValidos(matriz, numero_nodos)){
            
            // Rellenar los visitados
            bool visitados[numero_nodos];
            for(int i = 0; i < numero_nodos; i++) visitados[numero_nodos] = false;

            // Validación de si es conexo
            if(DFS(matriz, visitados, numero_nodos)) printf("Grafo conexo \n");
            else printf("Grafo no conexo \n");

            printf("Grado max: %d \n", gradoMax(matriz, numero_nodos));
            printf("Grado min: %d \n", gradoMin(matriz, numero_nodos));
        }
        else printf("Vecinos no validos\n");
    } 
    else printf("Grafo no conexo\n");
    
    // Liberación de memoria
    liberarMemoria(matriz, numero_nodos);
}