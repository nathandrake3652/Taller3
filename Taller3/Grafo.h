#include <iostream>
#include <vector>
#include "Nodo.h"
#include "Arista.h"
using namespace std;

class grafo{
    private:
    vector<node*> nodes;
    public:
    
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
