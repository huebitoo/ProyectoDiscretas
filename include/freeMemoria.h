#pragma once

/**
 * @brief Metodo para liberar memoria de la lista de adyacencia
 * @param grafo Lista de adyacencia
 * @param numero_nodos Numero de nodos del grafo
 */
void liberarMemoria(int **grafo, const int numero_nodos);

/**
 * @brief Metodo para liberar memoria de la lista de visitados
 * @param visitados Lista con los nodos visitados
 */
void liberarMemoriaVisitados(bool *grafo);