#include "particle.h"
#include "ofMain.h"


//------------------------------------------------------------
particle::particle(){
	setInitialCondition(ofGetWidth()/2,ofGetHeight()/2,0,0);
	damping = 0.08f;
    
    
    ofSetRectMode(OF_RECTMODE_CENTER); // center around the position
    
	ofSetCircleResolution(100);
	
	
	creatureScale = .15;
    
	//store in default points for when creature is at rest
	lowerBoundaryDefault.set(175,200);
    
	//control points are stored as differences from related points (either origin or lowerBound) not absolute points
	topHandleDefault.set(72,0);
	midHandleDefault.set(-26,-133);
	lowHandleDefault.set(-155, -34);
	
	
    
	justX.set(1,0);
	justY.set(0,1);
	bothXandY.set(1,1);
    
    
    
}

//------------------------------------------------------------
void particle::resetForce(){
    // we reset the forces every frame
    frc.set(0,0);
}

//------------------------------------------------------------
void particle::addForce(float x, float y){
    // add in a force in X and Y for this frame.
    frc.x = frc.x + x;
    frc.y = frc.y + y;
}

//------------------------------------------------------------
void particle::addDampingForce(){
	
	// the usual way to write this is  vel *= 0.99
	// basically, subtract some part of the velocity 
	// damping is a force operating in the oposite direction of the 
	// velocity vector
	
    frc.x = frc.x - vel.x * damping;
    frc.y = frc.y - vel.y * damping;
}

//------------------------------------------------------------
void particle::setInitialCondition(float px, float py, float vx, float vy){
    pos.set(px,py);
	vel.set(vx,vy);
}

//------------------------------------------------------------
void particle::update(){	
	vel = vel + frc;
	pos = pos + vel;
    
    currVel = ofDist(0,0, vel.x, vel.y);
    angle = atan2(vel.y, vel.x) + PI/2;
    
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

//------------------------------------------------------------
void particle::draw(){
 //   ofCircle(pos.x, pos.y, 3);
    ofFill();
	
    
	
	ofPushMatrix();
	
	ofTranslate(pos.x, pos.y, 0);
	ofRotateZ(angle * RAD_TO_DEG);
    
	
	
	// creature body color
	ofSetColor(230,80,0);
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
    
    
    //only replace points if moving
	if(currVel > .01) {
		ofPoint tempPt;
		tempPt.x = pos.x;
		tempPt.y = pos.y;
		points.push_back(tempPt);
	//	printf ("size of vector %i \n", points.size());
		
		
		if (points.size() > 35){
			points.erase(points.begin());
		}
	}


}


//------------------------------------------------------------
void particle::bounceOffWalls(){
	
	// sometimes it makes sense to damped, when we hit
	bool bDampedOnCollision = true;
	bool bDidICollide = false;
	
	// what are the walls
	float minx = 0;
	float miny = 0;
	float maxx = ofGetWidth();
	float maxy = ofGetHeight();
	
	if (pos.x > maxx){
		pos.x = maxx; // move to the edge, (important!)
		vel.x *= -1;
		bDidICollide = true;
	} else if (pos.x < minx){
		pos.x = minx; // move to the edge, (important!)
		vel.x *= -1;
		bDidICollide = true;
	}
	
	if (pos.y > maxy){
		pos.y = maxy; // move to the edge, (important!)
		vel.y *= -1;
		bDidICollide = true;
	} else if (pos.y < miny){
		pos.y = miny; // move to the edge, (important!)
		vel.y *= -1;
		bDidICollide = true;
	}
	
	if (bDidICollide == true && bDampedOnCollision == true){
		vel *= 0.3;
	}
	
}


//------------------------------------------------------------------
void particle::scaleCreature() {
	
	//scale creature
	topHandleDefault *= creatureScale;
	midHandleDefault *= creatureScale;
	lowerBoundaryDefault *= creatureScale;
	lowHandleDefault *= creatureScale;
	tentacleLength *= creatureScale;
	
}
