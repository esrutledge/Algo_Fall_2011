/*
 *  particle.h
 *  algo-W5-particles-in_class
 *
 *  Created by Liz Rutledge on 9/27/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef PARICLE_H
#define PARTICLE_H

#include "ofMain.h"

class Particle {

	
public:
	
	Particle();
	
	void draw();
	void update();
	
	float mass;
	
	ofPoint vel;
	ofPoint accel;
	ofPoint force;
	ofPoint pos;
	
	float particleRadius;
	
	
	
};




#endif
