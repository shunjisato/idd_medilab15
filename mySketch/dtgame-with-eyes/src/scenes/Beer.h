//
//  Beer.h
//  dtgame
//
//  Created by Hang Do Thi Duc on 16.05.15.
//
//

#pragma once
#include "ofMain.h"

class Beer {
    
public:
    Beer(float _posX, float _posY);
    void update();
    void draw();
    
    ofImage beerImg;
    float posX = 650;
    float posY = 200;
    float speedX, speedY;
};