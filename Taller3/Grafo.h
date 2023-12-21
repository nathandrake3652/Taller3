#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>
#include "Nodo.h"
#include "Arista.h"
using namespace std;

class grafo{
    private:
    vector<node*> nodes;
    public:

   int calctime(int peso,int velocidad){
        int division = 0;
        if(peso < velocidad){
            return 1;
        }else{
            division = (peso / velocidad);
            return (division+1);
        }
    }
    
void bellmanFord(int sourceID, int destinationID, int peso) {
        vector<double> distance(nodes.size(), numeric_limits<double>:: infinity());
        distance[sourceID] = 0;
        int tamanored = nodes.size();
        vector<int> anterior(tamanored,-1);
        

        for (int i = 0; i < nodes.size() - 1; ++i) {
            for (node* currentNode : nodes) {
                for (Arista& road : currentNode->getRoads()) {
                    double tiempoArista = calctime(peso, road.getspeed()) * road.gettime();
                    if (distance[currentNode->getID()] != numeric_limits<double>::infinity() && distance[currentNode->getID()] + tiempoArista< distance[road.getconex()])  {
                        distance[road.getconex()] = distance[currentNode->getID()] +tiempoArista;
                        anterior[road.getconex()] = currentNode->getID();
                    }
                }
            }
        }

        // Verificar ciclos negativos
        for (node* currentNode : nodes) {
            for (Arista& road : currentNode->getRoads()) {
                double tiempoArista = calctime(peso, road.getspeed()) * road.gettime();
                    if (distance[currentNode->getID()] != numeric_limits<double>::infinity() && distance[currentNode->getID()] + tiempoArista< distance[road.getconex()]) {
                    cerr << "El grafo contiene ciclos negativos." << endl;
                    return;
                }
            }
        }

        cout << "La distancia más corta desde el nodo " << sourceID << " al nodo " << destinationID
             << " es: " << distance[destinationID] << " unidades de tiempo." << endl;
        vector<int> camino;
        for (int nodoActual = destinationID; nodoActual != -1; nodoActual = anterior[nodoActual]) {
        camino.push_back(nodoActual);

        }
        reverse(camino.begin(), camino.end());     

        cout << "El camino que mas corto encontrado es: ";
        for (int nodo : camino) {
        cout << nodo << " ";
        }
             cout << endl;
        cout<<"ahora se procedera a mostrar la cantidad de tiempo entre cada nodo:"<<endl;
        timebeetweem(camino,distance,sourceID);
    }

    void addNode(node*& node){
        nodes.push_back(node);
    }
    node* findNode(int nodeId) {
    for (node* node : nodes) {
        if (node->getID() == nodeId) {
            return node;
        }
    }
    cout<< "no se encontraron los nodos buscado"<<endl;
    return nullptr;
}



void timebeetweem(const vector<int>& camino, const vector<double>& distancias, int nodoOrigen) {
    cout << "Tiempo acumulado entre nodos:" << endl;

    for (size_t i = 1; i < camino.size(); ++i) {
        int nodoActual = camino[i];
        double tiempoEntreNodos = distancias[nodoActual] - distancias[nodoOrigen];

        cout << "De " << nodoOrigen << " a " << nodoActual << ": " << tiempoEntreNodos << " segundos." << endl;

        nodoOrigen = nodoActual;
    }
}

void addArista(int idnodo1, int idnodo2, int speed, int time){
    node* node1 = findNode(idnodo1);
    node* node2 = findNode(idnodo2);

    if(node1 != nullptr && node2 != nullptr){
        node1->addRoad(idnodo2,speed,time);
        node2->addRoad(idnodo1,speed,time);
    }
}

vector<node*> getNodes(){
    return  nodes;
}
};