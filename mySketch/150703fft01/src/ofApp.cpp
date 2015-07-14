#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(60);
    ofSetVerticalSync(true);
    ofBackground(0);
    // FFTのサンプル数(2の累乗)を指定して初期化
    fft.setup(pow(2.0, 6.0));
    // GUI
    gui.setup();
    gui.add(saturation.setup("Saturation", 127.0, 0.0, 255.0));
    gui.add(hue.setup("Hue", 50.0, 0.0, 255.0));
    gui.loadFromFile("settings.xml");
}

//--------------------------------------------------------------
void ofApp::update(){
    fft.update(); // FFT更新
    plus += 1 ;
}

//--------------------------------------------------------------
void ofApp::draw(){
//    // float型の配列にFFT結果を格納
//    vector<float> buffer;
//    buffer = fft.getBins();
//    
//    // グラフに描画
//    ofPushMatrix();
//    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
//    ofSetLineWidth(ofGetWidth() / float(buffer.size()));
//    ofEnableBlendMode(OF_BLENDMODE_ADD);
//    for (int j = 0; j < 2; j++) {
//        for (int i = 0; i < buffer.size(); i++) {
//            float plus = 0;
//            plus += plus + 10.01;
//            ofRotateX(90 * sin(plus) * float(buffer.size())*10);
//
//            // 色を設定
//            float hue = ofMap(i, 0, buffer.size(), 70, 160);
//            float br = ofMap(buffer[i], 0, 1, 100, 255);
//            ofColor col;
//            col.setHsb(hue, saturation, br);
//            ofSetColor(col);
//            // 右
//            float rx = ofMap(i, 0, buffer.size(), 0, ofGetWidth() / 2.0);
//            ofLine(rx, -ofGetWidth() / 2.0, rx, ofGetWidth() / 2.0);
//            ofRotateY(cos(ofGetElapsedTimef()*3) + float(buffer.size())*24 * -1);
//
//            // 左
//            float lx = ofMap(i, 0, buffer.size(), 0, -ofGetWidth() / 2.0);
//            ofLine(lx, -ofGetWidth() / 2.0, lx, ofGetWidth() / 2.0);
//        }
//    }
//    ofPopMatrix();
//    
//    //GUI
//    gui.draw();




    vector<float> buffer;
    buffer = fft.getBins();
    
    // グラフに描画
    ofPushMatrix();
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
//    ofSetLineWidth(ofGetWidth() / float(buffer.size()));
    ofSetLineWidth(2);
    ofEnableBlendMode(OF_BLENDMODE_ADD);
    for (int j = 0; j < 2; j++) {
        for (int i = 0; i < buffer.size(); i++) {
            // 色を設定
//          float hue = ofMap(i, 0, buffer.size(), 10, 160);
            float br = ofMap(buffer[i], 0, 1, 2, 255);
            ofColor col;
            col.setHsb(hue, saturation, br);
            ofSetColor(col);
            // 右
            float rx = ofMap(i, 0, buffer.size(), 0, ofGetWidth() / 2.0);
            ofLine(rx, -ofGetWidth() / 2.0, rx, ofGetWidth() / 2.0);
            ofCircle(rx, rx, rx/10);
            // 左
            float lx = ofMap(i, 0, buffer.size(), 0, -ofGetWidth() / 2.0);
            ofLine(lx, -ofGetWidth() / 2.0, lx, ofGetWidth() / 2.0);
            ofCircle(lx, lx, lx/10);


            ofRotateX(i+rx+plus);
        }
    }
    ofPopMatrix();
    
    //GUI
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
