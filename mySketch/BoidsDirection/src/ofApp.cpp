#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(60);
    
    // 群れを初期化 (魚の数、初期位置x, 初期位置y, ばらつき)
    flock.setup(300, ofGetWidth()/2, ofGetHeight()/2, ofGetHeight()/4);
    flock.setBounds(0,0,ofGetWidth(), ofGetHeight());
    flock.setBoundmode(0);
}

//--------------------------------------------------------------
void ofApp::update(){
    // 群れを更新
    flock.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    // 背景
    ofBackgroundGradient(ofColor(64), ofColor(0));
    
    // 魚の数だけくりかえし
    for(int i=0; i<flock.size(); i++){
        Boid2d * b = flock.get(i);
        // 進行方向の角度を算出
        float angle = atan2(b->vy, b->vx) * 180 / PI;
        // 進行方向にかたむけて、楕円を描画
        ofPushMatrix();
        ofTranslate(b->x, b->y);
        ofRotate(angle);
        ofSetColor(255, 0, 0);
        ofEllipse(0, 0, 30, 8);
        ofSetLineWidth(1.0);
        ofPopMatrix();
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
