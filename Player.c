#include "Player.h"

struct PlayerRep{
    double x;
    double y;
    double vx;
    double vy;
    int w;
    int h;

    int disparando;
    int block_ground;

    int vida_aviso;

    double disparando_angulo;

    double animacion_angulo;

    double t;

    int puntos;
    int vidas;

    Imagen imagenes[2]; 

    int exp;

};





Player crea_player(){
    Player player = malloc(sizeof(struct PlayerRep));

    player-> w = 50;
    player-> h = 50;


    player -> x = 50;

    player -> y = Pantalla_Altura() - 40 - player->h;



    player -> vx = 0;
    player -> vy = 0;

    player -> disparando = 0;
    player -> disparando_angulo = 0;
    player -> animacion_angulo = 0;
    player -> vida_aviso = 0;


    player -> block_ground = 0;

    player -> t = 0;
    player -> puntos = 0;
    player -> vidas = 3;

    player -> imagenes[0] = Pantalla_ImagenLee("pelota.bmp",255);
    player -> imagenes[1] = Pantalla_ImagenLee("player_exp.bmp",255);

    player -> exp = 0;

    return player;
}

void libera_player(Player player){

    Pantalla_ImagenLibera(player -> imagenes[0]);
    Pantalla_ImagenLibera(player -> imagenes[1]);

    free(player); 
}

int getExp_player(Player player){
    return player -> exp;
}

void setExp_player(Player player, int exp){
    player -> exp = exp;
}

int isDisparando(Player player){
    return (player -> y < Pantalla_Altura()-40-player->h) && fabs(player -> vx) > 0.1;
}

void sumaPuntos(Player player, int puntos){
    player -> puntos+=puntos;
    if(player->puntos<0){
        player -> puntos = 0; //Minimo 0 puntos 
    }
}

int getPuntos(Player player){
    return player -> puntos;
}

void sumaVidas(Player player, int vidas){
    player -> vidas+=vidas;

    if(vidas==-1){
        player -> vida_aviso = 200;
    }

    if(player->vidas<0){
        player -> vidas = 0; //Minimo 0 puntos 
    }
}

int getVidasAviso(Player player){
    return player -> vida_aviso;
}



int getVidas(Player player){
    return player -> vidas;
}



void iniciarDisparo(Player player, double angulo, double fuerza_disparo){
    if(isDisparando(player) == 0){
        player -> disparando = 1;
        player -> disparando_angulo = angulo;


        player -> vx = fuerza_disparo * cos(player->disparando_angulo);
        player -> vy = fuerza_disparo * sin(player->disparando_angulo);
        player -> t = 0;
    }
}

void mueve_player(Player player){
        player -> vy = player->vy + 3.8 * player -> t;

        player -> x = player -> x + player -> vx * player -> t;
        player -> y = player -> y + player -> vy * player -> t;

        player -> t = player -> t + (1.0/25);


        player -> animacion_angulo = player -> animacion_angulo + (player -> vx / 10);




        colision_player(player);
        
}

void colision_player(Player player){
    if((player -> y + player -> h) > Pantalla_Altura()-41){

        player -> y = Pantalla_Altura()-40-player->h;
        player -> vy = player -> vy * 0.7 * (-1);
        player -> vx = player -> vx * 0.7;
    
    }

    if(player->x <= 0) {
        player -> x = 0;
        player -> vx = player -> vx * (-1) * 0.7;
    }

    if(player->x + player -> w >= Pantalla_Anchura()) {
        player -> x = Pantalla_Anchura() - player -> w;
        player -> vx = player -> vx * (-1) * 0.7;
    }

    if(player->y <= 0) {
        player -> y = 0;
        player -> vy = player -> vy * (-1) * 0.7;
    }
    
}

double get_player_x(Player player){
    return player->x;
}

double get_player_animacion_angulo(Player player){
    return player->animacion_angulo;
}

void set_player_animacion_angulo(Player player, double anim_angulo){
    player->animacion_angulo = anim_angulo; 
}

double get_player_y(Player player){
    return player->y;
}

double get_player_vx(Player player){
    return player->vx;
}

double get_player_vy(Player player){
    return player->vy;
}

void set_player_vx(Player player, double vx){
    player->vx = vx;
    
}

void set_player_vy(Player player, double vy){
    player->vy = vy;
    
}

void togglePlayerVx(Player player, double percent){
    player -> vx = player -> vx * (-1) * percent; 
    
}

void togglePlayerVy(Player player, double percent){
    player -> vy = player -> vy * (-1) * percent;
    
}


int get_player_w(Player player){
    return player->w;
}

int get_player_h(Player player){
    return player->h;
}

void set_player_x(Player player, double x){
    player -> x = x;
}

void set_player_y(Player player, double y){
    player -> y = y;
}

void dibuja_player(Player player){
    Pantalla_DibujaImagenTransformada(player->imagenes[player->exp], get_player_x(player), get_player_y(player), get_player_w(player), get_player_h(player), get_player_animacion_angulo(player), SDL_FLIP_HORIZONTAL);
}
