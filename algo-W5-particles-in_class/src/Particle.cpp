/*
 *  particle.cpp
 *  algo-W5-particles-in_class
 *
 *  Created by Liz Rutledge on 9/27/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "Particle.h"

Particle::Particle()
{
	mass = 1.2;
	
	vel.set(0,0);
	force.set(0, 9.81/ofGetFrameRate());
	accel = force/mass;

	pos.set(ofGetWidth()/2, 0);
	
	particleRadius = 20;
}


void Particle::draw(){
	ofCircle(pos.x, pos.y, particleRadius);
}
