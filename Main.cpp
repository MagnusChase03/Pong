#include "Window.h"

int main() {

    Window *window = new Window();

    int frameDelay = 1000 / 60;
    Uint32 start;
    Uint32 time;

    while (window->isRunning()) {

        start = SDL_GetTicks();

        window->events();
        window->update();
        window->render();

        if (frameDelay > time) {

            SDL_Delay(frameDelay - time);

        }

    }

    window->destroy();

    return 0;

}