/*
 *  traingleParticle.cpp
 *  algo_wk10_inheritance
 *
 *  Created by zachary lieberman on 11/8/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "squareParticle.h"


void squareParticle::draw(){
    ofSetColor(0,130,130);
    ofFill();
	float size = 15;
	ofRect(pos.x - size/2, pos.y - size/2, size, size);
}