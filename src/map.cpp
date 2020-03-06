#include "../includes/Map.h"

void Map::setup(){
    width = DefaultConfig::mapWidth;
    height = DefaultConfig::mapHeight;

    x = DefaultConfig::screenWidth - width - 65;
    y = 15;

    borderline = true;
}

void Map::draw(SDL_Renderer *ctx, Player &player, WolfieRenderer &wolfieRenderer){
    //if(borderline){
    //    SDL_Rect outlinedMap = {x, y, width, height};
    //    SDL_SetRenderDrawColor(ctx, 255, 0, 0, 255);
    //    SDL_RenderDrawRect(ctx, &outlinedMap);
    //}

    double scale = DefaultConfig::inGameTileSize / 16;
    
    double px = player.getX() / scale;
    double py = player.getY() / scale;

    for(int i = 0; i < DefaultConfig::gridHeight; i++){
        for(int j = 0; j < DefaultConfig::gridWidth; j++){

            SDL_Rect rect = {x + j * DefaultConfig::inGameTileSize / scale, y + i * DefaultConfig::inGameTileSize / scale, DefaultConfig::inGameTileSize / scale, DefaultConfig::inGameTileSize / scale};
            SDL_Color c = DefaultConfig::colorMap[DefaultConfig::grid[i][j]];
            SDL_SetRenderDrawColor(ctx, c.r, c.g, c.b, c.a);
            SDL_RenderFillRect(ctx, &rect);
        }
    }

    SDL_SetRenderDrawColor(ctx, 0, 255, 0, 255);
    for(auto &e : wolfieRenderer.getRaysIntersects()){
        SDL_RenderDrawLine(ctx, x + px, y + py, x + e.x / scale, y + e.y / scale);
    }

    SDL_Rect playerRect = {x + player.getX() / scale - 3, y + player.getY() / scale - 3, 6, 6};
    SDL_SetRenderDrawColor(ctx, 255, 0, 0, 255);
    SDL_RenderFillRect(ctx, &playerRect);
}