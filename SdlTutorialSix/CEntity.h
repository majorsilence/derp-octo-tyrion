#ifndef CENTITY_H_INCLUDED
#define CENTITY_H_INCLUDED


#include <vector>

#include "CAnimation.h"
#include "CSurface.h"

class CEntity {

    public:
        static std::vector<CEntity*> EntityList;

    protected:
        CAnimation Anim_Control;

        SDL_Surface* Surf_Entity;

    public:

        float X;

        float Y;

        int Width;

        int Height;

        int AnimState;

        CEntity();

        virtual ~CEntity();

        virtual bool OnLoad(char* File, int width, int height, int maxFrames);

        virtual void OnLoop();

        virtual void OnRender(SDL_Surface* Surf_Display);

        virtual void OnCleanup();

};


#endif // CENTITY_H_INCLUDED
