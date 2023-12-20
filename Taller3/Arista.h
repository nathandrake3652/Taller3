#pragma once
#include <iostream>
using namespace std;

class Arista{
    private: 
    int conexion;
    int velocidad;
    int tiempo;
    public:
    Arista(int conexion, int velocidad, int tiempo){
        this -> conexion = conexion;
        this -> velocidad = velocidad;
        this -> tiempo = tiempo;

    }
    int getconex(){
        return this-> conexion;
    }
    int getspeed(){
        return this-> velocidad;
    }
    int gettime(){
        return this-> tiempo;
    }
    void setconex(int conex){
        this-> conexion = conexion;
    }
    void setspeed(int veloc){
        this -> velocidad = veloc;
    }
    void settime(int tiemp){
        this-> tiempo = tiemp;
    }
};