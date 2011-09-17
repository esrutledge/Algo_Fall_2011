#pragma once

#include "ofMain.h"

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
		
	int r1;
	int g1;
	int b1;
	
	int r2;
	int g2;
	int b2;
	
	int rOpposite;
	int gOpposite;
	int bOpposite;
	
	int rCurr;
	int gCurr;
	int bCurr;
	
	float pct;
	
	bool goingRight;

	float durationInSeconds;
	float increment;
};
