#ifndef _Resource
#define _Resource

#include <iostream>
#include <SDL2/SDL.h>

class Resource{
private:
    SDL_Renderer *renderer;
public:
    void setup(SDL_Renderer *renderer);
    SDL_Texture *loadImage(std::string path);
    SDL_Texture *drawImage(SDL_Texture *img, double x, double y, double w, double h, double sx, double sy, double sw, double sh);

    SDL_Texture *brickWall;
    SDL_Texture *rockWall;
};

#endif