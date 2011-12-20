#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup() {
	
	ofSetVerticalSync(true);
	ofBackgroundHex(0xfdefc2);
	ofSetLogLevel(OF_LOG_NOTICE);
	
	box2d.init();
	box2d.setGravity(0, 0);
	box2d.setFPS(30.0);
    box2d.registerGrabbing();

		
	for (int i=0; i<100; i++) {
		
		
		float r = ofRandom(10, 20);		
		ofxBox2dCircle circle;
		circle.setPhysics(1.0, 0.53, 0.3);
		circle.setup(box2d.getWorld(), ofGetWidth()/2, ofGetHeight()/2, r);
		circles.push_back(circle);
		
		float w = ofRandom(4, 20);	
		float h = ofRandom(4, 20);	
		ofxBox2dRect rect;
		rect.setPhysics(1.0, 0.53, 0.3);
		rect.setup(box2d.getWorld(), ofGetWidth()/2, ofGetHeight()/2, w, h);
		boxes.push_back(rect);
	}
	
	VF.setupField(60,40,ofGetWidth(), ofGetHeight());
	//VF.randomizeField(2.0);
	
	drawingStyle = 0;
	bFade = false;
	
}

//--------------------------------------------------------------
void testApp::update() {
	
	box2d.update();	
	
	
	for(int i=0; i<circles.size(); i++) {
		ofVec2f	frc = VF.getForceFromPos(circles[i].getPosition().x, circles[i].getPosition().y);
		circles[i].addForce(frc, 10);
		
		// also a small force  towards the center
		ofVec2f centerDiff = ofPoint (ofGetWidth()/2, ofGetHeight()/2) -  circles[i].getPosition();
		centerDiff.normalize();
		circles[i].addForce(centerDiff, 1.2);
		
		circles[i].setDamping(0.93f);
		
		
	}
	for(int i=0; i<boxes.size(); i++) {
		ofVec2f	frc = VF.getForceFromPos(boxes[i].getPosition().x, boxes[i].getPosition().y);
		boxes[i].addForce(frc, 10);
		
		// also a small force towards the mouse
		ofVec2f diff = ofPoint(mouseX, mouseY) - boxes[i].getPosition();
		diff.normalize();
		boxes[i].addForce(diff, 3);
		
		boxes[i].setDamping(0.93f);
		
	}
	
	
	if (bFade == true) VF.fadeField(0.99f);
}


//--------------------------------------------------------------
void testApp::draw() {
	
	
	for(int i=0; i<circles.size(); i++) {
		ofFill();
		ofSetHexColor(0xf6c738);
		circles[i].draw();
	}
	
	for(int i=0; i<boxes.size(); i++) {
		ofFill();
		ofSetHexColor(0xBF2545);
		boxes[i].draw();
	}
	
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
	
	
	VF.draw();
	
	ofSetColor(0,0,0);
	
	ofSetColor(0,130,130, 200);
	ofRect(30,30,300,75);
	ofSetColor(255,255,255);
	ofDrawBitmapString("space to clear\nchange drawing mode 'a'\ntoggle fade 'f'", 50, 50);
	
	
	ofSetColor(255,255,130);
	switch (drawingStyle){
		case 0: ofDrawBitmapString("drawing mode: inward", 50, 90);
			break;
		case 1: ofDrawBitmapString("drawing mode: outward", 50, 90);
			break;
		case 2: ofDrawBitmapString("drawing mode: clockwise", 50, 90);
			break;
		case 3: ofDrawBitmapString("drawing mode: counter-clockwise", 50, 90); 
			break;
	}
	
	
	
}

//--------------------------------------------------------------
void testApp::keyPressed(int key) {
	
	if(key == 'c') {
		float r = ofRandom(14, 20);		// a random radius 4px - 20px
		ofxBox2dCircle circle;
		circle.setPhysics(3.0, 0.53, 0.9);
		circle.setup(box2d.getWorld(), mouseX, mouseY, r);
		circles.push_back(circle);
	}
	
	if(key == 'b') {
		float w = ofRandom(14, 20);	
		float h = ofRandom(14, 20);	
		ofxBox2dRect rect;
		rect.setPhysics(3.0, 0.53, 0.9);
		rect.setup(box2d.getWorld(), mouseX, mouseY, w, h);
		boxes.push_back(rect);
	}
	
	if(key == 't') ofToggleFullscreen();
	
	
	if (key == ' '){
		VF.clear();
	} else if (key == 'a'){
		drawingStyle ++;
		drawingStyle %= 4;
	} else if (key == 'f'){
		bFade = !bFade;
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
	
//	if (button == 0) {
//		switch (drawingStyle){
//			case 0: VF.addInwardCircle((float)x, (float)y, 400, 0.3f);
//				break;
//			case 1: VF.addOutwardCircle((float)x, (float)y, 400, 0.3f);
//				break;
//			case 2: VF.addClockwiseCircle((float)x, (float)y, 400, 0.3f);
//				break;
//			case 3: VF.addCounterClockwiseCircle((float)x, (float)y, 400, 0.3f);
//				break;
//		}		
//	} 
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













