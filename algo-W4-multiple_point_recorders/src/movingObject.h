/*
 *  movingObject.h
 *  algo_wk4
 *
 *  Created by Liz Rutledge on 9/26/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef _MOVING_OBJECT_H
#define _MOVING_OBJECT_H


#include "ofMain.h"


class movingObject {
	
	public:
	
		movingObject();
		
		void drawObjectAtPointInTime(ofPoint positionAtTime, float radius);
		ofPoint getPositionForTime(float time);	
		void changeHue(int hue, int saturation = 255, int brightness = 255, int alpha = 255);
	
		float x;
		float y;
	
		int hue;
	ofColor color;
	
	float objectWidth;
};

#endif
