#include "Ejercito.h"


struct EjercitoRep{
    Enemy enemigos[300];
    int n;
};


Ejercito crea_ejercito(){
    Ejercito ejercito = malloc(sizeof(struct EjercitoRep));
    ejercito -> n = 0;
    return ejercito;
}

void genera_ejercito(Ejercito e, int n){
        srand (time(NULL));

    for(int j=0; j < n ;j++){

        double sep_horizontal = genera_aleatorio(100,200);   // Separacion entre 100 y 200
        double y = genera_aleatorio(100,200);  // Separacion entre 100 y 200
        double x = Pantalla_Anchura()-100 + j*sep_horizontal;
        inserta_enemigo(e, crea_enemy(x,y)); 
    }
}

double genera_aleatorio(int n, int m){
    return m + rand()%(n + 1 - m);
}

void inserta_enemigo(Ejercito e, Enemy enemigo){
    e -> enemigos[e -> n] = enemigo;
    e -> n = (e -> n) + 1;
}

void dibuja_ejercito(Ejercito e){
    for(int j=0; j < e->n ;j++){ 
        dibuja_enemy(e->enemigos[j]);
    }
}

void mueve_ejercito(Ejercito e){
    for(int j=0; j < e->n ;j++){ 
        mueve_enemy(e->enemigos[j]);
    }
}

void colision_ejercito(Ejercito e, Player player){
    for(int j=0; j < e->n ;j++){ 
        colision_enemy_player(e->enemigos[j], player);
    }
}

