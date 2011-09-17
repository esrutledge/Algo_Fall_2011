#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	ofSetVerticalSync(TRUE);
	ofSetFrameRate(30);
	
	ofSetRectMode(OF_RECTMODE_CENTER);
	
	durationInSeconds = 4.0;

	r1 = 255;
	g1 = 200;
	b1 = 0;
	
	r2 = 0;
	g2 = 120;
	b2 = 255;
	
	pct = 0;
	
	goingRight = true;
	
	increment = 1.0/(durationInSeconds*ofGetFrameRate());
	
	
}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
	
	
	rCurr = (1-pct)*r1 + pct*r2;
	bCurr = (1-pct)*b1 + pct*b2;
	gCurr = (1-pct)*g1 + pct*g2;
	
	rOpposite = 255-rCurr;
	gOpposite = 255-gCurr;
	bOpposite = 255-bCurr;
	
	
	ofBackground(rCurr, gCurr, bCurr);
	
	ofSetColor(rOpposite, gOpposite, bOpposite);
	
	ofRect(ofGetWidth()/2, ofGetHeight()/2 - 100, 100, 100);

	
	if(goingRight) {
		pct += (increment);
		if(pct > (1.0-increment)){
			goingRight = false;
		}
	}
	else {
		pct -= (increment);
		if(pct < (0+increment)){
			goingRight = true;
		}
	}
	
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}