#ifndef CAPP_H_INCLUDED
#define CAPP_H_INCLUDED

#include <SDL/SDL.h>

#include "Define.h"
#include "CArea.h"
#include "CCamera.h"
#include "CEntity.h"
#include "CEvent.h"
#include "CSurface.h"



class CApp: public CEvent{

    private:
        bool Running;

        SDL_Surface* Surf_Display;

    public:
        CApp();

        int OnExecute();

        bool OnInit();

        void OnEvent(SDL_Event* Event);

        void OnKeyDown(SDLKey sym, SDLMod mod, Uint16 unicode);

        void OnExit();

        // All Game Logic
        void OnLoop();

        void OnRender();

        void OnCleanup();

};

#endif // CAPP_H_INCLUDED
