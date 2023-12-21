
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <stdexcept>
#include "Nodo.h"
#include "Grafo.h"
#include "Arista.h"


using namespace std;
void fillVector(vector<node*>& lista) {
     char delimiter = ',';
     string filename = "servidores.csv";

    ifstream readFile(filename);
    if (!readFile.is_open()) {
        cerr << "Error al abrir el archivo: " << filename << endl;
        return; 
    }
    string line;
    // se lee la primera linea la cual contiene los encabezados
    getline(readFile, line);

    // Leer el resto de las líneas
    while (getline(readFile, line)) {
        if (line.empty()) {
            continue; // se ignoran lineas vacias en caso de haber una
        }

        stringstream stream(line);
        string id, serverName, type;

        // Extraer valores del archivo
        getline(stream, id, delimiter);
        getline(stream, serverName, delimiter);
        getline(stream, type, delimiter);

        try {
            int idNumber = stoi(id);
            // Agregar el nodo al vector
            lista.push_back(new node(idNumber, serverName, type));
        } catch (const invalid_argument& e) {
            cerr << "Error al convertir el ID a entero en la línea: " << line << endl;
        } catch (const out_of_range& e) {
            cerr << "Error: ID fuera de rango en la línea: " << line << endl;
        }
    }

    readFile.close();
};

void conectRoads(grafo& Grafo){
    const char delimiter = ',';
    const string filename = "conexiones.csv";
     ifstream readFile(filename);
    if (!readFile.is_open()) {
        cerr << "Error al abrir el archivo: " << filename << endl;
        return; 
    }
    string line;
    // se lee la primera linea la cual contiene los encabezados
    getline(readFile, line);

    while (getline(readFile, line)) {
         if (line.empty()) {
            continue; // se ignoran lineas vacias en caso de haber una
        }

        stringstream stream(line);
        string clientid, serverid,speed, time;
        getline(stream, clientid, delimiter);
        getline(stream, serverid, delimiter);
        getline(stream, speed, delimiter);
        getline(stream, time, delimiter);
        try {
            int idclient = stoi(clientid);
            int idserver = stoi(serverid);
            int speed2 = stoi(speed);
            int time2 = stoi(time);

            Grafo.addArista(idclient,idserver,speed2,time2);
            
        } catch (const invalid_argument& e) {
            cerr << "Error al convertir el ID a entero en la línea: " << line << endl;
        } catch (const out_of_range& e) {
            cerr << "Error: ID fuera de rango en la línea: " << line << endl;
        }
    }
        readFile.close();

};
void Rellenar(grafo& Grafo, vector<node*> nodos){
    for(node* nodo: nodos){
        Grafo.addNode(nodo);
    }

};

int main() {
    grafo Grafo;
    vector<node*> nodos;
    fillVector(nodos);
    Rellenar(Grafo, nodos);
    conectRoads(Grafo);
    cout<<"Bienvenido"<<endl;
    bool continuar = true;
    while (continuar) {
        
        cout << "---Menu---" << endl;
        int sourceID, destinationID, peso;
        cout << "Ingrese el ID del nodo de partida: " << endl;
        cin >> sourceID;
        cout << "Ingrese el ID del nodo de destino: " << endl;
        cin >> destinationID;
        cout << "Ingrese el peso del archivo que desea enviar: " << endl;
        cin >> peso;

       
        Grafo.bellmanFord(sourceID, destinationID, peso);

        cout << "¿Desea enviar otro archivo?" << endl;
        cout << "1. Si" << endl << "2. No" << endl;
        cout << "Ingrese su opción de manera numérica: ";

        try {
            int eleccion;
            cin >> eleccion;

            if (eleccion == 1) {
                continuar = true;
            } else if (eleccion == 2) {
                continuar = false;
            } else {
                cerr << "Opción inválida. Por favor, ingrese 1 o 2." << endl;
            }
        } catch (const invalid_argument& e) {
            cerr << "Argumento inválido. Por favor, inténtelo de nuevo." << endl;
        }
    }

    
    }




   

