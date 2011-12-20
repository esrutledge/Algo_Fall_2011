#ifndef EMAIL_H
#define EMAIL_H

#include "ofMain.h"
#include "ofxBox2d.h"


//-----------------------------------


class email : public ofxBox2dCircle {
    
public:

    void drawMePlease();
    void setInitialConditions();
   
    void update();
    void updateTrash(); 
    void updateSaved(); 
    
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
};


#endif