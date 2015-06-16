#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(60);
    ofBackground(0);
    
    movie.loadMovie("fingers.mov");
    
    screenPosition.set(512, 20);
    threshold = 300;
}

//--------------------------------------------------------------
void ofApp::update(){
    movie.update();
    personPosition.set(mouseX, mouseY);
    distance = ofDist(screenPosition.x, screenPosition.y, personPosition.x, personPosition.y);
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(255, 0, 0);
    ofCircle(screenPosition.x, screenPosition.y, 5);
    ofCircle(personPosition.x, personPosition.y, 5);
    
    ofSetColor(255);
    ofLine(screenPosition.x, screenPosition.y, personPosition.x, personPosition.y);
    
    if (distance < threshold) {
        movie.play();
        movie.draw(0, 0);
    } else {
        movie.stop();
        movie.setFrame(0);
    }
    ofDrawBitmapString("Distance = " + ofToString(distance), 800, 20);
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
