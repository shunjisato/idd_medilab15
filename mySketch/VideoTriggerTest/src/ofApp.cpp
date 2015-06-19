#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(60);
    ofBackground(127);
    
    movie.loadMovie("countdown15.mov"); // ムービー読み込み
    movie.setLoopState(OF_LOOP_NONE); // ループ再生しない
    
    screenPos.set(ofGetWidth()/2, 40); // スクリーンの位置
    threshold = 200; // ムービー再生の閾値
}

//--------------------------------------------------------------
void ofApp::update(){
    movie.update();
    personPos.set(mouseX, mouseY); //人の位置 (とりあえずマウスの位置で代替)
    
    // 人とスクリーンの距離を算出
    dist = ofDist(screenPos.x, screenPos.y, personPos.x, personPos.y);
    
    // もし閾値よりも近付いて、かつムービーが再生していなかったら
    if (movie.isPlaying() == false && dist < threshold) {
        // ムービー再生
        movie.play();
    }
    
    // 再生が終わったら、最初のフレームに巻き戻して待機
    if (movie.getCurrentFrame() == movie.getTotalNumFrames()) {
        movie.firstFrame();
        movie.stop();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){

    // スクリーン位置と人の位置を表示
    if (dist < threshold) {
        ofSetColor(255, 0, 0);
    } else {
        ofSetColor(255);
    }
    ofLine(screenPos, personPos);
    ofSetColor(0, 0, 255);
    ofCircle(screenPos, 10);
    ofCircle(personPos, 10);
    
    // 距離を表示
    ofSetColor(255);
    ofDrawBitmapString("distance = " + ofToString(dist), 20, 20);
    
    // ムービー表示
    ofSetColor(255);
    movie.draw(100, 40);
    
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
