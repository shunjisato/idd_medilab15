#pragma once

#include "ofMain.h"

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
    
    ofVec2f screenPos; // スクリーンの位置
    ofVec2f personPos; // 検出した人の位置
    ofVideoPlayer movie; // ムービー
    float threshold; // ムービーを再生する距離の閾値
    float dist; // スクリーンと人との距離
};
