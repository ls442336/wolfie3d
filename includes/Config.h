#ifndef _CONFIG
#define _CONFIG

#include <SDL2/SDL.h>

namespace DefaultConfig{
    const int mapHeight = 100;
    const int mapWidth = 100;
    const int gridWidth = 10;
    const int gridHeight = 10;
    const int screenHeight = 480;
    const int screenWidth = 640;
    const int fov = 60;
    const int numRays = 640;
    const int inGameTileSize = 64;
    const int viewDistance = 512;

    const SDL_Color white = {255, 255, 255, 255};
    const SDL_Color black = {0, 0, 0, 255};
    const SDL_Color red = {255, 0, 0, 255};
    const SDL_Color green = {0, 255, 0, 255};
    const SDL_Color blue = {0, 0, 255, 255};

    const SDL_Color colorMap[] = {black, white, red, green, blue};

    const int grid[gridHeight][gridWidth] = {
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 2, 1, 3, 1, 0, 0, 1},
        {1, 0, 0, 1, 0, 0, 4, 0, 0, 1},
        {1, 0, 0, 4, 0, 0, 1, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
    };
}
#endif
