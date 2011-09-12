#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

	ofSetVerticalSync(TRUE);
	ofSetFrameRate(30);

	ofSetColor(255,120,0);
	
	for(int i = 0; i < NUMSQUARES; i++){
		pos[i].x = 50;
		pos[i].y = 50+i*50;
		velocity[i] = (i+1)*.02;
	}
	
	
	cout << "hello";
	printf("\nhello");
}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
	for(int i = 0; i < NUMSQUARES; i++){
		ofRect(pos[i].x, pos[i].y, 100, 100);
		pos[i].x += velocity[i];
	//	pos[i].y += velocity[i];

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
	pos[0].x = mouseX;
	pos[0].y = mouseY;
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