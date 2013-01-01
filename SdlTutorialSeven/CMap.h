#ifndef CMAP_H_INCLUDED
#define CMAP_H_INCLUDED

#include <SDL/SDL.h>
#include <vector>

#include "CTile.h"
#include "CSurface.h"

class CMap {

    public:

        SDL_Surface* Surf_Tileset;

        CMap();

        bool OnLoad(char* File);

        void OnRender(SDL_Surface* Surf_Display, int MapX, int MapY);

    private:
        std::vector<CTile> TileList;

};

#endif // CMAP_H_INCLUDED
