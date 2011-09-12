#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	ofSetVerticalSync(TRUE);
	ofSetFrameRate(30);
	ofBackground(60);
	
	ofSetRectMode(OF_RECTMODE_CENTER);
	
	for(int i = 0; i < NUMSQUARES; i++) {
		rectangles[i].pos.x = ofGetWidth()/2;
		rectangles[i].pos.y = (i+1)*ofGetHeight()/(NUMSQUARES+1);
	}
}

//--------------------------------------------------------------
void testApp::update(){
	for(int i = 0; i < NUMSQUARES; i++) {
		if(i == 0){
			rectangles[i].xenoToPoint(mouseX, mouseY);
		}
		else{
			rectangles[i].xenoToPoint(rectangles[i-1].pos.x, rectangles[i-1].pos.y);
		}
		
	}
	
	
}

//--------------------------------------------------------------
void testApp::draw(){
	for(int i = NUMSQUARES-1; i >= 0; i--) {
		rectangles[i].draw(i);
		rectangles[i].resize(rectangles[i].pos.y);
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