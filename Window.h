#ifndef WindowH
#define WindowH

#include <SDL2/SDL.h>
#include "Board.h"
#include "Ball.h"

class Window {

    private:
        SDL_Window *window;
        SDL_Renderer *renderer;

        Board *player1;
        Board *player2;
        Ball *ball;

        bool running;
        int speedIncreaseX;
        int speedIncreaseY;
        int speedTick;

        bool collision(Board *boardC, Ball *ballC);

    public:
        Window();

        void events();
        void update();
        void render();
        void destroy();

        bool isRunning() {return running;}

};

#endif