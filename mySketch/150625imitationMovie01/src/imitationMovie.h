#pragma once

#include "ofxState.h"
#include "SharedData.h"

class imitationMovie : public itg::ofxState<SharedData> {
    
public:
    
    void setup();
    void update();
    void draw();
    string getName();
    
    static const int NUM = 4;
    ofVideoPlayer IMmovie[NUM];
    
};