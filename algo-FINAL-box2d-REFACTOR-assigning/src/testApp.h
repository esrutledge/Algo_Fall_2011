#ifndef _TEST_APP
#define _TEST_APP


#include "ofMain.h"
#include "ofxBox2d.h"
#include "email.h"
#include "paletteColor.h"
#include "ofxFileLoader.h"


// set up constants to use instead of numeric keys for stringData

#define CATEGORY 0
#define TITLE 1
#define ABSTRACT 2
#define URL 3
#define BYLINE 4
#define HAS_IMG 5
#define IMG_URL 6

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
	
    
    void addEmail(int _whichCategory, int index);
    void resetAttractionPoints(int numCategories);
    void applyNewAttractionPoints(int numCategories);
    void countReleased();
    void assignDetailsInfo(int _i);
    
    void loadColors();
    
    vector <email> emails;
    
    
    email circle;
    
    paletteColor paletteColors[20];

    bool sortByCategory;
    
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

    vector <ofVec2f> centerPoints;

    int numEmailsStart;
    int numCategories;
    int oldNumCategories;
    int numCategoriesStart;
    
    ofVec2f tempPoint;
    bool tempBool;
    int tempInt;
    
    
    ofTrueTypeFont myFont; 
    
    // loading data utilities
    ofxFileLoader fileLoader;
    string dataString;
    
    vector <string> result;
    vector <string> tempResult;
    vector < vector <string> > nestedResults;
    
    
    // create arrays to deal with keys/indices for categories
    int indexForCategory(string _catString);
    
    vector <int> categoriesWithArticles;

    int currentCategoryKeys[20];
    bool catHasArticles[20];
    
    
};

#endif