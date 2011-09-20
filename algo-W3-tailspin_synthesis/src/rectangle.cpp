#include "rectangle.h"


//------------------------------------------------------------------
rectangle::rectangle(){
  
}

void rectangle::update(){

	pos.x = pos.x + ofRandom(-1,1);
}

//------------------------------------------------------------------
void rectangle::drawSquares(int whichSquare, int maxSquares) {
	
	float modulator = ofMap( sin(ofGetElapsedTimef()*6+60*whichSquare), -1, 1, 0, 1);
	
	pos.x = ofMap( sin(ofGetElapsedTimef()*3) * modulator, -1, 1, ofGetWidth()/4, 3*ofGetWidth()/4);

	pos.z = powf(-1, whichSquare)*(ofMap( sin(ofGetElapsedTimef()*6) * modulator, -1, 1, -300, 300));
	
	
	

	ofFill();
	ofSetRectMode(OF_RECTMODE_CENTER); // center around the position

	//    ofSetColor(whichSquare*60/maxSquares, (maxSquares-whichSquare)*205/maxSquares, whichSquare*255/maxSquares);
    ofSetColor(255, (maxSquares-whichSquare)*180/maxSquares, whichSquare*20/maxSquares);

    ofRect(pos.x, pos.y, pos.z, 20,20);
}
