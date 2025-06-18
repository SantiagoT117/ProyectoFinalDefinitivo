#include "Jugadores.h"

#include <iostream>
#include <string>

using namespace std;

Jugadores::Jugadores(){

}

Jugadores::Jugadores(string fecha,string nombrej1,string nombrej2, string codigoj1,string codigoj2, int victoriasj1,int victoriasj2 , int derrotasj1,int derrotasj2 , int empates){
    this -> fecha = fecha;
    this -> nombrej1 = nombrej1;
    this -> codigoj1 = codigoj1;
    this -> nombrej2 = nombrej2;
    this -> codigoj2 = codigoj2;
    this -> victoriasj1 = victoriasj1;
    this -> victoriasj2 = victoriasj2;
    this -> derrotasj1 = derrotasj1;
    this -> derrotasj2 = derrotasj2;    
    this -> empates = empates;
}

void Jugadores::setFecha(string fecha){
    this -> fecha = fecha;
}
string Jugadores::getFecha(){
    return fecha;
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

void Jugadores::setVictoriasj1(int victoriasj1){
    this -> victoriasj1 = victoriasj1;
}
int Jugadores::getVictoriasj1(){
    return victoriasj1;
}

void Jugadores::setVictoriasj2(int victoriasj2){
    this -> victoriasj2 = victoriasj2;
}
int Jugadores::getVictoriasj2(){
    return victoriasj2;
}

void Jugadores::setDerrotasj1(int derrtoasj1){
    this -> derrotasj1 = derrotasj1;
}
int Jugadores::getDerrotasj1(){
    return derrotasj1;
}

void Jugadores::setDerrotasj2(int derrtoasj2){
    this -> derrotasj2 = derrotasj2;
}
int Jugadores::getDerrotasj2(){
    return derrotasj2;
}

void Jugadores::setEmpates(int empates){
    this -> empates = empates;
}
int Jugadores::getEmpates(){
    return empates;
}