#include "JuegoDeLaVida.h"

void imprimirSeparador(JuegoDeLaVida & juegoDeLaVida) {
    string::size_type separador = juegoDeLaVida.tablero.anchoMaximo*2; 
    for(int i = 0; i != separador; ++i) {
        cout<<"—";
    }
    cout<<endl;
}

void imprimirJuegoDeLaVida(JuegoDeLaVida & juegoDeLaVida) {

    Tablero & tablero = juegoDeLaVida.tablero;

    int altoMaximo = getAltoMaximo(tablero);
    int anchoMaximo = getAnchoMaximo(tablero);

    cout<<"JUEGO DE LA VIDA 1.0"<<endl;

    imprimirSeparador(juegoDeLaVida);

    for(int i = 0; i < altoMaximo; i++) {
        cout<<"|";
        for(int j = 0; j < anchoMaximo; j++) {
            Celula celula = getValor(tablero, i , j);
            if (celula.Estado == Viva){
                cout<<"O|";
            } else {
                cout<<" |";
            }
        }
        cout<<endl;
    }
    imprimirSeparador(juegoDeLaVida);
}


void imprimirEstadisticas(JuegoDeLaVida & juegoDeLaVida) {
    cout<<"ESTADISTICAS"<<endl;
    cout<<"CV: "<<juegoDeLaVida.celulasVivas<<" CQN: "<<juegoDeLaVida.nacimientosDelTurno<<" CQM: "<<juegoDeLaVida.muertesDelTurno<<endl;
    float promedioDeNacimientos = (float)juegoDeLaVida.nacimientosTotales / (float)juegoDeLaVida.turnos;
    float promedioDeMuertes = (float)juegoDeLaVida.muertesTotales /  (float)juegoDeLaVida.turnos;
    cout<<"PN: "<<promedioDeNacimientos<<" PM: "<<promedioDeMuertes<<endl;
}

void inicializarJuegoDeLaVida(JuegoDeLaVida & juegoDeLaVida) {
    Tablero & tablero = juegoDeLaVida.tablero;
    juegoDeLaVida.celulasVivas = 0;
    juegoDeLaVida.muertesDelTurno = 0;
    juegoDeLaVida.muertesTotales = 0;
    juegoDeLaVida.nacimientosDelTurno = 0;
    juegoDeLaVida.nacimientosTotales = 0;
    juegoDeLaVida.turnos = 1;
    juegoDeLaVida.controlMuertes = juegoDeLaVida.muertesTotales;
    juegoDeLaVida.controlNacimientos = juegoDeLaVida.nacimientosTotales;
    inicializarTablero(tablero);
}

void cargarCelulasVivas(JuegoDeLaVida & juegoDeLaVida) {
    int i, j;
    cout<<"Si desea ingresar una Celula viva introduzca el primer valor - Enter y segundo valor - Enter, de lo contrario presione cualquier letra"<<endl;
    while (cin >> i >> j) {
        if (i <= 0 || j <= 0 || i > juegoDeLaVida.tablero.anchoMaximo || j > juegoDeLaVida.tablero.altoMaximo) {
            cout<<"Celula Inválida, por favor ingrese otra:"<<endl;
            continue;
        }
        cambiarEstado(juegoDeLaVida.tablero.Tablero[j-1][i-1], Viva);
        ++juegoDeLaVida.celulasVivas; 
        ++juegoDeLaVida.nacimientosDelTurno;
        ++juegoDeLaVida.nacimientosTotales;
        cout<<"Si no quiere agregar otra presione cualquier letra y Enter"<<endl;
    }
}

