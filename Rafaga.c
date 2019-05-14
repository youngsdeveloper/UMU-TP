#include "Rafaga.h"



struct Nodo{
    Bala bala;
    struct Nodo * sig;
};




NodoPtr nuevo_nodo(Bala bala) {
    NodoPtr nuevo = malloc( sizeof( struct Nodo ) );
    nuevo->bala = bala;
    nuevo->sig = NULL;
    return nuevo;
}

void inserta_rafaga( NodoPtr cabecera, Bala b ){
    NodoPtr nuevo = nuevo_nodo(b);
    nuevo->sig = cabecera->sig;
    cabecera->sig = nuevo;
}

void libera_rafaga( NodoPtr cabecera ){


    while ( cabecera->sig != NULL ) {
        NodoPtr borrar = cabecera->sig;
        cabecera->sig = borrar->sig;
        free( borrar );
    }

}


void mueve_rafaga( NodoPtr cabecera){



    NodoPtr aux = cabecera;

    while ( aux->sig != NULL) {
        mueve_bala(aux->sig->bala);

        if(!solape_rectangulos(get_x_bala(aux->sig->bala), get_y_bala(aux->sig->bala), get_w_bala(aux->sig->bala), get_h_bala(aux->sig->bala), 0, 0, 500, 500)){
            NodoPtr borrar = aux->sig;
            aux->sig = borrar->sig;
            libera_bala(borrar->bala);
            free(borrar);

        }else{
            aux = aux -> sig;
        }


    }
}

void dibuja_rafaga( NodoPtr cabecera){
    NodoPtr aux = cabecera;
    while ( aux->sig != NULL ) {
        aux = aux->sig;
        dibuja_bala(aux->bala);
    }
}


int longitud( NodoPtr cabecera ) {
    NodoPtr aux = cabecera;
    int contador = 0;

    while ( aux->sig != NULL ) {
        contador = contador + 1;
        aux = aux->sig; // Avance
    }

    return contador;
}



int impactaBala(NodoPtr cabecera, int x, int y, int w, int h){

    NodoPtr aux = cabecera;

    while ( aux->sig != NULL && !colision_bala(aux->sig->bala,x,y,w,h) ) {
        aux = aux->sig; // Avanzar
    }

    return aux->sig != NULL;
}

void impactaBalaEnemigo(NodoPtr cabecera, Enemy enemy){

    if (impactaBala(cabecera,get_enemy_x(enemy),get_enemy_y(enemy),get_enemy_w(enemy),get_enemy_h(enemy))){
        set_enemy_x(enemy, 250);
        set_enemy_y(enemy, 0);
    }
}

