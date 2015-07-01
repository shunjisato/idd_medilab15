#include "Webcam.h"
#include "ofxPS3EyeGrabber.h"

void Webcam::setup(){
    cam.isFrameNew();
//    cam.listDevices();
    cam.setGrabber(ofPtr<ofxPS3EyeGrabber>(new ofxPS3EyeGrabber()));
//    cam.setDesiredFrameRate(30);
    cam.initGrabber(1280,720);
}
void Webcam::update(){
    cam.update();
}

void Webcam::draw(){
    ofBackground(0);
    ofSetColor(255,200);
    cam.draw(0, 0, ofGetWidth(), ofGetHeight());
    
}


string Webcam::getName(){
    return "webcam";
}