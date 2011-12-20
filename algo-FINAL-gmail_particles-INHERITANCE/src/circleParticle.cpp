/*
 *  traingleParticle.cpp
 *  algo_wk10_inheritance
 *
 *  Created by zachary lieberman on 11/8/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "circleParticle.h"


void circleParticle::draw(){
	
	float size = 20;
	ofSetColor(255,100,0);
    ofFill();
	ofCircle(pos.x, pos.y, size);
	ofFill();
}