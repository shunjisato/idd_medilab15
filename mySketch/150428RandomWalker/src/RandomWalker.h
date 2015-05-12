//
//  RandomWalker.h
//  150428RandomWalker
//
//  Created by labメンバー on 2015/04/28.
//
//

#pragma once
#include "ofMain.h"
class RandomWalker {
public:
    RandomWalker(); //constlacter
    void update();
    void draw();
    
    ofVec3f position;
};