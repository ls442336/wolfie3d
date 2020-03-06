#ifndef _WolfieRenderer
#define _WolfieRenderer

#include <iostream>
#include <vector>

#include "Player.h"
#include "Ray.h"
#include "Resource.h"

class WolfieRenderer{
private:
    std::vector<Ray> raysIntersects;
    void calculateRaysIntersect(Player &player);
public:
    void update(Player &player);
    void draw(SDL_Renderer *ctx, Resource &resource);
    void setup();

    std::vector<Ray> getRaysIntersects(){
        return raysIntersects;
    }
};

#endif