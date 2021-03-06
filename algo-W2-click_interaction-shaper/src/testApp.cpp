#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	
	ofSetVerticalSync(TRUE);
	ofSetFrameRate(30);
	
	ofSetRectMode(OF_RECTMODE_CENTER);

	
	ofSetColor(255,120,0);
	
	whichSquare = 0;
	
		
	durationInSeconds = 1.0;
	
	shaper = 2.0;
	
	increment = 1.0/(durationInSeconds*ofGetFrameRate());
	
	
	for(int i = 0; i < NUMSQUARES; i++){
		startPos[i].set(0,ofGetHeight()*i/NUMSQUARES);
		endPos[i].set(0,ofGetHeight()*i/NUMSQUARES);
		pct[i] = 0;
		squareWidth[i] = ofRandom(20, 100);
	}
	
		
	cout << increment;
	printf("\nhello");
}

//--------------------------------------------------------------
void testApp::update(){
	
}

//--------------------------------------------------------------
void testApp::draw(){
	
	
	
	for(int i = 0; i < NUMSQUARES; i++){		
		shapedPct[i] = powf(pct[i], shaper);
		
		pos[i] = (1-shapedPct[i])*pos[i] + shapedPct[i]*endPos[i];
		
		ofRect(pos[i].x, pos[i].y, squareWidth[i], squareWidth[i]);

		
		if(pct[i] < 1.0 - increment){
			pct[i] += increment;
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

	endPos[whichSquare].set(mouseX, mouseY);
	
	pct[whichSquare] = 0;

	if(whichSquare < NUMSQUARES-1){
		whichSquare += 1;
	}
	else {
		whichSquare = 0;
	}
	

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