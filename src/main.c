#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <math.h>
#include <io.h>
#include <windows.h>

/* Core Files */
#include "citrus_core/core.h"
#include "citrus_core/input.h"
#include "citrus_core/entity.h"

/* utils */
#include "citrus_utils/linear.h"


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
    Vector *ve = create_vector(2, 0.0, 0.0);
    Vector *origin = create_vector(2, (SCREEN_W/2.f), (SCREEN_H/2.f));

    Uint32 prevTime = 0;
    while(!quit) { // SDL loop

        // Calculate Delta Time
        Uint32 currTime = SDL_GetTicks();
        Uint32 deltaTime = currTime - prevTime;
        prevTime = currTime;

        Uint64 fps = deltaTime == 0 ? 1000 : 1000/deltaTime;
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
        ve->s[x_] = x;
        ve->s[y_] = y;

        // offset pos
        // ve->s[x_] = x-origin->s[x_];
        // ve->s[y_] = y-origin->s[y_];
        v_subtract(ve, origin);

        v_normalise(ve);
        v_scale(ve, 100);
        v_add(ve, origin);

        int st = SDL_RenderDrawLineF(renderer, 
            origin->s[x_], origin->s[y_], 
            ve->s[x_], ve->s[y_]);

        // SDL_RenderDrawLineF(renderer, 0, origin->space[y_], SCREEN_W, origin->space[y_]);
        // SDL_RenderDrawLineF(renderer, origin->space[x_], 0, origin->space[x_], SCREEN_H);

        // printf("x: %.4f, y: %.4f\r", ve->s[x_], ve->s[y_]);
        printf("fps: %.8d\r", fps);
        

        SDL_RenderPresent(renderer);

    }

    destroy_vector(ve);
    
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
