#ifndef _TEST_APP
#define _TEST_APP


#include "ofMain.h"
#include "particle.h"
#include "spring.h"
#include "letter.h"

class testApp : public ofSimpleApp{
	
	public:
		
		void setup();
		void update();
		void draw();
		
		void keyPressed  (int key);
		void keyReleased (int key);
		
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased();
		
		// let's make a vector of them
		vector <particle> particles;
		vector <spring> springs;
        vector <letter> myLetters;
	
	
		vector < ofPoint > trail;
	
		ofTrueTypeFont myFont;
//		ofTTFCharacter testChar;
		char theLetter;
//		vector<ofPoint> points;
//    
        vector <char> typedLetters;
        
        vector <ofTTFCharacter> letterOutlines;
    
        letter myLetterObject; 
	
        int whichLetterToMove;
};

#endif
	
