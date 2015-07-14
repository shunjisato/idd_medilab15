#include "ofApp.h"
void ofApp::setup(){
    ofSetFrameRate(60);
    ofSetVerticalSync(true);
    ofBackground(0);
    
    gui.setup();
    gui.add(saturation.setup("saturation", 127.0, 0.0, 255.0));
    gui.add(hue.setup("hue", 160.0, 0.0, 255.0));
    gui.loadFromFile("setting.xml");
    
    fft.setup(256);
}

void ofApp::update(){
    fft.update();
    plus += 1;
    
}

void ofApp::draw(){
    
    vector<float> buffer;
    buffer = fft.getBins();
    //    buffer = fft.getAudio();
    
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
            float br = ofMap(buffer[i], 0, 1, 9, 255);
            ofColor col;
            col.setHsb(hue, saturation, br);
            ofSetColor(col);
            // 右
            float rx = ofMap(i, 0, buffer.size()/2, 0, ofGetWidth() / 2.0);
            ofLine(rx, -ofGetWidth() / 2.0, rx, ofGetWidth() / 2.0);
            ofCircle(rx, rx, rx/10);
            // 左
            float lx = ofMap(i, 0, buffer.size()/2, 0, -ofGetWidth() / 2.0);
            ofLine(lx, -ofGetWidth() / 2.0, lx, ofGetWidth() / 2.0);
            ofCircle(lx, i, lx/10);
            
            ofRotateX(i+rx);
            
            
        }
    }
    
    
    ofPopMatrix();
    
    ofPushMatrix();
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
    for (int i = 0; i < 10; i++) {
        ofRotateZ(plus);
        ofRotateX(plus);
        ofRotateY(-plus);
    ofColor col;
    col.setHsb(hue, saturation, 220);
    ofSetColor(col);
    box.set(i,i*52,i*40);
    box.drawWireframe();
    }
    ofPopMatrix();
    
    //GUI
    gui.draw();
    
}

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
