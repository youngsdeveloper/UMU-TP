#include <stdio.h>
#include <stdlib.h>
#include <math.h>


#include "Pantalla.h"
#include "Colisiones.h"
#include "Bala.h"
#include "Rafaga.h"
#include "Player.h"
#include "Enemy.h"
#include "Plataforma.h"
#include "ListaPlataformas.h"


int MAX_PANTALLA = 500;
int jugando = 1;


#define M_PI 3.14159265358979323846264338327


double x_mouse;
double y_mouse;


int pressed = 0;


double angulo;
double fuerza_disparo;

int main( int argc, char *argv[] ){

    Player player = crea_player();
    Enemy enemy = crea_enemy();

    NodoPlataforma cabeceraPlataformas = nuevo_nodo_plataforma(NULL);


    Pantalla_Crea("Sesion 6", 1000, MAX_PANTALLA);
    Pantalla_DibujaRellenoFondo(2555,255,255,255);
    Pantalla_ColorTrazo(0,0,0,255);


    Plataforma plataforma = crea_plataforma(Pantalla_Anchura()/2-10,Pantalla_Altura()/2.5,20,Pantalla_Altura() - Pantalla_Altura()/2.5, 0, 1);
    inserta_plataforma(cabeceraPlataformas, plataforma);

    Plataforma plataforma2 = crea_plataforma(Pantalla_Anchura()-100,Pantalla_Altura()/2.5,100,10, 1, 0);
    inserta_plataforma(cabeceraPlataformas, plataforma2);


    Imagen imagenJugador = Pantalla_ImagenLee("pelota.bmp",255);
    Imagen imagenEnemigo = Pantalla_ImagenLee("apple.bmp",255);
    Imagen imagenBala = Pantalla_ImagenLee("bala.bmp",255);
    Imagen imagenSuelo = Pantalla_ImagenLee("ground.bmp",255);
    Imagen imagenFlecha = Pantalla_ImagenLee("flecha.bmp",255);
    Imagen imagenPower = Pantalla_ImagenLee("power.bmp",255);

    int ground_height = 40;


    NodoPtr cabecera = nuevo_nodo(NULL);

    while ( Pantalla_Activa() && jugando) {




        //Controles de direccion

        if(isDisparando(player) == 0){
            if (Pantalla_TeclaPulsada(SDL_SCANCODE_RIGHT)) {
                set_player_vx(player, 3);
                set_player_x(player, get_player_x(player) + get_player_vx(player));
                set_player_animacion_angulo(player, get_player_animacion_angulo(player)+15);
            }
            if (Pantalla_TeclaPulsada(SDL_SCANCODE_LEFT)) {
                set_player_vx(player, -3);
                set_player_x(player, get_player_x(player) + get_player_vx(player));
                set_player_animacion_angulo(player, get_player_animacion_angulo(player)-15);
            }   
        }


        /*
        if (Pantalla_TeclaPulsada(SDL_SCANCODE_UP)) {
            set_player_y(player, get_player_y(player) - get_player_vy(player));
        }
        if (Pantalla_TeclaPulsada(SDL_SCANCODE_DOWN)) {
            set_player_y(player, get_player_y(player) + get_player_vy(player));
        }*/
        if(Pantalla_TeclaPulsada(SDL_SCANCODE_SPACE) ){
            Bala bala = crea_bala(get_player_x(player), get_player_y(player), imagenBala);
            inserta_rafaga(cabecera, bala);
        }


        mueve_player(player);


        mueve_rafaga(cabecera);

        impactaBalaEnemigo(cabecera, enemy);

        mueve_enemy(enemy,player);

        if(!(get_player_x(player)>= get_enemy_x(enemy) + get_enemy_w(enemy)) && !(get_player_x(player)+get_player_w(player)<get_enemy_x(enemy)) && !(get_player_y(player)>=get_enemy_y(enemy) + get_enemy_h(enemy)) && !(get_player_y(player)+get_player_h(player)<get_enemy_y(enemy))){
            //jugando = 0;
        }

        //colisiones_plataforma(plataforma, player);

        colisiones_plataformas(cabeceraPlataformas, player);

        //Dibujamos

        //Fondo
        Pantalla_DibujaRellenoFondo(255,255,255, 255);

        dibuja_plataformas(cabeceraPlataformas);

        //Jugador
        Pantalla_DibujaImagenTransformada(imagenJugador, get_player_x(player), get_player_y(player), get_player_w(player), get_player_h(player), get_player_animacion_angulo(player), SDL_FLIP_HORIZONTAL);

        //Enemigo
        //Pantalla_DibujaImagen(imagenEnemigo, get_enemy_x(enemy) , get_enemy_y(enemy), get_enemy_w(enemy), get_enemy_h(enemy));


        //Rafaga de balas
        dibuja_rafaga(cabecera);


        //Dibujar escenario
        Pantalla_DibujaImagen(imagenSuelo, 0, MAX_PANTALLA-ground_height, Pantalla_Anchura(), ground_height);

        Pantalla_ColorRelleno(0,0,0,255);
        Pantalla_DibujaRectangulo(Pantalla_Anchura()-20-150,20,150,20);
        Pantalla_DibujaImagen(imagenPower, Pantalla_Anchura()-20-150-20, 20, 20, 20);


        if(Pantalla_RatonBotonPulsado(SDL_BUTTON_LEFT)){

            pressed = 1;

            if(isDisparando(player) == 0){
                Pantalla_RatonCoordenadas(&x_mouse, &y_mouse);
                Pantalla_ColorRelleno(0,0,0,255);
                Pantalla_ColorTrazo(0,0,0,255);


                double y_flecha = y_mouse - (get_player_y(player) + get_player_h(player)/ 2);
                double x_flecha = x_mouse - (get_player_x(player) + get_player_w(player)/ 2);

                angulo = atan2(y_flecha, x_flecha);

                Pantalla_DibujaLinea(get_player_x(player)+get_player_w(player)/2, get_player_y(player)+get_player_h(player)/2, x_mouse, y_mouse);
                
                double modulo_flecha = sqrt(pow(x_flecha, 2) + pow(y_flecha,2));

                double MAX_FUERZA = 250; //250 EN PRODUCCION
                double MN_FUERZA = 50;

                fuerza_disparo =  modulo_flecha*MAX_FUERZA/1000;
                if(fuerza_disparo<50){
                    fuerza_disparo = 50;
                }


                //Dibujamos flecha

                int longitud_flecha = 30;


                double x_flecha_1 = x_mouse +  longitud_flecha*cos(angulo - (M_PI + M_PI/6));
                double y_flecha_1 = y_mouse +  longitud_flecha*sin(angulo - (M_PI + M_PI/6));

                double x_flecha_2 = x_mouse +  longitud_flecha*cos(angulo - (M_PI - M_PI/6));
                double y_flecha_2 = y_mouse +  longitud_flecha*sin(angulo - (M_PI - M_PI/6));

                Pantalla_DibujaTriangulo(x_mouse, y_mouse, x_flecha_1, y_flecha_1, x_flecha_2, y_flecha_2);

                Pantalla_ColorRelleno(0, 148, 50, 255);
                
                double w_energy_bar = fuerza_disparo*(150/MAX_FUERZA);

                Pantalla_DibujaRectangulo(Pantalla_Anchura()-20-150,20,w_energy_bar,20);

            }



        }else{
            if(pressed==1){
                iniciarDisparo(player, angulo, fuerza_disparo);
                pressed = 0;
            }
        }
        //Siguiente Frame
        Pantalla_Actualiza();
        Pantalla_Espera(40);
    }


    Pantalla_ImagenLibera(imagenBala);

    Pantalla_Libera();


    return 0;
}


