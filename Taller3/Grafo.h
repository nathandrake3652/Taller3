#include <iostream>
#include <vector>
#include <limits>
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
        vector<int> distance(nodes.size(), 1000000);
        distance[sourceID] = 0;

        for (int i = 0; i < nodes.size() - 1; ++i) {
            for (node* currentNode : nodes) {
                for (Arista& road : currentNode->getRoads()) {

                    int newDistance = distance[currentNode->getID()] + road.gettime();
                    if (newDistance < distance[road.getconex()]) {
                        distance[road.getconex()] = newDistance;
                    }
                }
            }
        }

        // Verificar ciclos negativos
        for (node* currentNode : nodes) {
            for (Arista& road : currentNode->getRoads()) {
                int newDistance = distance[currentNode->getID()] + road.gettime();
                if (newDistance < distance[road.getconex()]) {
                    cerr << "El grafo contiene ciclos negativos." << endl;
                    return;
                }
            }
        }

        cout << "La distancia más corta desde el nodo " << sourceID << " al nodo " << destinationID
             << " es: " << distance[destinationID] << " unidades de tiempo." << endl;
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