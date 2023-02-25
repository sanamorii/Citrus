#ifndef CITRUSENTITY_H
#define CITRUSENTITY_H

#include "citrus_core/core.h"
#include "citrus_utils/linear.h"

enum EntityComponents{
    POSITION,
    PHYSICS,
    SPRITE,
    AUDIO
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
    int x, y;

    void *sprite;

    void **components;
    int component_num;

}Entity;

typedef Vector C_Position;

typedef struct C_Sprite{
    void *sprite;
    int type;
}C_Sprite;

typedef struct StaticSprite{
    SDL_Texture *texture;
}StaticSprite;

typedef struct AnimatedSprite{
    SDL_Texture ***sheet;  // a pointer to an array of pointers to another array of pointers
    int *frame_num;
    double interval;
}AnimatedSprite;

Entity *create_entity();
void destroy_entity();

int create_component(Entity *);
void remove_component(Entity *, int component_type);


#endif