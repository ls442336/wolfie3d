#ifndef _RAY
#define _RAY

class Ray{
private:
public:
    Ray(int gridX, int gridY, double x, double y, bool isWall, double d, double cd, int texIndex){
        this->gridX = gridX;
        this->gridY = gridY;
        this->x = x;
        this->y = y;
        this->isWall = isWall;
        this->d = d;
        this->cd = cd;
        this->texIndex = texIndex;
    }
    int gridX;
    int gridY;
    int texIndex;
    double x;
    double y;
    double d;
    double cd;
    bool isWall;
};

#endif