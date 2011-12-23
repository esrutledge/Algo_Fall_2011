#ifndef PALETTE_COLOR_H
#define PALETTE_COLOR_H

#include "ofMain.h"


//-----------------------------------


class paletteColor : public ofColor {
    
public:
    
    void set(int _r, int _g, int _b);
    
    int r;
    int g;
    int b;
    

};


#endif