#pragma once

#include <stdbool.h>
#include "DFS.h"
#include "colores.h"

/**
 * @brief Metodo para analizar la k-conexidad de la lista de adyacencia
 * @param grafo Lista de adyacencia
 * @param numero_nodos Numero de nodos
 * @param visitados Lista con los nodos visitados
 * @param conexidad Indica la k-conexidad
 * @return Retorna 0 si es k-conexo, en caso contrario retorna 1
 */
int kConexidad(int **grafo, const int numero_nodos, bool *visitados, int *conexidad);

/**
 * @brief Valida las combinaciones posibles de eliminar nodos
 * @param visitados Lista de visitados
 * @param primer_indice Primer indice
 * @param segundo_indice Segundo indice
 * @param tercer_indice Tercer indice
 * @param cuarto_indice Cuarto indice
 * @param conexidad Indica la conexidad
 * @return Retorna true si es posible al combinacion y false si no lo es
 */
bool modificarVisitados(bool *visitados, int primer_indice, int segundo_indice, int tercer_indice, int cuarto_indice, int *conexidad);

/**
 * @brief Metodo para volver a los visitados en falso
 * @param visitados Lista de visitados
 * @param numero_nodos Numero de nodos
 */
void cambiarVisitados(bool *visitados, int numero_nodos);