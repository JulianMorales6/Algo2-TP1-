#include "Tablero.h"

Celula getValor(Tablero & tablero, int fila, int columna) {
    return tablero.Tablero[fila][columna];
}

int getAltoMaximo(Tablero & tablero) {
    return tablero.altoMaximo;
}

int getAnchoMaximo(Tablero & tablero) {
    return tablero.anchoMaximo;
}

void inicializarTablero(Tablero & tablero) {
    
    for(int i = 0; i < tablero.altoMaximo; i++) {
        for(int j = 0; j < tablero.anchoMaximo; j++) {
            Celula & celula = tablero.Tablero[i][j];
            cambiarEstado(celula, Muerta);
        }
    }
}
