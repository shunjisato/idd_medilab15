#pragma once

#include "ofMain.h"
#include "ofxOsc.h"

#include "ParticleVec2.h"

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
    
    void dumpOSC(ofxOscMessage e);
        
    ofxOscReceiver receiver;
    
    ofPoint remoteEye;
    
    string eyeState;
    
    
    
    
    static const int num = 30000;
    ParticleVec2 particles[num];
    ofVboMesh mesh;
    
    bool pressed;

};
