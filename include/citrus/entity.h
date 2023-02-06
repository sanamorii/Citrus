#ifndef CITRUSENTITY_H
#define CITRUSENTITY_H

enum EntityTypes{
    NONE,
    PLAYER,
    NPC,
    PROP
};

typedef struct Entity{
    long int id;
    int x, y;
    int type;

    SDL_Texture *image;

}Entity;

typedef struct Animation{
    long int parent_id;
    long int id;

    SDL_Texture **frames;
    int frame_count;
    double time;
}Animation;

#endif