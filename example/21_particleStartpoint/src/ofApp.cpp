#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(60);
    ofBackground(0);
}

//--------------------------------------------------------------
void ofApp::update(){
//<<<<<<< HEAD
    particle.update();
=======
    for (int i = 0; i < NUM; i++) {
        particle[i].addForce(ofVec2f(0, 1.0));
        particle[i].update();
        particle[i].bounceOffWalls();
    }
>>>>>>> tado/master
}

//--------------------------------------------------------------
void ofApp::draw(){
//<<<<<<< HEAD
    particle.draw();
=======
    for (int i = 0; i < NUM; i++) {
        particle[i].draw();
    }
>>>>>>> tado/master
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
//<<<<<<< HEAD
    particle.position.set(x, y);
    particle.velocity.set(0,0);
    particle.acceleration.set(ofRandom(-10,10),ofRandom(-10, 10));
    
=======
    for (int i = 0; i < NUM; i++) {
        particle[i].position.set(x, y);
        particle[i].velocity.set(0, 0);
        float length = ofRandom(20);
        float angle = ofRandom(2 * PI);
        float rx = length * cos(angle);
        float ry = length * sin(angle);
        particle[i].acceleration.set(rx, ry);
    }
>>>>>>> tado/master
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
//<<<<<<< HEAD
void ofApp::dragEvent(ofDragInfo dragInfo){
=======
void ofApp::dragEvent(ofDragInfo dragInfo){ 
>>>>>>> tado/master
    
}
