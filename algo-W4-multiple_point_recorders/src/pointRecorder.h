/*
 *  pointRecorder.h
 *  algo_wk4
 *
 *  Created by Liz Rutledge on 9/26/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef _POINT_RECORDER_H
#define _POINT_RECORDER_H


#include "ofMain.h"
#include "timePoint.h"
#include "movingObject.h"


#define NUMOBJECTS 3


class pointRecorder {
	
public:

	pointRecorder();
	
	void drawPath();
	void drawObjectAlongPath();
	
	void initiateNewPath(int x, int y);
	void storePointsInPath(int x, int y);
	void endNewPath();
	void clearPath();
	
	ofPoint getVelocityForTime( float time);
	
	
	vector < timePoint >	pts;
	movingObject  movingObjects[NUMOBJECTS];
	
	
	float					startTime;
	bool					bRecording;
	float					playbackStartTime;
	ofPoint					getPositionForTime( float time);
	
	float					totalTime;
	float					timeDelay;
	
	int baseHue;
	
	float pathWidth;
	
	float baseRadius;
	
	bool boolDrawPath;
	
};

#endif
