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
    
    stateMachine.addState<Webcam>();
    stateMachine.addState<imitationMovie>();
    
    stateMachine.changeState("webcam");
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    //    if(200< mouseX){
    //        stateMachine.changeState("IMmovie");
    //    }else{
    //        stateMachine.changeState("webcam");
    //    }
    
    if(tet.foundGaze()){
        //        if(ofGetWidth()/3 < tet.getGazeData().lefteye.raw.x) {
        
        
        //        if(ofGetWidth()/3 < tet.getGazeData().lefteye.raw.x ){
        //            stateMachine.changeState("webcam");
        //
        //        }
        
        if(mouseX > ofGetWidth()/3 && mouseX < ofGetWidth()/3 * 2 && mouseY < ofGetHeight()/2){
            stateMachine.changeState("webcam");
            
        }
        
        else {
            stateMachine.changeState("IMmovie");
        }
        
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    if (tet.foundGaze()) {
        ofSetColor(0, 255, 0);
        ofRect(tet.getGazeData().lefteye.raw.x, tet.getGazeData().lefteye.raw.y, 10, 10);
        ofRect(tet.getGazeData().righteye.raw.x, tet.getGazeData().righteye.raw.y, 10, 10);
    }
    ofSetColor(255, 2552, 255);
    ofDrawBitmapString(" key s: start streaming data \n key e: stop streaming data \n key d: download calibresult \n key u: upload calibresult \n key t: save calibresult \n key c: load calibresult from text \n", 10,10);
}



//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == '1') {
        stateMachine.changeState("webcam");
    }
    if (key == '2') {
        stateMachine.changeState("IMmovie");
    }
    if(key == 'f'){
        ofToggleFullscreen();
    }
    
    
    if (key == 's') {
        tet.requestStreamingData();
    }else if (key == 'e'){
        tet.requestStreamingDataStop();
    }else if (key == 'd'){
        tet.requestCalibResult();
    }else if (key == 't'){
        // API not supported !
        // save calibdata to text
        // tet.saveCalibResult();
    }else if (key == 'u'){
        // API not supported !
        //tet.sendCalibResult();
    }else if (key == 'c'){
        // API not supported !
        // load text to calibdata
        // tet.loadCalibResult();
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
