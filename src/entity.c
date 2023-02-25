#include <stdio.h>

#include "citrus_core/core.h"
#include "citrus_core/entity.h"

static unsigned long int counter = 0;

Entity *create_entity(){

    if(counter>MAX_ENTITIES){
        fprintf(stderr, "warning: reached entity limit\n");
        return NULL;
    }

    Entity *entity = (Entity *) malloc(sizeof(Entity));
    void **components = (void **) calloc(MAX_COMPONENTS, sizeof(void *));
    for(int i = 0; i<MAX_COMPONENTS; i++)
        components[i] = NULL;

    entity->id = counter++;
    entity->components = components;

    return entity;
}

void destroy_entity(Entity *entity){

    if(!(entity))
        return;
    
    for (int i = 0; i<MAX_COMPONENTS; i++){
        if(entity->components[i])
            remove_component(entity, i);
    }

    free(entity);
}

// int create_component(Entity *entity, int component_type){
//     NULL;
// }


StaticSprite *_create_static_sprite(SDL_Renderer *renderer, char *path){
    StaticSprite *sprite = IMG_LoadTexture(renderer, path);
    return (void *) sprite;
}


PositionComponent *_create_position(){
    PositionComponent *position = create_vector(2, 0.0, 0.0);
    return (void *) position;
}