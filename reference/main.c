#define SDL_MAIN_HANDLED
#include "SDL2/SDL.h"
#include "stdio.h"
#include "stdlib.h"
#include "time.h"

SDL_Window *win;
SDL_Surface *surf, *head_image, *body_image, *food_image;

int head_x, head_y;
int tail_xs[1024], tail_ys[1024];
int tail_length = 3;
int dir_x = 1, dir_y = 0;
int food_x, food_y;

void make_food() {
    food_x = rand() % 32;
    food_y = rand() % 32;
}

void load() {
    srand(time(NULL));
    
    head_image = SDL_LoadBMP("assets/head.bmp");
    body_image = SDL_LoadBMP("assets/body.bmp");
    food_image = SDL_LoadBMP("assets/food.bmp");
    
    SDL_Init(SDL_INIT_VIDEO);
    
    win = SDL_CreateWindow(
        "HackSoc",
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        1024, 1024, SDL_WINDOW_SHOWN);
    
    surf = SDL_GetWindowSurface(win);
    
    make_food();
    
    head_x = 16;
    head_y = 16;
    
    for (int i = 0; i < tail_length; i++) {
        tail_xs[i] = head_x - i - 1;
        tail_ys[i] = head_y;
    }
}

int step() {
    if (head_x == food_x && head_y == food_y) {
        tail_length++;
        make_food();
    }
    
    for (int i = tail_length-1; i > 0; i--) {
        tail_xs[i] = tail_xs[i-1];
        tail_ys[i] = tail_ys[i-1];
    }
    
    tail_xs[0] = head_x;
    tail_ys[0] = head_y;
    
    head_x += dir_x;
    head_y += dir_y;
    
    head_x = (head_x + 32) % 32;
    head_y = (head_y + 32) % 32;
    
    for (int i = 0; i < tail_length; i++) {
        if (head_x == tail_xs[i] && head_y == tail_ys[i]) {
            return 0;
        }
    }
    
    return 1;
}

int main(int argc, char **argv) {
    load();
    
    SDL_Rect r;
    int count = 0;
    
    while (1) {
        SDL_Event e;
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) {
                goto end;
            } else if (e.type == SDL_KEYDOWN) {
                switch (e.key.keysym.sym) {
                case SDLK_LEFT:
                    dir_x = -1;
                    dir_y = 0;
                    break;
                case SDLK_RIGHT:
                    dir_x = 1;
                    dir_y = 0;
                    break;
                case SDLK_UP:
                    dir_x = 0;
                    dir_y = -1;
                    break;
                case SDLK_DOWN:
                    dir_x = 0;
                    dir_y = 1;
                    break;
                }
            }
        }
        
        if (count++ > 50) {
            if (!step()) {
                goto end;
            }
            count = 0;
        }
        
        SDL_FillRect(surf, NULL, SDL_MapRGB(surf->format, 0, 0, 0));
        
        r.x = food_x * 32;
        r.y = food_y * 32;
        SDL_BlitSurface(food_image, NULL, surf, &r);
        
        r.x = head_x * 32;
        r.y = head_y * 32;
        SDL_BlitSurface(head_image, NULL, surf, &r);
        
        for (int i = 0; i < tail_length; i++) {
            r.x = tail_xs[i] * 32;
            r.y = tail_ys[i] * 32;
            SDL_BlitSurface(body_image, NULL, surf, &r);
        }
        
        SDL_UpdateWindowSurface(win);
    }
    
end:
    printf("you lose!\n");
    return 0;
}
