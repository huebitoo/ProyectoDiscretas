#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "../include/DFS.h"
#include "../include/manejoArchivo.h"
#include "../include/validaciones.h"
#include "../include/freeMemoria.h"
#include "../include/grados.h"
#include "../include/k-conexo.h"

#define RESETCOLOR   "\033[0m"   // Restablece el color
#define RED     "\033[31m"  // Rojo
#define GREEN   "\033[32m"  // Verde
#define YELLOW  "\033[33m"  // Amarillo
#define BLUE    "\033[34m"  // Azul


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
            if(DFS(matriz, visitados, numero_nodos)) printf(BLUE "Grafo conexo \n" RESETCOLOR);
            else printf(RED "Grafo no conexo \n" RESETCOLOR);

            printf(YELLOW "Grado max: %d \n" RESETCOLOR, gradoMax(matriz, numero_nodos));
            printf(YELLOW "Grado min: %d \n" RESETCOLOR, gradoMin(matriz, numero_nodos));

            kConexidad(matriz, numero_nodos, visitados);

        }
        else printf(RED "Vecinos no validos\n" RESETCOLOR);
    } 
    else printf(RED "Grafo no conexo\n" RESETCOLOR);
    
    // Liberación de memoria
    liberarMemoria(matriz, numero_nodos);
}