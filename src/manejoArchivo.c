#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "../include/manejoArchivo.h"

void obtenerMatriz(int **matriz, char *BUFFER, int indice){
    matriz[indice] = NULL;
    char *token = strtok(BUFFER, ",: ");
    bool salto = true;
    int contador = 0;
    
    while(token != NULL){
        if(!salto){
            // Redimensiona la matriz correctamente en cada iteración
            int *temp = realloc(matriz[indice], (contador + 1) * sizeof(int));
            
            // Verifica si realloc falla
            if (temp == NULL) {
                free(matriz[indice]);
                perror("Error al asignar memoria con realloc");
                exit(EXIT_FAILURE);
            }
            matriz[indice] = temp;
            
            int numero = atoi(token);
            matriz[indice][contador++] = numero - 1; // Numero - 1 para que el vertice inicial sea 0 
            // printf("VERTICE VECINO: %d\n", matriz[indice][contador - 1]);
        } else salto = false;
        
        token = strtok(NULL, ",: ");
    }

    // Para finalizar, agregar -1 al final de la lista de adyacencias
    matriz[indice] = realloc(matriz[indice], (contador + 1) * sizeof(int)); // +1 para el -1
    matriz[indice][contador] = -1; // Marcador de fin de lista
}

int extraerNumeroNodos(FILE *archivo){
    int aux;
    if(!fscanf(archivo, "%d", &aux)){
        printf("Numero de nodos invalidos");
        fclose(archivo);
    }
    return aux;
}

void insertarArchivo(char ruta_archivo[]){
    printf(YELLOW "Ingrese ruta archivo: " RESETCOLOR);
    scanf("%99s", ruta_archivo);
    return;
}

void solicitarArchivo(char ruta_archivo[]){
    bool insertar_archivo = false;
    while(!insertar_archivo){
        insertarArchivo(ruta_archivo);
        if(ruta_archivo != NULL) insertar_archivo = true;
    }
    return;
}