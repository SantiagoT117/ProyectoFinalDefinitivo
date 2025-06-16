#ifndef JUGADORES_H
#define JUGADORES_H

#include <iostream>
#include <string>
#include <vector>


using namespace std;

class Jugadores{

    public:

        Jugadores();
        Jugadores(string nombrej1,string nombrej2, string codigoj1,string codigoj2, int victorias, int derrotas, int empates);


        
        void setNombrej1(string nombrej1);
        string getNombrej1();

        void setNombrej2(string nombrej2);
        string getNombrej2();
        
        void setCodigoj1(string codigoj1);
        string getCodigoj1();

        void setCodigoj2(string codigoj2);
        string getCodigoj2();
        
        void setVictorias(int vistorias);
        int getVictorias();
        
        void setDerrotas(int derrotas);
        int getDerrotas();
        
        void setEmpates(int empates);
        int getEmpates();
        
        
        void registrarjugador1(){


            cout << "Registrese jugador numero 1:" << endl;

            cout << "Nombre:" << endl;
            cin >> nombrej1;

            cout << "Codigo:" << endl;
            cin >> codigoj1;


        }

        void registrarJugador2(){

            cout << "Registrese jugador numero 2:" << endl;

            cout << "Nombre:" << endl;
            cin >> nombrej2;

            cout << "Codigo:" << endl;
            cin >> codigoj2;
        }
        
        string nombrej1, codigoj1, nombrej2,codigoj2;
        int victorias, derrotas, empates;


        private:
        
        
        protected: 


};


#endif
