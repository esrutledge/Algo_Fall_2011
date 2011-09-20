#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "ofMain.h"

class rectangle {

	public:
	
		rectangle();
	
		void update();
		void drawSquares(int whichSquare, int maxSquares);
	
		ofPoint pos;
	

};

#endif // RECTANGLE_H
