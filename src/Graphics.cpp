#include "Graphics.h"

namespace CitrusEngine
{
    Graphics *Graphics::sInstance = NULL;
    bool Graphics::sInitialised = false;

    Graphics *Graphics::Instance()
    {

        if (sInstance == NULL)
        {
            sInstance = new Graphics();
        }

        return sInstance;
    }

    void Graphics::Release()
    {
        delete sInstance;
        sInstance = NULL;

        sInitialised = false;
    }

    bool Graphics::Initialised()
    {
        return sInitialised;
    }

    Graphics::Graphics()
    {
        mBackBuffer = NULL;
        sInitialised = Init();
    }

    Graphics::~Graphics()
    {

        SDL_DestroyRenderer(mRenderer);
        SDL_DestroyWindow(mWindow);

        mWindow = NULL;
        mRenderer = NULL;

        this->Release();

        SDL_Quit();
    }

    bool Graphics::Init()
    {

        // INIT SDL LIBRARY
        if (SDL_Init(SDL_INIT_VIDEO) < 0)
        {
            // error has occured
            std::cout << "SDL initialisation error: " << SDL_GetError() << std::endl;
            return false;
        }

        if (!(IMG_Init(IMG_INIT_PNG)))
        {
            std::cout << "SDL_image initialisation error: " << SDL_GetError() << std::endl;
            return false;
        }

        mWindow = SDL_CreateWindow(
            "Citrus",
            SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
            SCREEN_WIDTH, SCREEN_HEIGHT,
            SDL_WINDOW_SHOWN);

        if (mWindow == NULL)
        {
            std::cout << "Graphics creation error: " << SDL_GetError() << std::endl;
            return false;
        }

        mRenderer = SDL_CreateRenderer(mWindow, -1, SDL_RENDERER_PRESENTVSYNC);

        if (mRenderer == NULL)
        {
            std::cout << "Renderer creation error: " << SDL_GetError() << std::endl;
            return false;
        }

        return true;
    }
} // namespace CitrusEngine
