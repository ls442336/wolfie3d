#ifndef _Player
#define _Player

#include "Config.h"

class Player{
private:
    double x;
    double y;
    int rotSpeed;
    double rotation;
    bool isRotating;
    bool isMoving;
    int rotDir;
    int speed;
public:
    double getX(){
        return x;
    }
    void setX(double x){
        this->x = x;
    }
    double getY(){
        return y;
    }
    void setY(double y){
        this->y = y;
    }
    double getRotation(){
        return rotation;
    }
    void setRotation(double rot){
        this->rotation = rot;
    }
    void draw();
    void update();
    void setup();
    void onkeyDown(SDL_Scancode e);
    void onkeyUp(SDL_Scancode e);
};

#endif