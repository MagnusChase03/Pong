#ifndef BoardH
#define BoardH

#include <SDL2/SDL.h>

class Board {

    private:
        SDL_Rect rect;
        int vY;

    public:
        Board(int x, int y);

        SDL_Rect *getRect() {return &rect;}

        void setVY(int vY2) {vY = vY2;}
        int getVY() {return vY;}

};

#endif