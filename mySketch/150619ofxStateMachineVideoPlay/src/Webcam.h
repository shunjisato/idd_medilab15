#pragma once

#include "ofxState.h"
#include "SharedData.h"

class Webcam : public itg::ofxState<SharedData> {
    void setup();
    void update();
    void draw();
    string getName();
    
    ofVideoPlayer movie;
};