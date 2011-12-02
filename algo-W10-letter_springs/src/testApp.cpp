#include "testApp.h"


//--------------------------------------------------------------
void testApp::setup(){	
    
    ofEnableAlphaBlending();
    
    whichLetterToMove = 0;
	
	ofBackground(0,0,0);
	
	ofSetVerticalSync(true);
	ofSetFrameRate(60);
	    
    myLetterObject.theLetter = 'E';
    myLetterObject.startingX = 100;
    myLetters.push_back(myLetterObject);

    myLetterObject.theLetter = 'S';
    myLetterObject.startingX = 300;
    myLetters.push_back(myLetterObject);
    
    myLetterObject.theLetter = 'R';
    myLetterObject.startingX = 500;
    myLetters.push_back(myLetterObject);
    
    
    
    for(int i = 0; i < myLetters.size(); i++){
        myLetters[i].setup();
    }
    
//    testChar = myFont.getCharacterAsPoints(letter);
    
//    typedLetters.push_back('E');
//    typedLetters.push_back('S');
//    typedLetters.push_back('R'); 

//    
//    for(int i = 0; i < typedLetters.size(); i++) {   
//        testChar = myFont.getCharacterAsPoints(typedLetters[i]);
//        letterOutlines.push_back(testChar);
//    }
//    
//    for(int j = 0; j < letterOutlines.size(); j++) {   
//
//        ofPolyline line;
//        for(int k = 0; k < 1; k++){
//            //if( k!= 0)ofNextContour(true) ;
//            for(int i = 0; i < (int)letterOutlines[j].getOutline()[k].size(); i++){
//                ofPoint pos;
//                pos.x = letterOutlines[j].getOutline()[k].getVertices()[i].x;
//                pos.y = letterOutlines[j].getOutline()[k].getVertices()[i].y;
//                line.addVertex(pos);
//            }
//        }
//        line.addVertex(letterOutlines[j].getOutline()[0][0]);
//        
//        ofPolyline lineResampled = line.getResampledBySpacing(10);
//        
//        
//        ofSetColor(255);
//        
//        
//        lineResampled.draw();
//        for (int i = 0; i < lineResampled.getVertices().size(); i++){
//            float x = 100 + j*100 + lineResampled.getVertices()[i].x;
//            float y = ofGetHeight()/2 + lineResampled.getVertices()[i].y;
//            particle myParticle;
//            myParticle.setInitialCondition(x,y,0,0);
//            particles.push_back(myParticle);
//        }
//        
//        
//        
//        
//        
//        for (int i = 0; i < particles.size(); i++){
//            spring mySpring;
//            mySpring.distance		= 10;
//            mySpring.springiness	= 0.4f;
//            mySpring.particleA = & (particles[i]);
//            mySpring.particleB = & (particles[(i+1)%particles.size()]);
//            springs.push_back(mySpring);
//        }
//        
//        for (int i = 0; i < particles.size(); i++){
//            spring mySpring;
//            float dist = (particles[i].pos - particles[(i+10)%particles.size()].pos).length();
//            mySpring.distance		= dist;
//            mySpring.springiness	= 0.1f;
//            mySpring.particleA = & (particles[i]);
//            mySpring.particleB = & (particles[(i+10)%particles.size()]);
//            springs.push_back(mySpring);
//        }
//        
//        for (int i = 0; i < particles.size(); i++){
//            spring mySpring;
//            float dist = (particles[i].pos - particles[(i+20)%particles.size()].pos).length();
//            
//            mySpring.distance		= dist;
//            mySpring.springiness	= 0.1f;
//            mySpring.particleA = & (particles[i]);
//            mySpring.particleB = & (particles[(i+20)%particles.size()]);
//            springs.push_back(mySpring);
//        }
//        
//        //particles[particles.size()-1].bFixed = true;
//    }
    
    
//    myLetters.push_back(
	
}

//--------------------------------------------------------------
void testApp::update(){

	// on every frame 
	// we reset the forces
	// add in any forces on the particle
	// perfom damping and
	// then update
	
//	for (int i = 0; i < particles.size(); i++){
//		particles[i].resetForce();
//	}ouse
//	
//	
//	for (int i = 0; i < particles.size(); i++){
//		particles[i].addForce(0,0.1);
//		particles[i].addRepulsionForce(mouseX, mouseY, 300, 1.5);
//	}
//	 
//	
//	for (int i = 0; i < springs.size(); i++){
//		springs[i].update();
//	}
//	
//	
//	for (int i = 0; i < particles.size(); i++){
//		particles[i].bounceOffWalls();
//		particles[i].addDampingForce();
//		particles[i].update();
//	}
    
    for(int i = 0; i < myLetters.size(); i++){
        myLetters[i].mouseX = mouseX;
        myLetters[i].mouseY = mouseY;        
        myLetters[i].update();
    }	
}

//--------------------------------------------------------------
void testApp::draw(){
	

//	ofSetColor(255,0,255);
//	ofFill();
//	//ofBeginShape();
//	for (int i = 0; i < particles.size(); i++){
//		///ofVertex(particles[i].pos.x, particles[i].pos.y);
//		particles[i].draw();
//	}
//	//ofEndShape(true);
//	
//	for (int i = 0; i < springs.size(); i++){
//		springs[i].draw();
//	}
//	
//	ofNoFill();
//	ofBeginShape();
//	for (int i = 0; i < trail.size(); i++){
//		ofVertex(trail[i].x, trail[i].y);
//	}
//	ofEndShape();

    
    for(int i = 0; i < myLetters.size(); i++){
        myLetters[i].draw();
    }
}

//--------------------------------------------------------------
void testApp::keyPressed  (int key){ 
	
	if(key == ' ') {
//			// reposition everything: 
//			for (int i = 0; i < particles.size(); i++){
//				particles[i].setInitialCondition(ofRandom(0,ofGetWidth()),ofRandom(0,ofGetHeight()),0,0);
//			}

            if(whichLetterToMove < myLetters.size()-1){        
                whichLetterToMove ++;
            }
            else {
                whichLetterToMove = 0;
            }
    }
    else {
        //add a new letter
        myLetterObject.theLetter = char(key);
        myLetterObject.startingX = ofRandom(ofGetWidth());
       
        myLetters.push_back(myLetterObject);

        myLetters[myLetters.size()-1].setup();
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
	myLetters[whichLetterToMove].particles[0].pos.set(mouseX, mouseY);
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
	myLetters[whichLetterToMove].particles[0].bFixed = true;
}

//--------------------------------------------------------------
void testApp::mouseReleased(){
	myLetters[whichLetterToMove].particles[0].bFixed = false;
}

