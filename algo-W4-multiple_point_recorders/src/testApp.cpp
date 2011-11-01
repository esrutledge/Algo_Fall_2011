#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

	ofBackground(0);
	ofSetVerticalSync(TRUE);
	boolDrawPaths = FALSE;
}


//--------------------------------------------------------------
void testApp::update(){
	if(boolDrawPaths){
		for(int i = 0; i<pointRecorders.size(); i++){
			pointRecorders[i].boolDrawPath = true;
		}
	}
	else {
		for(int i = 0; i<pointRecorders.size(); i++){
			if(pointRecorders[i].bRecording == false){
				pointRecorders[i].boolDrawPath = FALSE;
			}
		}
		
	}
}

//--------------------------------------------------------------
void testApp::draw(){
	for(int i = 0; i<pointRecorders.size(); i++){
		pointRecorders[i].drawPath();
		pointRecorders[i].baseHue = 150 + sin(PI/8 * i) * 40;
		pointRecorders[i].drawObjectAlongPath();
	}
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){
	if(key == ' '){
		if(pointRecorders.size()>0){	
			pointRecorders.pop_back();
		}
	}
	
	if(key == '1'){
		boolDrawPaths = !boolDrawPaths;
	}

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

		pointRecorders[pointRecorders.size()-1].storePointsInPath(mouseX, mouseY);

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
	pointRecorder tempPointRecorder;
	pointRecorders.push_back(tempPointRecorder);
	
	pointRecorders[pointRecorders.size()-1].initiateNewPath(mouseX, mouseY);

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

		pointRecorders[pointRecorders.size()-1].endNewPath();
	 
}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}


