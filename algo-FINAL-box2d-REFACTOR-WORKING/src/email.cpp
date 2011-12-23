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
    isClickedOn = false;
    clickHold = false;
     showSavedAb = false;   
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
    
    if(ofGetElapsedTimef() - timeStamp > .3 && ofGetElapsedTimef() > 1.5) {
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
        attractionForce = 8;
    }
    


    
}

//--------------

void email::hoverTitle(ofTrueTypeFont font, ofTrueTypeFont smallerFont) {
    
    ofFill();
    
    
    if(isClickedOn){
        
        displayDetails(smallerFont);
        
    }
    
  //      cout << title << "\n";
    
    string info = "";
	info += title+"\n";
//	info += "Total Saved: "+ ofToString(saved) +"\n\n";
//	info += "Total Trashed: "+ ofToString(trash) + "\n";
//	info += "Number of categories: "+ofToString(numCategories)+"\n";
//	ofDrawBitmapString(info, getPosition().x, getPosition().y);
    
    infoWidth = font.stringWidth(info);
    
   
    
    ofSetColor(0,0,0);
    ofRect(getPosition().x - infoWidth/2 -10, 
           getPosition().y - getRadius() - 6 - font.getLineHeight(), 
           infoWidth+18, 
           font.getLineHeight());

    ofSetColor(r,g,b);
    ofRect(getPosition().x - infoWidth/2 -8, 
           getPosition().y - getRadius() - 6 - font.getLineHeight(), 
           infoWidth+16, 
           font.getLineHeight()-2);

    ofSetColor(0,0,0);
    ofTriangle(getPosition().x-3, getPosition().y - getRadius() + 2 -1, 
               getPosition().x - 5 -3, getPosition().y - getRadius() - 8, 
               getPosition().x + 5, getPosition().y - getRadius() - 8);
    
    ofSetColor(r,g,b);
    ofTriangle(getPosition().x, getPosition().y - getRadius() + 2, 
               getPosition().x - 5, getPosition().y - getRadius() - 8, 
               getPosition().x + 5, getPosition().y - getRadius() - 8);

    
    ofSetHexColor(0xffffff);

    font.drawString(info, getPosition().x - infoWidth/2, getPosition().y - getRadius()*3-4);
    
}

// -------

void email::checkHovering(int mouseX, int mouseY, bool mousePressed) {
    
    if(ofDist(mouseX, mouseY, getPosition().x, getPosition().y) <= getRadius()){
        isHovering = true;
    }
    else {
        isHovering = false;
}
    isClickedOn = mousePressed;
    
    
}

//------

void email::displayDetails(ofTrueTypeFont font) {
    
    
    vector <string> splitAb = ofSplitString(abstract, " ");
    
    info = "";
    multiInfo = byline + "\n";
    int counter = 3;
    
    for(int i=0; i< splitAb.size(); i++) {
        info += splitAb[i] + " ";
        if(font.stringWidth(info) > 200){
            info += "\n";
            counter ++;
            multiInfo += info;
            info = "";
        }
    }
    // get last partial line
    multiInfo += info;
    
        
    infoWidth = font.stringWidth(multiInfo);
    
   
//    ofSetColor(0,0,0);
//    ofRect(getPosition().x - infoWidth/2 -10, 
//           getPosition().y - getRadius() +1+2, 
//           infoWidth+16, 
//           font.getLineHeight()*counter+6);
    
    
    ofSetColor(240,240,240, 200);
    ofRect(getPosition().x - infoWidth/2 -8, 
           getPosition().y - getRadius() -1+2, 
           infoWidth+16, 
           font.getLineHeight()*counter+6);
    
    

        
    
    ofSetColor(30,30,30);
    
    font.drawString(multiInfo, getPosition().x - infoWidth/2, getPosition().y - getRadius());

    
}

//------

void email::displaySavedTitle(ofTrueTypeFont font) {
    
    ofSetColor(240,240,240);
    if(isHovering){
        font.drawString(title, getPosition().x, getPosition().y);
        ofSetColor(200,200,200);
        font.drawString(url, getPosition().x, getPosition().y+20
                        );

        if(clickHold){
            showSavedAb = true;      
        }
        else {
            showSavedAb = false;
        }
    }
    else {
        vector <string> split = ofSplitString(title, " ");
        
        info = split[0];
        for(int i=1; i< split.size(); i++) {
            
            if(font.stringWidth(info) < 100){
                info += " " + split[i];
            }
            else {
            }
        }
        // get last partial line
        info += "...";
        font.drawString(info, getPosition().x, getPosition().y);

    }
    

}

//-----

void email::displaySavedAbstract(ofTrueTypeFont font) {
    
    vector <string> splitAb = ofSplitString(abstract, " ");
    
    info = "";
    multiInfo = byline + "\n";
    int counter = 3;
    
    for(int i=0; i< splitAb.size(); i++) {
        info += splitAb[i] + " ";
        if(font.stringWidth(info) > 200){
            info += "\n";
            counter ++;
            multiInfo += info;
            info = "";
        }
    }
    // get last partial line
    multiInfo += info;
    
    
    infoWidth = font.stringWidth(multiInfo);
    
    
    
    ofSetColor(240,240,240, 240);
    ofRect(getPosition().x , 
           getPosition().y +45, 
           infoWidth+16, 
           font.getLineHeight()*counter+6);
    
    
    
    
    
    ofSetColor(30,30,30);
    
    font.drawString(multiInfo, getPosition().x+4, getPosition().y+44);
    

}