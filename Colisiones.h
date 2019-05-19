#ifndef __Colisiones_H__
#define __Colisiones_H__



int dentro_rectangulo( int x, int y, int w, int h, int px, int py );
double distancia_punto_punto( double x1, double y1, double x2, double y2 );
int solape_circunferencias(int x1, int y1, int r1, int x2, int y2, int r2 );
int solape_rectangulos(double x1, double y1, double w1, double h1, double x2, double y2, double w2, double h2);
int solape_circuferencia_rectangulo(double cx, double cy,double rx,double x,double y,double w,double h);

#endif
