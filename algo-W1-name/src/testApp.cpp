#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	
	ofBackground(255);
	ofEnableSmoothing();

}

//--------------------------------------------------------------
void testApp::update(){
}

//--------------------------------------------------------------
void testApp::draw(){

	ofSetColor(0,100,mouseX/2, 255);

	
	//LETTER L
	ofCircle(100, 100, 20);
	
	ofBeginShape();
	ofVertex(92, 100);
	ofVertex(108, 100);
	ofVertex(83, 300);
	ofVertex(72, 300);
	ofVertex(92,100);
	ofEndShape();
	
	ofCircle(80,300, 20);
	
	ofRect(80, 300, 140, 10);
	
	ofCircle(220, 300, 20);
	
	
	//LETTER i
	ofCircle(270, 300, 20);
	
	ofBeginShape();
	ofVertex(280, 190);
	ofVertex(262, 300);
	ofVertex(278, 300);
	ofVertex(292, 190);
	ofVertex(280,190);
	ofEndShape();	
	
	ofCircle(285, 190, 20);

	ofCircle(295, 120, mouseY/10+10);
	
	ofSetColor(0,100,400-mouseX/2, 255);
	ofCircle(295, 120, mouseY/20+10);
	
	ofSetColor(0,100,mouseX/2, 255);

	//LETTER z
	ofCircle(360,195,20);
	ofRect(360,190,120,14);
	ofCircle(480, 195, 20);
	
	ofBeginShape();
	ofVertex(480, 195);
	ofVertex(490, 195);	
	ofVertex(350, 305);
	ofVertex(320, 305);	
	ofVertex(480, 195);
	ofEndShape();
	
	
	ofCircle(340, 305, 20);
	ofRect(340,300,130,14);
	ofCircle(470, 305, 20);
	
	

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