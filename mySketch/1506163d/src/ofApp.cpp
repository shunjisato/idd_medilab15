#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    ofSetFrameRate(60);
    ofSetSphereResolution(64);
    cam.setFov(35);
    
    light.setPosition(-500, 100, 100);
    light.enable();
    light.setAmbientColor(ofFloatColor(0.5, 0.2, 0.2));
    light.setDiffuseColor(ofFloatColor(0.2, 0.2, 0.5));
    light.setSpecularColor(ofFloatColor(1.0, 1.0, 0.0));
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
    cam.begin();
    ofEnableDepthTest();
    
    box.set(200);
    box.setResolution(4);
    box.setPosition(-200, 0,0);
    box.drawWireframe();
    
    sphere.setRadius(100);
    sphere.setPosition(200,0,0);
    sphere.draw();
    
    ofDisableDepthTest();
    
    cam.end();

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
