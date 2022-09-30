#ifndef TABLERO_H_
#define TABLERO_H_

#include "Celula.h"

static const int FILAS_MAXIMAS = 80;
static const int COLUMNAS_MAXIMAS = 20;

typedef struct {
    Celula Tablero[FILAS_MAXIMAS][COLUMNAS_MAXIMAS];
    int altoMaximo = FILAS_MAXIMAS;
    int anchoMaximo = COLUMNAS_MAXIMAS;
} Tablero;

void inicializarTablero(Tablero & tablero);

int getAltoMaximo(Tablero & tablero);

int getAnchoMaximo(Tablero & tablero);

Celula getValor(Tablero & tablero, int fila, int columna);

#endif // TABLERO_H_