#include <iostream>
#include "CApp.h"
#include "Filepaths.h"


bool CApp::OnInit(){

    if (SDL_Init(SDL_INIT_EVERYTHING) < 0){
        return false;
    }

    if ((Surf_Display = SDL_SetVideoMode(640, 480,
                                         32, SDL_HWSURFACE|SDL_DOUBLEBUF)) == NULL){
        return false;
    }


    std::string path = "assets" + PATH_SEPARATOR + "images" + PATH_SEPARATOR + "yoshi.bmp";
    if((Surf_Test = CSurface::OnLoad( (char*)path.c_str())) == NULL){
        return false;
    }

    //CSurface::Transparent(Surf_Test, 255, 0, 255);

    Anim_Yoshi.MaxFrames = 8;
    //Anim_Yoshi.Oscillate = true;

    return true;
}
