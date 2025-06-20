#include "Concentrece.h"

Concentrece::Concentrece(){
    puntos = 0;
    paresTotales = 0;
    paresEncontrados = 0;
    resultado = "P";
}

void Concentrece::jugar(){
    int modo;
    cout <<"Digite la fecha (Ej: 2025-06-07): ";
    cin >> fecha; //viene de jugadores

    cout << "¿Qué modo desea jugar? (1. Jugador vs Jugador / 2. Jugador vs CPU): ";
    cin >> modo;

    cargarSimbolos();
    mezclarTablero();

    descubiertas.resize(tablero.size(), false); //marca las casilla como ocultas

    if (modo == 1){
        registrarjugador1();
        registrarJugador2();
        juegoJugadorVsJugador();
    } else {
        registrarjugador1();
        jugadorVsCPU();
    }
}

void Concentrece::cargarSimbolos(){
    ifstream archivo("pares.txt");
    string simbolo;

    while (archivo >> simbolo){
        tablero.push_back(simbolo);
        tablero.push_back(simbolo);
        paresTotales ++ ;
    }
    archivo.close();
}

void Concentrece::mezclarTablero(){
    for (int i = 0; i < tablero.size(); i++) {
        int j = rand() % tablero.size();
        swap(tablero[i], tablero[j]);
    }
}

void Concentrece::mostrarTablero(){
    cout << "\nTablero:\n";
    for (int i = 0; i < tablero.size(); i++) {
        if (descubiertas[i]) {
            cout << "[" << tablero[i] << "]";
        } else {
            cout << "[" << i + 1 << "]";
        }

        if ((i + 1) % 4 == 0) cout << endl;
    }
    cout << endl;
}

bool Concentrece::jugarTurno(string jugador){
    int p1, p2;

    cout << jugador << ", elige dos posiciones del tablero.";
    cin >> p1 >> p2;
    p1--; p2--;

    if (p1 == p2 || p1 < 0 || p2 < 0 || p1 >= tablero.size() || p2 >= tablero.size() || descubiertas[p1] || descubiertas[p2]) {
        cout << "Posiciones inválidas. Pierdes el turno.\n";
        return false;
    }

    cout << "Descubriste: " << tablero[p1] << " y " << tablero[p2] << endl;

    if (tablero[p1] == tablero[p2]) {
        descubiertas[p1] = true;
        descubiertas[p2] = true;
        puntos += 10;
        paresEncontrados++;
        cout << "¡Par encontrado!\n";
        return true;
    } else {
        cout << "No coinciden.\n";
        return false;
    }
}

void Concentrece::juegoJugadorVsJugador(){
    int turno = 0;
    while (paresEncontrados < paresTotales){
        mostrarTablero();

        string jugadorActual = (turno % 2 == 0) ? nombrej1 : nombrej2;
        jugarTurno(jugadorActual);
        turno++;
    } 

    cout << "¡FELICIDADES, todos los pares han sido encontrados";
    resultado = "G";
    tablaInfo();
}

void Concentrece::jugadorVsCPU() {
    int turno = 0;
    int oportunidadesJugador = 5;  
    bool ganoJugador = false;      
    while (paresEncontrados < paresTotales && oportunidadesJugador > 0) {
        mostrarTablero();
        cout << "--------------------------------------------------\n";

        if (turno % 2 == 0) { 
            cout << "Turno de " << nombrej1 << " (Oportunidades restantes: " << oportunidadesJugador << ")\n";
            
            int p1, p2;
            cout << "Elige dos posiciones (ej: 1 2): ";
            cin >> p1 >> p2;
            p1--; p2--;  // 

            if (p1 < 0 || p2 < 0 || p1 >= tablero.size() || p2 >= tablero.size() || 
                p1 == p2 || descubiertas[p1] || descubiertas[p2]) {
                cout << "¡Selección inválida! Pierdes una oportunidad.\n";
                oportunidadesJugador--;
            } 
            else {
                
                cout << "Cartas reveladas: " << tablero[p1] << " y " << tablero[p2] << endl;
                
                if (tablero[p1] == tablero[p2]) { 
                    descubiertas[p1] = descubiertas[p2] = true;
                    paresEncontrados++;
                    puntos += 10;
                    cout << "¡Correcto! Has encontrado un par.\n";
                    if (paresEncontrados == paresTotales) {
                        ganoJugador = true;
                    }
                } 
                else { 
                    cout << "¡No coinciden! Pierdes una oportunidad.\n";
                    oportunidadesJugador--;
                }
            }
        } 
        else { 
            cout << "Turno de la CPU\n";
            
            int p1 = rand() % tablero.size();
            int p2 = rand() % tablero.size();

            
            while (p1 == p2 || descubiertas[p1] || descubiertas[p2]) {
                p1 = rand() % tablero.size();
                p2 = rand() % tablero.size();
            }

            cout << "La CPU eligió posiciones: " << p1+1 << " y " << p2+1 << endl;
            cout << "Cartas reveladas: " << tablero[p1] << " y " << tablero[p2] << endl;

            if (tablero[p1] == tablero[p2]) { 
                descubiertas[p1] = descubiertas[p2] = true;
                paresEncontrados++;
                cout << "¡La CPU encontró un par!\n";
                if (paresEncontrados == paresTotales) {
                    ganoJugador = false;
                }
            } 
            else { 
                cout << "¡La CPU no acertó!\n";
            }
        }
        turno++;
        cout << "--------------------------------------------------\n";
    }
    cout << "\n¡Juego terminado!\n";
    if (paresEncontrados == paresTotales) {
        if (ganoJugador) {
            cout << "¡Felicidades " << nombrej1 << "! Has ganado.\n";
            resultado = "G";
        } else {
            cout << "¡La CPU ha ganado!\n";
            resultado = "D";
        }
    } 
    else {
        cout << "Te quedaste sin oportunidades. ¡La CPU gana!\n";
        resultado = "D";
    }
    
    cout << "¡Fin del juego!\n";
    resultado = "G"; 
    tablaInfo();
}

void Concentrece::tablaInfo() {
    ofstream info("Informacion.txt", ios::app);
    if (info.is_open()) {
        info << "Nombre: " << nombrej1
             << " // Fecha: " << fecha
             << " // Juego: Concentrece"
             << " // Resultado: " << resultado
             << " // Puntos: " << puntos << endl;
        info.close();
    }
}