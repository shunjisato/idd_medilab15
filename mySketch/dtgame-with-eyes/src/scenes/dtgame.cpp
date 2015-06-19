#include "dtgame.h"

//--------------------------------------------------------------
void dtgame::setup(){
    ofBackground(40, 220, 220);
    ofEnableSmoothing();
    frameCount = 0;
    
    ground.loadImage("ChallengeGame-ground.png");
    cloud.loadImage ("cloud.png");
    assignment.loadImage ("assignment.png");
    me.loadImage("me.png");
    meSick.loadImage("meSick.png");
    runningright.loadImage("runningright.png");
    runningleft.loadImage("runningleft.png");
    
    music.loadSound("Rolemusic_-_Gringo_Steele_rocks_the_40.mp3");
    music.play();
    
}

//--------------------------------------------------------------
void dtgame::update(float _x, float _y){
    
    ofBackground(40, 220, 220);
    frameCount++;
    
    if (frameCount == 1 || frameCount%100 == 0) {
        cout << "MAKE CLOUD!!!" << endl;
        Clouds cl = Clouds(1150, ofRandom(100, 500));
        clouds.push_back(cl);
    }
    
    if (frameCount == 30 || frameCount%783 == 0) {
        cout << "MAKE BEER!!!" << endl;
        Beer br = Beer(1150, ofRandom(200, 650));
        beers.push_back(br);
    }
    
    if (frameCount == 10 || frameCount == 270 || frameCount%183 == 0) {
        cout << "MAKE ASS!!!" << endl;
        Assignments as = Assignments(1150, ofRandom(200, 650));
        ass.push_back(as);
    }
    
    posY = ofMap(_y, 0, ofGetHeight(), 120, 665);
    
}

//--------------------------------------------------------------
void dtgame::draw(){
    ground.draw(0,0);
    
    //    cout << frameCount << endl;
    //    cout << ofGetFrameNum() << endl;
    
    
    // 1 first start game
    // 2 play game
    // 3 after not collecting assignment
    // 4 game over after hitting obstacle
    // 5 is after time
    
    if (gameStart == 1) {
        me.draw(150, 665 );
        cloud.draw(100, 100);
        cloud.draw(200, 500);
        cloud.draw(800, 275);
        
        ofSetColor(255);
        ofDrawBitmapString("THE DT GAME", ofGetWidth()/2 - 100, ofGetHeight()/2 - 100);
        
        scale = ofMap(sin(frameCount/2), -1, 1, 200, 255);
        ofSetColor(255, 255, 255, scale);
        
        ofDrawBitmapString("Press spacebar to start.", ofGetWindowSize()/2);
    }
    
    if (gameStart == 2) {
        cout << ass.size() << beers.size() << clouds.size() << endl;
        
        for (int i=0; i<clouds.size(); i++) {
            clouds[i].update();
            clouds[i].draw();
        }
        for (int i=0; i<beers.size(); i++) {
            beers[i].update();
            beers[i].draw();
        }
        for (int i=0; i<ass.size(); i++) {
            ass[i].update();
            ass[i].draw();
        }
        
        displayScore();
        running();
        //        jump();
        
        
        if (frameCount <= 180) {
            ofSetColor(255);
            ofDrawBitmapString("Collect yellow assignments.", 30, 100);
        }
        
        if (frameCount > 180 && frameCount <= 360) {
            ofSetColor(255);
            ofDrawBitmapString("Avoid blue obstacles.", 30, 100);
        }
    }
    
    if (gameStart == 3 || gameStart == 5) {
        ass.clear();
        clouds.clear();
        beers.clear();
        
        me.draw(150, 665);
        cloud.draw(100, 100);
        cloud.draw(200, 500);
        cloud.draw(800, 275);
        
        ofSetColor(255);
        ofDrawBitmapString("THE DT GAME", ofGetWidth()/2 - 200, ofGetHeight()/2 - 100);
        
        ofSetColor(255, 250, 0);
        ofDrawBitmapString ("You failed, because you missed 5 assignments.", ofGetWidth()/2, ofGetHeight() - 200);
        ofDrawBitmapString ("Assignments done: " + ofToString(score), ofGetWidth()/2, ofGetHeight() - 160);
        scale = ofMap(sin(frameCount/2), -1, 1, 200, 255);
        ofSetColor(255, 255, 255, scale);
        
        ofDrawBitmapString("Press spacebar to start.", ofGetWindowSize()/2);
    }
    
    if (gameStart == 4) {
        ass.clear();
        clouds.clear();
        beers.clear();
        
        meSick.draw(ofGetWidth()/2-40, 690 );
        cloud.draw(100, 100);
        cloud.draw(200, 500);
        cloud.draw(800, 275);
        
        ofSetColor(255);
        ofDrawBitmapString("THE DT GAME", ofGetWidth()/2 - 200, ofGetHeight()/2 - 100);
        
        ofSetColor(255, 250, 0);
        ofDrawBitmapString("Ooooh No! You got sick at Bootcamp.", ofGetWidth()/2 - 100, ofGetHeight() - 300);
        
        ofDrawBitmapString ("Assignments done: " + ofToString(score), ofGetWidth()/2, ofGetHeight() - 260);
        scale = ofMap(sin(frameCount/2), -1, 1, 200, 255);
        ofSetColor(255, 255, 255, scale);
        
        ofDrawBitmapString("Press spacebar to start.", ofGetWindowSize()/2);
    }
    
    
    if (miss == 5) {
        gameStart = 3;
        ass.clear();
        clouds.clear();
        beers.clear();
    }
    
    checkAssCollision();
    checkBeerCollision();
    
    if (gameStart == 2 && frameCount > 3600) {
        gameStart = 5; //because game ends after spec. time
    }
    
}


