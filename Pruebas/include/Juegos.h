#ifndef JUEGOS_H
#define JUEGOS_H

#include <iostream>
#include <string>

using namespace std;

class Juegos{
    
    public:

    Juegos();
    Juegos(int puntos, int intentos, int opcionJuego);

        virtual void jugar() = 0;
        virtual void tablaInfo() = 0;

        void setPuntos(int puntos);
        int getPuntos();

        void setIntentos(int intentos);
        int getIntentos();

        void setopcionJuego(int opcionJuego);
        int getopcionJuego();

        void modoJuego(){  

            cout << "Dijite que modo de juego desea (1. Jugador vs Jugador / 2. Jugador vs IA)" << endl;
            cin >> opcionJuego;

        }

        int puntos;
        int intentos;
        int opcionJuego;
        
        
        private:
        
        
        protected:
        

};


#endif