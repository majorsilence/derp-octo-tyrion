#include "CApp.h"

void CApp::OnRender(){


    // Fill the screen black before drawing other surfaces on it
    SDL_FillRect( Surf_Display, &Surf_Display->clip_rect, SDL_MapRGB( Surf_Display->format, 0, 0, 0 ));

    CArea::AreaControl.OnRender(Surf_Display, CCamera::CameraControl.GetX(), CCamera::CameraControl.GetY());

    for (int i=0; i<CEntity::EntityList.size(); i++){

        if(!CEntity::EntityList[i]){
            continue;
        }

        CEntity::EntityList[i]->OnRender(Surf_Display);

    }

    SDL_Flip(Surf_Display);

}
