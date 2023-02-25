#ifndef CITRUSENTITY_H
#define CITRUSENTITY_H

#include "citrus_core/core.h"
#include "citrus_maths/linear.h"

#define MAX_COMPONENTS 10

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

typedef Vector C_Position;

typedef struct C_Sprite{
    void *sprite;
    int type;
}C_Sprite;

typedef SDL_Texture StaticSprite;

typedef struct AnimatedSprite{
    SDL_Texture ***sheet;  // a pointer to an array of pointers to another array of pointers
    int *frame_num;
    double interval;
}AnimatedSprite;

Entity *create_entity();
void destroy_entity(Entity *);

int create_component(Entity *, int);
void remove_component(Entity *, int);


#endif