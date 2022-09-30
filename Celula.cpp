#include "Celula.h"

void inicializarCelula (Celula & celula) {
    celula.Estado = Muerta;
}

void cambiarEstado (Celula & celula, EstadoDeCelula Estado) {
    celula.Estado = Estado;
}

EstadoDeCelula obtenerEstado (Celula & celula) {
    return celula.Estado;
}