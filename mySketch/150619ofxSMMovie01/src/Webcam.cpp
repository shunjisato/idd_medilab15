#include "Webcam.h"

void Webcam::setup(){
    cam.isFrameNew();
    cam.setDesiredFrameRate(30);
    cam.setDeviceID(0);
    cam.initGrabber(620, 480);
    cam.listDevices();
}
void Webcam::update(){
    cam.update();
}

void Webcam::draw(){
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
    cam.draw(-320,0);
        
}


string Webcam::getName(){
    return "webcam";
}