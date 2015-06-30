#include "imitationMovie.h"

void imitationMovie::setup(){
    IMmovie.loadMovie("face.mp4");
    IMmovie.setLoopState(OF_LOOP_NORMAL);

}
void imitationMovie::update(){
    IMmovie.update();

    IMmovie.play();
}

void imitationMovie::draw(){
    IMmovie.draw(0, 0, ofGetWidth(), ofGetHeight());
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