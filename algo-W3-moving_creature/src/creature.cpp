/*
 *  creature.cpp
 *  algo-W3-moving_creature
 *
 *  Created by Liz Rutledge on 9/19/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "creature.h"



//------------------------------------------------------------------
creature::creature(){
	
	ofSetRectMode(OF_RECTMODE_CENTER); // center around the position

	ofSetCircleResolution(100);
	
	catchUpSpeed = 0.06f;	
	pos.set(0,0);
	prevPos.set(0,0);
	
	creatureScale = .15;
		
	//store in default points for when creature is at rest
	lowerBoundaryDefault.set(175,200);

	//control points are stored as differences from related points (either origin or lowerBound) not absolute points
	topHandleDefault.set(72,0);
	midHandleDefault.set(-26,-133);
	lowHandleDefault.set(-155, -34);
	
	tentacleLength = 300;
	
		
	//set current points to the default to start off
	//topHandle = topHandleDefault;
//	midHandle = midHandleDefault;
//	lowerBoundary = lowerBoundaryDefault;
//	lowHandle = lowHandleDefault;
	
	justX.set(1,0);
	justY.set(0,1);
	bothXandY.set(1,1);
	
	
	//vertices[0][0].set(0 + topHandle.x, 0 + topHandle.y);
//	vertices[0][1].set(lowerBoundary.x + midHandle.x, lowerBoundary.y + midHandle.y);
//	vertices[0][2].set(lowerBoundary.x, lowerBoundary.y);
//	
//	vertices[1][0].set(lowerBoundary.x + lowHandle.x, lowerBoundary.y + lowHandle.y);
//	vertices[1][1].set(-1*(lowerBoundary.x + lowHandle.x), lowerBoundary.y + lowHandle.y);
//	vertices[1][2].set(-1*lowerBoundary.x, lowerBoundary.y);
//	
//	vertices[2][0].set(-1*(lowerBoundary.x + midHandle.x), lowerBoundary.y + midHandle.y);
//	vertices[2][1].set(-1*(0 + topHandle.x), 0 + topHandle.y);
//	vertices[2][2].set(0,0);	
	
	
	
}


//------------------------------------------------------------------
void creature::update() {
	
		
	//reset vertices to current points
	vertices[0][0].set(0 + topHandle.x, 0 + topHandle.y);
	vertices[0][1].set(lowerBoundary.x + midHandle.x, lowerBoundary.y + midHandle.y);
	vertices[0][2].set(lowerBoundary.x, lowerBoundary.y);
	
	vertices[1][0].set(lowerBoundary.x + lowHandle.x, lowerBoundary.y + lowHandle.y);
	vertices[1][1].set(-1*(lowerBoundary.x + lowHandle.x), lowerBoundary.y + lowHandle.y);
	vertices[1][2].set(-1*lowerBoundary.x, lowerBoundary.y);
	
	vertices[2][0].set(-1*(lowerBoundary.x + midHandle.x), lowerBoundary.y + midHandle.y);
	vertices[2][1].set(-1*(0 + topHandle.x), 0 + topHandle.y);
	vertices[2][2].set(0,0);	
	
	
	
	// update boundary points
	lowerBoundary = lowerBoundaryDefault + 4*currVel*justY - currVel*justX;
	
	topHandle = topHandleDefault + 2*currVel*justX;
	midHandle = midHandleDefault - 1*currVel*justX - 2*currVel*justY;
	lowHandle = lowHandleDefault + 2*currVel*justX;
	tentacleLength += 2*currVel;
	
	
}

//------------------------------------------------------------------
void creature::draw() {

	
	
	ofFill();
	
	   
	
	ofPushMatrix();
	
	ofTranslate(pos.x, pos.y, 0);
	ofRotateZ(angle * RAD_TO_DEG);

	
	
	// creature body color
	ofSetColor(255,240,230);
//	ofSetColor(198,246,55);

	
	ofBeginShape();
	
	ofVertex(0,0);
	
	for(int i =0; i< 3; i++){
		ofBezierVertex(vertices[i][0].x, vertices[i][0].y, vertices[i][1].x, vertices[i][1].y, vertices[i][2].x, vertices[i][2].y);
		ofVertex(vertices[i][2].x, vertices[i][2].y);
	}
	
		
	ofEndShape();
	
		
	
	
	
	ofPopMatrix();
	

	//draw tentacles
	ofNoFill();
	ofBeginShape();

	for (int i = 0; i < points.size(); i++){
		ofVertex(points[i].x + cos(ofGetElapsedTimef()*10+1*i)*10, points[i].y );
	}
	ofEndShape();
	
	ofBeginShape();
	for (int i = 0; i < points.size(); i++){
		ofVertex(points[i].x, points[i].y );
	}
	ofEndShape();
	
	
}

//------------------------------------------------------------------
void creature::xenoToPoint(float catchX, float catchY){
	
	
	pos.x = catchUpSpeed * catchX + (1-catchUpSpeed) * pos.x; 
	pos.y = catchUpSpeed * catchY + (1-catchUpSpeed) * pos.y; 
	
	float dx = pos.x - prevPos.x;
	float dy = pos.y - prevPos.y;
	
	angle = atan2(dy, dx) + PI/2;
	
	currVel = sqrt(powf(dx, 2) + powf(dy, 2));
	cout << currVel << "\n";
	
	prevPos.x = pos.x;
	prevPos.y = pos.y;
	
	//only replace points if moving
	if(currVel > 1) {
		ofPoint tempPt;
		tempPt.x = pos.x;
		tempPt.y = pos.y;
		points.push_back(tempPt);
		printf ("size of vector %i \n", points.size());
		
		
		if (points.size() > 50){
			points.erase(points.begin());
		}
	}
	
}

//------------------------------------------------------------------
void creature::scaleCreature() {
	
	//scale creature
	topHandleDefault *= creatureScale;
	midHandleDefault *= creatureScale;
	lowerBoundaryDefault *= creatureScale;
	lowHandleDefault *= creatureScale;
	tentacleLength *= creatureScale;
	
}
