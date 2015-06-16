#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    receiver.setup(PORT);
    mouseX =0;
    mouseY =0;
//    mouseButtonState = "";
//    eyeState = "";
    
    
}

//--------------------------------------------------------------
void ofApp::update(){
//    while(receiver.hasWaitingMessages()){
//        ofxOscMessage m;
//        receiver.getNextMessage(&m);
//        
//        if(m.getAddress() == "/mouse/position"){
//            remoteMouse.x = m.getArgAsInt32(0);
//            remoteMouse.y = m.getArgAsInt32(1);
//        }
//        else if(m.getAddress() == "/mouse/button"){
//            mouseButtonState = m.getArgAsString(0);
//        }
//        
//        else if(m.getAddress() == "/eye/position"){
//            eyeState = m.getArgAsFloat(0);
//        }
//        
//        dumpOSC(m);
//        
//    }
    
    while(receiver.hasWaitingMessages()){
        ofxOscMessage e;
        receiver.getNextMessage(&e);
 
        if(e.getAddress() == "/eye/position"){
            eyeState = e.getArgAsFloat(0);
        }
        
        dumpOSC(e);
        
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    int radius = 20;
//    if(mouseButtonState == "down"){
//        radius = 20;
//        ofSetColor(255,127,9);
//    } else{
//        radius = 5;
//        ofSetColor(0,100,255);
//    }
//    ofCircle(remoteMouse.x, remoteMouse.y, radius);
    
    ofCircle(remoteEye.x, remoteEye.y, radius);
    
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

void ofApp::dumpOSC(ofxOscMessage e){
    string msg_string;
    msg_string = e.getAddress();
    for(int i=0; i<e.getNumArgs(); i++){
        msg_string += " ";
        if(e.getArgType(i) == OFXOSC_TYPE_INT32)
            msg_string += ofToString(e.getArgAsInt32(i));
        else if(e.getArgType(i) == OFXOSC_TYPE_FLOAT)
            msg_string += ofToString(e.getArgAsFloat(i));
        else if(e.getArgType(i) == OFXOSC_TYPE_STRING)
            msg_string += ofToString(e.getArgAsString(i));
    }
    
    cout << msg_string << endl;
}