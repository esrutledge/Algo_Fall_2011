#pragma once

#include "ofMain.h"

const int NUMSQUARES = 12;

class testApp : public ofBaseApp{
	
public:
	void setup();
	void update();
	void draw();
	
	void keyPressed  (int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y );
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void windowResized(int w, int h);
	void dragEvent(ofDragInfo dragInfo);
	void gotMessage(ofMessage msg);
	
	float squareWidth[NUMSQUARES];
	
	float keyFrameSquareWidths[2];
	int whichWidth;
	float opacityValues[NUMSQUARES]; 
	int whichOpacity;
	
	float squareWidthStart;
	float squareWidthEnd;
	
	ofPoint pos[NUMSQUARES];
	ofPoint endPos[NUMSQUARES];
	ofPoint startPos[NUMSQUARES];
	
	float pct[NUMSQUARES];
	float shapedPct[NUMSQUARES];
	float opacity[NUMSQUARES];
	
	float shaper;


	
	int whichSquare;

	float durationInSeconds;
	float increment;
	

	
	bool growing[NUMSQUARES];
};
