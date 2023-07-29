#ifndef _GAME_H
#define _GAME_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

#include "Graphics.h"

namespace CitrusEngine{
    class Game{
    private:
        static Game *sInstance;
        const int FRAMERATE = 60;
        bool mQuit;
        Graphics *mGraphics;

        void Update();
        void Render();

    public:
        static Game *Instance();
        static void Release();

        void Run();

        Game();
        ~Game();
    };
    
}

#endif