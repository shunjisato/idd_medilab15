#include "imitationMovie.h"

void imitationMovie::setup(){
    IMmovie.loadMovie("countdown15.mov");
    IMmovie.setLoopState(OF_LOOP_NORMAL);
    
}
void imitationMovie::update(){
    IMmovie.update();
    
    IMmovie.play();
}

void imitationMovie::draw(){
    IMmovie.draw(0, 0, ofGetWidth(), ofGetHeight());
    
    ofSetColor(255, 2552, 255);
    ofDrawBitmapString(" key s: start streaming data \n key e: stop streaming data \n", 10,10);
}


string imitationMovie::getName(){
    return "IMmovie";
}

void imitationMovie::stateEnter()
{
    IMmovie.setPaused(false);
}

void imitationMovie::stateExit()
{
    IMmovie.setPaused(true);
}