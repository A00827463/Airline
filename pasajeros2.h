#ifndef pasajeros2_h
#define pasajeros2_h
#include <string>
#include <iostream>
using namespace std;



class pasajero
{
 private:
    string nombre;
    string telefono;
    int ren_asiento;
    int col_asiento;

public:
pasajero(){
    nombre = "";
    telefono = "";
    ren_asiento =0;
    col_asiento = 0;
}

void setPasajero(string n, string t, int ren, int col){
    nombre = n;
    telefono = t;
    ren_asiento = ren;
    col_asiento = col;
}

};

#endif /* Pasajero_h */