#ifndef CITRUSKB_H
#define CITRUSKB_H

#include "SDL2/SDL.h"


/* Keybindings */
enum BINDING_INDEX{
    A_UP,
    A_DOWN,
    A_LEFT,
    A_RIGHT,
    A_INTERACT,
    A_CRTL,
    A_SHFT
};

int K_MAP[4] = {
    SDL_SCANCODE_W,
    SDL_SCANCODE_S,
    SDL_SCANCODE_A,
    SDL_SCANCODE_D
};


int Citrus_RebindInput(void);
int InputTest();

#endif
