#include "DFS.h"
#include <stdio.h>
#include <stdbool.h>
#define MAXBUFFER 1024

// FLAGS -1

int main(){
    char *ruta_archivo = "./grafo.txt";
    FILE *archivo = fopen(ruta_archivo, "r");
    char *BUFFER[MAXBUFFER];

    int contador;

    if(fgets(BUFFER, sizeof(BUFFER), archivo) != NULL) 
        contador = atoi(BUFFER);
    else return 0;

    while(fgets(BUFFER, sizeof(BUFFER), archivo) != NULL){
        
    }
}