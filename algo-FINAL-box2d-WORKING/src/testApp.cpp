#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup() {
	
	ofSetVerticalSync(true);
	ofBackgroundHex(0x333333);
	ofSetLogLevel(OF_LOG_NOTICE);
    
    
    ofSetCircleResolution(200);
    
	
    numCategories = 5;

    
	box2d.init();
	box2d.setFPS(30.0);
    box2d.registerGrabbing();
    box2d.setGravity(-32, 32);
    box2d.createBounds();
		
	for (int i=0; i<20; i++) {
		
		
		float r = ofRandom(30, 50);		
		float rx = ofRandom(55, ofGetWidth()-55);		        
		float ry = ofRandom(10, ofGetHeight()-10);		        
		ofxBox2dCircle circle;
        
		circle.setPhysics(.2, 0.2, .8);
		circle.setup(box2d.getWorld(), rx, ry, 40);
		circles.push_back(circle);
        
        for(int i=0; i<numCategories; i++) {
            tempPoint.x = ofGetWidth()/2 + 200*cos(i*PI*2/numCategories);
            tempPoint.y = ofGetHeight()/2 + 200*sin(i*PI*2/numCategories);
            centerPoints.push_back(tempPoint);
        }
        
        for(int i=0; i<circles.size(); i++) {
            tempBool = false;
            isTrash.push_back(tempBool);
            tempBool = false;
            isSaved.push_back(tempBool);
            circles[i].enableGravity(false);
            
            tempInt = i%numCategories;
            whichCategory.push_back(tempInt);

        }
        
//        emailUserData* tempStruct = new emailUserData;
//        tempStruct->category = 3; 
//        circles[0]->setUserData(tempStruct);
//        
//        emailUserData* udStruct = (emailUserData*)circles[0]->GetUserData();
//        
//        cout << udStruct;
		
        
        
//		float w = ofRandom(4, 20);	
//		float h = ofRandom(4, 20);	
//		ofxBox2dRect rect;
//		rect.setPhysics(1.0, 0.53, 0.3);
//		rect.setup(box2d.getWorld(), ofGetWidth()/2, ofGetHeight()/2, w, h);
//		boxes.push_back(rect);
	}
		
}

//--------------------------------------------------------------
void testApp::update() {
	
	box2d.update();	
	
    if(oldNumCategories != numCategories){
        centerPoints.clear();
        whichCategory.clear();
        for(int i=0; i<circles.size(); i++) {
            tempInt = i%numCategories;
            whichCategory.push_back(tempInt);            
        }

        for(int i=0; i<numCategories; i++) {
            if(numCategories < 6) {    
                tempPoint.x = ofGetWidth()/2 + 250*cos(i*PI*2/numCategories)+200;
                tempPoint.y = ofGetHeight()/2 + 250*sin(i*PI*2/numCategories)-100;
                centerPoints.push_back(tempPoint);
            }
            else {
                if(i < numCategories - 1){
                    tempPoint.x = ofGetWidth()/2 + 250*cos(i*PI*2/(numCategories-1))+200;
                    tempPoint.y = ofGetHeight()/2 + 250*sin(i*PI*2/(numCategories-1))-100;
                }
                else {
                    tempPoint.x = ofGetWidth()/2+200;
                    tempPoint.y = ofGetHeight()/2-100;
                }
                centerPoints.push_back(tempPoint);

            }
        }
        
    }
    
    
    
   //cout << centerPoints[0] << "\n";
    

	
	for(int i=0; i<circles.size(); i++) {
        
        if(isTrash[i]) {
            circles[i].addAttractionPoint(ofGetWidth() - 40, ofGetHeight() - 40, 10);
        }
        else {
            if(isSaved[i]){
//                circles[i].addAttractionPoint(20, 20 , 30);
                circles[i].enableGravity(true);

            }
            else {
                // also a small force  towards the center        
                circles[i].addAttractionPoint(centerPoints[whichCategory[i]], 10);
                circles[i].enableGravity(false);
            }
        }
        circles[i].setDamping(0.9f);

        
        if(circles[i].getPosition().x > ofGetWidth()-50){
          //  isTrash[i] = true;
            cout << "hi " << i << "\n";;
        }
        else if(circles[i].getPosition().x < 100 && ofGetElapsedTimef() > 1){
//        else if(circles[i].getPosition().x < centerPoints[whichCategory[i]].x - 150 && ofGetElapsedTimef() > 1){
            isSaved[i] = true;
            cout << "hi " << i << "\n";;
        }
        

	}
       oldNumCategories = numCategories;
}


//--------------------------------------------------------------
void testApp::draw() {
	
//    ofCircle(centerPoints[0].x, centerPoints[0].y, 20);
//    ofCircle(centerPoints[1].x, centerPoints[1].y, 20);
//    ofCircle(centerPoints[2].x, centerPoints[2].y, 20);    

    
 //   ofCircle(ofGetWidth()/2, ofGetHeight()/2, 100);
    
	for(int i=0; i<circles.size(); i++) {
		ofFill();
        
        if(isTrash[i]){
            ofSetColor(255, 80, 0);
        }
        else {
            ofSetHexColor(0xf6c738);            
        }

		circles[i].draw();
	}
	
//	for(int i=0; i<boxes.size(); i++) {
//		ofFill();
//		ofSetHexColor(0xBF2545);
//		boxes[i].draw();
//	}
	
	// draw the ground
	box2d.drawGround();
	
	
	
	string info = "";
	info += "Press [c] for circles\n";
	info += "Press [b] for blocks\n";
	info += "Total Bodies: "+ofToString(box2d.getBodyCount())+"\n";
	info += "Total Joints: "+ofToString(box2d.getJointCount())+"\n\n";
	info += "FPS: "+ofToString(ofGetFrameRate(), 1)+"\n";
	ofSetHexColor(0x444342);
	ofDrawBitmapString(info, 30, 30);
	
	
//	ofSetColor(0,0,0);
//
//	ofSetColor(0,130,130, 200);
//	ofRect(30,30,300,75);
//	ofSetColor(255,255,255);
//	ofDrawBitmapString("space to clear\nchange drawing mode 'a'\ntoggle fade 'f'", 50, 50);
	


	
	ofSetColor(255,255,130);
	
	
}

//--------------------------------------------------------------
void testApp::keyPressed(int key) {
	
//	if(key == 'c') {
//		float r = ofRandom(30, 40);		// a random radius 4px - 20px
//		ofxBox2dCircle circle;
//		circle.setPhysics(3.0, 0.53, 0.9);
//		circle.setup(box2d.getWorld(), mouseX, mouseY, 40);
//		circles.push_back(circle);
//	}
	
	
	
	if(key == 't') ofToggleFullscreen();
    
    if(key == 'f') {
        centerPoints[0].x = 700;
        centerPoints[0].y = 500;
    
    }
    
    if(key == 'm'){
        numCategories++;
    }
	
	
}

//--------------------------------------------------------------
void testApp::keyReleased(int key) {
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ) {
	
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button) {
	

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button) {
	
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button) {
}

//--------------------------------------------------------------
void testApp::resized(int w, int h){
}













