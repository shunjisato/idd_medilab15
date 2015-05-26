#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    cam.initGrabber(640, 480); //input cam
    
    gui.setup();
    gui.add(thresh.setup("threshhold", 127, 0, 255));
    
}

//--------------------------------------------------------------
void ofApp::update(){
    cam.update(); //input cam
    if(cam.isFrameNew()){
        background.update(cam, thresh);
        contourFinder.setThreshhold(thresh));
        contourFinder.findContours(cam);
        
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    cam.draw(0,0); //input cam
    contourFinder.draw();
    gui.draw();
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key == ' '){
        background.reset();
    }
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
