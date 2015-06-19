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
    IMmovie.draw(0,0);
}


string imitationMovie::getName(){
    return "IMmovie";
}