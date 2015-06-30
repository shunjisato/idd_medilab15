#include "Webcam.h"

void Webcam::setup(){
    cam.isFrameNew();
    cam.setDesiredFrameRate(30);
    cam.setDeviceID(0);
    cam.initGrabber(1280,720);
    cam.listDevices();
}
void Webcam::update(){
    cam.update();
}

void Webcam::draw(){
    cam.draw(0, 0, ofGetWidth(), ofGetHeight());
    
}


string Webcam::getName(){
    return "webcam";
}