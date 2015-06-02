#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(60);
    ofBackground(0);
    kinect.setRegistration(true);
    kinect.init();
    kinect.open();
    mesh.setMode(OF_PRIMITIVE_POINTS);
    
}

void ofApp::update(){
    kinect.update();
    
    
}

//--------------------------------------------------------------
void ofApp::draw(){
//    kinect.draw(0,0);
//    kinect.drawDepth(kinect.width, 0);
    int step = 1;
    mesh.clear();
    for(int j=0; j<kinect.height; j+=step){
        for(int i=0; i<kinect.width; i+=step){
            mesh.addColor(kinect.getColorAt(i, j));
            mesh.addVertex(kinect.getWorldCoordinateAt(i, j));
        }
    }
    
    glPointSize(3.0);
    cam.begin();
    ofPushMatrix();
    ofScale(1, -1, -1);
    ofTranslate(0, 0, -1000);
    ofEnableDepthTest();
    mesh.draw();
    ofPopMatrix();
    cam.end();
    
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
