#include "RafagaBomba.h"

struct NodoBomba{
    Bomba bomba;
    struct NodoBomba * sig;
};

NodoBombaPtr nuevo_nodo_bomba(Bomba bomba) {
    NodoBombaPtr nuevo = malloc( sizeof( struct NodoBomba ) );
    nuevo->bomba = bomba;
    nuevo->sig = NULL;
    return nuevo;
}


void inserta_bomba(NodoBombaPtr cabecera, Bomba b){
    NodoBombaPtr nuevo = nuevo_nodo_bomba(b);
    nuevo->sig = cabecera->sig;
    cabecera->sig = nuevo;
}

void libera_rafaga_bomba( NodoBombaPtr cabecera ){
    while ( cabecera->sig != NULL ) {
        NodoBombaPtr borrar = cabecera->sig;
        cabecera->sig = borrar->sig;
        free( borrar );
    }
}
void mueve_rafaga_bomba( NodoBombaPtr cabecera, Player player){



    NodoBombaPtr aux = cabecera;

    while ( aux->sig != NULL) {
        mueve_bomba(aux->sig->bomba);
        
        if(get_w_bomba(aux->sig->bomba)>200){
            NodoBombaPtr borrar = aux->sig;
            aux->sig = borrar->sig;
            libera_bomba(borrar->bomba);
            free(borrar);

            setExp_player(player, 0);


        }else{
            aux = aux -> sig;
        }


    }
}

void dibuja_rafaga_bomba( NodoBombaPtr cabecera){
    NodoBombaPtr aux = cabecera;
    while ( aux->sig != NULL ) {
        aux = aux->sig;
        dibuja_bomba(aux->bomba);
    }
}

void colision_rafaga_bomba( NodoBombaPtr cabecera, Player player, Ejercito ejercito){
    NodoBombaPtr aux = cabecera;
    while ( aux->sig != NULL ) {
        aux = aux->sig;
        colision_bomba(aux->bomba, player, ejercito);
    }
}