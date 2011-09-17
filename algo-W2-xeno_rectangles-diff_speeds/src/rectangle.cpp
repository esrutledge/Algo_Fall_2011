/*
 *  rectangle.cpp
 *  algo-20110910-xeno_rectangles
 *
 *  Created by Liz Rutledge on 9/10/11, based off of class code by Zach Lieberman
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "rectangle.h"


//------------------------------------------------------------------
rectangle::rectangle(){
	catchUpSpeed = ofRandom(0.04, 0.3);
	
	rValues[0] = 237;
	rValues[1] = 129;
	rValues[2] = 0;
	rValues[3] = 95;
	rValues[4] = 255;

	gValues[0] = 0;
	gValues[1] = 135;
	gValues[2] = 173;
	gValues[3] = 181;
	gValues[4] = 209;
	
	bValues[0] = 140;
	bValues[1] = 187;
	bValues[2] = 239;
	bValues[3] = 146;
	bValues[4] = 2;
	
	
	rectWidth = 20;
	
}

//------------------------------------------------------------------
void rectangle::draw(int whichColor) {
	
	
	//rotate through 5 colors no matter how many rectangles are drawn
	whichColor = whichColor % 5;
	
	ofSetRectMode(OF_RECTMODE_CENTER); // center around the position
    
	ofSetColor(rValues[whichColor], gValues[whichColor], bValues[whichColor]);
	ofFill();

    ofRect(pos.x, pos.y, rectWidth, rectWidth);


}

//------------------------------------------------------------------
void rectangle::xenoToPoint(float catchX, float catchY){
	pos.x = catchUpSpeed * catchX + (1-catchUpSpeed) * pos.x; 
	pos.y = catchUpSpeed * catchY + (1-catchUpSpeed) * pos.y; 
}


void rectangle::resize(float yPos) {
	rectWidth = yPos/ofGetHeight()*100 +20;
}


