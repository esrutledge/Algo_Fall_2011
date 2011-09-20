#include "testApp.h"
#include "ofMain.h"

//--------------------------------------------------------------
void testApp::setup(){

	
	// macs by default run on non vertical sync, which can make animation very, very fast
	// this fixes that: 
	
	ofSetVerticalSync(true);
	ofSetFrameRate(30);

	// set background: 
	
	ofEnableAlphaBlending();
//	ofBackground(30,30,30);
	
	
	// set the position of the rectangle:
	
	myRectangle.pos.x = 100;
	myRectangle.pos.y = 50;
	
	runAnimation = false;
	
	whichPoint = 1;
}

//--------------------------------------------------------------
void testApp::update(){
	
	if(runAnimation){
					myRectangle.xenoToPoint(pointsInPath[whichPoint-1].pos.x, pointsInPath[whichPoint-1].pos.y, pointsInPath[whichPoint].pos.x, pointsInPath[whichPoint].pos.y );
		
		//if(myRectangle.pos.x >= pointsInPath[whichPoint].pos.x - 1){
//			
//			whichPoint ++;
//			runAnimation = false;
//		}
		whichPoint ++;
	}
}

//--------------------------------------------------------------
void testApp::draw(){
	myRectangle.draw();
	
	
	ofSetColor(255,0,0);
	ofNoFill();
	ofBeginShape();
	for (int i = 0; i < pointsInPath.size(); i++){
		ofVertex(pointsInPath[i].pos.x, pointsInPath[i].pos.y);
	}
	ofEndShape();

	
}

//--------------------------------------------------------------
void testApp::keyPressed  (int key){
}

//--------------------------------------------------------------
void testApp::keyReleased  (int key){
	runAnimation = true;
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

	
//	ofPoint tempPt;
//	tempPt.x = x;
//	tempPt.y = y;
//	points.push_back(tempPt);
//
//	
	recordedPoint tempPathPoint;
	
	tempPathPoint.pos.x = x;
	tempPathPoint.pos.y = y;
	tempPathPoint.timeElapsed = ofGetElapsedTimef();
	
	cout << tempPathPoint.pos.x << "\n";
	
	
	pointsInPath.push_back(tempPathPoint);
	
	
	//printf ("size of vector %i \n", pointsInPath.size());
//
//	printf ("time elapsed [0] %i \n", pointsInPath.end().pos.x);

//	cout << pointsInPath;
	
	
	
	if (pointsInPath.size() > 50){
		pointsInPath.erase(pointsInPath.begin());
	}
	

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
	
	pointsInPath.clear();
	whichPoint = 0;
	runAnimation = false;


}

//--------------------------------------------------------------
void testApp::mouseReleased(){
	


}
