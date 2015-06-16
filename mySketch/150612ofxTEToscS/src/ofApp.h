#pragma once

#include "ofMain.h"
#include "ofxOsc.h"

#include "ofxTET.h"


#define HOST "localhost"

//#define HOST "172.21.23.208"

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
		
    ofxOscSender sender;
    
    void exit();
    ofxTET tet;
    gtl::GazeData recentGazeData;


};
