#include "JuegoDeLaVida.cpp"
#include "Celula.cpp"
#include "Tablero.cpp"

int main() {
    JuegoDeLaVida juegoDeLaVida;
    JuegoDeLaVida & juego = juegoDeLaVida;
    inicializarJuegoDeLaVida(juego);
    cargarCelulasVivas(juego);
    imprimirJuegoDeLaVida(juego);
    imprimirEstadisticas(juego);
    interaccionesUsuario(juego);
    return 0;   
}
    
