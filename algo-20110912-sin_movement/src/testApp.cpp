#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	ofSetVerticalSync(TRUE);
	ofSetFrameRate(30);
	
	ofBackground(80);
	
	ofSetRectMode(OF_RECTMODE_CENTER);
	
	ofSetColor(255, 120, 0);
	
	pos.x = ofGetWidth()/2;
	pos.y = ofGetHeight()/2;
		
	squareWidth = 20;
}

//--------------------------------------------------------------
void testApp::update(){
	pos.x = sin(ofGetElapsedTimef())*((ofGetWidth()-squareWidth)/2) + ofGetWidth()/2;
}

//--------------------------------------------------------------
void testApp::draw(){
	ofRect(pos.x, pos.y, squareWidth, squareWidth);
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