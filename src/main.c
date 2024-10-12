#include "DFS.h"
#include <stdio.h>
#include <stdbool.h>
#define MAXBUFFER 1024

// FLAGS -1

int main(){
    char *ruta_archivo = "./grafo.txt";
    FILE *archivo = fopen(ruta_archivo, "r");
    char BUFFER[MAXBUFFER];
    
    int numero_nodos; 

    // Cantidad de nodos se guarda en numero_nodos
    if(!fscanf(archivo, "%d", &numero_nodos)){
        printf("Numero de nodos invalidos");
        return 0;
    } 

    printf("Numero de nodos: %d \n", numero_nodos);

    while(fgets(BUFFER, sizeof(BUFFER), archivo) != NULL){
        printf("%s\n", BUFFER);
    }
    printf("\n");
}