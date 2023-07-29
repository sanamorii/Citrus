#include "Game.h"

namespace CitrusEngine
{
    Game *Game::sInstance = NULL;
    
    Game *Game::Instance(){
        if (sInstance == NULL){ sInstance = new Game(); }
        return sInstance;
    }

    void Game::Run()
    {
        while(mQuit!=false){
            Update();
            Render();
        }
    }

    void Game::Update(){

    }

    void Game::Render(){

    }

    Game::Game(){
        mQuit = false;
        this->mGraphics = Graphics::Instance();

    }

    Game::~Game(){
        Game::Release();

    }

    void Game::Release(){

    }
} // namespace Citrus

