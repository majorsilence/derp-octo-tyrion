#ifndef CSURFACE_H_INCLUDED
#define CSURFACE_H_INCLUDED

#include <SDL/SDL.h>


class CSurface {

    public :
        CSurface();

        static SDL_Surface* OnLoad(char* File);

        static bool OnDraw(SDL_Surface* Surf_Dest, SDL_Surface* Surf_Src, int x, int y);

        // Allow specifying which pixels from the source should be copied using x1,x2, w, h
        static bool OnDraw(SDL_Surface* Surf_Dest, SDL_Surface* Surf_Src, int x, int y, int x2, int y2, int w, int h);

};


#endif // CSURFACE_H_INCLUDED
