/*
 *  rectangle.h
 *  algo-20110910-xeno_rectangles
 *
 *  Created by Liz Rutledge on 9/10/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "ofMain.h"

class rectangle {
	
public:
	
	rectangle();
	
	void	draw();
	void	xenoToPoint(float catchX, float catchY);
	
	
	ofPoint		pos;
	float		catchUpSpeed;		// take this pct of where I want to be, and 1-catchUpSpeed of my pos
	int rgbColor[3];
	
};

#endif // RECTANGLE_H
