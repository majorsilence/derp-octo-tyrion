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

    if (Entity1.OnLoad((char*)path.c_str(), 64, 64, 8) == false){
        return false;
    }

    if(Entity2.OnLoad((char*)path.c_str(), 64, 64, 8) == false){
        return false;
    }

    Entity2.X = 100;
    CEntity::EntityList.push_back(&Entity1);
    CEntity::EntityList.push_back(&Entity2);


    return true;
}
