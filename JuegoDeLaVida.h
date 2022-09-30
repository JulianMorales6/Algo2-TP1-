#ifndef JUEGODELAVIDA_H_
#define JUEGODELAVIDA_H_

#include "Tablero.h"

typedef struct {
    Tablero tablero;
    Tablero tableroAux;
    int nacimientosTotales;
    int muertesTotales;
    int celulasVivas;
    int nacimientosDelTurno;
    int muertesDelTurno;
    int turnos;
    int controlMuertes;
    int controlNacimientos;

} JuegoDeLaVida;

void inicializarJuegoDeLaVida(JuegoDeLaVida & juegoDeLaVida);
/* Esta funcion recibe como parametro una referencia a un struct juegoDeLaVida
e inicializa todas las Celulas en Muerta, todos los valores int en el correspondiente 
al comenzar el juego */

void imprimirJuegoDeLaVida(JuegoDeLaVida & juegoDeLaVida);
/* Esta funcion recibe como parametro una refencia a un struct juegoDeLaVida y lo imprime */

void imprimirEstadisticas(JuegoDeLaVida & juegoDeLaVida);

void cargarCelulasVivas(JuegoDeLaVida & juegoDeLaVida);

void interaccionesUsuario(JuegoDeLaVida & juegoDeLaVida);

void PasarTurno(JuegoDeLaVida & juegoDeLaVida);

void PasarEstado(JuegoDeLaVida & juegoDeLaVida);

void imprimirSeparador(JuegoDeLaVida & juegoDeLaVida);

#endif //JUEGODELAVIDA_H_