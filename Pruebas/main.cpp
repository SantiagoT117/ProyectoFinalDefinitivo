#include <iostream>
#include <fstream> // leer archivo historial
#include <vector>
#include <string>
#include <Ahorcado.h>
#include "Concentrece.h" 

int opcionJuego = 0;
int selector = 0;

void verInformacion();


using namespace std;


int main(){

    cout << "Bienvenido a la sala de juegos" << endl;

    cout << "Que desea jugar el dia de hoy? ( 1. ahorcado // 2. concentrese)" << endl;
    cin >> opcionJuego;

    if(opcionJuego == 1){

        Juegos* juego = new Ahorcado();

        juego -> jugar();

        cout << "Desea ver la informacion de partida?: 1. si // 2. no"<< endl;
        cin >> selector;

        if(selector == 1){
            ((Ahorcado*)juego) -> tablaInfo();
        }


        delete juego;

        return 0;



    }else if(opcionJuego == 2){
        cout << "Aqui va el concentrese" << endl;
        Juegos* juego = new Concentrece();     // Creamos juego como puntero a Juegos

        juego->jugar();

        cout << "¿Desea ver la información de partida?: 1. sí // 2. no" << endl;
        cin >> selector;

        if (selector == 1) {
            ((Concentrece*)juego)->tablaInfo();  // Convertimos para llamar tablaInfo()
        }

        delete juego;
        return 0;
    }
}


void verInformacion(){
    ifstream archivo("Informacion.txt");

    if(archivo.is_open()){
        string linea;

        while(getline(archivo, linea)){
            cout << linea << endl;

        }
        archivo.close();
    }
}