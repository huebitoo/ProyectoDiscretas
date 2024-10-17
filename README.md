# Grafos

- [Introducción](#introducción)
- [Algoritmos usados](#algoritmos-usados)
- [Compilación](#compilación)

### Introducción
El problema dado consiste en analisis de grafos, donde nos pasaron una lista de adyacencia y debemos obtener las siguientes caracteristicas.

* Grados: Acá retornaremos los grados máximos y minimos que hay en el grafo.
* Conexidad: Esto nos retornará si el grafo es conexo o disconexo.
* K-Conexidad: Esto es un analisis mas profundo sobre la conexidad del grafo, donde nos indica hasta que punto puede ser, el grafo dado, conexo si uno va quitando vertices.

### Algoritmos usados
Se usó DFS para navegar sobre el grafo y estudiar su conexidad contando que ademas sirvió como algoritmo para eliminación de vertices. Se hizo un estudio del como al colocar un vertice visitado antes de ser llevado al DFS (Se supone que todos los vertices no deben estar visitados) podemos notar un comportamiento identico al "eliminar vertices".

### Compilación
Para facilitar la compilación, se creo un archivo `Makefile` tiene cierta particularidades:
* `make run`: Se encarga de crear los objetos, solo de ser necesario, para luego ejecutar el programa.
* `make clean`: Limpia los objetos y elimina el ejecutable. Normalmente se usa para compilar nuevamente el codigo en caso de algún cambio o simplemente para limpiar la carpeta de archivos innecesarios.
* `make memoria`: Esta instrucción fue hecha para el monitoreo de fugas de memoria.
