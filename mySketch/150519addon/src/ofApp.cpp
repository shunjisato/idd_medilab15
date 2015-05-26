#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(60);
    ofBackground(0);
    ofVec2f locationMin = ofVec2f(0, 0);
    ofVec2f locationMax = ofVec2f(ofGetWidth(), ofGetHeight());
    ofVec2f locationCur = ofVec2f(200, 200);
    ofColor colorMin = ofColor(0, 0, 0, 0);
    ofColor colorMax = ofColor(255, 255, 255, 255);
    ofColor colorCur = ofColor(122, 50, 211, 100);
    
    gui.setup();
    
    gui.add(radius.setup("radius", 200.0, 0.0, 800.0));
    gui.add(location.setup("location", locationCur, locationMin,locationMax));
    gui.add(color.setup("color", colorCur, colorMin, colorMax));
    
    
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(color);
    ofCircle(ofVec2f(location), radius);
    gui.draw();
    
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
