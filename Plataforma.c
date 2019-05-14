#include "Plataforma.h"


struct PlataformaRep{
    double x;
    double y;
    double w;
    double h;


};



Plataforma crea_plataforma(double x, double y, double w, double h){
    Plataforma plataforma = malloc(sizeof(struct PlataformaRep));

    plataforma->x = x;
    plataforma->y = y;

    plataforma->w = w;
    plataforma->h = h;

    return plataforma;
}

void dibuja_plataforma(Plataforma plataforma){
    Pantalla_ColorRelleno(0,0,0,255); //Plataforma negra
    Pantalla_DibujaRectangulo(plataforma->x, plataforma -> y, plataforma -> w, plataforma -> h);
}

int colision_plataforma_player(Plataforma plataforma, Player player){
    return solape_rectangulos(get_player_x(player), get_player_y(player), get_player_w(player), get_player_h(player), plataforma->x, plataforma->y, plataforma->w, plataforma->h);
}

void colisiones_plataforma(Plataforma plataforma, Player player){

    //int x_colision = !(get_player_x(player) < plataforma -> x)&&(get_player_x(player) + get_player_w(player) > plataforma -> x + plataforma -> w);
 
    if(colision_plataforma_player(plataforma, player)){

        if(get_player_vx(player)>0){ 
            set_player_x(player, plataforma->x - get_player_w(player));
        }

        if(get_player_vx(player)<0){
            set_player_x(player, plataforma->x);
        }

        

        togglePlayerVx(player); 
        printf("colision \n");
    }
}