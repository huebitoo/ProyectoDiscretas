#pragma once
#include <stdbool.h>

/**
 * @brief Metodo para analizar una conexidad simple, o sea, que no haya vertices aislados
 * @param grafo Lista de adyacencia
 * @param numero_nodos Numero de nodos
 * @return Retorna true si es conexo, false si es disconexo
 * @note Le puse conexidad simple personalmente, pero no tiene nombre como tal
 */
bool conexidadSimple(int **grafo, const int numero_nodos);

/**
 * @brief Metodo para analizar numero de vecinos validos
 * @param grafo Lista de adyacencia
 * @param numero_nodos Numero de nodos
 */
bool vecinosValidos(int **grafo, const int numero_nodos);