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
    int numero_nodos, contador_indice = 0, operacion, conexidad; 
    
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

    // Rellenar los visitados
    bool visitados[numero_nodos];
    for(int i = 0; i < numero_nodos; i++) visitados[numero_nodos] = false;

    // Cerrar el archivo
    fclose(archivo); 

    // Inicio menú con las selecciones
    while(1){
        printf(BLUE "\t\tMATRIZ\n" RESETCOLOR);
        printf(YELLOW "(1) Conexidad\n" RESETCOLOR);
        printf(YELLOW "(2) Grado máximo y minimo\n" RESETCOLOR);
        printf(YELLOW "(3) K-conexidad del grafo\n" RESETCOLOR);
        printf(YELLOW "(4) Ingresar grafo\n" RESETCOLOR);
        printf(YELLOW "(5) Salir\n\n" RESETCOLOR);
        printf(YELLOW "Ingrese operación: " RESETCOLOR);
        scanf("%d", &operacion);

        system("clear");

        switch(operacion){
            case 1:
                if(conexidadSimple(matriz, numero_nodos)){
                    if(DFS(matriz, visitados, numero_nodos)){
                        printf(BLUE "Grafo conexo \n\n\n" RESETCOLOR);
                        break;
                    }
                }
                else printf(RED "Grafo no conexo \n\n\n" RESETCOLOR);
                break;

            case 2:
                printf(YELLOW "Grado max:" GREEN "%d \n" RESETCOLOR, gradoMax(matriz, numero_nodos));
                printf(YELLOW "Grado min:" GREEN "%d \n\n\n" RESETCOLOR, gradoMin(matriz, numero_nodos));
                break;
            
            case 3:
                if(conexidadSimple(matriz, numero_nodos)){
                    if(kConexidad(matriz, numero_nodos, visitados, &conexidad)){
                        printf(YELLOW "El grafo es " BLUE "%d-conexo\n\n\n" RESETCOLOR, conexidad);
                        break;
                    }
                    printf(YELLOW "El grafo es " BLUE "%d-conexo\n\n\n" RESETCOLOR, conexidad);
                    break;
                }
                else printf(RED "Grafo  0-conexo \n\n\n" RESETCOLOR);
                break;
            
            case 4:
                printf("En proceso... \n\n\n");
                break;
            
            case 5:
                return 0;

            default:
                printf(RED "¡Número invalido, por favor reingrese!" RESETCOLOR);
                break;
        }

    }
    
    // Liberación de memoria
    liberarMemoria(matriz, numero_nodos);
}