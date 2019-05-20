#include <stdio.h>
#include <stdlib.h>
#include <math.h>


#include "Pantalla.h"
#include "Colisiones.h"

#include "Player.h"
#include "Enemy.h"
#include "Ejercito.h"
#include "RafagaBomba.h"
#include "GameUtils.h"



int MAX_PANTALLA = 500;

int HIGH_SCORE;
int NEW_HIGH_SCORE = 0;



//#define M_PI 3.14159265358979323846264338327


double x_mouse;
double y_mouse;


int pressed = 0;


double angulo;
double fuerza_disparo;

/*
    1. Menu
    2. Juego
    3. Ayuda
    4. Pantalla POST-JUEGO
*/

int GAME_PANTALLA = 1;
int ground_height = 40;

int exitGame = 0; //Si es 1, sale del juego


void menu(){

    double anim_menu_x = Pantalla_Anchura()-50-10;
    double anim_menu_y = Pantalla_Altura()-50 - ground_height;

    double anim_menu_vx = 0;
    double anim_menu_vy = 0;

    Imagen logo1 = Pantalla_ImagenLee("logo1.bmp", 255);
    Imagen logo2 = Pantalla_ImagenLee("logo2.bmp", 255);

    Imagen btnPlay = Pantalla_ImagenLee("btnPlay.bmp", 255);
    Imagen btnAyuda = Pantalla_ImagenLee("btnAyuda.bmp", 255);
    Imagen btnSalir = Pantalla_ImagenLee("btnSalir.bmp", 255);

    Imagen imagenSuelo = Pantalla_ImagenLee("ground.bmp",255);

    Imagen imagenJugador = Pantalla_ImagenLee("pelota.bmp",255);



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

        Pantalla_DibujaImagen(btnPlay, btnPlay_x, btnPlay_y, btnPlay_w, btnPlay_h);


        double btnAyuda_x = 500-150/2;
        double btnAyuda_y = 200+50*1.5;
        double btnAyuda_w = 150;
        double btnAyuda_h = 50;

        Pantalla_DibujaImagen(btnAyuda, btnAyuda_x, btnAyuda_y, btnAyuda_w, btnAyuda_h); 


        int btnSalir_x = 500-150/2;
        int btnSalir_y = 200+50*3;
        int btnSalir_w = 150;
        int btnSalir_h = 50;

        Pantalla_DibujaImagen(btnSalir, btnSalir_x, btnSalir_y, btnSalir_w, btnSalir_h); 

        Pantalla_DibujaImagen(imagenSuelo, 0, MAX_PANTALLA-ground_height, Pantalla_Anchura(), ground_height);

        anim_menu_x = anim_menu_x + anim_menu_vx;
        anim_menu_y = anim_menu_y + anim_menu_vy;

        double x_mouse_new = 0;
        double y_mouse_new = 0;
        Pantalla_RatonCoordenadas(&x_mouse_new, &y_mouse_new);

        if(Pantalla_RatonBotonPulsado(SDL_BUTTON_LEFT)){

            if(dentro_rectangulo(btnPlay_x, btnPlay_y, btnPlay_w, btnPlay_h, x_mouse_new, y_mouse_new)){
                GAME_PANTALLA = 2; //Iniciar juego
            }

            if(dentro_rectangulo(btnAyuda_x, btnAyuda_y, btnAyuda_w, btnAyuda_h, x_mouse_new, y_mouse_new)){
                GAME_PANTALLA = 3; //Ir a ayuda
            }

            if(dentro_rectangulo(btnSalir_x, btnSalir_y, btnSalir_w, btnSalir_h, x_mouse_new, y_mouse_new)){
                GAME_PANTALLA  = 0;
                exitGame = 1; //Salir del juego
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

        //Puntuacion
        char puntos_str [1000];
        sprintf(puntos_str, "MAXIMA PUNTUACION: %d puntos", HIGH_SCORE);
        Pantalla_DibujaTexto(puntos_str, 20, Pantalla_Altura()-60);


        Pantalla_Actualiza();
        Pantalla_Espera(40);

    }

    Pantalla_ImagenLibera(logo1);
    Pantalla_ImagenLibera(logo2);

    Pantalla_ImagenLibera(btnPlay);
    Pantalla_ImagenLibera(btnAyuda);
    Pantalla_ImagenLibera(btnSalir);

    Pantalla_ImagenLibera(imagenSuelo);

    Pantalla_ImagenLibera(imagenJugador);

}


void pantallaPostJuego(Player player){

    Imagen logo = Pantalla_ImagenLee("logo1.bmp", 255);
    Imagen btnVolverMenu = Pantalla_ImagenLee("btnVolverMenu.bmp", 255);


    while ( Pantalla_Activa() && GAME_PANTALLA == 4) {
        Pantalla_DibujaRellenoFondo(2555,255,255,255);


        //LOGO

        double logo_x = 500-200;
        double logo_y = 50;
        double logo_w = 400;
        double logo_h = 100;
        Pantalla_DibujaImagen(logo, logo_x, logo_y, logo_w, logo_h);


        //Puntuacion
        int puntos = getPuntos(player);
        char puntos_str [1000];
        sprintf(puntos_str, "Puntuacion: %d puntos", puntos);
        Pantalla_DibujaTexto(puntos_str, logo_x+100, 200);

        char puntos_record_str [1000];
        sprintf(puntos_record_str, "RECORD: %d puntos", HIGH_SCORE);
        Pantalla_DibujaTexto(puntos_record_str, logo_x+100, 230);


        if(NEW_HIGH_SCORE==1){
            Pantalla_DibujaTexto("Has logrado un nuevo record!", logo_x+100, 260);
        }

        //VOLVER AL MENU

        double btnVolverMenu_w = 200;
        double btnVolverMenu_h = 50;

        double btnVolverMenu_x = Pantalla_Anchura()/2 - btnVolverMenu_w/2;
        double btnVolverMenu_y = Pantalla_Altura()-btnVolverMenu_h-50;
        Pantalla_DibujaImagen(btnVolverMenu, btnVolverMenu_x, btnVolverMenu_y, btnVolverMenu_w, btnVolverMenu_h);


        double x_mouse_new = 0;
        double y_mouse_new = 0;
        Pantalla_RatonCoordenadas(&x_mouse_new, &y_mouse_new);

        if(Pantalla_RatonBotonPulsado(SDL_BUTTON_LEFT)){
            if(dentro_rectangulo(btnVolverMenu_x, btnVolverMenu_y, btnVolverMenu_w, btnVolverMenu_h, x_mouse_new, y_mouse_new)){
                GAME_PANTALLA = 1;
            }

        }

        Pantalla_Actualiza();
        Pantalla_Espera(40);
    }

    Pantalla_ImagenLibera(logo);
    Pantalla_ImagenLibera(btnVolverMenu);

    libera_player(player); //Liberamos la memoria del player aqui para obtener la información de la partida


    GAME_PANTALLA = 1;
    menu();
}

void ayuda(){
    

    Imagen btnAtras = Pantalla_ImagenLee("btnAtras.bmp", 255);
    Imagen btnSiguiente = Pantalla_ImagenLee("btnSiguiente.bmp", 255);
    Imagen btnVolverMenu = Pantalla_ImagenLee("btnVolverMenu.bmp", 255);


    int M = 4; //NUMERO DE PANTALLAS
    Imagen imagenesAyuda[M];
    imagenesAyuda[0] = Pantalla_ImagenLee("ayuda1.bmp", 255);
    imagenesAyuda[1] = Pantalla_ImagenLee("ayuda2.bmp", 255);
    imagenesAyuda[2] = Pantalla_ImagenLee("ayuda3.bmp", 255);
    imagenesAyuda[3] = Pantalla_ImagenLee("ayuda4.bmp", 255);

    int n = 0;
    int click_block = 0;


    while ( Pantalla_Activa() && GAME_PANTALLA == 3) {
    
        Pantalla_DibujaRellenoFondo(2555,255,255,255);
    
        double btnAtras_w = 60;
        double btnAtras_h = 50;

        double btnAtras_x = Pantalla_Anchura()/2 - btnAtras_w - 30;
        double btnAtras_y = Pantalla_Altura()-btnAtras_h-30;
        if(n>0){
            Pantalla_DibujaImagen(btnAtras, btnAtras_x, btnAtras_y, btnAtras_w, btnAtras_h);
        }

        double btnSiguiente_w = 60;
        double btnSiguiente_h = 50;

        double btnSiguiente_x = Pantalla_Anchura()/2 + 30;
        double btnSiguiente_y = Pantalla_Altura()-btnAtras_h-30;


        if(n+1 < M){
            Pantalla_DibujaImagen(btnSiguiente, btnSiguiente_x, btnSiguiente_y, btnSiguiente_w, btnSiguiente_h);
        }

        double btnVolverMenu_w = 200;
        double btnVolverMenu_h = 50;

        double btnVolverMenu_x = 20;
        double btnVolverMenu_y = Pantalla_Altura()-btnAtras_h-30;
        Pantalla_DibujaImagen(btnVolverMenu, btnVolverMenu_x, btnVolverMenu_y, btnVolverMenu_w, btnVolverMenu_h);

       

        if(Pantalla_RatonBotonPulsado(SDL_BUTTON_LEFT) && click_block==0){

            click_block = 1;

            double x_mouse_new = 0;
            double y_mouse_new = 0;
            Pantalla_RatonCoordenadas(&x_mouse_new, &y_mouse_new);

            if(dentro_rectangulo(btnSiguiente_x, btnSiguiente_y, btnSiguiente_w, btnSiguiente_h, x_mouse_new, y_mouse_new)){
                if(n+1 < M){n++;}
            }

            if(dentro_rectangulo(btnAtras_x, btnAtras_y, btnAtras_w, btnAtras_h, x_mouse_new, y_mouse_new)){
                if(n>0){
                    n--;
                }
            }

            if(dentro_rectangulo(btnVolverMenu_x, btnVolverMenu_y, btnVolverMenu_w, btnVolverMenu_h, x_mouse_new, y_mouse_new)){
                GAME_PANTALLA = 1;
            }

            

        }else{
            click_block = 0;
        }


        Pantalla_DibujaImagen(imagenesAyuda[n],20,20,Pantalla_Anchura()-20*2,Pantalla_Altura()-btnAtras_h-30-20-20);
        //960 x 380px

        Pantalla_Actualiza();
        Pantalla_Espera(40);
    }

    Pantalla_ImagenLibera(btnAtras);
    Pantalla_ImagenLibera(btnSiguiente);
    Pantalla_ImagenLibera(btnVolverMenu);
    for(int j=0;j<M-1;j++){
        Pantalla_ImagenLibera(imagenesAyuda[j]);
    }


}


int pausa = 0;

void juego(){

    Player player = crea_player();
    Ejercito ejercito = crea_ejercito();

    NodoBombaPtr cabeceraBombas = nuevo_nodo_bomba(NULL);

    Pantalla_DibujaRellenoFondo(2555,255,255,255);
    Pantalla_ColorTrazo(0,0,0,255);


    Imagen imagenAlert = Pantalla_ImagenLee("alert.bmp",255);

    Imagen imagenSuelo = Pantalla_ImagenLee("ground.bmp",255);
    Imagen imagenPower = Pantalla_ImagenLee("power.bmp",255);
    Imagen imagenCielo = Pantalla_ImagenLee("cielo.bmp",255);
    Imagen imagenBomba = Pantalla_ImagenLee("bomba.bmp",255);
    Imagen imagenBombaExp = Pantalla_ImagenLee("explosion.bmp",255);

    genera_ejercito(ejercito, 10);



    int jugando = 1;

    NEW_HIGH_SCORE = 0;


    while ( Pantalla_Activa() && jugando == 1) {

        //Controles de direccion

        if(cuenta_ejercito(ejercito)<=1){
            
            genera_ejercito(ejercito, 10);
                
            
            Imagen imagenes[2];
        
            imagenes[0] = imagenBomba;
            imagenes[1] = imagenBombaExp;

            Imagen * ptrImages = imagenes;
            double x_bomba = genera_aleatorio(0,400);
            Bomba bomba = crea_bomba(x_bomba,0,ptrImages);
            inserta_bomba(cabeceraBombas, bomba);
        }

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

        if(Pantalla_TeclaPulsada(SDL_SCANCODE_SPACE) ){
            
            //Pausa
            if(pausa == 0){
                pausa = 1;
            }else{
                pausa = 0;
            }
            
        }

    
        if(pausa==0){ //Movimiento si no está pausado
            mueve_player(player);
            mueve_ejercito(ejercito, player);
            mueve_rafaga_bomba(cabeceraBombas, player);
        }



        colision_ejercito(ejercito, player);
        colision_rafaga_bomba(cabeceraBombas, player, ejercito);
        

        //Dibujamos

        //Fondo
        Pantalla_DibujaRellenoFondo(73,168,228,255);
        Pantalla_DibujaImagen(imagenCielo, 0, 0, Pantalla_Anchura(), Pantalla_Altura() - ground_height/2);


        //Enemigos
        dibuja_ejercito(ejercito); //Le pasamos como parametro si debe o no animar el pajaro


        //Bombas
        dibuja_rafaga_bomba(cabeceraBombas);
            
        
        //Dibujar escenario
        Pantalla_DibujaImagen(imagenSuelo, 0, MAX_PANTALLA-ground_height, Pantalla_Anchura(), ground_height);

        //Jugador
        dibuja_player(player);
        
    

        //Puntuacion
        int puntos = getPuntos(player);


        if(puntos>HIGH_SCORE){
            HIGH_SCORE = puntos;
            NEW_HIGH_SCORE = 1;
        }

        char puntos_str [1000];
        sprintf(puntos_str, "%d puntos (Record: %d)", puntos, HIGH_SCORE);
        if(NEW_HIGH_SCORE==1){
            strcat(puntos_str," NUEVO RECORD!");
        }
        Pantalla_DibujaTexto(puntos_str, 10, 10);

    
        //Vidas
        char vidas_str [1000];
        int vidas = getVidas(player);
        sprintf(vidas_str, "%d vidas", vidas);

        Pantalla_DibujaTexto(vidas_str, 10, 30);
        
        if(vidas <= 0 || Pantalla_TeclaPulsada(SDL_SCANCODE_ESCAPE)){
            jugando = 0; //Si se presiona ESC o te quedas sin vidas, termina la partida
        }

        if(vidas < 3){
            Pantalla_DibujaImagen(imagenAlert, 80,30-25/2 + 5, 25,25);
        }

        if(pausa==1){
            Pantalla_DibujaTexto("PAUSA. Presiona espacio para reanudar.", Pantalla_Anchura()/2 - 8*37/2, Pantalla_Altura()/2 - 13);
        }
        
        
        Pantalla_ColorRelleno(0,0,0,255);
        Pantalla_DibujaRectangulo(Pantalla_Anchura()-20-150,20,150,20);
        Pantalla_DibujaImagen(imagenPower, Pantalla_Anchura()-20-150-20, 20, 20, 20);


        if(Pantalla_RatonBotonPulsado(SDL_BUTTON_LEFT) && pausa==0){

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


    //Si hay un nuevo record, grabar nuevo record
    if(NEW_HIGH_SCORE == 1){
        FILE *fp;
        fp = fopen("gamedata.txt","w"); 
        
        fprintf(fp, "high_score: %i", HIGH_SCORE);
        fclose(fp);
    }

    //Liberamos memoria

    libera_ejercito(ejercito);
    libera_rafaga_bomba(cabeceraBombas);

    Pantalla_ImagenLibera(imagenAlert);
    Pantalla_ImagenLibera(imagenSuelo);
    Pantalla_ImagenLibera(imagenPower);
    Pantalla_ImagenLibera(imagenCielo);
    Pantalla_ImagenLibera(imagenBomba);
    Pantalla_ImagenLibera(imagenBombaExp);


    //Ir al post-game
    GAME_PANTALLA = 4; //Menu
    pantallaPostJuego(player);
}



int main( int argc, char *argv[] ){

    srand (time(NULL));



    //Leemos la puntuacion más alta, si el archivo no existe, creamos uno nuevo con puntuacion cero
    FILE *fp;
     
    if( (fp = fopen("gamedata.txt","r")) ){
        fscanf(fp, "high_score: %i", &HIGH_SCORE);
        //El archivo existe, vamos a leer la puntuacion
    }else{
        fp = fopen("gamedata.txt","w"); 
        fprintf(fp, "high_score: %i", 0);
        //No existe el archivo, creamos un nuevo archivo de datos con 0 puntos
    }
    fclose(fp);

    

    Pantalla_Crea("MalditoPajaro", 1000, MAX_PANTALLA);
    
    while ( Pantalla_Activa() && exitGame == 0) {
    
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


