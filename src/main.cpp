#define SDL_MAIN_HANDLED
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "Graphics.h"
#include "Game.h"

using namespace CitrusEngine;

int main(int argc, char **argv)
{
    Game *game = Game::Instance();
    game->Run();


}


