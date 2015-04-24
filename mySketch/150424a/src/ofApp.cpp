#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0,0,0);
    ofSetFrameRate(60);
    
    nCurveVertices = num;
    
    for (int i = 0; i < nCurveVertices; i++){
        curveVertices[i].bOver 			= false;
        curveVertices[i].bBeingDragged 	= false;
        curveVertices[i].radius = 4;
        velocity[i].x = ofRandom(-5, 5);
        velocity[i].y = ofRandom(-5, 5);
        velocity[i].z = ofRandom(-4, 4);
    }
    
}

//--------------------------------------------------------------
void ofApp::update(){
    for(int i=0; i<nCurveVertices; i++){
        
        curveVertices[i].x += velocity[i].x;
        curveVertices[i].y += velocity[i].y;
        curveVertices[i].z += velocity[i].z;
//        curveVertices[1].x += velocity[1].x;
//        curveVertices[1].y += velocity[1].y;
//        curveVertices[1].z += velocity[1].z;
//        curveVertices[2].x += velocity[2].x;
//        curveVertices[2].y += velocity[2].y;
//        curveVertices[2].z += velocity[2].z;
//        curveVertices[3].x += velocity[3].x;
//        curveVertices[3].y += velocity[3].y;
//        curveVertices[3].z += velocity[3].z;
//        curveVertices[4].x += velocity[4].x;
//        curveVertices[4].y += velocity[4].y;
//        curveVertices[4].z += velocity[4].z;
//        curveVertices[5].x += velocity[5].x;
//        curveVertices[5].y += velocity[5].y;
//        curveVertices[5].z += velocity[5].z;
//        curveVertices[6].x += velocity[6].x;
//        curveVertices[6].y += velocity[6].y;
//        curveVertices[6].z += velocity[6].z;
        
        if(curveVertices[i].x > ofGetWidth() || curveVertices[i].x < 0){
            velocity[i].x *= -1;
        }
        if(curveVertices[i].y > ofGetHeight() || curveVertices[i].y < 0){
            velocity[i].y *= -1;
        }
        
    }
    
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    //------(f)--------------------------------------
    //
    // 		ofCurveVertex
    //
    // 		because it uses catmul rom splines, we need to repeat the first and last
    // 		items so the curve actually goes through those points
    //
    
    ofSetColor(100, 255, 199, 50);
    ofBeginShape();
    
    for (int i = 0; i < nCurveVertices; i++){
        
        
        // sorry about all the if/states here, but to do catmull rom curves
        // we need to duplicate the start and end points so the curve acutally
        // goes through them.
        
        // for i == 0, we just call the vertex twice
        // for i == nCurveVertices-1 (last point) we call vertex 0 twice
        // otherwise just normal ofCurveVertex call
        
        if (i == 0){
            ofCurveVertex(curveVertices[0].x, curveVertices[0].y, curveVertices[0].z); // we need to duplicate 0 for the curve to start at point 0
            ofCurveVertex(curveVertices[0].x, curveVertices[0].y, curveVertices[0].z); // we need to duplicate 0 for the curve to start at point 0
        } else if (i == nCurveVertices-1){
            ofCurveVertex(curveVertices[i].x, curveVertices[i].y, curveVertices[i].z);
            ofCurveVertex(curveVertices[0].x, curveVertices[0].y, curveVertices[0].z);	// to draw a curve from pt 6 to pt 0
            ofCurveVertex(curveVertices[0].x, curveVertices[0].y, curveVertices[0].z);	// we duplicate the first point twice
        } else {
            ofCurveVertex(curveVertices[i].x, curveVertices[i].y, curveVertices[i].z);
        }
    }
    
    ofEndShape();
    
    
    // show a faint the non-curve version of the same polygon:
    ofEnableAlphaBlending();
    //    ofNoFill();
    ofSetColor(0,0,200,40);
    ofBeginShape();
    for (int i = 0; i < nCurveVertices; i++){
        ofVertex(curveVertices[i].x, curveVertices[i].y, curveVertices[i].z);
    }
    ofEndShape(true);
    
    
    ofSetColor(100,0,0,80);
    for (int i = 0; i < nCurveVertices; i++){
        if (curveVertices[i].bOver == true) ofFill();
        //        else ofNoFill();
//        ofCircle(curveVertices[i].x, curveVertices[i].y,4);
    }
    ofDisableAlphaBlending();
    
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
    for (int i = 0; i < nCurveVertices; i++){
        if (curveVertices[i].bBeingDragged == true){
            curveVertices[i].x = x;
            curveVertices[i].y = y;
        }
    }
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    for (int i = 0; i < nCurveVertices; i++){
        float diffx = x - curveVertices[i].x;
        float diffy = y - curveVertices[i].y;
        float dist = sqrt(diffx*diffx + diffy*diffy);
        if (dist < curveVertices[i].radius){
            curveVertices[i].bBeingDragged = true;
        } else {
            curveVertices[i].bBeingDragged = false;
        }
    }
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
