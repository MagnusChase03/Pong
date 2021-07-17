#include <ctime>
#include <iostream>
#include "Window.h"

Window::Window() {

    SDL_Init(SDL_INIT_EVERYTHING);

    window = SDL_CreateWindow("Pong", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, 0);
    renderer = SDL_CreateRenderer(window, -1, 0);

    player1 = new Board(20, 250);
    player2 = new Board(770, 250);
    ball = new Ball();

    speedIncreaseX = 1;
    speedIncreaseY = 1;
    speedTick = 0;

    running = true;

}

void Window::events() {

    SDL_Event event;
    const Uint8 *keys = SDL_GetKeyboardState(NULL);

    SDL_PollEvent(&event);

    if (event.type == SDL_QUIT) {
    
            running = false;
    
    }

    else if (event.type == SDL_KEYDOWN || event.type == SDL_KEYUP) {

        if (keys[SDL_SCANCODE_ESCAPE]) {

            running = false;

        }

        if (keys[SDL_SCANCODE_W]) {

            player1->setVY(-10);

        } else if (keys[SDL_SCANCODE_S]) {

            player1->setVY(10);

        } else {

            player1->setVY(0);

        }

        if (keys[SDL_SCANCODE_UP]) {

            player2->setVY(-10);

        } else if (keys[SDL_SCANCODE_DOWN]) {

            player2->setVY(10);

        } else {

            player2->setVY(0);

        }

    }

}

bool Window::collision(Board *boardC, Ball *ballC) {

    int boardX = boardC->getRect()->x;
    int boardY = boardC->getRect()->y;
    int boardW = boardC->getRect()->w;
    int boardH = boardC->getRect()->h;

    int ballX = ballC->getRect()->x;
    int ballY = ballC->getRect()->y;
    int ballW = ballC->getRect()->w;
    int ballH = ballC->getRect()->h;

    if (ballX > boardX && ballX < boardX + boardW) {

        if (ballY > boardY && ballY < boardY + boardH) {

            return true;

        } else if (boardY > ballY && boardY < ballY + ballH) {

            return true;

        }

    } else if (boardX > ballX && boardX < ballX + ballW) {

        if (ballY > boardY && ballY < boardY + boardH) {

            return true;

        } else if (boardY > ballY && boardY < ballY + ballH) {

            return true;

        }

    }

    return false;

}

void Window::update() {

    player1->getRect()->y += player1->getVY();
    player2->getRect()->y += player2->getVY();

    ball->getRect()->x += ball->getVX();
    ball->getRect()->y += ball->getVY();

    if (ball->getRect()->y < 0 || ball->getRect()->y > 580) {

        ball->setVY(ball->getVY() * -1);

    }

    if (collision(player1, ball) || collision(player2, ball)) {

        ball->setVX(ball->getVX() * -1);

        srand(time(NULL));
        ball->setVY(rand() % 4 - 2);

        speedTick += 1;
        if (speedTick == 2) {

            speedTick = 0;
            ball->setVX(ball->getVX() > 0 ? ball->getVX() + speedIncreaseX : ball->getVX() - speedIncreaseX);
            ball->setVY(ball->getVY() > 0 ? ball->getVY() + speedIncreaseY : ball->getVY() - speedIncreaseY);
            speedIncreaseY += 1;

        }

    }

}

void Window::render() {


    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);


    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderFillRect(renderer, player1->getRect());
    SDL_RenderFillRect(renderer, player2->getRect());

    SDL_RenderFillRect(renderer, ball->getRect());

    SDL_RenderPresent(renderer);

}

void Window::destroy() {

    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();

}