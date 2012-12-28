#include <iostream>
#include "CApp.h"
#include "Filepaths.h"


bool CApp::OnInit(){

    if (SDL_Init(SDL_INIT_EVERYTHING) < 0){
        return false;
    }

    if ((Surf_Display = SDL_SetVideoMode(600, 600,
                                         32, SDL_HWSURFACE|SDL_DOUBLEBUF)) == NULL){
        return false;
    }


    std::string path = "assets" + PATH_SEPARATOR + "images" + PATH_SEPARATOR;
    if((Surf_Grid = CSurface::OnLoad( (char*)(path+"grid.bmp").c_str())) == NULL){
        return false;
    }

    if((Surf_X = CSurface::OnLoad( (char*)(path+"x.bmp").c_str())) == NULL){
        return false;
    }

    if((Surf_O = CSurface::OnLoad( (char*)(path+"o.bmp").c_str())) == NULL){
        return false;
    }


    CSurface::Transparent(Surf_X, 255, 0, 253);
    CSurface::Transparent(Surf_O, 255, 0, 253);

    Reset();

    return true;
}
