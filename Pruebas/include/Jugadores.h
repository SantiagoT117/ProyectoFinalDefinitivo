#ifndef JUGADORES_H
#define JUGADORES_H

#include <iostream>
#include <string>
#include <vector>


using namespace std;

class Jugadores{

    public:

        Jugadores();
        Jugadores(string fecha,string nombrej1,string nombrej2, string codigoj1,string codigoj2, int victoriasj1,int victoriasj2 , int derrotasj1,int derrotasj2 , int empates);

        void setFecha(string fecha);
        string getFecha();
        
        void setNombrej1(string nombrej1);
        string getNombrej1();

        void setNombrej2(string nombrej2);
        string getNombrej2();
        
        void setCodigoj1(string codigoj1);
        string getCodigoj1();

        void setCodigoj2(string codigoj2);
        string getCodigoj2();
        
        void setVictoriasj1(int vistoriasj1);
        int getVictoriasj1();

        void setVictoriasj2(int vistoriasj2);
        int getVictoriasj2();
        
        void setDerrotasj1(int derrotasj1);
        int getDerrotasj1();

        void setDerrotasj2(int derrotasj2);
        int getDerrotasj2();
        
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
        
        string fecha ,nombrej1, codigoj1, nombrej2, codigoj2;
        int victoriasj1, victoriasj2, derrotasj1, derrotasj2 , empates;


        private:
        
        
        protected: 


};


#endif
