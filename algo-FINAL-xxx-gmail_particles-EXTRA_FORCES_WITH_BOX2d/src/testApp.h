#ifndef _TEST_APP
#define _TEST_APP


#include "ofMain.h"
#include "email.h"
#include "ofxBox2d.h"


// -------------------------------------------------

class testApp : public ofBaseApp {
	
public:
	
	void setup();
	void update();
	void draw();
	
	void keyPressed(int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y);
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void resized(int w, int h);
	
	
	ofxBox2d						box2d;			  //	the box2d world
	vector		<ofxBox2dCircle *>	circles;		  //	default box2d circles
	vector		<ofxBox2dRect>		boxes;			  //	defalut box2d rects

    // let's make a vector of particles
 //   vector <email> emails;

    email myEmail;  

    
    bool	bRepel;
    float	radius;
    float	strength;
	
	
};

#endif
