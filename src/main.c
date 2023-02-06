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

const int SCREEN_W = 640;
const int SCREEN_H = 480;


int main(int argc, char **argv)
{

    SDL_Window *window = NULL;
    SDL_Surface *surface = NULL;
    SDL_Renderer *renderer;

    int NOW = 0, LAST = 0;
    double deltaTime = 0;

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

    Entity player; player.x = 1; player.y = 1;
    player.image = IMG_LoadTexture(renderer, "./assets/sprites/MyChar.png");
    
    while(!quit) { // SDL loop
        quit = Citrus_EventHandler(window, &player);
        Citrus_Renderer(renderer, &player);
    }

    
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}

/* Return 1 on window quit */
int Citrus_EventHandler(SDL_Window *window, Entity *player){
    // event handler
    SDL_Event event;

    
    while(SDL_PollEvent( &event ) != 0) {
        if( event.type == SDL_QUIT ) {
            return 1;
        }
        const Uint8 *keyStates = SDL_GetKeyboardState(NULL);

        player->y -= keyStates[KEY_MAP[ACTION_UP]]*1;
        player->y += keyStates[KEY_MAP[ACTION_DOWN]]*1;
        player->x -= keyStates[KEY_MAP[ACTION_LEFT]]*1;
        player->x += keyStates[KEY_MAP[ACTION_RIGHT]]*1;

        // if(keyStates[KeyMap[ACTION_UP]]){
        //     printf("UP\n");
        //     if(keyStates[KeyMap[ACTION_LEFT]]){

        //     }
        //     else if(keyStates[KeyMap[ACTION_RIGHT]])
        // }
        // else if(keyStates[KeyMap[ACTION_DOWN]]){
        //     printf("DOWN\n");
        // }


        // else if(event.type = SDL_KEYDOWN){
        //     if(event.key.keysym.sym==KeyMap[ACTION_UP]){
        //         printf("up\n");
        //         player->y -= 1;
        //     }
        //     else if(event.key.keysym.sym==KeyMap[ACTION_DOWN]){
        //         printf("down\n");
        //         player->y += 1;
        //     }
        //     else if(event.key.keysym.sym==KeyMap[ACTION_LEFT]){
        //         printf("left\n");
        //         player->x -= 1;
        //     }
        //     else if(event.key.keysym.sym==KeyMap[ACTION_RIGHT]){
        //         printf("right\n");
        //         player->x += 1;
        //     }


        //     /* switch (event.key.keysym.sym)
        //     {
        //     case KeyMap[ACTION_UP]:
        //         printf("up\n");
        //         break;
            
        //     default:
        //         break;
        //     } */
        // }
    }
    // end

    return 0;

}

void Citrus_Renderer(SDL_Renderer *renderer, Entity *player){
    SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
    SDL_RenderClear(renderer);

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

    SDL_Rect rect = {player->x, player->y, 64, 64};
    SDL_RenderCopy(renderer, player->image, NULL, &rect);


    SDL_RenderPresent(renderer);
}
