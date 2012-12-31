#ifndef CANIMATION_H_INCLUDED
#define CANIMATION_H_INCLUDED

#include <SDL/SDL.h>

class CAnimation {

    private:
        int CurrentFrame;

        int FrameInc; // Increment?

        int FrameRate; // Milliseconds

        long OldTime;

    public:
        int MaxFrames;

        bool Oscillate;

        CAnimation();

        void OnAnimate();

        void SetFrameRate(int Rate);

        void SetCurrentFrame(int Frame);

        int GetCurrentFrame();

};


#endif // CANIMATION_H_INCLUDED
