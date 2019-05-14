#include <stdio.h>
#include <stdlib.h>
#include <math.h>


#include "Pantalla.h"
#include "Colisiones.h"
#include "Bala.h"
#include "Rafaga.h"
#include "Player.h"
#include "Enemy.h"
#include "Ejercito.h"



int MAX_PANTALLA = 500;
int jugando = 1;


#define M_PI 3.14159265358979323846264338327


double x_mouse;
double y_mouse;


int pressed = 0;


double angulo;
double fuerza_disparo;

/*

    1. Menu

    2. Juego

*/

int GAME_PANTALLA = 1;
    int ground_height = 40;




void menu(){

    double anim_menu_x = Pantalla_Anchura()-50-10;
    double anim_menu_y = Pantalla_Altura()-50 - ground_height;

    double anim_menu_vx = 0;
    double anim_menu_vy = 0;

    Imagen logo1 = Pantalla_ImagenLee("logo1.bmp", 255);
    Imagen logo2 = Pantalla_ImagenLee("logo2.bmp", 255);

    Imagen logo = logo1;

    double x_mouse;
    double y_mouse;

    Pantalla_RatonCoordenadas(&x_mouse, &y_mouse);

    int animationStart = 0;


    while ( Pantalla_Activa() && GAME_PANTALLA == 1) {
    
        Pantalla_DibujaRellenoFondo(2555,255,255,255);



        double logo_x = 500-200;
        double logo_y = 50;
        double logo_w = 400;
        double logo_h = 100;


        Pantalla_DibujaImagen(logo, logo_x, logo_y, logo_w, logo_h);

        double btnPlay_x = 500-150/2;
        double btnPlay_y = 200;
        double btnPlay_w = 150;
        double btnPlay_h = 50;

        Imagen btnPlay = Pantalla_ImagenLee("btnPlay.bmp", 255);
        Pantalla_DibujaImagen(btnPlay, btnPlay_x, btnPlay_y, btnPlay_w, btnPlay_h);


        Imagen btnAyuda = Pantalla_ImagenLee("btnAyuda.bmp", 255);
        Pantalla_DibujaImagen(btnAyuda, 500-150/2,200+50*1.5,150,50); 

        Imagen imagenSuelo = Pantalla_ImagenLee("ground.bmp",255);
        Pantalla_DibujaImagen(imagenSuelo, 0, MAX_PANTALLA-ground_height, Pantalla_Anchura(), ground_height);

        Imagen imagenJugador = Pantalla_ImagenLee("pelota.bmp",255);

        anim_menu_x = anim_menu_x + anim_menu_vx;
        anim_menu_y = anim_menu_y + anim_menu_vy;

        double x_mouse_new = 0;
        double y_mouse_new = 0;
        Pantalla_RatonCoordenadas(&x_mouse_new, &y_mouse_new);

        if(Pantalla_RatonBotonPulsado(SDL_BUTTON_LEFT)){
             if(dentro_rectangulo(btnPlay_x, btnPlay_y, btnPlay_w, btnPlay_h, x_mouse_new, y_mouse_new)){
                GAME_PANTALLA = 2;
            }   
        }



       

        if(x_mouse!=x_mouse_new || y_mouse != y_mouse_new){
            animationStart = 1;
        }

        if(animationStart==1){
            anim_menu_vx = anim_menu_vx - 3;
            anim_menu_vy = anim_menu_vy - 3;
        }




        Pantalla_DibujaImagen(imagenJugador, anim_menu_x, anim_menu_y, 50, 50);

        if(solape_rectangulos(anim_menu_x, anim_menu_y, 50, 50, logo_x, logo_y, logo_w, logo_h)){
            logo = logo2;
        }

    

        Pantalla_Actualiza();
        Pantalla_Espera(40);

    }

    

}

void ayuda(){
    Pantalla_DibujaRellenoFondo(2555,255,255,255);
    Pantalla_DibujaTexto("¿Te ayudamos?", 100, 100);

    Pantalla_DibujaTexto("Haz click para jugar ya", 100, 400);
    if(Pantalla_TeclaPulsada(SDL_SCANCODE_SPACE) ){
        GAME_PANTALLA = 2;
    }

}

int juego(){

    Player player = crea_player();
    Ejercito ejercito = crea_ejercito();


    Pantalla_DibujaRellenoFondo(2555,255,255,255);
    Pantalla_ColorTrazo(0,0,0,255);




    Imagen imagenJugador = Pantalla_ImagenLee("pelota.bmp",255);
    Imagen imagenEnemigo = Pantalla_ImagenLee("apple.bmp",255);
    Imagen imagenBala = Pantalla_ImagenLee("bala.bmp",255);
    Imagen imagenSuelo = Pantalla_ImagenLee("ground.bmp",255);
    Imagen imagenFlecha = Pantalla_ImagenLee("flecha.bmp",255);
    Imagen imagenPower = Pantalla_ImagenLee("power.bmp",255);


   
    genera_ejercito(ejercito, 200);


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
        mueve_ejercito(ejercito);

        //impactaBalaEnemigo(cabecera, enemy);

        //mueve_enemy(enemy,player);

        colision_ejercito(ejercito, player);

        

        //Dibujamos

        //Fondo
        Pantalla_DibujaRellenoFondo(255,255,255, 255);


        //Jugador
        Pantalla_DibujaImagenTransformada(imagenJugador, get_player_x(player), get_player_y(player), get_player_w(player), get_player_h(player), get_player_animacion_angulo(player), SDL_FLIP_HORIZONTAL);

        //Enemigo

        dibuja_ejercito(ejercito);

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

}

int main( int argc, char *argv[] ){

    Pantalla_Crea("MalditoPajaro", 1000, MAX_PANTALLA);
    
    while ( Pantalla_Activa()) {
    
        switch(GAME_PANTALLA){
            case 1:
                menu();
                break;

            case 2:
                juego();
                break;

            case 3:
                ayuda();
                break;

        }

        Pantalla_Actualiza();
        Pantalla_Espera(40);

    }

    Pantalla_Libera();




    


    return 0;
}


