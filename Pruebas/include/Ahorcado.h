#ifndef AHORCADO_H
#define AHORCADO_H

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <fstream>
#include <Juegos.h>
#include <Jugadores.h>

using namespace std;

class Ahorcado : public Juegos, public Jugadores{

    public:
        
        Ahorcado();
        Ahorcado(string palabraAdivinar, string palabraNormal);
        
        void setPalabraAdivinar(string palabraAdivinar);
        string getPalabraAdivinar();
        
        void setPalabraNormal(string palabraNormal);
        string getPalabraNormal();
        
        void jugar() override;

        void tablaInfo();


    
    private:

        string palabraAdivinar, palabraNormal;
        int intentos;
        vector<string> palabras;

        void iniciarJuegoJvsJ();
        void iniciarJuegoJvsIA();
        bool mostrarPalabra();
        void cambioPalabra();
};

#endif