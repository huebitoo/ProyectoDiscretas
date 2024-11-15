import random
import networkx as nx
import os
from datetime import datetime

def generate_adjacency_list(num_vertices, edge_probability):
    # Crear un grafo aleatorio usando NetworkX
    G = nx.gnm_random_graph(num_vertices, int(num_vertices * (num_vertices - 1) / 2 * edge_probability))
    
    # Crear la lista de adyacencia
    adjacency_list = {i: [] for i in range(num_vertices)}

    for node in G.nodes():
        adjacency_list[node] = list(G.neighbors(node))

    return adjacency_list

def save_adjacency_list_to_file(adjacency_list, folder):
    # Crear la carpeta "grafos" si no existe
    if not os.path.exists(folder):
        os.makedirs(folder)
    
    # Obtener la fecha actual para el nombre del archivo
    current_time = datetime.now().strftime("%Y-%m-%d_%H-%M-%S")
    filename = os.path.join(folder, f"grafo_{current_time}.txt")
    
    with open(filename, 'w') as f:
        # Escribir el número de vértices
        f.write(f"{len(adjacency_list)}\n")
        
        # Escribir la lista de adyacencia en el formato deseado
        for node in sorted(adjacency_list.keys()):
            # Convertir la lista de vecinos a un formato de texto
            neighbors = sorted(adjacency_list[node])  # Ordenar los vecinos
            neighbors_str = ", ".join(str(neighbor + 1) for neighbor in neighbors)  # Convertir a 1-indexed
            f.write(f"{node + 1}: {neighbors_str}\n")  # Escribir nodo con sus vecinos
    
    print(f"La lista de adyacencia se ha guardado en '{filename}'.")

# Parámetros
num_vertices = 30  # Número de vértices (puedes cambiarlo)
edge_probability = 0.5  # Probabilidad de que se forme una arista entre dos vértices
folder = 'grafos'  # Carpeta donde se guardará el archivo

# Generar la lista de adyacencia
adjacency_list = generate_adjacency_list(num_vertices, edge_probability)

# Guardar la lista de adyacencia en el archivo
save_adjacency_list_to_file(adjacency_list, folder)
