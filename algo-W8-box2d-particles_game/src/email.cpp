#include "ofMain.h"
#include "email.h"

//----------------------------------------------------------------


void email::drawMePlease(){
    
    ofSetColor(255,255,255);
//    ofCircle( getPosition().x, getPosition().y, getRadius());
    
    if(whichCat == 0){
        correction.x = 30;
        correction.y = -20;
    }

    if(whichCat == 1){
        correction.x = 0;
        correction.y = -20;
    }
    
//    ofSetColor(r-100, g-100, b-100);
//    ofSetLineWidth(8);
 //   ofLine(getPosition().x-getRadius()-4, getPosition().y,getPosition().x+getRadius()+4,getPosition().y);

    tempImg.draw(getPosition().x - origWidth/2 + correction.x, getPosition().y - origHeight/2 + correction.y);
    
    
}


//----------------------------------------------------------------


void email::setInitialConditions() {
    
    isTrash = false;
    isSaved = true;
    isSettled = false;
    timeStamp = ofGetElapsedTimef();
    radius = 40;
    
   // whichCat = floor(ofRandom(4.9999));
    whichCat = whichCategory;
    std::stringstream ss;
    ss << "cat" << whichCat + 1 << ".png";
    std::string fileName = ss.str();
    
    catImg.loadImage(fileName);
    tempImg.clone(catImg);
    
    origWidth = catImg.getWidth();
    origHeight = catImg.getHeight();

    
    
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
            addAttractionPoint(attractionPoint.x, attractionPoint.y, 12);
        }
    }
    setDamping(0.8f);
    
    if(ofGetElapsedTimef() - timeStamp > 1 && ofGetElapsedTimef() > 5) {
//    if(ofGetElapsedTimef() - timeStamp > 1 && ofDist(getPosition().x, getPosition().y, attractionPoint.x, attractionPoint.y) < 50 && getVelocity().x < 0.01 && getVelocity().y < .01) {
    //    isSettled = true;
    }
    
    if(isSettled){
//        if(getPosition().x > attractionPoint.x + 200){
//            isTrash = true;
//        }
//        else if(getPosition().x < 100 && ofGetElapsedTimef() > 1){
        if(ofDist(getPosition().x, getPosition().y, attractionPoint.x, attractionPoint.y) < 200){
            isSaved = false;
        }
    }
}
