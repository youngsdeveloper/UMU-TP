#include "ListaPlataformas.h"


struct NodoPlataformaRep{
    Plataforma plataforma;
    struct NodoPlataformaRep * sig;
};

NodoPlataforma nuevo_nodo_plataforma(Plataforma plataforma) {
    NodoPlataforma nuevo = malloc( sizeof( struct NodoPlataformaRep ) );
    nuevo->plataforma = plataforma;
    nuevo->sig = NULL;
    return nuevo;
}

void inserta_plataforma( NodoPlataforma cabecera, Plataforma plataforma){
    NodoPlataforma nuevo = nuevo_nodo_plataforma(plataforma);
    nuevo->sig = cabecera->sig;
    cabecera->sig = nuevo;
}

void dibuja_plataformas( NodoPlataforma cabecera){
    NodoPlataforma aux = cabecera;
    while ( aux->sig != NULL ) {
        aux = aux->sig;
        dibuja_plataforma(aux->plataforma);
    }
}

void colisiones_plataformas(NodoPlataforma cabecera, Player player){
    NodoPlataforma aux = cabecera;
    while ( aux->sig != NULL ) {
        aux = aux->sig;
        colisiones_plataforma(aux->plataforma, player);

    }
}

