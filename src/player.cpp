#include "../includes/Player.h"

#include <iostream>
#include <cmath>

#define PI 3.14159265

void Player::update(){
    if(isRotating){
        rotation += (rotSpeed * rotDir) % 360;
    }

    if(isMoving){
        x += cos(rotation * PI / 180) * speed;
        y += sin(rotation * PI / 180) * speed;
    }
}

void Player::draw(){

}

void Player::onkeyDown(SDL_Scancode e){
    if(e == SDL_SCANCODE_A){
        isRotating = true;
        rotDir = -1;
    }else if(e == SDL_SCANCODE_D){
        isRotating = true;
        rotDir = 1;
    }else if(e == SDL_SCANCODE_W){
        isMoving = true;
    }
}

void Player::onkeyUp(SDL_Scancode e){
    if(e == SDL_SCANCODE_A){
        isRotating = false;
    }else if(e == SDL_SCANCODE_D){
        isRotating = false;
    }else if(e == SDL_SCANCODE_W){
        isMoving = false;
    }
}

void Player::setup(){
    x = 320;
    y = 512;
    rotation = -90;
    isRotating = false;
    rotDir = 0;
    rotSpeed = 1;
    speed = 1;
}