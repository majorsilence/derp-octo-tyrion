#ifndef CCAMERA_H_INCLUDED
#define CCAMERA_H_INCLUDED

#include <SDL/SDL.h>

#include "Define.h"

enum {
    TARGET_MODE_NORMAL = 0,
    TARGET_MODE_CENTER
};

class CCamera {

    public:
        static CCamera CameraControl;

        int TargetMode;

        CCamera();

        void OnMove(int MoveX, int MoveY);

        int GetX();

        int GetY();

        void SetPos(int X, int Y);

        void SetTarget(int* X, int *Y);


    private:
        int X;
        int Y;

        int* TargetX;
        int* TargetY;

};


#endif // CCAMERA_H_INCLUDED
