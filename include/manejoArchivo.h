#pragma once
#include "colores.h"

/**
 * @brief Metodo para obtener la lista de adyacencia del archivo
 * @param mateiz Lista de adyacencia
 * @param BUFFER Buffer de las palabras
 * @param indice Indice de la lista de adyacencia
 */
void obtenerMatriz(int **matriz, char *BUFFER, int indice);

/**
 * @brief Metodo para extraer el numero de nodos
 * @param archivo Es un archivo
 * @return Retorna el numero de nodos
 */
int extraerNumeroNodos(FILE *archivo);

/**
 * @brief Metodo para insertar un archivo
 * @param ruta_archivo Ruta del archivo
 */
void insertarArchivo(char ruta_archivo[]);

/**
 * @brief Solicita el archivo
 * @param ruta_archivo Ruta del archivo
 */
void solicitarArchivo(char ruta_archivo[]);