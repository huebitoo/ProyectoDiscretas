# Grafos: K-Conexidad de un grafo

### Integrantes

- [Javier Alejandro Campos Contreras](https://github.com/huebitoo "Javier Alejandro Campos Contreras") 
- [Jorge Alejandro Slimming Lagos](https://github.com/JorshSlimming "Jorge Alejandro Slimming Lagos")
- [Benjamin Alonso Henriquez Cid](https://github.com/ba-hc "Benjamin Alonso Henriquez Cid")

##

###  Indice 
- [Introducción del proyecto](#introducción)
- [Algoritmos usados para su desarrollo](#algoritmos-usados)
- [Compilación del código](#compilación)
- [Funcionamiento del código](#funcionamiento)

##

### Introducción
El problema dado consiste en analisis de grafos, donde nos pasaron una lista de adyacencia y debemos obtener las siguientes caracteristicas.

* Grados: Acá retornaremos los grados máximos y minimos que hay en el grafo.
* Conexidad: Esto nos retornará si el grafo es conexo o disconexo.
* K-Conexidad: Esto es un analisis mas profundo sobre la conexidad del grafo, donde nos indica hasta que punto puede ser, el grafo dado, conexo si uno va quitando vertices.

##

### Algoritmos usados
Se usó DFS para navegar sobre el grafo y estudiar su conexidad contando que ademas sirvió como algoritmo para eliminación de vertices. Se hizo un estudio del como al colocar un vertice visitado antes de ser llevado al DFS (Se supone que todos los vertices no deben estar visitados) podemos notar un comportamiento identico al "eliminar vertices".

##

### Compilación
El proyecto está distribuido en secciones (grafos, include, src y build) donde en cada parte del proyecto estan los archivos conrrespondientes. Para su compilación, solo necesita dejar el grafo (un archivo sin extension o txt) en la carpeta grafos.\
Para facilitar la compilación, se creo un archivo `Makefile` que consta con cierta particularidades.


* `make run`: Se encarga de crear los objetos (almacenados en la carpeta build), solo si es  necesario, para luego ejecutar el programa.
* `make clean`: Limpia los objetos y elimina el ejecutable. Normalmente se usa para compilar nuevamente el codigo en caso de algún cambio o simplemente para limpiar la carpeta de archivos innecesarios.
* `make memoria`: Esta instrucción fue hecha para el monitoreo de fugas de memoria.
* En caso de que el archivo make no compile, ejecute la siguiente instrucción desde la carpeta raíz ```gcc -Wall -g -O2 src/main.c src/DFS.c src/manejoArchivo.c src/validaciones.c src/freeMemoria.c src/grados.c src/k-conexo.c src/prepararDatos.c src/mostrargrafo.c -I include -o main``` y se creará un archivo llamado `main`el cual debe ejecutar con el comando `./main`. 

##

### Funcionamiento
El funcionamiento del código es simple. Al momento de ejecutarse, este le pedirá que ingrese un grafo donde usted solo debe colocar el nombre del archivo, ejemplo `grafo1` (sin extensión si no tiene extensión) o `matriz.txt` (con extensión) y luego le abrirá un menú con las siguientes características:

* **(1) Mostrar grafo:** como dice su numbre, ese solo desplegará el grafo con sus respectivos vertices vecinos.
* **(2) Conexidad:** Acá marcará si el grafo es conexo o no lo és.
* **(3) Grado máximo y minimo:** Se desplegará el grado máximo y minimo del grafo.
* **(4) K-Conexidad del grafo:** Mostrará la K-Conexidad del grafo entregado.
* **(5) Ingresar nuevo grafo:** Permite que dentro del mismo programa se pueda ingresar otro grafo.
* **(6) Salir:** Como dice el nombre, sale del programa.
