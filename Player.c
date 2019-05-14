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


    double disparando_angulo;

    double animacion_angulo;

    double t;
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


    player -> block_ground = 0;

    player -> t = 0;
    return player;
}

int isDisparando(Player player){
    return (player -> y < Pantalla_Altura()-40-player->h) && fabs(player -> vx) > 0.1;
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

double set_player_animacion_angulo(Player player, double anim_angulo){
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

void togglePlayerVx(Player player){
    player -> vx = player -> vx * (-1);
}

void togglePlayerVy(Player player){
    player -> vy = player -> vy * (-1);
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
