#include "Juegos.h"

#include <iostream>
#include <string>

using namespace std;

Juegos::Juegos(){
    
}

Juegos::Juegos(int puntos,int intentos,int opcionJuego){
    this -> puntos = puntos;
    this -> intentos = intentos;
    this -> opcionJuego = opcionJuego;
}

void Juegos::setPuntos(int puntos){
    this -> puntos = puntos;
}
int Juegos::getPuntos(){
    return puntos;
}

void Juegos::setIntentos(int intentos){
    this -> intentos = intentos;
}
int Juegos::getIntentos(){
    return intentos;
}

void Juegos::setopcionJuego(int opcionJuego){
    this -> opcionJuego = opcionJuego;
}
int Juegos::getopcionJuego(){
    return opcionJuego;
}