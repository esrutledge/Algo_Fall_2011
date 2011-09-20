#include "testApp.h"
#include "ofMain.h"

//--------------------------------------------------------------
void testApp::setup(){

	
	// macs by default run on non vertical sync, which can make animation very, very fast
	// this fixes that: 
	
	ofSetVerticalSync(true);
	
	// set background: 
	
	ofBackground(255);
	
	
	// set the position of the rectangle:
	for(int i = 0; i< NUMSQUARES; i++){
	//	rectangles[i].pos.x = 120;
		rectangles[i].pos.y = (ofGetHeight()/(2*NUMSQUARES+1))*(i+NUMSQUARES/2+1);
	}
}

//--------------------------------------------------------------
void testApp::update(){
	for(int i = 0; i< NUMSQUARES; i++){
		rectangles[i].update();
	}	
	

}



//--------------------------------------------------------------
void testApp::draw(){
	
	
	float xorig = ofGetWidth()/2;
	float yorig = ofGetHeight()/2;
	
	
	
	for (int i = 0; i < 255; i++){
		
		float radius = 1 + i*1.5;
		float angle = ofGetElapsedTimef() * (1 + i/3);
		float x = xorig + radius * cos(angle);
		float y = yorig + radius * -sin(angle);
		
		ofSetRectMode(OF_RECTMODE_CENTER);
		ofSetColor(255-i, i,0, 10);
		ofRect(x,y,2,2);
		
	}
	
	
	
	float bgModulator = ofMap( sin(ofGetElapsedTimef()*12), -1, 1, 0, 1);
	
	float bgVal = ofMap( sin(ofGetElapsedTimef()*1.5) * bgModulator, -1, 1, 0, 160);
	
	ofBackground(0,20,bgVal);
	
	for(int i = 0; i< NUMSQUARES; i++){
		rectangles[i].drawSquares(i, NUMSQUARES);
	}
	
	
	
		
		
		
}

//--------------------------------------------------------------
void testApp::keyPressed  (int key){
	
}

//--------------------------------------------------------------
void testApp::keyReleased  (int key){
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
	// in class we looked at this -- click = new position
	//myRectangle.pos.x = ofRandom(0,ofGetWidth());
	//myRectangle.pos.y =  ofRandom(0,ofGetHeight());
}

//--------------------------------------------------------------
void testApp::mouseReleased(){
}
