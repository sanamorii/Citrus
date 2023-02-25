#include "citrus_core/core.h"
#include "citrus_core/entity.h"

static int counter = 0;

Entity *create_entity(){
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

int create_component(Entity *entity, int component_type){
    void *component;
    
    switch (component_type)
    {
    case POSITION:
        component = (void *) create_vector(2, 0.0, 0.0);
        break;
    case SPRITE:
        C_Sprite *tmp =  (C_Sprite *) malloc(sizeof(C_Sprite));
        tmp->sprite = NULL;
        tmp->type = NULL;
        component = (void *) tmp;
    
    default:
        break;
    }
    entity->components[component_type] = component;
}


C_Sprite *_create_sprite(int sprite_type){

}


