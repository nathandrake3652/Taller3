#pragma once
#include <iostream>
#include <vector>
#include "Arista.h"
using namespace std;


class node{
    private:
    int id;
    string name;
    string type;
    vector<Arista> roads;
    public:
    node(int id, string name, string type){
        this -> id= id;
        this ->name = name;
        this -> type = type;
    }

    int getID(){
        return this-> id;

    }
    string getName(){
        return this-> name;
    }
    string getType(){
        return this->type;
    }

     vector<Arista>& getRoads() {
        return roads;
    }

    void addRoad(int id2, int speed, int time){
        roads.push_back(Arista(id2,speed,time));

    }
};