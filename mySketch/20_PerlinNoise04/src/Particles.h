#pragma once
#include "ofMain.h"

class Particles {
public:
    Particles(int maxParticles);
    void update();
    void draw();
    void addParticle(ofVec3f position,
                     ofVec3f velocity = ofVec3f(0, 0, 0),
                     ofColor color = 0xffffff);
    void resetForce();
    void addForce(int count, ofVec3f force);
    void addDampingForce();
    void resetOffWalls();
    void updatePos();
    
    int maxParticles;
    float pointSize;
    
    int numParticles;
    deque<ofVec3f> positions;
    deque<ofVec3f> velocitys;
    deque<ofVec3f> forces;
    deque<ofColor> colors;
    float friction;
    
    ofVboMesh mesh;
};
