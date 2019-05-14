#include "Colisiones.h"
#include "Pantalla.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>



int dentro_rectangulo( int x, int y, int w, int h, int px, int py ){
    return (px>=x)&&(px<=(x+w))&&(py>=y)&&(py<=(y+h));
}

double distancia_punto_punto( double x1, double y1, double x2, double y2 ){
    return sqrt(pow(x2-x1,2) + pow(y2-y1,2));
}

int solape_circunferencias(int x1, int y1, int r1, int x2, int y2, int r2 ){
    return (distancia_punto_punto(x1,y1,x2,y2)<=(r1+r2));
}

int solape_rectangulos(double x1, double y1, double w1, double h1, double x2, double y2, double w2, double h2){
    return !(x1> x2+w2) && !(x1+w1 < x2) && !(y1 > y2 + h2) && !(y1+h1 < y2);
}


