#include "Webcam.h"
#include "ofxPS3EyeGrabber.h"

void Webcam::setup(){
    cam.isFrameNew();
    //    cam.listDevices();
    
    ofxPS3EyeGrabber* g = new ofxPS3EyeGrabber();
    
    cam.setGrabber(ofPtr<ofxPS3EyeGrabber>(g));
    cam.setDesiredFrameRate(30);
    cam.initGrabber(1280,720);
    
    g->setExposure(64);
    g->setGain(128);
    //printf("\n\n\n\n\nexp = %i\n",exp);
    
    
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