void dtgame::running() {
    if ((int)frameCount%20 == 0) {
        isMoving = !isMoving;
    }
    
    if (isMoving == true) {
        runningleft.draw(posX, posY);
    } else {
        runningright.draw(posX, posY);
    }
}


void dtgame::displayScore() {
    ofSetColor(0);
    ofDrawBitmapString("Assignments done: " + ofToString(score), 30, 50);
    ofDrawBitmapString("Assignments missed: " + ofToString(miss), 30, 70);
    ofSetColor(255);
}

void dtgame::checkAssCollision() {
    for (int i = 0; i < ass.size (); i++) {
        if (posX + 60 > ass[i].posX && // right of me (60, 85) and left of assignment(40, 55)
            posX < ass[i].posX + 40 && // left of me and right of assignment
            posY + 85 > ass[i].posY &&
            posY < ass[i].posY + 55) {
            
            score += 1;
            ofBackground(255, 250, 0);
            ass.erase(ass.begin() + i);;
        }
        
        if (ass[i].posX + 40 < 150) { // if right of assignment smaller than 0
            miss++;
            ass.erase(ass.begin() + i);
        }
    }
}

void dtgame::checkBeerCollision() {
    for (int i = 0; i < beers.size (); i++) {
        if (posX + 60 > beers[i].posX && // right of me (60, 85) and left of obstacle(40, 80)
            posX < beers[i].posX + 40 && // left of me and right of obstacle
            posY + 85 > beers[i].posY &&
            posY < beers[i].posY + 80) {
            
            gameStart = 4; // game ends after hitting obstacle
        }
    }
}

//--------------------------------------------------------------
void dtgame::keyPressed(int key){
    switch (key) {
        case ' ':
            // start the game
            if (gameStart != 2) {
                gameStart = 2;
                frameCount= 0;
                score = 0;
                miss = 0;
                
                ass.clear();
                clouds.clear();
                beers.clear();
            };
            break;
            
            
        default:
            break;
    }
}

//--------------------------------------------------------------
void dtgame::keyReleased(int key){
    
}

//--------------------------------------------------------------
void dtgame::mouseMoved(int x, int y ){
//    posY = ofMap(y, 0, ofGetHeight(), 100, 665);
}

//--------------------------------------------------------------
void dtgame::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void dtgame::mousePressed(int x, int y, int button){
    
}

//--------------------------------------------------------------
void dtgame::mouseReleased(int x, int y, int button){
    
}

//--------------------------------------------------------------
void dtgame::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void dtgame::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void dtgame::dragEvent(ofDragInfo dragInfo){ 
    
}
