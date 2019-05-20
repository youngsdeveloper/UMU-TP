/**
 * @file Colisiones.h
 * @brief Fichero de cabecera para funciones auxiliares para las colisiones
 * 
 */
#ifndef __Colisiones_H__
#define __Colisiones_H__


/**
 * @brief Devuelve 1 si el punto (px,py) estan dentros del rectangulo(x,y,w,h)
 * 
 * @param x Coordenada x del rectangulo
 * @param y Coordenada y del rectangulo
 * @param w Anchura del rectangulo
 * @param h Altura del rectangulo
 * @param px Coordenada x del punto
 * @param py Coordenada y del punto
 * @return int Devuelve 1 si el punto esta dentro del rectangulo, 0 en caso contrario
 */
int dentro_rectangulo( int x, int y, int w, int h, int px, int py );

/**
 * @brief Calcula la distancia de dos puntos
 * 
 * @param x1 Coordenada x del punto 1
 * @param y1 Coordenada y del punto 1
 * @param x2 Coordenada x del punto 2
 * @param y2 Coordenada y del punto 2
 * @return double Distancia de (x1,y1) y (x2,y2)
 */
double distancia_punto_punto( double x1, double y1, double x2, double y2 );

/**
 * @brief Devuelve 1 si se solapan las circunferencias (x1,y1,r1) y (x2,y2,r2)
 * 
 * @param x1 Coordenada x de la circunferencia 1
 * @param y1 Coordenada y de la circunferencia 1
 * @param r1 Radio de la circunferencia 1
 * @param x2 Coordenada x de la circunferencia 2
 * @param y2 Coordenada y de la circunferencia 2
 * @param r2 Radio de la circunferencia 2
 * @return int Devuelve 1 si se solapan las circunferencias (x1,y1,r1) y (x2,y2,r2)
 */
int solape_circunferencias(int x1, int y1, int r1, int x2, int y2, int r2 );

/**
 * @brief Devuelve 1 si se solapan los rectangulos (x1,y1,w1,h1) y (x2,y2,w2,h2)
 * 
 * @param x1 Coordenada x del rectangulo 1
 * @param y1 Coordenada y del rectangulo 1
 * @param w1 Anchura del rectangulo 1
 * @param h1 Altura del rectangulo 1
 * @param x2 Coordenada x del rectangulo 2
 * @param y2 Coordenada y del rectangulo 2
 * @param w2 Anchura del rectangulo 2
 * @param h2 Altura del rectangulo 2

 * @return int Devuelve 1 si se solapan los rectangulos (x1,y1,w1,h1) y (x2,y2,w2,h2)
 */
int solape_rectangulos(double x1, double y1, double w1, double h1, double x2, double y2, double w2, double h2);

/**
 * @brief Devulve 1 si se solapa la circunferencia (cx,cy,r) y el rectangulo (x,y,w,h)
 * @param cx Coordenada x de la circunferencia
 * @param cy Coordenada y de la circunferencia
 * @param r Radio de la circunferencia

 * @param x Coordenada x del rectangulo
 * @param y Coordenada y del rectangulo
 * @param w Anchura del rectangulo
 * @param h Altura del rectangulo
 */
int solape_circuferencia_rectangulo(double cx, double cy,double r,double x,double y,double w,double h);

#endif
