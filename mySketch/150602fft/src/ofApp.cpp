#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(60);
    ofBackground(0);
    
    fft.setup(1024); //2 no ruijo = fft.setup(pow(2.0,10.0));
    
    
}

//--------------------------------------------------------------
void ofApp::update(){
    fft.update();
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    vector<float> buffer;
    buffer = fft.getBins(); //sound kara shuuhasu
    ofNoFill();
    ofSetLineWidth(2.0);
    ofBeginShape();
    for(int i=0; i<buffer.size(); i++){
//        cout << buffer[i] << endl; //like print
        float x = ofMap(i, 0, buffer.size(), 0, ofGetWidth());
        float y = ofMap(buffer[i], 0.0, 1.0, ofGetHeight(), 0);
        ofVertex(x,y);
        
    }
    ofEndShape();
    
    
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
