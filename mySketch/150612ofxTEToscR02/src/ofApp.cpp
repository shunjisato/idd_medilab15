#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    receiver.setup(PORT);
    pressed = true;
    mesh.setMode(OF_PRIMITIVE_POINTS);

    for (int i = 0; i < num; i++) {
        particles[i].position = ofVec2f(ofRandom(ofGetWidth()), ofRandom(ofGetHeight()));
    }
    eyeState = "";
}

//--------------------------------------------------------------
void ofApp::update(){
    while(receiver.hasWaitingMessages()){
        ofxOscMessage e;
        receiver.getNextMessage(&e);
        
        
        if(e.getAddress() == "/eye/position"){
            remoteEye.x = e.getArgAsFloat(0);
            remoteEye.y = e.getArgAsFloat(1);
        }
        //        else if(e.getAddress() == "/eye/position"){
        //            eyeState = e.getArgAsFloat(0);
        //        }
        
        dumpOSC(e);
        
    }
    
    
    
    mesh.clear();
    for (int i = 0; i < num; i++) {
        
        if (pressed) {
            particles[i].addAttractionForce(remoteEye.x, remoteEye.y, 1000, 1.0);
        }
        
        particles[i].update();
        particles[i].throughOffWalls();
        mesh.addVertex(ofVec3f(particles[i].position.x, particles[i].position.y));
    }

    
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(255);
    mesh.draw();
    ofCircle(remoteEye.x, remoteEye.y, 20);
    
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

void ofApp::dumpOSC(ofxOscMessage e) {
    string msg_string;
    msg_string = e.getAddress();
    for (int i=0; i<e.getNumArgs(); i++ ) {
        msg_string += " ";
        if(e.getArgType(i) == OFXOSC_TYPE_INT32)
            msg_string += ofToString( e.getArgAsInt32(i));
        else if(e.getArgType(i) == OFXOSC_TYPE_FLOAT)
            msg_string += ofToString( e.getArgAsFloat(i));
        else if(e.getArgType(i) == OFXOSC_TYPE_STRING)
            msg_string += e.getArgAsString(i);
    }
    cout << msg_string << endl;
}
