#include "Plataforma.h"


struct PlataformaRep{
    double x;
    double y;
    double w;
    double h;

    int isH;
    int isV;
};



Plataforma crea_plataforma(double x, double y, double w, double h, int isH, int isV){
    Plataforma plataforma = malloc(sizeof(struct PlataformaRep));

    plataforma->x = x;
    plataforma->y = y;

    plataforma->w = w;
    plataforma->h = h;


    plataforma->isH = isH;
    plataforma->isV = isV;

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
 
    if(colision_plataforma_player(plataforma, player)){

        if(plataforma->isV == 1){
             if(get_player_vx(player)>0){ 
                set_player_x(player, plataforma->x - get_player_w(player));
            }

            if(get_player_vx(player)<0){
                set_player_x(player, plataforma->x + plataforma -> w); 
            }

            

            togglePlayerVx(player, 0.8); 
        }

            printf("colision!!\n");

        if(plataforma->isH == 1){

            printf("colision!!\n");

            if(get_player_vy(player)<0){ 
                set_player_y(player, plataforma->y + plataforma -> h);
            }

            if(get_player_vy(player)>0){ 
                set_player_y(player, plataforma->y - get_player_w(player));
                set_player_vx(player, get_player_vx(player)*0.3); 
                
            }

            togglePlayerVy(player, 0.5); 
        }

       
    }
}