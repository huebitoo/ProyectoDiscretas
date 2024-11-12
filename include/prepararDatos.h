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

void limpiarVisitados(bool *visitados, const int numero_nodos);