#pragma once

/**
 * @brief Prepara los valores iniciales
 * @param visitados Lista de visitados
 * @param numero_nodos Numero de nodos
 * @param ruta_archivo Ruta del archivo
 * @param matriz Lista de adyacencia
 * @note Este metodo se hizo mas que nada para limpiar el main
 */
void prepararValoresIniciales(bool **visitados, int *numero_nodos, char *ruta_archivo, int ***matriz);

/**
 * @brief Limpia la lista de los nodos visitados
 * @param visitados Lista de visitados
 * @param numero_nodos Numero de nodos
 * @note Solo se implementó para poder limpiar la lisat de visitados y evitar errores
 */
void limpiarVisitados(bool *visitados, const int numero_nodos);