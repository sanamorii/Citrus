#ifndef _GRAPHICS_H
#define _GRAPHICS_H

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

namespace CitrusEngine
{
    class Graphics
    {
    public:
        /* VARIABLES */
        static const int SCREEN_WIDTH = 800;
        static const int SCREEN_HEIGHT = 600;

        /* Singleton Method to get Graphics Instance */
        static Graphics *Instance();
        static void Release();
        static bool Initialised();

    private:
        static Graphics *sInstance;
        static bool sInitialised;

        SDL_Window *mWindow;
        SDL_Surface *mBackBuffer;
        SDL_Renderer *mRenderer;

        // Constructor and destructor
        Graphics();
        ~Graphics();

        bool Init();

    };
}

#endif