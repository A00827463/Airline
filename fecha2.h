#ifndef fecha2_h
#define fecha2_h
#include <string>
#include <iostream>
using namespace std;
class fecha{
public:
int dia;
int mes;
int anio;
int hora;
int minuto;

fecha(int h, int m){
    dia =1;
    mes = 1;
    anio = 2019;
    hora = h;
    minuto = m;
}

fecha(){
  dia =1;
    mes = 1;
    anio = 2019;
    hora = 0;
    minuto = 0;  
}

void setHoraMin(int h, int m){
    hora = h;
    minuto = m;
}

 void spill(){
     cout << dia << "/" << mes << "/"<<anio<< "..."<< hora<< ":"<<minuto;
 }

};


#endif 