/*
 *  pointRecorder.cpp
 *  algo_wk4
 *
 *  Created by Liz Rutledge on 9/26/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "pointRecorder.h"



pointRecorder::pointRecorder() {

	bRecording = false;
	playbackStartTime = 0;
	pathWidth = 1;
	ofSetLineWidth(pathWidth);
	baseRadius = 10;
	
	boolDrawPath = false;
	
	
	for(int i = 0; i<NUMOBJECTS; i++){
		movingObjects[i].x = - 100;
		movingObjects[i].y = - 100;
	}
	
}


//------------------------------------------------------------------
void pointRecorder::drawPath() {
	// -------------------------- draw the line
	if(boolDrawPath){
		ofSetColor(60);
		ofNoFill();
		ofBeginShape();
		for (int i = 0; i < pts.size();i++){
			ofVertex(pts[i].x, pts[i].y);
		}
		ofEndShape();

	}
}



//------------------------------------------------------------------
void pointRecorder::drawObjectAlongPath() {
	for(int i = 0; i<NUMOBJECTS; i++){
		movingObjects[i].changeHue(baseHue, 240, 230);
		
		ofPoint calcPosition = getPositionForTime(ofGetElapsedTimef()-timeDelay*i);
		ofPoint velocity =  getVelocityForTime(ofGetElapsedTimef()-timeDelay*i);
		
		float objectRadius = ofDist(0, 0, velocity.x, velocity.y)/8;
	
		if (objectRadius > 40) {
			objectRadius = 20;
		}
		
		movingObjects[i].drawObjectAtPointInTime(calcPosition, baseRadius + objectRadius);
	
	}		
}



//------------------------------------------------------------------
void pointRecorder::initiateNewPath(int x, int y) {
	bRecording = true;
	pts.clear();
	startTime = ofGetElapsedTimef();
	timePoint temp;
	temp.x = x;
	temp.y = y;
	temp.t = 0;
	pts.push_back(temp);
	boolDrawPath = true;
	
}


//------------------------------------------------------------------
void pointRecorder::storePointsInPath(int x, int y) {
	timePoint temp;
	temp.x = x;
	temp.y = y;
	temp.t = ofGetElapsedTimef() - startTime;
	pts.push_back(temp);
	
	printf("adding point %i at time %f \n", pts.size(), ofGetElapsedTimef() - startTime);
	
}



//------------------------------------------------------------------
void pointRecorder::endNewPath() {
	bRecording = false;
	totalTime = pts[pts.size()-1].t - playbackStartTime;
	timeDelay = totalTime/NUMOBJECTS;
	playbackStartTime = ofGetElapsedTimef();
	boolDrawPath = false;

}



//------------------------------------------------------------------
void pointRecorder::clearPath() {
	bRecording = false;
	pts.clear();
}



//--------------------------------------------------------------
ofPoint pointRecorder::getPositionForTime(float time){
	
	// are we recording?
	
	if (bRecording == true){
		return ofPoint(-100,-100,0);
	} else if (pts.size() < 2){
		return ofPoint(-100,-100,0);
	}
	
	// now, let's figure out where we are in the drawing....
	
	// (a) figure out where we are in the cycle
	
	// (like % but for floats)
	while (time > pts[pts.size()-1].t){
		time -= pts[pts.size()-1].t;
	}
	
	
	ofPoint pos;
	
	for (int i = 0; i < pts.size()-1; i++){
		if (time >= pts[i].t && time < pts[i+1].t){
			
			// calculate pct: 
			
			float part = time - pts[i].t;
			float whole = pts[i+1].t - pts[i].t;
			float pct = part / whole;
			
			// figure out where we are between a and b
			
			
			pos.x = (1-pct) * pts[i].x + (pct) * pts[i+1].x;
			pos.y = (1-pct) * pts[i].y + (pct) * pts[i+1].y;
			
			
		}
	}
	
	return pos;
	
}


//--------------------------------------------------------------
ofPoint	 pointRecorder::getVelocityForTime( float time){
	
	// to get the velocity, look back a bit of time, and at the current time
	// and get the difference 
	// veclocity = pos at time 1 - pos at time 0... 
	
	// (like % but for floats)
	//while (time > pts[pts.size()-1].t){
//		time -= pts[pts.size()-1].t;
//	}
	
	
	
	float prevPtTime= MAX(time - 0.09f, 0);
	
	ofPoint prevPt = getPositionForTime(prevPtTime);		// check for where we were 0.05 seconds ago
	ofPoint currPt = getPositionForTime(time);							// check for where we are now.
	
	ofPoint diff;
	diff.x = currPt.x - prevPt.x;
	diff.y = currPt.y - prevPt.y;
	
	ofPoint baseVel;
	baseVel.x = 0;
	baseVel.y = baseRadius;
	
	return diff;

	
}






	