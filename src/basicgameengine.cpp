#include "../includes/BasicGameEngine.h"
#include "../includes/Config.h"
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

void BasicGameEngine::draw(){
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    wolfieRenderer.draw(renderer, resource);

    map.draw(renderer, player, wolfieRenderer);

    SDL_RenderPresent(renderer);
}

void BasicGameEngine::update(){
    player.update();
    wolfieRenderer.update(player);
}

void BasicGameEngine::mainloop(){
    while(true){
        if(SDL_GetTicks() - dt >= 1000.0 / 60.0){
            dt = SDL_GetTicks();
            if(handleEvents() != 0){
                return;
            }
            update();
            draw();

            framesCounter++;
        }

        double now = SDL_GetTicks();
        if(now - fpsTimestamp >= 1000){
            fps = framesCounter;
            //std::cout << fps << std::endl;
            framesCounter = 0;
            fpsTimestamp = now;
        }
    }
}

void BasicGameEngine::setup(){
    fpsTimestamp = 0;
    framesCounter = 0;
    dt = 0;
    player = Player();
    player.setup();
    map = Map();
    map.setup();
    wolfieRenderer = WolfieRenderer();
    resource = Resource();
    resource.setup(renderer);
}

void BasicGameEngine::onKeyDown(SDL_Scancode e){
    player.onkeyDown(e);
}

void BasicGameEngine::onKeyUp(SDL_Scancode e){
    player.onkeyUp(e);
}

int BasicGameEngine::handleEvents(){
    SDL_Event windowEvent;

    while(SDL_PollEvent(&windowEvent) != 0){
        switch(windowEvent.type){
            case SDL_KEYDOWN:
                onKeyDown(windowEvent.key.keysym.scancode);
            break;
            case SDL_KEYUP:
                onKeyUp(windowEvent.key.keysym.scancode);
            break;
            case SDL_QUIT:
                return 1;
            break;
        }
    }

    return 0;
}

void BasicGameEngine::run(){
    SDL_Init(SDL_INIT_EVERYTHING);

    window = SDL_CreateWindow("Wolfie", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, DefaultConfig::screenWidth, DefaultConfig::screenHeight, SDL_WINDOW_ALLOW_HIGHDPI);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    if(window == NULL){
        std::cout << "Impossivel criar uma janela." << SDL_GetError() << std::endl;
        return;
    }

    setup();
    mainloop();

    SDL_DestroyWindow(window);
    SDL_Quit();
}