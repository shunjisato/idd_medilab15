#include "imitationMovie.h"

void imitationMovie::setup(){
    IMmovie[0].loadMovie("circlerotate.mov"); //, "countdown15.mov", "face.mp4", "m.c.d.testbyperfume_640x468.mp4");
    IMmovie[1].loadMovie("m.c.d.testbyperfume_640x468.mp4");
    IMmovie[2].loadMovie("countdown15.mov");
    IMmovie[3].loadMovie("face.mp4");
    
    IMmovie[0].setLoopState(OF_LOOP_NORMAL);
    IMmovie[1].setLoopState(OF_LOOP_NORMAL);
    IMmovie[2].setLoopState(OF_LOOP_NORMAL);
    IMmovie[3].setLoopState(OF_LOOP_NORMAL);

    
}
void imitationMovie::update(){
    NUM == ofRandom(0,3);
    IMmovie[NUM].update();
    IMmovie[NUM].play();
}

void imitationMovie::draw(){
    IMmovie[NUM].draw(0, 0, ofGetWidth(), ofGetHeight());
}


string imitationMovie::getName(){
    return "IMmovie";
}