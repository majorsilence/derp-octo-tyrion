#ifndef CAPP_H_INCLUDED
#define CAPP_H_INCLUDED

#include <SDL/SDL.h>

#include "CAnimation.h"
#include "CEvent.h"
#include "CSurface.h"
#include "CEntity.h"

class CApp: public CEvent{

    private:
        bool Running;

        SDL_Surface* Surf_Display;

        CEntity Entity1;
        CEntity Entity2;
        CEntity Entity3;

    public:
        CApp();

        int OnExecute();

        bool OnInit();

        void OnEvent(SDL_Event* Event);

        void OnExit();

        // All Game Logic
        void OnLoop();

        void OnRender();

        void OnCleanup();

};

#endif // CAPP_H_INCLUDED
