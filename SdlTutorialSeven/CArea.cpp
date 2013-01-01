#include "CArea.h"

CArea CArea::AreaControl;

CArea::CArea(){
    AreaSize = 0;
}

bool CArea::OnLoad(char* File){
    MapList.clear();

    FILE* FileHandle = fopen(File, "r");

    if(FileHandle == NULL){
        return false;
    }

    char TilesetFile[255];

    fscanf(FileHandle, "%s\n", TilesetFile);

    if((Surf_Tileset = CSurface::OnLoad(TilesetFile)) == false){
        fclose(FileHandle);

        return false;
    }

    fscanf(FileHandle, "%d\n", &AreaSize);

    for(int x=0; x<AreaSize; x++){

        for(int y=0; y<AreaSize; y++){

            char MapFile[255];

            fscanf(FileHandle, "%s ", MapFile);

            CMap tempMap;
            if(tempMap.OnLoad(MapFile) == false){
                fclose(FileHandle);

                return false;
            }

            tempMap.Surf_Tileset = Surf_Tileset;

            MapList.push_back(tempMap);

        }

        fscanf(FileHandle, "\n");
    }

    fclose(FileHandle);

    return true;

}


void CArea::OnRender(SDL_Surface* Surf_Display, int CameraX, int CameraY){

    int MapWidth = MAP_WIDTH * TILE_SIZE;
    int MapHeight = MAP_HEIGHT * TILE_SIZE;

    int FirstID = -CameraX / MapWidth;
    FirstID = FirstID + ((-CameraY / MapHeight) * AreaSize);

    // only render the maps that are currently
    // visible in the area.  At 640x480
    // only 4 maps are able to be shown at most
    // see http://www.sdltutorials.com/sdl-maps


    //for (int i = 0; i < 4; i++){
    //    int ID = FirstID + ((i/2) * AreaSize) + (i%2);

    // Draw as many maps as can fit on screen
    int nHorizontalMaps = (WWIDTH/(MAP_WIDTH*TILE_SIZE)) + 2;
    int nVerticalMaps = (WHEIGHT/(MAP_HEIGHT*TILE_SIZE)) + 2;

    for(int i = 0; i < nHorizontalMaps*nVerticalMaps; i++) {
        int ID = FirstID + ((i / nHorizontalMaps) *AreaSize) + (i % nHorizontalMaps);

        if (ID <0 || ID >= MapList.size()){
            continue;
        }

        int x = ((ID % AreaSize) * MapWidth) + CameraX;
        int y = ((ID / AreaSize) * MapHeight) + CameraY;

        MapList[ID].OnRender(Surf_Display, x, y);

    }

}

void CArea::OnCleanup(){

    if(Surf_Tileset){
        SDL_FreeSurface(Surf_Tileset);
    }

    MapList.clear();

}

int CArea::GetAreaSize(){
    return AreaSize;
}


