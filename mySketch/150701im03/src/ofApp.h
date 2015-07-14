#pragma once

#include "ofMain.h"
#include "ofxTET.h"
#include "ofxStateMachine.h"
#include "SharedData.h"
#include "ofxOsc.h"

//#define HOST "172.21.21.114"
#define HOST "172.21.20.108"
#define PORT 2222

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
    
    itg::ofxStateMachine<SharedData> stateMachine;
    void exit();
    ofxTET tet;
    
    ofxOscSender sender;
    
};
