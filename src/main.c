#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <io.h>

/* Engine Files */
#include "citrus/core.h"
#include "citrus/input.h"
#include "citrus/entity.h"

/* SDL2 & OpenGL */
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "glad/glad.h"

/* utils */
#include "tools/linear.h"

const int SCREEN_W = 640;
const int SCREEN_H = 480;


int main(int argc, char **argv)
{

    SDL_Window *window = NULL;
    SDL_Surface *surface = NULL;
    SDL_Renderer *renderer;

    int quit = 0;

    if(SDL_Init(SDL_INIT_VIDEO) < 0){
        printf("SDL failed to intialise: %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }

    window = SDL_CreateWindow("Citrus Engine",
                            SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                            SCREEN_W, SCREEN_H,
                            SDL_WINDOW_SHOWN);

    if(window == NULL){
        printf("SDL failed to create window %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }

    if(!(renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED ))){
        printf("SDL failed to create renderer: %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }

    int x = 0, y = 0;
    Vector *ve = initVector(2);

    Uint32 prevTime = 0;
    while(!quit) { // SDL loop

        // Calculate Delta Time
        Uint32 currTime = SDL_GetTicks();
        Uint32 deltaTime = currTime - prevTime;
        prevTime = currTime;

        SDL_Event event;
        while(SDL_PollEvent( &event ) != 0) {
            if( event.type == SDL_QUIT ) {
                return 1;
            }
            const Uint8 *keyStates = SDL_GetKeyboardState(NULL);

            // player.y -= keyStates[KEY_MAP[ACTION_UP]]*1;
            // player.y += keyStates[KEY_MAP[ACTION_DOWN]]*1;
            // player.x -= keyStates[KEY_MAP[ACTION_LEFT]]*1;
            // player.x += keyStates[KEY_MAP[ACTION_RIGHT]]*1;
        }

        SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
        SDL_RenderClear(renderer);
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

        SDL_GetMouseState(&x, &y);

        ve->space[x_] = (double) x;
        ve->space[y_] = (double) y;

        normalise(ve);


        int st = SDL_RenderDrawLine(renderer, 0, 0, (int) ceil(ve->space[x_]), (int) ceil(ve->space[y_]));
        


        printf("x: %.4d, y: %.4d\r", x, y);


        SDL_RenderPresent(renderer);

    }

    
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
