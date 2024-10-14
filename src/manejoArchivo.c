#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "manejoArchivo.h"

void obtenerMatriz(char *BUFFER){
    char *token = strtok(BUFFER, ",: ");

    while(token != NULL){
        printf("%s \n", token);
        token = strtok(NULL, ",: ");
    }
}