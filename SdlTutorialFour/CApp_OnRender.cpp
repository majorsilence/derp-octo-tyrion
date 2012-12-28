#include "CApp.h"

void CApp::OnRender(){

    CSurface::OnDraw(Surf_Display, Surf_Grid, 0, 0);

    for(int i=0; i<9; i++){
        int x = (i % 3) * 200;
        int y = (i / 3) * 200;


        if(Grid[i] == GRID_TYPE_X){
        CSurface::OnDraw(Surf_Display, Surf_X, x, y);
        }
        else if (Grid[i] == GRID_TYPE_O){
            CSurface::OnDraw(Surf_Display, Surf_O, x, y);
        }

    }



    SDL_Flip(Surf_Display);

}
