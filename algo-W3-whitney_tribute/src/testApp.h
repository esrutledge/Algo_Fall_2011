#ifndef _TEST_APP
#define _TEST_APP

#define NUMSHAPES 300

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


	int shapeWidth;
	
	int rMax;
	int gMax;
	int bMax;
	int aMax;
	
	int r;
	int g;
	int b;
	int a;
	
	float startRadius;
	float maxRadius;
	
	float radiusIncrement;
	float incMax;
	float incMin;
	
};

#endif
