#include <iostream>
#include <vector>
#include <string>
#include <Ahorcado.h>

using namespace std;

int main(){

    Juegos* juego = new Ahorcado();

    juego->jugar();

    delete juego;

    return 0;

}