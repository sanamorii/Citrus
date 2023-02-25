#ifndef CITRUSENTITY_H
#define CITRUSENTITY_H

#include "citrus_core/core.h"
#include "citrus_maths/linear.h"

#define MAX_COMPONENTS 10
#define MAX_ENTITIES 500

enum EntityComponents{
    POSITION,
    SPRITE,
    PHYSICS,
    
    AUDIO,
};

enum SpriteType{
    Static,
    Animated
};

enum SpriteSheetIndex{
    IDLE,
    WALK,
    RUN,
    ATTACK
};


typedef struct Entity{
    long int id;
    void **components;
}Entity;

typedef Vector PositionComponent;

// TODO: static sprite can be an animated sprite - just only have a 1x1 array and specify interval to 0
typedef struct SpriteComponent{
    int id;
    int type;
    SDL_Texture ***sheet;  // a pointer to an array of pointers to another array of pointers
    int *frame_num;
    double interval;
}SpriteComponent;

typedef SDL_Texture StaticSprite;

Entity *create_entity();
void destroy_entity(Entity *);

int create_component(Entity *, int);
void remove_component(Entity *, int);

StaticSprite *_create_static_sprite(SDL_Renderer *, char *);
PositionComponent *_create_position();

#endif