#include "testApp.h"
#include "ofMain.h"

//--------------------------------------------------------------
void testApp::setup(){

	
	// macs by default run on non vertical sync, which can make animation very, very fast
	// this fixes that: 
	
	ofSetVerticalSync(true);
	
	// set background: 
	
	ofEnableAlphaBlending();
	
	ofBackground(0,20,50);
	
	
	// set the position of the rectangle:
	
	myCreature.pos.x = 100;
	myCreature.pos.y = 50;
	myCreature.creatureScale = 0.2;
	
	secondCreature.pos.x = ofGetWidth()-100;
	secondCreature.pos.y = 100;
	secondCreature.catchUpSpeed = .03;	
	secondCreature.creatureScale = .15;
	
	myCreature.scaleCreature();
	secondCreature.scaleCreature();

	
}

//--------------------------------------------------------------
void testApp::update(){
	myCreature.xenoToPoint(mouseX, mouseY);
	secondCreature.xenoToPoint(mouseX + 40, mouseY + 30);
}

//--------------------------------------------------------------
void testApp::draw(){
		myCreature.update();
	secondCreature.update();
	myCreature.draw();
	secondCreature.draw();
}

//--------------------------------------------------------------
void testApp::keyPressed  (int key){
}

//--------------------------------------------------------------
void testApp::keyReleased  (int key){
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
void testApp::mouseReleased(){
}
