#include <Ahorcado.h>
#include <Juegos.h>
#include <Jugadores.h>


#include <iostream>
#include <string>

using namespace std;

Ahorcado::Ahorcado(){

}

Ahorcado::Ahorcado(string palabraAdivinar, string palabraNormal){
    this -> palabraAdivinar = palabraAdivinar;
    this -> palabraNormal = palabraNormal;

}

void Ahorcado::setPalabraAdivinar(string palabraAdivinar){
    this -> palabraAdivinar = palabraAdivinar;
}
string Ahorcado::getPalabraAdivinar(){
    return palabraAdivinar;
}

void Ahorcado::setPalabraNormal(string palabraNormal){
    this -> palabraNormal = palabraNormal;
}
string Ahorcado::getPalabraNormal(){
    return palabraNormal;
}



void Ahorcado::jugar(){

    modoJuego();

    if(opcionJuego == 1){

        iniciarJuegoJvsJ();
        mostrarPlabra();

    }else if(opcionJuego == 2){

        registrarjugador1();

    }



}

void Ahorcado::tablaInfo() {
}