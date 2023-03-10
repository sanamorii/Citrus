#ifndef CITRUSCORE_H
#define CITRUSCORE_H

#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "glad/glad.h"

#include "citrus/entity.h"

/* data structures */
#include "utils/linked_list.h"
#include "utils/queue.h"
#include "utils/stack.h"

int Citrus_EventHandler(SDL_Window *window, Entity *player);
void Citrus_Renderer(SDL_Renderer *renderer, Entity *player);

#endif

/* 
draw
update

 */