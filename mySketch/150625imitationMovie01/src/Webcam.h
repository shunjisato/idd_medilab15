#pragma once

#include "ofxState.h"
#include "SharedData.h"

class Webcam : public itg::ofxState<SharedData> {
    
public:
    
    void setup();
    void update();
    void draw();
    string getName();
    
    ofVideoGrabber cam;
    ofTexture tex;
    
};