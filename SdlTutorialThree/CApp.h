#ifndef CAPP_H_INCLUDED
#define CAPP_H_INCLUDED

#include <SDL/SDL.h>
#include "CSurface.h"

class CApp{

    private:
        bool Running;

        SDL_Surface* Surf_Display;

        SDL_Surface* Surf_Test;

    public:
        CApp();

        int OnExecute();

        bool OnInit();

        void OnEvent(SDL_Event* Event);

        // All Game Logic
        void OnLoop();

        void OnRender();

        void OnCleanup();

};

#endif // CAPP_H_INCLUDED
