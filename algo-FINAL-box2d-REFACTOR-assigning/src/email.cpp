#include "ofMain.h"
#include "email.h"

//----------------------------------------------------------------


void email::drawMePlease(){
    
    ofSetColor(r,g,b);
    ofCircle( getPosition().x, getPosition().y, getRadius());
    
    ofSetColor(r-100, g-100, b-100);
    ofSetLineWidth(8);
 //   ofLine(getPosition().x-getRadius()-4, getPosition().y,getPosition().x+getRadius()+4,getPosition().y);
    
//    if(isHovering) {
//        hoverTitle();
//    }
}


//----------------------------------------------------------------


void email::setInitialConditions() {
    
    isTrash = false;
    isSaved = false;
    isSettled = false;
    timeStamp = ofGetElapsedTimef();
    isHovering = false;
    
}


//----------------------------------------------------------------


void email::update() {
    

    if(isTrash) {
      //  setPosition(ofGetWidth() + 100, ofGetHeight());
        addAttractionPoint(ofGetWidth() + 500, getPosition().y, 100);
    }
    else {
        if(isSaved){
            if (getPosition().x < getRadius()/2+ 10) {
                //addAttractionPoint(0, getPosition().y, 1);
            }
            else {
                addAttractionPoint(0, getPosition().y, 4);
            }
        }
        else {
            // also a small force  towards category spots        
            
            addAttractionPoint(attractionPoint.x, attractionPoint.y, attractionForce);
            enableGravity(false);
        }
    }
    setDamping(0.8f);
    
    if(ofGetElapsedTimef() - timeStamp > .5 && ofGetElapsedTimef() > 3) {
//    if(ofGetElapsedTimef() - timeStamp > 1 && ofDist(getPosition().x, getPosition().y, attractionPoint.x, attractionPoint.y) < 50 && getVelocity().x < 0.01 && getVelocity().y < .01) {
        isSettled = true;
    }
    
    if(isSettled){
        attractionForce = 2;

        if(getPosition().x > attractionPoint.x + 200){
            isTrash = true;
        }
//        else if(getPosition().x < 100 && ofGetElapsedTimef() > 1){
        else if(getPosition().x < attractionPoint.x - 200){
            isSaved = true;
        }
    }
    else {
        attractionForce = 6;
    }
    


    
}

//--------------

void email::hoverTitle(ofTrueTypeFont font) {
    
    cout << title << "\n";
    
    string info = "";
	info += title+"\n";
//	info += "Total Saved: "+ ofToString(saved) +"\n\n";
//	info += "Total Trashed: "+ ofToString(trash) + "\n";
//	info += "Number of categories: "+ofToString(numCategories)+"\n";
	ofSetHexColor(0x00bbbb);
	ofDrawBitmapString(info, getPosition().x, getPosition().y);
    
    font.drawString(info, getPosition().x, getPosition().y);
    
}

// -------

void email::checkHovering(int mouseX, int mouseY) {
    
    if(ofDist(mouseX, mouseY, getPosition().x, getPosition().y) <= getRadius()){
        isHovering = true;
    }
    else {
        isHovering = false;
    }

}

