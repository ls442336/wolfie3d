#include "../includes/Resource.h"

#include <SDL2/SDL_image.h>

void Resource::setup(SDL_Renderer *renderer){
    this->renderer = renderer;

    brickWall = loadImage("../data/images/tiles/brickWall.jpg");
    rockWall = loadImage("../data/images/tiles/rockWall.jpg");

    if(brickWall == 0){
        std::cout << "LOAD ERROR" << std::endl;
    }
}

SDL_Texture* Resource::loadImage(std::string path){
    SDL_Texture *tex = NULL;
    SDL_Surface *sur = NULL;

    sur = IMG_Load(path.c_str());
    std::cout << IMG_GetError() << std::endl;
    tex = SDL_CreateTextureFromSurface(renderer, sur);

    SDL_FreeSurface(sur);

    return tex;
}

SDL_Texture *Resource::drawImage(SDL_Texture *img, double x, double y, double w, double h, double sx, double sy, double sw, double sh){
    SDL_Rect rect = {x, y, w, h};
    SDL_Rect srcrect = {sx, sy, sw, sh};

    SDL_RenderCopy(renderer, img, &srcrect, &rect);
}