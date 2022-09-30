#ifndef CELULA_H_
#define CELULA_H_

#include <iostream>
using namespace std;

enum EstadoDeCelula {
    Viva, 
    Muerta
};

typedef struct {
    EstadoDeCelula Estado;
} Celula;

void inicializarCelula (Celula & celula);

void cambiarEstado (Celula & celula, EstadoDeCelula Estado);

EstadoDeCelula obtenerEstado (Celula & celula);

#endif //CELULA_H_