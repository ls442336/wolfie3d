#ifndef _BasicGameEngine
#define _BasicGameEngine

#include <SDL2/SDL.h>
#include "Player.h"
#include "Map.h"
#include "WolfieRenderer.h"
#include "Resource.h"

class BasicGameEngine{
private:
    SDL_Window *window;
    SDL_Renderer *renderer;
    void draw();
    void update();
    int handleEvents();
    void mainloop();
    void setup();
    void onKeyDown(SDL_Scancode e);
    void onKeyUp(SDL_Scancode e);

    double fpsTimestamp;
    int framesCounter;
    double fps;
    double dt;
public:
    void run();

    WolfieRenderer wolfieRenderer;
    Resource resource;
    Player player;
    Map map;
};

#endif