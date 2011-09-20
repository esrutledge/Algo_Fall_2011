#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "ofMain.h"

class rectangle {
	
public:
	
	rectangle();
	
	void update();
	void draw();
	void drawContainer();
	
	ofPoint pos;
	
	float pctSin;
	float pctCos;
	
	float containerRadius;
	
	float shapeWidth;
	
	float pathRadius;
	
	float spinVel;
	float dropVel;
	
	bool startAnimation;
	float timeStarted;
	float timeMultiplier;
	
	vector < ofPoint > points;

};

#endif // RECTANGLE_H
