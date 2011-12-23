#ifndef EMAIL_H
#define EMAIL_H

#include "ofMain.h"
#include "ofxBox2d.h"

#define CATEGORY 0
#define TITLE 1
#define ABSTRACT 2
#define URL 3
#define BYLINE 4
#define HAS_IMG 5
#define IMG_URL 6

//-----------------------------------


class email : public ofxBox2dCircle {
    
public:

    void drawMePlease();
    void setInitialConditions();
   
    void update();
    void updateTrash(); 
    void updateSaved(); 
    
    bool isHovering;
    bool isClickedOn;
    void checkHovering(int mouseX, int mouseY, bool mousePressed);
    void hoverTitle(ofTrueTypeFont font, ofTrueTypeFont smallerFont);
    void displayDetails(ofTrueTypeFont font);
    void displaySavedTitle(ofTrueTypeFont font);
    void displaySavedAbstract(ofTrueTypeFont font);
    
//    void sort();
    
    float radius;
    
    int r;
    int g;
    int b;
    
    ofVec2f attractionPoint;
    
    bool isTrash;
    bool isSaved;
    int whichCategory;
    
    bool isSettled;
    
    float timeStamp;
    
    float attractionForce;
    
    //vector <string> detailsInfo;
    string catName;
    string title;
    string abstract;
    string url;
    string byline;
    string hasImg;
    string imgURL;
    
    
    string info;
    string multiInfo;
    int infoWidth;
    
    bool clickHold;
    bool showSavedAb;
    

};


#endif