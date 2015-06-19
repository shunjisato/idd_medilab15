#pragma once

#include "ofMain.h"
#include "Beer.h"
#include "Clouds.h"
#include "Assignments.h"

#include "ofxXmlSettings.h"
#include "baseScene.h"

class dtgame : public baseScene {

	public:
		void setup();
        void update(float _x, float _y);
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
		
    
    ofSoundPlayer music;
    vector<Beer> beers;
    vector<Clouds> clouds;
    vector<Assignments> ass;
    
    int score = 0;
    int miss = 0;
    int posX = 150;
    int posY = 465;
    float speedY = 0;
    bool isMoving = false;
    int gameStart = 1;
    float scale;
    float acce = 0.95;
    float gravity = 0.3;
    
    ofImage ground, cloud, assignment, me, meSick, runningright, runningleft;
    
    void running();
    void displayScore();
    
    void checkAssCollision();
    void checkBeerCollision();
    
    int frameCount;
};
