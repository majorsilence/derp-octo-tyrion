#ifndef CAREA_H_INCLUDED
#define CAREA_H_INCLUDED

#include <vector>
#include "CMap.h"

class CArea {

    public:
        static CArea AreaControl;

        std::vector<CMap> MapList;

        CArea();

        bool OnLoad(char* File);

        void OnRender(SDL_Surface* Surf_Display, int CameraX, int CameraY);

        void OnCleanup();

        int GetAreaSize();

    private:
        /// We are going to assume that areas will
        /// always be square, so an AreaSize of 3,
        /// would be a 3x3 area.
        int AreaSize;

        SDL_Surface* Surf_Tileset;



};


#endif // CAREA_H_INCLUDED
