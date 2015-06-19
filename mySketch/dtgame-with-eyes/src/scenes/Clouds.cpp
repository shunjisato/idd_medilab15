//
//  Clouds.cpp
//  dtgame
//
//  Created by Hang Do Thi Duc on 16.05.15.
//
//

#include "Clouds.h"

Clouds::Clouds(float _posX, float _posY) {
    posX = _posX;
    posY = _posY;
    
    speedX = 0.3;
    speedY = 0;
    
    cloudImg.loadImage("cloud.png");
}

void Clouds::update() {
    posX += speedX;
    posY += speedY;
}

void Clouds::draw() {
    cloudImg.draw(posX, posY);
    posX -= 2;
}