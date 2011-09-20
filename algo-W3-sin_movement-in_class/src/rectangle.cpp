#include "rectangle.h"


//------------------------------------------------------------------
rectangle::rectangle(){
	pos.y = ofGetHeight()/2;
}

void rectangle::update(){
	pos.x = sin(ofGetElapsedTimef())*((ofGetWidth())/2) + ofGetWidth()/2;
//	pos.x = pos.x + ofRandom(-1,1);
}

//------------------------------------------------------------------
void rectangle::draw() {
	ofFill();
	ofSetRectMode(OF_RECTMODE_CENTER); // center around the position
    ofSetColor(198,246,55);
    ofRect(pos.x, pos.y, 20,20);
}
