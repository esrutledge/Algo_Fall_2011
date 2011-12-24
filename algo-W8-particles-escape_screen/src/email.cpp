#include "ofMain.h"
#include "email.h"

//----------------------------------------------------------------


void email::drawMePlease(){
    
    ofSetColor(r,g,b);
    ofCircle( getPosition().x, getPosition().y, getRadius());
    
    ofSetColor(r-100, g-100, b-100);
    ofSetLineWidth(8);
 //   ofLine(getPosition().x-getRadius()-4, getPosition().y,getPosition().x+getRadius()+4,getPosition().y);
    
}


//----------------------------------------------------------------


void email::setInitialConditions() {
    
    isTrash = false;
    isSaved = false;
    isSettled = false;
    timeStamp = ofGetElapsedTimef();
    
    
}


//----------------------------------------------------------------


void email::update() {
    

    if(isTrash) {
      //  setPosition(ofGetWidth() + 100, ofGetHeight());
        addAttractionPoint(ofGetWidth() + 500, getPosition().y, 100);
    }
    else {
        if(isSaved){
            enableGravity(true);
        }
        else {
            // also a small force  towards category spots        
            addAttractionPoint(attractionPoint.x, attractionPoint.y, 4);
            enableGravity(false);
        }
    }
    setDamping(0.8f);
    
//    if(ofGetElapsedTimef() - timeStamp > 1 && ofGetElapsedTimef() > 5) {
////    if(ofGetElapsedTimef() - timeStamp > 1 && ofDist(getPosition().x, getPosition().y, attractionPoint.x, attractionPoint.y) < 50 && getVelocity().x < 0.01 && getVelocity().y < .01) {
//        isSettled = true;
//    }
//    
//    if(isSettled){
//        if(getPosition().x > attractionPoint.x + 200){
//            isTrash = true;
//        }
////        else if(getPosition().x < 100 && ofGetElapsedTimef() > 1){
//        else if(getPosition().x < attractionPoint.x - 200){
//            isSaved = true;
//        }
//    }
}
