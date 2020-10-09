#include "vuelo2.h"
#include <vector>
#include <unistd.h>
 
#include <iostream>
#include <fstream>



void loadFlights(ifstream &flights, vector<vuelo> &vuelos){

    while(!flights.eof()){
        float precio;
        string destino;
        int distancia;
        int h;
        int m;
        string n;
        
        
        flights >> precio;
        flights >> destino;
        flights >> distancia;
        flights >> h >> m;
        flights >>n;
        vuelos.push_back(vuelo(precio, destino, distancia, h, m, n));
    }
}


int totalDeVentas(vuelo flight){
    return static_cast<float>(flight.getNumPas())* flight.getPrecio();
}





int main()
{

    vector<vuelo> vuelos;
    ifstream flights("Vuelos.txt");

    int cont = 0;
    cout << "\033[2J\033[1;1H";
    int opcion1;
    int opcion2;
    string temp;
    opcion1 = 0;
    cout << "" << endl;
    cout << "Hola, Bienvenido a Volaris" << endl;
    cout << "" << endl;

    loadFlights(flights, vuelos);

    flights.close();

    while (true)
    {
        cout << "Elige una Opcion del Siguiente menu" << endl;
        cout << "    1) Agregar pasajero con vuelo" << endl;
        cout << "    2) Agregar vuelo" << endl;
        cout << "    3) Desplegar asientos de cierto vuelo" << endl;
        cout << "    4) Desplegar lista de vuelos" << endl;
        cout << "    5) Obtener el total de ventas" << endl;
        cout << "    6) Salir" << endl;
        cin >> opcion1;
        cout << "\033[2J\033[1;1H";

        if (opcion1 == 6)
        {
            break;
        }




        else if (opcion1 == 1)
        {

            if (vuelos.size() == 0)
            {
                cout << "No hay vuelos disponibles" << endl;
            }
            else
            {
                int seleccion = 0;
                string name;
                string tel;
                int f, a;
                cout << "Vuelos disponibles:"<<endl;

                for (int i = 0; i < vuelos.size(); i++)
                {
                    cout << "     " << i + 1 << ")";
                    vuelos[i].spill();
                    cout<<endl;
                }
                cin >> seleccion;
                cout << "Nombre:" << endl;
                cin >> name;
                cout << "Telefono" << endl;
                cin >> tel;
                cout << "asientos disponibles:" << endl;
                for (int i = 0; i < 30; i++)
                {
                    for (int j = 0; j < 4; j++)
                    {
                        cout << vuelos[seleccion - 1].asientos[i][j] << " ";
                    }
                    cout << endl;
                }

                cout << "Fila?" << endl;
                cin >> f;
                cout << "Asiento?" << endl;
                cin >> a;
                while (true)
                {
                    if (vuelos[seleccion - 1].takeSeat(f, a))
                    {
                        vuelos[seleccion - 1].agregarPas(name, tel, f, a);
                        break;
                    }
                    else
                    {
                        cout << "Fila?" << endl;
                        cin >> f;
                        cout << "Asiento?" << endl;
                        cin >> a;
                    }
                }
            }
        }





        else if (opcion1 == 2)
        {
            float precio;
            string destino;
            int distancia;
            int h;
            int m;
            string n;
            cout << "Precio:" << endl;
            cin >> precio;
            cout << "Destino:" << endl;
            cin >> destino;
            cout << "Distancia:" << endl;
            cin >> distancia;
            cout << "Hora y Min: (horario entre las 23:00 - 7:00 unicamente" << endl;
            cin >> h >> m;
            cout << "Numero de Matricula:" << endl;
            cin >> n;
            while (true)
                {
                    if ((h>=23 && h<=24) || (h>=0 &&h<=7))
                    {
                        break;
                    }
                    else
                    {
                        cout<<"Horario no disponible"<<endl;
                        cout << "Hora y Min: (horario entre las 23:00 - 7:00 unicamente" << endl;
                        cin >> h >> m;
                    }
                }
            vuelos.push_back(vuelo(precio, destino, distancia, h, m, n));
        }




        else if (opcion1 == 3){
            int seleccion = 0;
            string name;
            string tel;
            int f, a;
            cout << "Vuelos disponibles:"<<endl;
            

            for (int i = 0; i < vuelos.size(); i++)
            {
                cout << "     " << i + 1 << ")";
                vuelos[i].spill();
                cout<<endl;
            }
            cin >> seleccion;

            for (int i = 0; i < 30; i++)
            {   
                for (int j = 0; j < 4; j++)
                {
                    cout << vuelos[seleccion - 1].asientos[i][j] << " ";
                }
                cout << endl;
            }
            cout<<"Ingresa cualquier letra para regresar al Menu Principal"<<endl;
            cin>>temp;
        }





        else if (opcion1 == 4)
        {   
            for (int i = 0; i < vuelos.size(); i++)
            {
                cout << "     " << i + 1 << ")";
                vuelos[i].spill();
                cout <<""<<endl;
            }
            cout<<"Ingresa cualquier letra para regresar al Menu Principal"<<endl;
            cin>>temp;
        }
        else if (opcion1 == 5)
        {
            float total = 0.0;
            for (int i =0; i <vuelos.size();i++){
                total +=totalDeVentas(vuelos[i]);
            }
            cout<<"Total de Ventas: $"<<total<<endl;
            cout<<"Ingresa cualquier letra para regresar al Menu Principal"<<endl;
            cin>>temp;
        }
        else
        {
            cout << "Opcion Invalida";
        }

    cout<<""<<endl;
    cout<<"Regresando al menu Principal..."<<endl;
    cout<<""<<endl;
    usleep(2000000);
    cout << "\033[2J\033[1;1H";
    }

    cout<<""<<endl;
    cout<<"Saliendo..."<<endl;
    cout<<""<<endl;
    usleep(2000000);
    cout<<"Que tengas un buen dia!"<<endl;
    cout<<""<<endl;
    return 0;
}