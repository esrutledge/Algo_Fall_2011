#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

	ofSetVerticalSync(TRUE);
	ofSetFrameRate(30);

	ofSetColor(255,120,0);
	
	for(int i = 0; i < NUMSQUARES; i++){
		pos[i].x = 50;
		pos[i].y = 50+i*300;
		velocity[i] = (i)*ofGetWidth()/18 + 0.02;
		isMoving[i] = true;
		
		//calculate mph from following calc (using screen resolution of 132 ppi): 132px/1in * 63360in/1mi = 8,363,520px/1mi; 1frame*frameRate/sec * 3600sec/1hr = 3600*frameRate/hr; 1mi/1hr = 8363520px/3600*frameRate frames; mph = velocity/(2,323.2/frameRate)
		mph[i] = velocity[i]/(2323.2/ofGetFrameRate());
		cout << mph[i] << "mph\n";
	}
		
	squareWidth = 100;

}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
	for(int i = 0; i < NUMSQUARES; i++){
		ofRect(pos[i].x, pos[i].y, squareWidth, squareWidth);
		if(pos[i].x < ofGetWidth() - velocity[i] - squareWidth - 50){
			pos[i].x += velocity[i];
		}
		else {
			pos[i].x = ofGetWidth() - squareWidth - 50;
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
	for(int i = 0; i < NUMSQUARES; i++){
		pos[i].x = 50;
	}
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