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
                            640, 480,
                            SDL_WINDOW_SHOWN);

    if(window == NULL){
        printf("SDL failed to create window %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }

    if(!(renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC ))){
        printf("SDL failed to create renderer: %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }

    // int x = 0, y = 0;
    Vector *origin = create_vector(2, (SCREEN_W/2.f), (SCREEN_H/2.f));

    Vector *direction = create_vector(2, 0.0, 0.0);
    Vector *position = create_vector(2, 0.0, 0.0);

    Entity player; player.x = 0; player.y = 0;
    player.sprite = (void *) IMG_LoadTexture(renderer, "./assets/sprites/MyChar.png");

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
            const Uint8 *k_states = SDL_GetKeyboardState(NULL);

            direction->s[y_] = ((k_states[K_MAP[A_UP]] * -1) + (k_states[K_MAP[A_DOWN]] * 1));
            direction->s[x_] = ((k_states[K_MAP[A_RIGHT]] * 1) + (k_states[K_MAP[A_LEFT]] * -1));
            v_normalise(direction);
            v_scale(direction, 5);
            // v_add(direction, origin);
            
        }

        SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
        SDL_RenderClear(renderer);
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

        // SDL_GetMouseState(&x, &y);
        // position->s[x_] = x;
        // position->s[y_] = y;

        // offset pos
        // position->s[x_] = x-origin->s[x_];
        // position->s[y_] = y-origin->s[y_];

        // v_subtract(position, origin);
        // v_normalise(position);

        // v_scale(position, 100);
        // v_add(position, origin);


        // int st1 = SDL_RenderDrawLineF(renderer, 
        //     origin->s[x_], origin->s[y_], 
        //     position->s[x_], position->s[y_]);
        // int st2 = SDL_RenderDrawLineF(renderer, 
        //     origin->s[x_], origin->s[y_], 
        //     direction->s[x_], direction->s[y_]);

        SDL_RenderDrawLineF(renderer, 0, origin->s[y_], SCREEN_W, origin->s[y_]);
        SDL_RenderDrawLineF(renderer, origin->s[x_], 0, origin->s[x_], SCREEN_H);

        printf("x: %.4f, y: %.4f\r", direction->s[x_], direction->s[y_]);
        // printf("fps: %.8d\r", fps);

        v_add(position, direction);
        
        SDL_FRect rect = {position->s[x_], position->s[y_],
                          64, 64};
        SDL_RenderCopyF(renderer, (SDL_Texture *) player.sprite, NULL, &rect);

        SDL_RenderPresent(renderer);

    }

    destroy_vector(direction);
    
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
