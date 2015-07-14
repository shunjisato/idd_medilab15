#include "ofApp.h"
#include "Webcam.h"
#include "imitationMovie.h"


void ofApp::exit(){
    tet.close();
}
//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    
    tet.setup();
    
    sender.setup(HOST, PORT);
    
    stateMachine.addState<Webcam>();
    stateMachine.addState<imitationMovie>();
    stateMachine.changeState("webcam");
    
}

//--------------------------------------------------------------
void ofApp::update(){
    if(tet.foundGaze()){
        //        ofxOscMessage m;
        //        m.setAddress("/mouse/position");
        //        m.addIntArg(mouseX);
        //        m.addIntArg(mouseY);
        //        sender.sendMessage(m);
        
//        ofxOscMessage m;
//        m.setAddress("/eye/position");
//        m.addFloatArg(tet.getGazeData().righteye.raw.x);
//        sender.sendMessage(m);
        
        
        if(mouseX > ofGetWidth()/3 && mouseX < ofGetWidth()/3 * 2 && mouseY < ofGetHeight()/2){
//        if(tet.getGazeData().lefteye.raw.x > ofGetWidth()/3 && tet.getGazeData().lefteye.raw.x < ofGetWidth()/3 * 2 && tet.getGazeData().lefteye.raw.y < ofGetHeight()/3 *2){
            stateMachine.changeState("webcam");
        }
        else {
            stateMachine.changeState("IMmovie");
        }
    }
    
    ofxOscMessage m;
    m.setAddress("/eye/position");
    m.addFloatArg(mouseX);
    sender.sendMessage(m);
}

//--------------------------------------------------------------
void ofApp::draw(){
    //    if (tet.foundGaze()) {
    //        ofSetColor(0, 255, 0);
    //        ofRect(tet.getGazeData().lefteye.raw.x, tet.getGazeData().lefteye.raw.y, 10, 10);
    //        ofRect(tet.getGazeData().righteye.raw.x, tet.getGazeData().righteye.raw.y, 10, 10);
    //    }
    //    ofSetColor(255, 2552, 255);
    //    ofDrawBitmapString(" key s: start streaming data \n key e: stop streaming data \n", 10,10);
}



//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == 's') {
        tet.requestStreamingData();
    }else if (key == 'e'){
        tet.requestStreamingDataStop();
    }else if(key == 'f'){
        ofToggleFullscreen();
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
