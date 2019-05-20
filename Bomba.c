#include "Bomba.h"


struct BombaRep{
    double x;
    double y;
    double w;
    double h;
    double vx;
    double vy;

    int exp;
    int vidaEliminada;

    Imagen imagenes[2];

};

Bomba crea_bomba(double x, double y, Imagen * imagenes){
    Bomba bomba = malloc(sizeof(struct BombaRep));


    bomba->x = x;
    bomba->y = y;
    bomba->vx =  0;
    bomba->vy =  10;

    bomba->imagenes[0] = imagenes[0];
    bomba->imagenes[1] = imagenes[1];

    bomba->w = 60;
    bomba->h = 60;

    bomba-> exp = 0;

    bomba -> vidaEliminada = 0;

    return bomba;
}

void libera_bomba(Bomba bomba){
    free(bomba);
}

void mueve_bomba(Bomba bomba){
    bomba->x = bomba->x + bomba->vx;
    bomba->y = bomba->y + bomba->vy;

    if(bomba -> exp == 1){
        bomba -> w = bomba -> w + 40;
        bomba -> h = bomba -> h + 40;
    }
    
}

void dibuja_bomba(Bomba bomba){

    Imagen imagenDibujar;

    if(bomba->exp==0){
        imagenDibujar = bomba -> imagenes[0];
        Pantalla_DibujaImagen(imagenDibujar, bomba->x, bomba -> y, bomba -> w, bomba -> h);
    }else{
        imagenDibujar = bomba -> imagenes[1];
        Pantalla_DibujaImagen(imagenDibujar, bomba->x-bomba->w/2, bomba -> y-bomba->h/2, bomba -> w, bomba -> h);
    }      
}

void colision_bomba(Bomba bomba, Player player, Ejercito ejercito){

    if(bomba -> y + bomba -> h > Pantalla_Altura()-40){
        bomba -> exp = 1;
        bomba -> vy = 0;
    }

    double cx = get_player_x(player)+get_player_w(player)/2;
    double cy = get_player_y(player)+get_player_h(player)/2;
    double rx = get_player_h(player)/2;


    if(bomba -> exp == 0){
        if(solape_circuferencia_rectangulo(cx,cy,rx,bomba->x ,bomba->y,bomba->w,bomba->h)==1){
            bomba -> exp = 1;
        }
    }else{
        if(solape_circuferencia_rectangulo(cx,cy,rx,bomba->x -bomba -> w/2 ,bomba->y - bomba -> h/2,bomba->w,bomba->h)==1){
            if(bomba -> vidaEliminada == 0){
                añadeVidas(player, -1);
                reset_ejercito(ejercito);
                bomba -> vidaEliminada = 1;
            }
            setExp_player(player, 1);

        }
    }
    
    if(colision_ejercito_bomba(ejercito, bomba->x, bomba -> y, bomba -> w, bomba -> h)){
        bomba -> exp = 1;
    }

}

double get_x_bomba(Bomba bomba){
    return bomba->x;
}

double get_y_bomba(Bomba bomba){
    return bomba->y;
}

double get_w_bomba(Bomba bomba){
    return bomba->w;
}
double get_h_bomba(Bomba bomba){
    return bomba->h;
}

