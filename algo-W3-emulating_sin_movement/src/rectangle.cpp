#include "rectangle.h"


//------------------------------------------------------------------
rectangle::rectangle(){
	pos.y = 0;
	pos.z = 0;
	pos.x = 0;
	
	containerRadius = 400;
	
	pathRadius = containerRadius;
	
	shapeWidth = 30;
	
	spinVel = 3;
	dropVel = 20;
	
	startAnimation = false;
	timeStarted = 0;
	timeMultiplier = 10;

}

void rectangle::update(){
	
	pctSin = ofMap(sin((ofGetElapsedTimef()-timeStarted)*timeMultiplier), -1, 1, 0, 1); 
	pctCos = ofMap(cos((ofGetElapsedTimef()-timeStarted)*timeMultiplier), -1, 1, 0, 1);
	
	if(pathRadius >= 0){
		pos.z = sin((ofGetElapsedTimef()-timeStarted)*timeMultiplier)*pathRadius/2
;
		pos.x = cos((ofGetElapsedTimef()-timeStarted)*timeMultiplier)*pathRadius;
		pos.y += spinVel;

//		spinVel -= .0015;
		pathRadius -= 2;
	}
	else {
		
		pos.x = 0;
		pos.z = 0;
		dropVel = 1.3*dropVel;
		pos.y += dropVel;
	}
	
	timeMultiplier += .08;
	
	if(pos.y >= 2*ofGetHeight()){
		startAnimation = false;
	}
}

//------------------------------------------------------------------
void rectangle::draw() {
	
		
	
	ofPushMatrix();
		ofTranslate(ofGetWidth()/2, 0, 0);
		ofFill();
		ofSetRectMode(OF_RECTMODE_CENTER); // center around the position
		ofSetColor(190);
		ofPushMatrix();
			ofTranslate(pos.x, pos.y, pos.z);
			ofRotate(40,1,0,0);
			ofCircle(0,0,0, shapeWidth);
	
		ofPopMatrix();
	
	ofPoint tempPt;
	tempPt.x = pos.x;
	tempPt.y = pos.y;
	tempPt.z = pos.z;
	points.push_back(tempPt);
	
	if (points.size() > 50){
		points.erase(points.begin());
	}
	
	ofNoFill();
	ofBeginShape();
	for (int i = 0; i < points.size(); i++){
		if(i>0){
			ofLine(points[i].x, points[i].y, points[i].z, points[i-1].x, points[i-1].y, points[i-1].z);
		}
	}
	ofEndShape();
	
	

	
	ofPopMatrix();	
	
	
	
		
	
}

//------------------------------------------------------------------
void rectangle::drawContainer() {

	ofSetColor(255, 230, 0);
	ofFill();
//	ofRect(ofGetWidth()/2, ofGetHeight()/2, containerRadius*2 + shapeWidth*2, ofGetHeight());
	ofTriangle(ofGetWidth()/2-containerRadius - shapeWidth, 0, ofGetWidth()/2+ containerRadius + shapeWidth, 0, ofGetWidth()/2, ofGetHeight()-110);
	ofRect(ofGetWidth()/2, ofGetHeight()/2, shapeWidth*2, ofGetHeight());
	ofSetColor(200, 180, 0);
	ofEllipse(ofGetWidth()/2, 0, 2*containerRadius + 2*shapeWidth, 40);
	ofEllipse(ofGetWidth()/2, ofGetHeight()-154, 2*shapeWidth, 20);

}
















