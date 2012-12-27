#include "CApp.h"

void CApp::OnCleanup(){
    SDL_QuitSubSystem(SDL_INIT_VIDEO);
    SDL_Quit();
}
