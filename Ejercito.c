#include "Ejercito.h"


struct Nodo{
    Enemy enemy;
    struct Nodo * sig;
};

NodoEjercito nuevo_nodo_ejercito(Enemy enemy) {
    NodoEjercito nuevo = malloc( sizeof( struct Nodo ) );
    nuevo->enemy = enemy;
    nuevo->sig = NULL;
    return nuevo;
}
