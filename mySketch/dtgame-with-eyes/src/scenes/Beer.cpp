//
//  Beer.cpp
//  dtgame
//
//  Created by Hang Do Thi Duc on 16.05.15.
//
//

#include "Beer.h"

Beer::Beer(float _posX, float _posY) {
    posX = _posX;
    posY = _posY;
    
    speedX = 0.5;
    speedY = 0;
    
    beerImg.loadImage("obstacle.jpg");
}

void Beer::update() {
    posX += speedX;
    posY += speedY;
}

void Beer::draw() {
    beerImg.draw(posX, posY);
    posX -= 2;
}