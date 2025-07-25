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
        mostrarPalabra();

    }else if(opcionJuego == 2){
        
        bool gano;

        cout << "Digite la fecha:" << endl;
        cin >> fecha;

        iniciarJuegoJvsIA();
        cambioPalabra();
        gano = mostrarPalabra();

        if(gano){
            victoriasj1++;
        }else{
            derrotasj1++;
        }

    }

}

void Ahorcado::iniciarJuegoJvsIA(){
    srand(time(0));

    registrarjugador1();

    ifstream archivo("Palabras.txt");
    string palabraECU;

    while(getline(archivo,palabraECU)){
        if(!palabraECU.empty()){
            palabras.push_back(palabraECU);
        }
    }
    archivo.close();

    if(palabras.empty()){
        cout << "error" << endl;
    }

    int indice = rand() % palabras.size();

    palabraAdivinar = palabras[indice];
    cout << "La ECU ya ha elegido una palabra" << endl;
}


void Ahorcado::iniciarJuegoJvsJ(){

        registrarjugador1();
        registrarJugador2();

        int primero;
        bool gano;

            cout << "Digite la fecha:" << endl;
            cin >> fecha;

            cout << "Que jugador desea empezar? (1. jugador1 / 2. jugador2):" << endl;
            cin >> primero;
            cin.ignore();

            if(primero == 1){

                cout << "El jugador " << nombrej1 << " Empieza poniendo una palabra" << endl;
                cout << "Porfavor elija una palabra:" << endl;
                cin.ignore();
                getline(cin, palabraAdivinar);


                cambioPalabra();

                gano = mostrarPalabra();

                if(gano){
                    victoriasj2++;
                }else{
                    derrotasj2++;
                }

                cout << "Ahora jugador " << nombrej2 << " Ponga una palabra:"<< endl;
                cin.ignore();
                getline(cin, palabraAdivinar);


                cambioPalabra();

                gano = mostrarPalabra();

                if(gano){
                    victoriasj1++;
                }else{
                    derrotasj1++;
                }


            }else if(primero == 2){

                cout << "El jugador " << nombrej2 << " Empieza poniendo una palabra" << endl;
                cout << "Porfavor elija una palabra:" << endl;
                cin.ignore();
                getline(cin, palabraAdivinar);

                cambioPalabra();

                gano = mostrarPalabra();

                if(gano){
                    victoriasj1++;
                }else{
                    derrotasj1++;
                }

                cout << "Ahora jugador " << nombrej1 << " Ponga una palabra:"<< endl;
                cin.ignore();
                getline(cin, palabraAdivinar);

                cambioPalabra();

                gano = mostrarPalabra();

                if(gano){
                    victoriasj2++;
                }else{
                    derrotasj2++;
                }

            }

        }

