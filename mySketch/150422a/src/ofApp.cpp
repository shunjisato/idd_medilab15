#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0,0,0);
    ofEnableBlendMode(OF_BLENDMODE_ADD);
    ofSetFrameRate(60);
    
    for(int i=0;i<num; i++){
        position[i].x = ofRandom(ofGetWidth());
        position[i].y = ofRandom(ofGetHeight());
        position[i].z = ofRandom(-3, 3);
        velocity[i].x = ofRandom(-3, 3);
        velocity[i].y = ofRandom(-3, 3);
        velocity[i].z = ofRandom(-6, 6);
        color[i].r = ofRandom(255);
        color[i].g = ofRandom(255);
        color[i].b = ofRandom(255);
        color[i].a = ofRandom(10, 30);
        
    }
    
    box.set(40);
}

//--------------------------------------------------------------
void ofApp::update(){
    for(int i=0; i<num; i++){
        position[i] += velocity[i];
        
        if(position[i].x > ofGetWidth() || position[i].x < 0){
            velocity[i].x *= -1;
        }
        if(position[i].y > ofGetWidth() || position[i].y < 0){
            velocity[i].y *= -1;
        }
        if(position[i].z > ofGetWidth() || position[i].z < 0){
            velocity[i].z *= -1;
        }
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    for(int i=0; i<num; i++){
        ofSetColor(color[i]);
        box.setPosition(position[i].x, position[i].y, position[i].z);
        box.drawWireframe();
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