void checkearEstado(JuegoDeLaVida & juegoDeLaVida) {
    Tablero tablero = juegoDeLaVida.tablero;
    Tablero tableroAux = juegoDeLaVida.tableroAux; 
    for(int i = 0; i < getAltoMaximo(tablero); i++) {
        for(int j = 0; j < getAnchoMaximo(tablero); j++) {
            int celulasVivasAlrededor = 0;
            int maxi = i+1;
            int mini = i-1;
            int maxj = j+1;
            int minj = j-1; 
            for(int k = mini; k <= maxi; k++) {
                for(int m = minj; m <= maxj; m++) {
                    if(k >= 0 && m >= 0 && k < 80 && m < 80) {
                        Celula celula = getValor(tableroAux,k,m);
                        if(celula.Estado == Viva) {
                            if(i == k && j == m) {
                                celulasVivasAlrededor--;
                            }
                            celulasVivasAlrededor++;
                        }
                    } 
                }    
            }
            //cout<<celulasVivasAlrededor;
            //Celula celula = getValor(tablero, i, j);
            //cout<<celula.Estado<<" ";
            //Celula celulaAux = getValor(tableroAux, i, j);
            //cout<<i<<" "<<j<<" "<<endl;
            if(juegoDeLaVida.tableroAux.Tablero[i][j].Estado == Muerta && celulasVivasAlrededor == 3) {
                juegoDeLaVida.tablero.Tablero[i][j].Estado = Viva;
                juegoDeLaVida.celulasVivas++;
                juegoDeLaVida.nacimientosDelTurno++;
                juegoDeLaVida.nacimientosTotales++;
            }    
            if(juegoDeLaVida.tableroAux.Tablero[i][j].Estado == Viva) {
                if(celulasVivasAlrededor != 2 || celulasVivasAlrededor != 3) {
                    juegoDeLaVida.tablero.Tablero[i][j].Estado = Muerta;
                    juegoDeLaVida.celulasVivas--;
                    juegoDeLaVida.muertesDelTurno++;
                    juegoDeLaVida.muertesTotales++;
                }
            } 
            //cout<<celula.Estado<<" "<<endl;
        }
    }
}

void pasarTurno(JuegoDeLaVida & juegoDeLaVida) {

    for(int i = 0; i < getAltoMaximo(juegoDeLaVida.tablero); i++) {
        for(int j = 0; j < getAnchoMaximo(juegoDeLaVida.tablero); j++) {
            juegoDeLaVida.tableroAux.Tablero[i][j].Estado = juegoDeLaVida.tablero.Tablero[i][j].Estado;
        }
    }
    checkearEstado(juegoDeLaVida);
    juegoDeLaVida.turnos++;
    if(juegoDeLaVida.controlMuertes == juegoDeLaVida.muertesTotales && juegoDeLaVida.controlNacimientos == juegoDeLaVida.nacimientosTotales) {
        cout<<"El juego esta congelado, presione 2 para reiniciar o 3 para cerrar"<<endl;
    }
    juegoDeLaVida.controlMuertes = juegoDeLaVida.muertesTotales;
    juegoDeLaVida.controlNacimientos = juegoDeLaVida.nacimientosTotales;
}

void interaccionesUsuario(JuegoDeLaVida & juegoDeLaVida) {
    int numeroIngresado;
    cin.clear();
    cin.ignore( 100, '\n' );
    cout<<"Presione 1 para avanzar un turno, 2 para reiniciar el juego, 3 o cualquier otro digito para cerrarlo"<<endl;
    while(cin>>numeroIngresado) {
        cout<<"Presione 1 para avanzar un turno, 2 para reiniciar el juego, 3 o cualquier otro digito para cerrarlo"<<endl;
        if(numeroIngresado == 1) {
            pasarTurno(juegoDeLaVida);
            imprimirJuegoDeLaVida(juegoDeLaVida);
            imprimirEstadisticas(juegoDeLaVida);
            continue;
        }
        if(numeroIngresado == 2) {
            inicializarJuegoDeLaVida(juegoDeLaVida);
            cargarCelulasVivas(juegoDeLaVida);
            imprimirJuegoDeLaVida(juegoDeLaVida);
            imprimirEstadisticas(juegoDeLaVida);
            interaccionesUsuario(juegoDeLaVida);
        }
        if(numeroIngresado == 3) {
            return;
        } else {
            return;
        }
        }
    }
