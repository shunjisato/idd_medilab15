#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0, 0, 0);
    ofSetFrameRate(60);
    ofSetCircleResolution(32);
    
    for(int i=0;i<CIRCLE_NUM; i++){
        position[i].x = ofRandom(ofGetWidth());
        position[i].y = ofRandom(ofGetHeight());
        position[i].z = ofRandom(-300, 300);
        velocity[i].set(ofRandom(-10, 10), ofRandom(-10, 10));
        force[i].set(0,0);

    }

    friction = 0.001;
}

//--------------------------------------------------------------
void ofApp::update(){
    for (int i = 0; i < CIRCLE_NUM; i++) {
        // 力をリセット
        force[i].set(0, 0);
        // 摩擦力の計算
        force[i] -= velocity[i] * friction;
        // 力から速度を算出
        velocity[i] += force[i];
        // 速度から位置を算出
        position[i] += velocity[i];
        
        // 画面からはみ出たらバウンドさせる
        if (position[i].x < 0 || position[i].x > ofGetWidth()) {
            velocity[i].x *= -1;
        }
        if (position[i].y < 0 || position[i].y > ofGetHeight()) {
            velocity[i].y *= -1;
        }
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(100, 30, 200);
    for(int i=0; i<CIRCLE_NUM; i++){
    ofCircle(position[i], 4);
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
