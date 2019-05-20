#include "Enemy.h"


struct EnemyRep{
    double x;
    double y;
    
    double vx;
    double vy;
    
    int w;
    int h;
    Imagen imagenes[4]; 

    int animacionP;

    int exp;


};

Enemy crea_enemy(double x, double y, double vx, double vy, Imagen * imagenes){
    Enemy enemy = malloc(sizeof(struct EnemyRep));
    enemy -> x = x;
    enemy -> y = y;

    enemy -> vx = vx;
    enemy -> vy = vy;

    enemy -> w = 50;
    enemy -> h = 50;


    enemy -> exp = 0;
    enemy -> animacionP = 1;

    /*
        Imagenes
    */

    enemy -> imagenes[0] = imagenes[0];
    enemy -> imagenes[1] = imagenes[1];
    enemy -> imagenes[2] = imagenes[2];
    enemy -> imagenes[3] = imagenes[3];

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

void set_enemy_exp(Enemy enemy, int exp){
    enemy -> exp = exp;
}

void set_enemy_y(Enemy enemy, double y){
    enemy -> y = y;
}

void dibuja_enemy(Enemy enemy){
    Imagen imagenEnemigo;
    
    
    switch (enemy -> animacionP)
    {
    case 1:
        imagenEnemigo = enemy -> imagenes[0];
        break;

    case 2:
        imagenEnemigo = enemy -> imagenes[1];
        break;

    case 3:
        imagenEnemigo = enemy -> imagenes[2];
        break;
    
    default:
        break;
    }

    if(enemy->exp==1){
        imagenEnemigo = enemy -> imagenes[3];
    }

    Pantalla_DibujaImagen(imagenEnemigo, enemy -> x, enemy -> y, enemy -> w, enemy -> h);

    
    

    //Pantalla_DibujaRectangulo(enemy->x,enemy->y,enemy->w, enemy->h); test Colisiones

}

int get_enemy_exp(Enemy enemy){
    return enemy -> exp;
}



void colision_enemy_player(Enemy enemy, Player player){

    double cx = get_player_x(player)+get_player_w(player)/2;
    double cy = get_player_y(player)+get_player_h(player)/2;
    double rx = get_player_h(player)/2;


    if(solape_circuferencia_rectangulo(cx,cy,rx,enemy->x,enemy->y,enemy->w,enemy->h)==1){
        if(enemy -> exp == 0){
            añadePunto(player, 1);
        }
        enemy -> exp = 1;
    }
}



void libera_enemy(Enemy enemy){
    free(enemy);
}

void mueve_enemy(Enemy enemy){

    enemy->x += enemy->vx;
    enemy->y += enemy->vy;

    if(enemy->exp==1){
        enemy -> vy = enemy -> vy + 10;
    }

    //Animacion del pajaro
    if(enemy -> animacionP<3){
            enemy -> animacionP = enemy -> animacionP + 1;
        }else{
            enemy -> animacionP = 1;
        } 

    

}

