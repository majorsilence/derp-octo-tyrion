#include <iostream>
#include "CApp.h"
#include "Filepaths.h"


bool CApp::OnInit(){

    if (SDL_Init(SDL_INIT_EVERYTHING) < 0){
        return false;
    }

    if ((Surf_Display = SDL_SetVideoMode(WWIDTH, WHEIGHT,
                                         32, SDL_HWSURFACE|SDL_DOUBLEBUF)) == NULL){
        return false;
    }


    if(CArea::AreaControl.OnLoad("./assets/maps/1.area") == false){
        return false;
    }

    SDL_EnableKeyRepeat(1, SDL_DEFAULT_REPEAT_INTERVAL / 3);


    return true;
}
