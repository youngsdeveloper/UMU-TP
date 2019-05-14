#include "Enemy.h"


struct EnemyRep{
    double x;
    double y;
    double vx;
    double vy;
    int w;
    int h;
    Imagen imagenEnemigo1;
    Imagen imagenEnemigo2;
    Imagen imagenEnemigo3;

    int animacionP;

    int exp;


};

Enemy crea_enemy(double x, double y){
    Enemy enemy = malloc(sizeof(struct EnemyRep));
    enemy -> x = x;
    enemy -> y = y;
    enemy -> vx = -10;
    enemy -> vy = 0;
    enemy -> w = 50;
    enemy -> h = 50;
    enemy -> imagenEnemigo1 = Pantalla_ImagenLee("pajaro1.bmp",255);
    enemy -> imagenEnemigo2 = Pantalla_ImagenLee("pajaro2.bmp",255);
    enemy -> imagenEnemigo3 = Pantalla_ImagenLee("pajaro3.bmp",255);
    enemy -> exp = 0;
    enemy -> animacionP = 1;
    return enemy;
}

double get_enemy_x(Enemy enemy){
    return enemy->x;
}

double get_enemy_y(Enemy enemy){
    return enemy->y;
}

double get_enemy_vx(Enemy enemy){
    return enemy->vx;
}

double get_enemy_vy(Enemy enemy){
    return enemy->vy;
}

int get_enemy_w(Enemy enemy){
    return enemy->w;
}

int get_enemy_h(Enemy enemy){
    return enemy->h;
}

void set_enemy_x(Enemy enemy, double x){
    enemy -> x = x;
}

void set_enemy_y(Enemy enemy, double y){
    enemy -> y = y;
}

void dibuja_enemy(Enemy enemy){
    Imagen imagenEnemigo;
    switch (enemy -> animacionP)
    {
    case 1:
        imagenEnemigo = enemy -> imagenEnemigo1;
        break;

    case 2:
        imagenEnemigo = enemy -> imagenEnemigo2;
        break;

    case 3:
        imagenEnemigo = enemy -> imagenEnemigo3;
        break;
    
    default:
        break;
    }

    if(enemy->exp==1){
        imagenEnemigo = Pantalla_ImagenLee("pajaro_exp.bmp",255);
    }

    Pantalla_DibujaImagen(imagenEnemigo, enemy -> x, enemy -> y, enemy -> w, enemy -> h);

    if(enemy -> animacionP<3){
        enemy -> animacionP = enemy -> animacionP + 1;
    }else{
        enemy -> animacionP = 1;
    }
}


void colision_enemy_player(Enemy enemy, Player player){
    if(solape_rectangulos(enemy->x, enemy->y, enemy->w, enemy->h, get_player_x(player), get_player_y(player),
    get_player_w(player), get_player_h(player))==1){
        enemy -> exp = 1;
    }
}

void mueve_enemy(Enemy enemy){

    enemy->x += enemy->vx;
    enemy->y += enemy->vy;

    if(enemy->exp==1){
        enemy -> vy = enemy -> vy + 10;
    }

    //Movimiento del enemigo


    /*
        enemy->vx = get_player_x(player) - enemy->x;
        enemy->vy = get_player_y(player) - enemy->y;



        double m = sqrt( enemy->vx*enemy->vx + enemy->vy*enemy->vy );

        if ( m > 0 ) {
          enemy->vx = enemy->vx / m;
          enemy->vy = enemy->vy / m;
        }


        enemy->vx = enemy->vx * 6;
        enemy->vy = enemy->vy * 6;


        enemy->x += enemy->vx;
        enemy->y += enemy->vy;
        */

}

