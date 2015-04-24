#pragma once

#include "ofMain.h"

typedef struct {
    
    float 	x;
    float 	y;
    float 	z;
    bool 	bBeingDragged;
    bool 	bOver;
    float 	radius;
    
}draggableVertex;

class ofApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
    
				int nCurveVertices;
    draggableVertex curveVertices[7];
    draggableVertex bezierVertices[4];
    
    static const int num = 7;
    ofVec3f velocity[num];
    
};
