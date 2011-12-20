#ifndef EMAIL_H
#define EMAIL_H

#include "ofMain.h"
#include "ofxBox2d.h"


class email : public ofxBox2dCircle { 

public:
    
    email();
    
    void draw();
    
    void labelYourself(ofVec2f pos);

};

#endif // EMAIL_H
