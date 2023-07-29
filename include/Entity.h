#ifndef _ENTITY_H
#define _ENTITY_H

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <vector>

#include "Component.h"

namespace CitrusEngine{
    class Entity
    {
    private:
        /* data */
        std::vector<Component*> Components;
        void AddComponent(Component *component);
    public:
        Entity(/* args */);
        ~Entity();
    };
    
    Entity::Entity(/* args */)
    {
    }
    
    Entity::~Entity()
    {
    }
    
}

#endif