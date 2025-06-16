#include "Jugadores.h"

#include <iostream>
#include <string>

using namespace std;

Jugadores::Jugadores(){

}

Jugadores::Jugadores(string nombrej1,string nombrej2, string codigoj1,string codigoj2, int victorias, int derrotas, int empates){
    this -> nombrej1 = nombrej1;
    this -> codigoj1 = codigoj1;
    this -> nombrej2 = nombrej2;
    this -> codigoj2 = codigoj2;
    this -> victorias = victorias;
    this -> derrotas = derrotas;
    this -> empates = empates;
}

void Jugadores::setNombrej1(string nombrej1){
    this -> nombrej1 = nombrej1;
}
string Jugadores::getNombrej1(){
    return nombrej1;
}

void Jugadores::setCodigoj1(string codigoj1){
    this -> codigoj1 = codigoj1;
}
string Jugadores::getCodigoj1(){
    return codigoj1;
}

void Jugadores::setNombrej2(string nombrej2){
    this -> nombrej2 = nombrej2;
}
string Jugadores::getNombrej2(){
    return nombrej2;
}

void Jugadores::setCodigoj2(string codigoj2){
    this -> codigoj2 = codigoj2;
}
string Jugadores::getCodigoj2(){
    return codigoj2;
}

void Jugadores::setVictorias(int victorias){
    this -> victorias = victorias;
}
int Jugadores::getVictorias(){
    return victorias;
}

void Jugadores::setDerrotas(int derrtoas){
    this -> derrotas = derrotas;
}
int Jugadores::getDerrotas(){
    return derrotas;
}

void Jugadores::setEmpates(int empates){
    this -> empates = empates;
}
int Jugadores::getEmpates(){
    return empates;
}