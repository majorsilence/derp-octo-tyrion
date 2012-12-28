#ifndef CAPP_H_INCLUDED
#define CAPP_H_INCLUDED

#include <SDL/SDL.h>

#include "CEvent.h"
#include "CSurface.h"

class CApp: public CEvent{

    private:
        bool Running;

        SDL_Surface* Surf_Display;

        SDL_Surface* Surf_Grid;

        SDL_Surface* Surf_X;

        SDL_Surface* Surf_O;

        int Grid[9];

        int CurrentPlayer;

        enum {
            GRID_TYPE_NONE = 0,
            GRID_TYPE_X = 1,
            GRID_TYPE_O = 2
        };

    public:
        CApp();

        int OnExecute();

        bool OnInit();

        void OnEvent(SDL_Event* Event);

        void OnLButtonDown(int mX, int mY);

        void OnExit();

        // All Game Logic
        void OnLoop();

        void OnRender();

        void OnCleanup();

        void Reset();

        void SetCell(int ID, int Type);

};

#endif // CAPP_H_INCLUDED
