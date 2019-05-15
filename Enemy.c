#include "Enemy.h"


struct EnemyRep{
    double x;
    double y;
    double vx;
    double vy;
    int w;
    int h;
    Imagen * imagenes; 

    int animacionP;

    int exp;


};

Enemy crea_enemy(double x, double y, Imagen * imagenes){
    Enemy enemy = malloc(sizeof(struct EnemyRep));
    enemy -> x = x;
    enemy -> y = y;
    enemy -> vx = -10;
    enemy -> vy = 0;
    enemy -> w = 50;
    enemy -> h = 50;


    enemy -> exp = 0;
    enemy -> animacionP = 1;

    /*
        Imagenes
    */

    enemy -> imagenes = imagenes;

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
    
    imagenEnemigo = enemy -> imagenes[0];

    /*
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
    }*/

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

void libera_enemy(Enemy enemy){
    free(enemy);
}

int mueve_enemy(Enemy enemy){

    //Devuelve 1 si hay que eliminar, 0 si no

    enemy->x += enemy->vx;
    enemy->y += enemy->vy;

    if(enemy->exp==1){
        enemy -> vy = enemy -> vy + 10;
    }

    if(enemy -> y + enemy -> h > Pantalla_Altura() || enemy -> x + enemy -> w < 0){
        //Eliminamos el enemigo 
        return 1; 
    }

    return 0;

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

