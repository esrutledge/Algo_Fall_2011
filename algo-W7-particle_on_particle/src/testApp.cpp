#include "testApp.h"


//--------------------------------------------------------------
void testApp::setup(){	
	
	ofSetVerticalSync(true);
	ofSetFrameRate(60);
	
    ofBackground(0,20,50);

	
	for (int i = 0; i < 200; i++){
		particle myParticle;
		myParticle.setInitialCondition(ofRandom(0,ofGetWidth()),ofRandom(0,ofGetHeight()),0,0);
		particles.push_back(myParticle);
	}
	
	bRepel		= true;
	radius		= 160;
	strength	= 1.22f; 
    
    
    // set the position of the rectangle:
	
	myCreature.pos.x = 100;
	myCreature.pos.y = 50;
	myCreature.creatureScale = 0.2;
	
		
	myCreature.scaleCreature();
	
    
    secondCreature.pos.x = ofGetWidth()-100;
	secondCreature.pos.y = 100;
	secondCreature.catchUpSpeed = .03;	
	secondCreature.creatureScale = .15;
	
	secondCreature.scaleCreature();


	
	
}

//--------------------------------------------------------------
void testApp::update(){

	// on every frame 
	// we reset the forces
	// add in any forces on the particle
	// perfom damping and
	// then update
	
	for (int i = 0; i < particles.size(); i++){
		particles[i].resetForce();
	}
	
	
	for (int i = 0; i < particles.size(); i++){
	
        if (bRepel){
            particles[i].addRepulsionForce(myCreature.pos.x, myCreature.pos.y, radius, strength);
            particles[i].addRepulsionForce(secondCreature.pos.x, secondCreature.pos.y, radius, strength);
        }
        else {
            particles[i].addAttractionForce(myCreature.pos.x, myCreature.pos.y, radius, strength);
            particles[i].addAttractionForce(secondCreature.pos.x, secondCreature.pos.y, radius, strength);

        }
        
		
		for (int j = 0; j < i; j++){
			particles[i].addRepulsionForce(particles[j], 50, 0.4);
			particles[i].addAttractionForce(particles[j], 500, 0.005);
		}
//		//for (int j = 0; j < i; j++){
////			if (bRepel){
////				particles[i].addRepulsionForce(particles[j], radius, strength);
////			} else {
////				particles[i].addAttractionForce(particles[j], radius, strength);
////			}
////		}
	}
	
	for (int i = 0; i < particles.size(); i++){
		particles[i].addDampingForce();
		particles[i].update();
	}
    
    myCreature.xenoToPoint(mouseX, mouseY);
	secondCreature.xenoToPoint(mouseX + 40, mouseY + 30);

    
    
}

//--------------------------------------------------------------
void testApp::draw(){
	
	ofEnableAlphaBlending();
	ofSetColor(0,130,130, 200);
	
	ofSetColor(0x000000);
	
	for (int i = 0; i < particles.size(); i++){
		particles[i].draw();
	}
	
	string reportString =	"(space) = reset\n(a/s) strength = " + ofToString(strength) + 
							"\n(z/x) radius = " + ofToString(radius) + 
							"\n(r) toggle mode = " + (bRepel ? "repelling" : "attracting");
	
	ofSetColor(40,40,0);
	ofRect(10,10,300,80);
	ofSetColor(255,255,255);
	ofDrawBitmapString(reportString, 30, 30);
    

    myCreature.update();
	myCreature.draw();


    secondCreature.update();
	secondCreature.draw();

}

//--------------------------------------------------------------
void testApp::keyPressed  (int key){ 
	
	switch (key){
			
		case ' ':
			// reposition everything: 
			for (int i = 0; i < particles.size(); i++){
				particles[i].setInitialCondition(ofRandom(0,ofGetWidth()),ofRandom(0,ofGetHeight()),0,0);
			}
			break;
		case 'a':
			strength += 0.02f;
			break;
		case 's':
			strength -= 0.02f;
			if (strength <= 0) strength = 0.02f;
			break;
		case 'z':
			radius += 5.0f;
			break;
		case 'x':
			radius -= 5.0f;
			if (radius <= 0) radius = 5.0f;
			break;
		case 'r':
			bRepel = !bRepel;
			break;
	}
	
	
}

//--------------------------------------------------------------
void testApp::keyReleased  (int key){ 
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
	particles.erase(particles.begin());
	particle myParticle;
	myParticle.setInitialCondition(x,y,0,0);
	particles.push_back(myParticle);
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
}

//--------------------------------------------------------------
void testApp::mouseReleased(){
}
