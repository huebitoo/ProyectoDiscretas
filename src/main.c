#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "../include/DFS.h"
#include "../include/manejoArchivo.h"
#include "../include/validaciones.h"
#include "../include/freeMemoria.h"
#include "../include/grados.h"
#include "../include/k-conexo.h"
#include "../include/prepararDatos.h"

#define RESETCOLOR   "\033[0m"   // Restablece el color
#define RED     "\033[31m"  // Rojo
#define GREEN   "\033[32m"  // Verde
#define YELLOW  "\033[33m"  // Amarillo
#define BLUE    "\033[34m"  // Azul


#define MAXBUFFER 1024

int main(){
    // Extraer datos importantes e inicializacion de variables
    char ruta_prearchivo[MAXBUFFER], ruta_archivo[MAXBUFFER] = "./";
    int numero_nodos, operacion, conexidad, **matriz = NULL; 
    bool *visitados = NULL;

    // Solicitar archivo
    solicitarArchivo(ruta_prearchivo);
    
    // Concatenar
    strcat(ruta_archivo, ruta_prearchivo);

    // Manejar datos antes de ser usados
    prepararValoresIniciales(&visitados, &numero_nodos, ruta_archivo, &matriz);

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
                printf(RED "Grafo no conexo \n\n\n" RESETCOLOR);
                break;

            case 2:
                printf(YELLOW "Grado max:" GREEN " %d \n" RESETCOLOR, gradoMax(matriz, numero_nodos));
                printf(YELLOW "Grado min:" GREEN " %d \n\n\n" RESETCOLOR, gradoMin(matriz, numero_nodos));
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
                char ruta_prearchivo[MAXBUFFER] = "";
                char ruta_archivo[MAXBUFFER] = "./";

                // Solicitar archivo
                solicitarArchivo(ruta_prearchivo);

                // Concatenar
                strcat(ruta_archivo, ruta_prearchivo);

                // Preparar
                prepararValoresIniciales(&visitados, &numero_nodos, ruta_archivo, &matriz);

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