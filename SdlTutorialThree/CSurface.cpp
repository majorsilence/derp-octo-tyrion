#include "CSurface.h"

CSurface::CSurface(){
}

SDL_Surface* CSurface::OnLoad(char* File){
    SDL_Surface* Surf_Temp = NULL;
    SDL_Surface* Surf_Return = NULL;

    if ((Surf_Temp = SDL_LoadBMP(File)) == NULL){
        return NULL;
    }

    Surf_Return = SDL_DisplayFormat(Surf_Temp);
    SDL_FreeSurface(Surf_Temp);

    return Surf_Return;
}

bool CSurface::OnDraw(SDL_Surface* Surf_Dest, SDL_Surface* Surf_Src, int x, int y){

    if(Surf_Dest == NULL || Surf_Src == NULL){
        return false;
    }

    SDL_Rect DestR;
    DestR.x = x;
    DestR.y = y;

    SDL_BlitSurface(Surf_Src, NULL, Surf_Dest, &DestR);

    return true;
}

bool CSurface::OnDraw(SDL_Surface* Surf_Dest, SDL_Surface* Surf_Src, int x, int y, int x2, int y2, int w, int h){

    if(Surf_Dest == NULL || Surf_Src == NULL){
        return false;
    }

    SDL_Rect DestR;

    DestR.x = x;
    DestR.y = y;

    SDL_Rect SrcR;

    SrcR.x = x2;
    SrcR.y = y2;
    SrcR.w = w;
    SrcR.h = h;

    SDL_BlitSurface(Surf_Src, &SrcR, Surf_Dest, &DestR);

    return true;

}



