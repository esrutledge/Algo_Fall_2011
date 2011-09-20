/*
 *  creature.h
 *  algo-W3-moving_creature
 *
 *  Created by Liz Rutledge on 9/19/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef CREATURE_H
#define CREATURE_H

#include "ofMain.h"


class creature {
	
public:
	
	creature();
	
	void	draw();
	void	update();
	void	scaleCreature();
	void	xenoToPoint(float catchX, float catchY);
	
	ofPoint		pos;
	ofPoint		prevPos;
	
	float		angle;
	
	float		catchUpSpeed;		// take this pct of where I want to be, and 1-catchUpSpeed of my pos
	
	float creatureScale;
	
	float currVel;
	
	ofPoint vertices[3][3];
	ofPoint currVertices[3][3];
	
	ofPoint topHandle;
	ofPoint midHandle;
	ofPoint lowerBoundary;
	ofPoint lowHandle;
	
	ofPoint topHandleDefault;
	ofPoint midHandleDefault;
	ofPoint lowerBoundaryDefault;
	ofPoint lowHandleDefault;
	
	float tentacleLength;
	
	ofPoint justX;
	ofPoint justY;
	ofPoint bothXandY;
	
	
	vector < ofPoint > points;

	
};





#endif // RECTANGLE_H