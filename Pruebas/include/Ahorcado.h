#ifndef AHORCADO_H
#define AHORCADO_H

#include <iostream>
#include <string>
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
        void tablaInfo() override;
    
    private:
    
        string palabraAdivinar, palabraNormal;

        void iniciarJuegoJvsJ(){

            registrarjugador1();
            registrarJugador2();

            int primero;

            cout << "Que jugador dese empezar? (1. jugador1 / 2. jugador2):" << endl;
            cin >> primero;

            if(primero == 1){

                cout << "El jugador " << nombrej1 << " Empieza" << endl;
                cout << "Porfavor elija una palabra:" << endl;
                cin >> palabraAdivinar;

            }else if(primero == 2){

                cout << "El jugador " << nombrej2 << " Empieza" << endl;
                cout << "Porfavor elija una palabra:" << endl;
                cin >> palabraAdivinar;

            }

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

            intentos = 6;

            cout << "Usted tiene " << intentos << " intentos" << endl;
        }

        void mostrarPlabra(){


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
            }

        }

        if(palabraNormal == palabraAdivinar){

            cout << "Felicidades has adivinado la plabra" << endl;
            victorias ++;

        }else{
            cout << "perdiste la plabra era: " << palabraAdivinar << endl;
            derrotas ++;
        }
    }           



    protected:

};

#endif