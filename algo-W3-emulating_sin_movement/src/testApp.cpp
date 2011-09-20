#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	ofSetVerticalSync(TRUE);
	ofSetFrameRate(60);
	
	ofBackground(100, 0, 255);
	
	ofSetRectMode(OF_RECTMODE_CENTER);
	
	ofSetColor(255, 120, 0);
		
}

//--------------------------------------------------------------
void testApp::update(){
	if(myRect.startAnimation){
		myRect.update();
	}
}

//--------------------------------------------------------------
void testApp::draw(){
	myRect.drawContainer();

	if(myRect.startAnimation){
		myRect.draw();
	}
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){
	myRect.startAnimation = true;
	myRect.pos.x = 0;
	myRect.pos.y = 0;
	myRect.spinVel = 3;
	myRect.dropVel = 20;
	myRect.timeStarted = ofGetElapsedTimef();
	myRect.containerRadius = 400;
	myRect.pathRadius = myRect.containerRadius;
	myRect.timeMultiplier = 10;
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