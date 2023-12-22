# Taller3

Integrantes: 
Donovan Alexander Almendares Carvajal 21.497.714-1
Bastian Alonso Guerra Valdés 21.319.198-5

Clases:
Arista.h:
esta clase posee la estructura del objeto arista en la cual se define los datos: int conexiones,velocidad, tiempo.
las cuales son utilizadas como la conexion entre los nodos y se rellenan con el el archivo conexiones.csv
node.h:
La clase node define los atributos de los nodos siendo estos int,id, string name, string type, vector<Aristas> roads.
este vector de aristas llamado roads nos permite conectar los nodos entre si

Grafo.h:
En esta clase se encuentra la estructura del grafo creado a partir de los csv entregados la clase se define como un vector<node > nodos, la particularidad de esta clase es la implementacion
de varios metodos entre ellos el algoritmo de busqueda bellmanFord el cual consiste en la busqueda del camino mas corto en un grafo para esto se recorre  el vector de nodos de manera extensiva
comparando entre si los caminos presentados en Aristas/Roads utilizando el sistema de velocidad y tiempo para calcular el tiempo de demora entre el viaje de cada nodo,se vuelve a recorrer el grafo para 
comprobar la existencia de conexiones "negativas" en este, para despues desplegar el recorrido mas corto entre nodos y presentar el tiempo que transcurre entre cada nodo

Main.cpp
aqui se crean las funciones necesarias para leer los archivos conexiones.csv y servidores.csv y armar el grafo en base a esto despues se implementa un menu simple en el cual usuario puede comprobar el 
camino mas corto despues de ingresar su id inicial, id destino y el peso del archivo por enviar, por ultimo se le pregunta al usuario si desea enviar mas archivos si la respuesta es si el proceso se repita y 
si es negativa se cierra el programa

