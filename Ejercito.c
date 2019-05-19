#include "Ejercito.h"


struct EjercitoRep{
    Enemy enemigos[200];
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


        Imagen imagenes[4];
        
    
        imagenes[0] = Pantalla_ImagenLee("pajaro1.bmp",255);
        imagenes[1] = Pantalla_ImagenLee("pajaro2.bmp",255);
        imagenes[2] = Pantalla_ImagenLee("pajaro3.bmp",255);
        imagenes[3] = Pantalla_ImagenLee("pajaro_exp.bmp",255);

        Imagen * ptrImages = imagenes;
        

        inserta_enemigo(e, crea_enemy(x,y, ptrImages)); 
    }
}

double genera_aleatorio(int n, int m){
    return m + rand()%(n + 1 - m);
}

void inserta_enemigo(Ejercito e, Enemy enemigo){
    e -> enemigos[e -> n] = enemigo;
    e -> n = (e -> n) + 1;
}

void suprime_enemy(Ejercito e, int pos){


    libera_enemy(e->enemigos[pos]);
    int i;

    for(i= pos; i <(e->n-1); i++){
        e->enemigos[i]= e->enemigos[i+1];
    }
    e->n-=1;
}


int	colision_ejercito_objeto( Ejercito e,	double	x,	double	y,	double	w,	double h ){
    int colisionDetectada = 0;
    int j=0;
    while(j< e->n && colisionDetectada == 0){
        Enemy ene = e->enemigos[j];
        if(solape_rectangulos(get_enemy_x(ene),get_enemy_y(ene),get_enemy_w(ene), get_enemy_h(ene),x,y,w,h)==1){
            colisionDetectada = 1;
        }
        j++;
    }
    return colisionDetectada;
}

void dibuja_ejercito(Ejercito e){
    for(int j=0; j < e->n ;j++){ 
        dibuja_enemy(e->enemigos[j]);
    }
}

void mueve_ejercito(Ejercito e){

    int j = 0;
    while(j < e->n){

        Enemy enemy = e->enemigos[j];

        
        mueve_enemy(enemy);

        if(get_enemy_y(enemy) + get_enemy_h(enemy) > Pantalla_Altura() || get_enemy_x(enemy) + get_enemy_w(enemy) < 0){
            suprime_enemy(e,j);
        }


        j++;
    }
}

void colision_ejercito(Ejercito e, Player player){
    for(int j=0; j < e->n ;j++){ 
        colision_enemy_player(e->enemigos[j], player);
    }
}

