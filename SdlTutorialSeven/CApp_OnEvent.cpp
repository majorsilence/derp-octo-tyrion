#include "CApp.h"

void CApp::OnEvent(SDL_Event* Event){
    CEvent::OnEvent(Event);
}

void CApp::OnKeyDown(SDLKey sym, SDLMod mod, Uint16 unicode){

    switch(sym){
        case SDLK_UP: {

            if (CCamera::CameraControl.GetY() > -5) {
                break;
            }
            else {
                CCamera::CameraControl.OnMove( 0, 5);
                break;
            }
        }
        case SDLK_DOWN: {

            if (CCamera::CameraControl.GetY() < -(CArea::AreaControl.GetAreaSize() * MAP_HEIGHT * TILE_SIZE - WHEIGHT - 5)) {
                break;
            }
            else {
                CCamera::CameraControl.OnMove( 0, -5);
                break;
            }

        }
        case SDLK_LEFT: {
            if (CCamera::CameraControl.GetX() > -5) {
                 break;
            }
            else {
                CCamera::CameraControl.OnMove( 5, 0);
                break;
            }
        }
        case SDLK_RIGHT: {

            if (CCamera::CameraControl.GetX() < -(CArea::AreaControl.GetAreaSize() * MAP_WIDTH * TILE_SIZE - WWIDTH - 5)) {
                break;
            }
            else {
                CCamera::CameraControl.OnMove( -5, 0);
                break;
            }
        }
        default: {}
    }

}


void CApp::OnExit(){
    Running = false;
}
