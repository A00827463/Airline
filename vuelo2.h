#ifndef vuelo2_h
#define vuelo2_h
#include <string>
#include <iostream>
#include "pasajeros2.h"
#include "fecha2.h"
using namespace std;

class vuelo
{
private:
    int cont;
    int precio_total;
    float precio;
    string destino;
    int distancia;
    int num_lugares;
    fecha date;
    pasajero pas[120];
    int numPas;
    string matricula;


public:
    bool asientos[30][4];
    vuelo(int p, string dest, int dist, int h, int m, string n)
    {
        precio = p;
        destino = dest;
        distancia = dist;
        date.setHoraMin(h, m);
        numPas = 0;
        matricula = n;
       
        for(int i = 0; i <30; i++){
            for(int j =0; j <4; j++){
                asientos[i][j] = false;
            }
        }
    }
    void spill(){
        cout << " "<<destino << "..........."<< date.dia << "/" << date.mes << "/"<<date.anio<< "..."<< date.hora<< ":"<<date.minuto<<"   "<<matricula<<endl;
    }
    bool takeSeat(int fila, int asiento){
        if(asientos[fila-1][asiento-1]== false){
            asientos[fila-1][asiento-1]= true;
            return true;
        }
        else{
            cout << "Asiento no disponible, Intenta de nuevo"<<endl;
            return false;
        }
    }
    void agregarPas(string nombre, string tel, int fila, int ass)
    {
        pas[numPas].setPasajero(nombre,tel,fila,ass);
        numPas++;
    }

    int getNumPas(){
        return numPas;
    }
    float getPrecio(){
        return precio;
    }

};
 
#endif