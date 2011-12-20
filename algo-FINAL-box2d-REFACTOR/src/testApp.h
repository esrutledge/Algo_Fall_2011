#ifndef _TEST_APP
#define _TEST_APP


#include "ofMain.h"
#include "ofxBox2d.h"
#include "email.h"
#include "paletteColor.h"

// -------------------------------------------------

class testApp : public ofBaseApp {
	
public:
	
	void setup();
	void update();
	void draw();
	
	void keyPressed(int key);
	void keyReleased(int key);
	void mouseMoved(int x,  int y);
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void resized(int w, int h);
	
    
    void addEmail(int _whichCategory);
    void resetAttractionPoints(int numCategories);
    void applyNewAttractionPoints(int numCategories);
    void countReleased();
   
    void loadColors();
    
    vector <email> emails;
    
    
    email circle;
    
    paletteColor paletteColors[20];

    int radius;
    int xShift;
    int yShift;
    int unitRadius;
    int innerRingRadius;
    int defaultRingRadius;
    int outerRingRadius;
    
    int saved;
    int trash;
	
	ofxBox2d						box2d;			  //	the box2d world
//	vector		<ofxBox2dCircle>	circles;		  //	default box2d circles
//	vector		<ofxBox2dRect>		boxes;			  //	defalut box2d rects
//	
    vector <ofVec2f> centerPoints;
//    vector <ofVec2f> catDiffs;    
//    vector <bool> isTrash;
//    vector <bool> isSaved;
//    vector <bool> isSettled;
//    
//    vector <int> whichCategory;
//    
//    struct emailUserData {
//        int category;
//        string sender;      
//        string subject;              
//    };
//	
    int numEmailsStart;
    int numCategories;
    int oldNumCategories;
//    
    ofVec2f tempPoint;
    bool tempBool;
    int tempInt;
    
};

#endif