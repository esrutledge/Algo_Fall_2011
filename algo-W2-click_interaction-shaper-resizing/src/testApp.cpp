#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	

	
	ofSetVerticalSync(TRUE);
	ofSetFrameRate(30);
	ofEnableAlphaBlending();
	
	ofBackground(0);
	
	ofSetRectMode(OF_RECTMODE_CENTER);

	
	whichSquare = 0;
	
	keyFrameSquareWidths[0] = 10;
	keyFrameSquareWidths[1] = 100;


	opacityValues[0] = 40;
	opacityValues[1] = 255;

	
	squareWidthStart = keyFrameSquareWidths[0];
	squareWidthEnd = keyFrameSquareWidths[1];
	
	
	durationInSeconds = 1.0;
	
	shaper = 2.0;
	
	increment = 1.0/(durationInSeconds*ofGetFrameRate());
	
	
	for(int i = 0; i < NUMSQUARES; i++){
		opacity[i] = opacityValues[0];
		ofSetColor(255,120,0, opacity[i]);
		startPos[i].set(ofGetWidth()/2,ofGetHeight()*(i+1)/(NUMSQUARES+1));
		endPos[i].set(ofGetWidth()/2,ofGetHeight()*(i+1)/(NUMSQUARES+1));
		pct[i] = 0;
		squareWidth[i] = squareWidthStart;
		growing[i] = true;
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
		
		squareWidth[i] = (1-shapedPct[i])*keyFrameSquareWidths[growing[i]] + shapedPct[i]*keyFrameSquareWidths[!growing[i]];
		opacity[i] = (1-shapedPct[i])*opacityValues[growing[i]] + shapedPct[i]*opacityValues[!growing[i]];

		ofSetColor(255, 120, 0, opacity[i]);
		
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
//	startPos[whichSquare] = pos[whichSquare];
	endPos[whichSquare].set(mouseX, mouseY);

	growing[whichSquare] = !growing[whichSquare];

	cout << growing[whichSquare];
	
	pct[whichSquare] = 0;

	if(whichSquare < NUMSQUARES-1){
		whichSquare += 1;
	}
	else {
		whichSquare = 0;
	}

	squareWidthStart = squareWidth[whichSquare];
	

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