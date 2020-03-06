#ifndef _MAP
#define MAP

#include <SDL2/SDL.h>

#include "Config.h"
#include "Player.h"
#include "WolfieRenderer.h"

class Map{
private:
    bool borderline;
    int x;
    int y;
    int width;
    int height;
public:
    void setup();
    void draw(SDL_Renderer *ctx, Player &player, WolfieRenderer &wolfieRenderer);
};

#endif