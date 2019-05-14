#include "Bala.h"


struct BalaRep{
    double x;
    double y;
    double w;
    double h;
    double vx;
    double vy;
    Imagen imagenBala;

};



Bala crea_bala(double x, double y, Imagen imagenBala){
    Bala bala = malloc(sizeof(struct BalaRep));

    int M = -20;
    int N = 20;


    bala->x = x;
    bala->y = y;
    bala->vx =  rand () % (N-M+1) + M;   // Este está entre M y N
    bala->vy =  rand () % (N-M+1) + M; // Este está entreo 20 y 30

    bala->imagenBala = imagenBala;

    bala->w = 20;
    bala->h = 20;

    return bala;
}


void libera_bala(Bala bala){
    free(bala);
}

void mueve_bala(Bala bala){
    bala->x = bala->x - bala->vx;
    bala->y = bala->y + bala->vy;
}

void dibuja_bala( Bala bala){
    Pantalla_DibujaImagen(bala->imagenBala, bala->x, bala -> y, bala -> w, bala -> h);
}

double get_x_bala(Bala bala){
    return bala->x;
}

double get_y_bala(Bala bala){
    return bala->y;
}

double get_w_bala(Bala bala){
    return bala->w;
}
double get_h_bala(Bala bala){
    return bala->h;
}

int colision_bala( Bala b, double x, double y, double w, double h ){
    return solape_rectangulos(b->x, b->y, b->w, b->h, x, y, w, h);
}
