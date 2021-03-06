#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	
	ofSetVerticalSync(true);
	
	ofBackground(0,0,0);
	
	ofSetCircleResolution(100);
	
	shapeWidth = 1;
	
	maxRadius = 4;
	
	incMax = 2.4;
	incMin = 1;
	
	rMax = 255;
	gMax = 60;
	bMax = 180;
	aMax = 120;
	
	r=rMax;
	g=gMax;
	b=bMax;
	a=aMax;

}

//--------------------------------------------------------------
void testApp::update(){
	
	
	

}

//--------------------------------------------------------------
void testApp::draw(){
	
	float xorig = ofGetWidth()/2;
	float yorig = ofGetHeight()/2;
	
	startRadius = ofMap(sin(ofGetElapsedTimef()/10), -1, 1, 0, 1)*maxRadius;
	//startRadius = 50;
	radiusIncrement	= ofMap(sin(ofGetElapsedTimef()), -1, 1, incMin/incMax, 1)*incMax;

	
	for (int i = 0; i < NUMSHAPES; i++){
	
		float radius = startRadius + i*radiusIncrement;
		float angle = ofGetElapsedTimef() * (1 + i / 20.0);
		r = ofMap(sin(ofGetElapsedTimef()*1), -1, 1, 0, 1)*rMax;
		g = ofMap(sin(ofGetElapsedTimef()*1.5), -1, 1, 0, 1)*gMax;
		b = ofMap(sin(ofGetElapsedTimef()*2), -1, 1, 0, 1)*bMax;

		
		float x = xorig + radius * cos(angle);
		float y = yorig + radius * -sin(angle);
		
		
		ofSetColor(r, g, b, a);
		ofCircle(x,y,shapeWidth + i/2,shapeWidth + i/8);
	
	}	
		
	
	

}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

