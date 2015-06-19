//
//  Assignments.cpp
//  dtgame
//
//  Created by Hang Do Thi Duc on 16.05.15.
//
//

#include "Assignments.h"

Assignments::Assignments(float _posX, float _posY) {
    posX = _posX;
    posY = _posY;
    
    speedX = 0.4;
    speedY = 0;
    
    assImg.loadImage("assignment.png");
}

void Assignments::update() {
    posX += speedX;
    posY += speedY;
}

void Assignments::draw() {
    assImg.draw(posX, posY);
    posX -= 3;
}