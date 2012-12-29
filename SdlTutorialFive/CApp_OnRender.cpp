#include "CApp.h"

void CApp::OnRender(){

    CSurface::OnDraw(Surf_Display, Surf_Test, 0, 0);
    CSurface::OnDraw(Surf_Display, Surf_Test, 100,
                     100, 0, 0, 25, 15);

    SDL_Flip(Surf_Display);

}
