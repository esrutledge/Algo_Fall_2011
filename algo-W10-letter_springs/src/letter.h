//
//  letter.h
//  algo_wk9
//
//  Created by Elizabeth Rutledge on 11/15/11.
//  Copyright (c) 2011 __MyCompanyName__. All rights reserved.
//

#ifndef LETTER_H
#define LETTER_H

#include "ofMain.h"
#include "spring.h"
#include "particle.h"

class letter
{
    public:
       
//        vector <particle> particles;    
        
    letter();
    
    void setup();
    void update();
    void draw();
    
    
    // let's make a vector of them
    vector <particle> particles;
    vector <spring> springs;
	
	
    vector < ofPoint > trail;
	
    ofTrueTypeFont myFont;
    ofTTFCharacter testChar;
    char theLetter;
    vector<ofPoint> points;

    int startingX;    
    
    int mouseX;
    int mouseY;

        
    protected:
    private:
};






#endif
