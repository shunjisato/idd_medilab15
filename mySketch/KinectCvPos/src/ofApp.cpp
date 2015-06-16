#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    //画面設定
    ofSetFrameRate(60);
    ofBackground(0);
    // Kinect初期化
    kinect.init();
    kinect.open();
    // GUI初期設定
    gui.setup();
    gui.add(thresh.setup("Threshhold", 127, 0, 255));
    gui.add(minRadius.setup("Min Radius", 10, 0, 400));
    gui.add(maxRadius.setup("Max Radius", 200, 0, 400));
}

//--------------------------------------------------------------
void ofApp::update(){
    // CV設定
    contourFinder.setMinAreaRadius(minRadius);
    contourFinder.setMaxAreaRadius(maxRadius);
    // Kinect状態更新
    kinect.update();
    if (kinect.isFrameNew()) {
        // Kinectの深度画像を、cv::Mat形式に変換
        cv::Mat mat = cv::Mat(kinect.height, kinect.width, CV_8UC1, kinect.getDepthPixels(), 0);
        // ofxCvで輪郭抽出
        contourFinder.setThreshold(thresh);
        contourFinder.findContours(mat);
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    // 深度画像描画
    ofSetColor(255);
    kinect.drawDepth(0, 0, ofGetWidth(), ofGetHeight());
    // 輪郭抽出結果描画
    ofSetColor(255, 255, 0);
    ofPushMatrix();
    ofScale(ofGetWidth() / float(kinect.width), ofGetHeight() / float(kinect.height));
    //contourFinder.draw();
    
    // 検出された輪郭線の数だけくりかえし
    for (int i = 0; i < contourFinder.size(); i++) {
        // 中心点抽出
        cv::Point2f pos = contourFinder.getCenter(i);
        //if (i == 0) {
        // 円を描画
        ofSetColor(255, 0, 0);
        ofCircle(pos.x, pos.y, 5);
        ofSetColor(255);
        ofDrawBitmapString(ofToString(i, 0), pos.x + 10, pos.y);
    }
    
    ofPopMatrix();
    // GUI描画
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