bool Ahorcado::mostrarPalabra(){

            cout << "--------" << endl;
            cout << "|" << endl;
            cout << "|" << endl;
            cout << "|" << endl;
            cout << "|" << endl;
            cout << "|" << endl;
            cout << "|" << endl;
            cout << "----" << endl;

            bool letraCorrecta;

            while(intentos > 0 && palabraNormal != palabraAdivinar){

                letraCorrecta = false;

                cout << "palabra " << palabraNormal << endl;
                cout << "Intentos: " << intentos << endl;
                cout << "Ingrese una letra: " << endl;

                char x;
                cin >> x;
            
            for(int i = 0; i < palabraAdivinar.length(); i++){

                if(x == palabraAdivinar[i]){
                    palabraNormal[i] = x;
                    letraCorrecta = true;

                }
            }

            if(!letraCorrecta){
                cout << "letra incorrecta" << endl;
                intentos --;

            cout << "Usted tiene " << intentos << " intentos" << endl;


            if(intentos == 3){

                cout << "--------" << endl;
                cout << "|       |" << endl;
                cout << "|       O" << endl;
                cout << "|" << endl;
                cout << "|" << endl;
                cout << "|" << endl;
                cout << "|" << endl;
                cout << "----" << endl;

            }else if(intentos == 2){

                cout << "--------" << endl;
                cout << "|       |" << endl;
                cout << "|       O" << endl;
                cout << "|       |" << endl;
                cout << "|       |" << endl;
                cout << "|" << endl;
                cout << "|" << endl;
                cout << "----" << endl;

            }else if(intentos == 1){

                cout << "--------" << endl;
                cout << "|       |" << endl;
                cout << "|       O" << endl;
                cout << "|      ||| " << endl;
                cout << "|       |" << endl;
                cout << "|" << endl;
                cout << "|" << endl;
                cout << "----" << endl;

            }else if(intentos == 0){

                cout << "--------" << endl;
                cout << "|       |" << endl;
                cout << "|       O" << endl;
                cout << "|      ||| " << endl;
                cout << "|       |" << endl;
                cout << "|      | |" << endl;
                cout << "|" << endl;
                cout << "----" << endl;
            }
            }

        }

        if(palabraNormal == palabraAdivinar){
            cout << "Felicidades has adivinado la plabra" << endl;
            return true;

        }else{
            cout << "perdiste la plabra era: " << palabraAdivinar << endl;
            return false;
        }


    }
void Ahorcado::cambioPalabra(){

            for(int i = 0; i < palabraAdivinar.length(); i++){

            if(palabraAdivinar[i] >= 'A' && palabraAdivinar[i] <= 'Z'){
                palabraAdivinar[i] += 32;
            }
            }

            palabraNormal = "";

            for(int i = 0; i < palabraAdivinar.length(); i++){

                if(palabraAdivinar[i] >= 'a' && palabraAdivinar[i] <= 'z'){
                    palabraNormal += '_';

                }else{

                palabraNormal += palabraAdivinar[i];
            }
            }

            intentos = 4;

            cout << "Usted tiene " << intentos << " intentos" << endl;
        }

void Ahorcado::tablaInfo(){

        string Jueguito = "Ahorcado";


        ofstream info("Informacion.txt", ios::app);
            if(!info.is_open()){
                cout << "Error al abri el archivo " << endl;
                return;
            }

        if(opcionJuego == 1){
                info << "Nombre: " << nombrej1 << " // " << " Fecha: " << fecha << " // " << " Juego: " <<  Jueguito << " // "<< " victorias/derrotas " << " // " << victoriasj1 << " // "<< derrotasj1 << endl;
                info << "Nombre: " << nombrej2 << " // " << " Fecha: " << fecha << " // " << " Juego: " <<  Jueguito << " // "<< " victorias/derrotas " << " // " << victoriasj2 << " // "<< derrotasj2 << endl;
        
        }else if(opcionJuego == 2){
                info << "Nombre: " << nombrej1 << " // " << " Fecha: " << fecha << " // " << " Juego: " <<  Jueguito << " // "<< " victorias/derrotas " << " // " << victoriasj1 << " // "<< derrotasj1 << endl;
        }

        info.close();

        if(opcionJuego == 1){
            cout << "Informacion partida jugador vs jugador" << endl;
            cout << "Nombre: " << nombrej1 << " // " << " Fecha: " << fecha << " // " << " Juego: " <<  Jueguito << " // "<< " victorias/derrotas " << " // " << victoriasj1 << " // "<< derrotasj1 << endl;
            cout << "Nombre: " << nombrej2 << " // " << " Fecha: " << fecha << " // " << " Juego: " <<  Jueguito << " // "<< " victorias/derrotas " << " // " << victoriasj2 << " // "<< derrotasj2 << endl;
        
        }else if(opcionJuego == 2){
            cout << "Informacion partida jugador vs IA" << endl;
            cout << "Nombre: " << nombrej1 << " // " << " Fecha: " << fecha << " // " << " Juego: " <<  Jueguito << " // "<< " victorias/derrotas " << " // " << victoriasj1 << " // "<< derrotasj1 << endl;
        }

}

