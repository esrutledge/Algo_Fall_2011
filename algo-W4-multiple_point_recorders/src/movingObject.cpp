/*
 *  movingObject.cpp
 *  algo_wk4
 *
 *  Created by Liz Rutledge on 9/26/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "movingObject.h"



//--------------------------------------------------------------

movingObject::movingObject(){
	hue = 0;
	objectWidth = 20;
	x=-100;
	y=-100;
	
}


//--------------------------------------------------------------
void movingObject::drawObjectAtPointInTime(ofPoint positionAtTime, float radius){
	// -------------------------- draw the point at the current time
	
	ofFill();
	ofSetColor(color);
	ofCircle(positionAtTime.x, positionAtTime.y, radius);
	
}


//--------------------------------------------------------------
void movingObject::changeHue(int hueVal, int saturation, int brightness, int alpha){
	color.setHsb(hueVal, saturation, brightness, alpha);
}