#ifndef BallH
#define BallH

#include <SDL2/SDL.h>

class Ball {

    private:
        SDL_Rect rect;
        int vX, vY;

    public:
        Ball();

        SDL_Rect *getRect() {return &rect;}

        void setVX(int vX2) {vX = vX2;}
        int getVX() {return vX;}

        void setVY(int vY2) {vY = vY2;}
        int getVY() {return vY;}

};

#endif