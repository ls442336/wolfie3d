#include "../includes/WolfieRenderer.h"
#include "../includes/Config.h"
#include "../includes/Resource.h"

#include <cmath>

#define PI 3.14159265

void WolfieRenderer::update(Player &player){
    calculateRaysIntersect(player);
}

void WolfieRenderer::draw(SDL_Renderer *ctx, Resource &resource){
    int wallWidth = DefaultConfig::screenWidth / DefaultConfig::numRays;
    int wallHeight = DefaultConfig::screenHeight;

    double max = 0;

    for(int i = 0; i < DefaultConfig::numRays; i++){
        Ray r = raysIntersects[i];
        if(r.d > max){
            max = r.d;
        }
    }

    for(int i = 0; i < DefaultConfig::numRays; i++){
        Ray r = raysIntersects[i];

        if(r.isWall){
            double d = (DefaultConfig::screenWidth / 2.0) / tan((DefaultConfig::fov / 2.0) * (PI / 180.0));
            wallHeight = (DefaultConfig::inGameTileSize / r.cd) * d;

            int wx = i * wallWidth;
            int hy = (DefaultConfig::screenHeight - wallHeight) / 2;

            //double shadingFactor = (r.d / DefaultConfig::viewDistance);

            //if(shadingFactor > 1){
            //    shadingFactor = 1;
            //}

            //SDL_Color color = DefaultConfig::colorMap[DefaultConfig::grid[r.gridY][r.gridX]];

            //double shade = 255 * shadingFactor;

            //SDL_Rect rect = {wx, hy, wallWidth, wallHeight};
            //SDL_SetRenderDrawColor(ctx, color.r * (1 - shadingFactor), color.g* (1 - shadingFactor), color.b * (1 - shadingFactor), 255);
            //SDL_RenderFillRect(ctx, &rect);

            resource.drawImage(resource.brickWall, wx, hy, wallWidth, wallHeight, r.texIndex, 0, 1, 512);

            SDL_Rect rect2 = {wx, 0, wallWidth, hy};
            SDL_SetRenderDrawColor(ctx, 135, 206, 235, 255);
            SDL_RenderFillRect(ctx, &rect2);

            SDL_Rect rect3 = {wx, hy + wallHeight, wallWidth, DefaultConfig::screenHeight - hy - wallHeight};
            SDL_SetRenderDrawColor(ctx, 100, 100, 100, 255);
            SDL_RenderFillRect(ctx, &rect3);
        }
    }
}
void WolfieRenderer::setup(){
    raysIntersects = std::vector<Ray>();
}

void WolfieRenderer::calculateRaysIntersect(Player &player){
    int fov = DefaultConfig::fov;
    int numRays = DefaultConfig::numRays;
    double playerRotation = player.getRotation();

    double playerX = player.getX();
    double playerY = player.getY();

    double angleByRay = (double) fov / (double) numRays;
    double currAngle = playerRotation - (double) fov / 2;

    int lastGridX = playerX / DefaultConfig::inGameTileSize, lastGridY = playerY / DefaultConfig::inGameTileSize;
    int lstGridX = playerX / DefaultConfig::inGameTileSize, lstGridY = playerY / DefaultConfig::inGameTileSize;

    raysIntersects.clear();

    for(int i = 0; i < numRays; i++){
        double x = playerX, y = playerY;
        int gridX, gridY;
        bool isRay = false;
        Ray r(-1, -1, 0, 0, false, 0, 0, -1);

        while(true){
            x += cos(currAngle * PI/180.0);
            y += sin(currAngle * PI/180.0);

            gridX = (int)(x / DefaultConfig::inGameTileSize);
            gridY = (int)(y / DefaultConfig::inGameTileSize);

            if(DefaultConfig::grid[gridY][gridX] != 0){
                isRay = true;
                break;
            }
            
            if(x < 0 || x > DefaultConfig::inGameTileSize * DefaultConfig::gridWidth || y < 0 || y > DefaultConfig::inGameTileSize * DefaultConfig::gridHeight){
                break;
            }

            int tx = lastGridX, ty = lastGridY;

            lastGridX = gridX;
            lastGridY = gridY;

            lstGridX = tx;
            lstGridY = ty;
        }

        if(isRay){
            r.isWall = true;

            int gx, gy;

            if(gridX != lastGridX && gridY != lastGridY){
                gx = lastGridX;
                gy = lastGridY;
            }else{
                gx = lstGridX;
                gy = lstGridY;
            }

            if(gridX + 1 == gx && gridY == gy){
                r.texIndex = (gridY * DefaultConfig::inGameTileSize + DefaultConfig::inGameTileSize - y);
            }else if(gridX - 1 == gx && gridY == gy){
                r.texIndex = (gridY * DefaultConfig::inGameTileSize - y);
            }else if(gridX == gx && gridY == gy + 1){
                r.texIndex = (gridX * DefaultConfig::inGameTileSize - x);
            }else if(gridX == gx && gridY == gy - 1){
                r.texIndex = (gridX * DefaultConfig::inGameTileSize + DefaultConfig::inGameTileSize - x);
            }

            r.texIndex = abs(r.texIndex);
        }

        r.gridX = gridX;
        r.gridY = gridY;
        r.x = x;
        r.y = y;
        r.d = sqrt((playerX - x) * (playerX - x) + (playerY - y) * (playerY - y));
        
        r.cd = r.d * cos((player.getRotation() - currAngle) * PI / 180.0);
        raysIntersects.push_back(r);

        currAngle += angleByRay;
    }

}