//
//  letter.cpp
//  algo_wk9
//
//  Created by Elizabeth Rutledge on 11/15/11.
//  Copyright (c) 2011 __MyCompanyName__. All rights reserved.
//

//#include <iostream>
#include "letter.h"


letter::letter() {
    startingX = ofGetWidth()/2;
}



void letter::setup() {
	myFont.loadFont("GothamHTF-Bold.otf", 150, true,true,true);
    testChar = myFont.getCharacterAsPoints(theLetter);
    ofPolyline line;
    for(int k = 0; k < 1; k++){
        //if( k!= 0)ofNextContour(true) ;
        for(int i = 0; i < (int)testChar.getOutline()[k].size(); i++){
            ofPoint pos;
            pos.x = testChar.getOutline()[k].getVertices()[i].x;
            pos.y = testChar.getOutline()[k].getVertices()[i].y;
            line.addVertex(pos);
        }
    }
	line.addVertex(testChar.getOutline()[0][0]);
    
    ofPolyline lineResampled = line.getResampledBySpacing(10);
    
    
    ofSetColor(255);
    

    
    lineResampled.draw();
    for (int i = 0; i < lineResampled.getVertices().size(); i++){
        float x = startingX + lineResampled.getVertices()[i].x;
		float y = 100 + lineResampled.getVertices()[i].y;
		particle myParticle;
		myParticle.setInitialCondition(x,y,0,0);
		particles.push_back(myParticle);
    }
    
    
	
	
	
	for (int i = 0; i < particles.size(); i++){
		spring mySpring;
		mySpring.distance		= 10;
		mySpring.springiness	= 0.1f;
		mySpring.particleA = & (particles[i]);
		mySpring.particleB = & (particles[(i+1)%particles.size()]);
		springs.push_back(mySpring);
	}
    	
	for (int i = 0; i < particles.size(); i++){
		spring mySpring;
		float dist = (particles[i].pos - particles[(i+10)%particles.size()].pos).length();
		mySpring.distance		= dist;
		mySpring.springiness	= 0.1f;
		mySpring.particleA = & (particles[i]);
		mySpring.particleB = & (particles[(i+10)%particles.size()]);
		springs.push_back(mySpring);
	}
	
	for (int i = 0; i < particles.size(); i++){
		spring mySpring;
		float dist = (particles[i].pos - particles[(i+20)%particles.size()].pos).length();
		
		mySpring.distance		= dist;
		mySpring.springiness	= 0.1f;
		mySpring.particleA = & (particles[i]);
		mySpring.particleB = & (particles[(i+20)%particles.size()]);
		springs.push_back(mySpring);
	}
	
	//particles[particles.size()-1].bFixed = true;

    
}



void letter::update() {
    
    // on every frame 
	// we reset the forces
	// add in any forces on the particle
	// perfom damping and
	// then update
	
	for (int i = 0; i < particles.size(); i++){
		particles[i].resetForce();
	}
	
	
	for (int i = 0; i < particles.size(); i++){
		particles[i].addForce(0,0.3);
		particles[i].addRepulsionForce(mouseX, mouseY, 300, 1.5);
	}
    
	
	for (int i = 0; i < springs.size(); i++){
		springs[i].update();
	}
	
	
	for (int i = 0; i < particles.size(); i++){
		particles[i].bounceOffWalls();
		particles[i].addDampingForce();
		particles[i].update();
	}
	

}



void letter::draw() {
    
    ofSetColor(255,153,0);
	ofFill();
	//ofBeginShape();
	for (int i = 0; i < particles.size(); i++){
	//	ofVertex(particles[i].pos.x, particles[i].pos.y);
		particles[i].draw();
	}
	//ofEndShape(true);
	
	for (int i = 0; i < springs.size(); i++){
        if(i < springs.size()/3 ){
            ofSetColor(255,64,0);
        }
        else {
            ofSetColor(0,0,0,0);
        }
        springs[i].draw();
	
    }
	
	ofNoFill();
//	ofBeginShape();
//	for (int i = 0; i < trail.size(); i++){
//		ofVertex(trail[i].x, trail[i].y);
//	}
//	ofEndShape();

}





