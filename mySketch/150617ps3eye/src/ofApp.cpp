#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    cam.setDesiredFrameRate(30);
    cam.setDeviceID(0);
    cam.initGrabber(ofGetWidth(), ofGetHeight());
    cam.listDevices();
    
    pseye.setDesiredFrameRate(30);
    pseye.setDeviceID(0);
    pseye.initGrabber(ofGetWidth(), ofGetHeight());
    pseye.listDevices();
    
    pressed = true;
    
}

//--------------------------------------------------------------
void ofApp::update(){
    

        cam.update();
        pseye.update();
        
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    if(pressed){
        cam.draw(0,0);
    } else{
        pseye.draw(0,0);
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    
    pressed = true;
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 
    
}
