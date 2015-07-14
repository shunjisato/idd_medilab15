#pragma once

#include "ofxState.h"
#include "SharedData.h"

class imitationMovie : public itg::ofxState<SharedData> {
    
public:
    
    void setup();
    void update();
    void draw();
    
    virtual void stateEnter();
    virtual void stateExit();
    
    string getName();
    
    ofVideoPlayer IMmovie;
    
};