#ifndef CITRUSKB_H
#define CITRUSKB_H

#include "SDL2/SDL.h"


/* Keybindings */
enum BINDING_INDEX{
    ACTION_UP,
    ACTION_DOWN,
    ACTION_LEFT,
    ACTION_RIGHT
};

int KEY_MAP[4] = {
    SDL_SCANCODE_W,
    SDL_SCANCODE_S,
    SDL_SCANCODE_A,
    SDL_SCANCODE_D
};


int Citrus_RebindInput(void);
int InputTest();

#endif
