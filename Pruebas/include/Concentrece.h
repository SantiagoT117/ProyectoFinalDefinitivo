#ifndef CONCENTRECE_H
#define CONCENTRECE_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cstdlib> // Para rand()
#include "Juegos.h"
#include "Jugadores.h"

using namespace std;

class Concentrece : public Juegos, public Jugadores
{
    public: 
    Concentrece();

    void jugar() override;
    void tablaInfo() override;

    private:
    vector<string> tablero;
    vector<bool> descubiertas;
    int paresTotales;
    int paresEncontrados;
    string resultado;

    void cargarSimbolos();
    void mezclarTablero();
    void mostrarTablero();
    bool jugarTurno(string jugador);
    void juegoJugadorVsJugador();
    void jugadorVsCPU();

};


#endif