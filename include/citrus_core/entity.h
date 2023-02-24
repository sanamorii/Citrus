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

    void *sprite;

}Entity;


#endif