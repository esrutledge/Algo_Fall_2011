#include "testApp.h"


//--------------------------------------------------------------
void testApp::setup(){	
	
	ofBackground(0,0,0);
	
	ofSetVerticalSync(true);
	ofSetFrameRate(60);
	
	
	particle myParticle;
    
    myParticle.setInitialCondition(227,-1,0,0);
	particles.push_back(myParticle);
	
    myParticle.setInitialCondition(227,0,0,0);
	particles.push_back(myParticle);
    	
	myParticle.setInitialCondition(283,38,0,0);
	particles.push_back(myParticle);
	
	myParticle.setInitialCondition(232,86,0,0);
	particles.push_back(myParticle);

    myParticle.setInitialCondition(408,126,0,0);
	particles.push_back(myParticle);
	
	myParticle.setInitialCondition(511,113,0,0);
	particles.push_back(myParticle);
    
    myParticle.setInitialCondition(325,226,0,0);
	particles.push_back(myParticle);
    
    myParticle.setInitialCondition(461,292,0,0);
	particles.push_back(myParticle);
    
    myParticle.setInitialCondition(412,372,0,0);
	particles.push_back(myParticle);
    
    myParticle.setInitialCondition(389,410,0,0);
	particles.push_back(myParticle);
    
    myParticle.setInitialCondition(330,410,0,0);
	particles.push_back(myParticle);
    
    myParticle.setInitialCondition(339,310,0,0);
	particles.push_back(myParticle);
    
    myParticle.setInitialCondition(278,431,0,0);
	particles.push_back(myParticle);
    
    myParticle.setInitialCondition(298,392,0,0);
	particles.push_back(myParticle);
    
    myParticle.setInitialCondition(209,432,0,0);
	particles.push_back(myParticle);
    
    myParticle.setInitialCondition(266,226,0,0);
	particles.push_back(myParticle);
    
    myParticle.setInitialCondition(191,167,0,0);
	particles.push_back(myParticle);
    
    myParticle.setInitialCondition(0,160,0,0);
	particles.push_back(myParticle);
    
    myParticle.setInitialCondition(152,52,0,0);
	particles.push_back(myParticle);
    
    myParticle.setInitialCondition(185,29,0,0);
	particles.push_back(myParticle);
    
    
	
	spring mySpring;
		
//	for (int i = 0; i < particles.size(); i++){
//		
//		mySpring.distance		= 100;
//		mySpring.springiness	= 0.2f;
//		mySpring.particleA = & (particles[i  ]);
//		mySpring.particleB = & (particles[(i+1) % particles.size()]);
//		springs.push_back(mySpring);
//	}
	
    // assign array for all the connections we need to make. 1st is ptA, 2nd is ptB, and 3rd is 0 for invisible, 1 for visible
    int springPairsVisible[][2] = {{1,2}, {2,3}, {3,18}, {18,19}, {19,1}, {19,3}, {3,4}, {4,6}, {6,7}, {7,8}, {8,9}, {9,10}, /*{10,8}, {13,14},*/ {14,12}, {12,13}, {13,11}, {11,15}, {15,16}, {16,3}, {15,6}, {11,12}, {9,7}, {18,1}, {18,2}, {11,7} };
   
    int springPairsInvisible[][2] = {{1,3}, {19,2}, {2,4}, {10,6},  {14,15}, {16,4}, {4,15}, {15,3}, {3,6}, {6,16}, {0,1},  {12,15}, {9,6}, {14,11}, {10,7}, {10,15}, {9,15}, {14,6}, {7,15}, {14,16}, {4,7}, {12,10}, {16,18} }; 
   
    int springPairsPuppet[][2] = { {3,5}, {5,16}, {5,11}, {5,7}, {10,17}, {14,17}, {17,16}, {17,3}, {18,17}, {10,5}, {14,5}};

    for(int i = 0; i< 26 ; i++){
        mySpring.distance		= (particles[springPairsVisible[i][0]].pos-particles[springPairsVisible[i][1]].pos).length();
        mySpring.springiness	= 0.2f;
        mySpring.particleA = & (particles[springPairsVisible[i][0]]);
        mySpring.particleB = & (particles[springPairsVisible[i][1]]);
        springs.push_back(mySpring);
    }
    
    for(int i = 0; i< 23 ; i++){
        mySpring.distance		= (particles[springPairsInvisible[i][0]].pos-particles[springPairsVisible[i][1]].pos).length();
        mySpring.springiness	= 0.2f;
        if(i == 10){
        //    mySpring.springiness = 0.00f;
        }
        mySpring.particleA = & (particles[springPairsInvisible[i][0]]);
        mySpring.particleB = & (particles[springPairsInvisible[i][1]]);
        invisibleSprings.push_back(mySpring);

    }
    
    for(int i = 0; i< 11 ; i++){
        mySpring.distance		= (particles[springPairsPuppet[i][0]].pos-particles[springPairsPuppet[i][1]].pos).length();
        mySpring.springiness	= 0.3f;
        mySpring.particleA = & (particles[springPairsPuppet[i][0]]);
        mySpring.particleB = & (particles[springPairsPuppet[i][1]]);
        puppetSprings.push_back(mySpring);
        
    }
    
    
    
    
//    
//        mySpring.distance		= (particles[0].pos-particles[2].pos).length();
//        mySpring.springiness	= 0.2f;
//        mySpring.particleA = & (particles[0]);
//        mySpring.particleB = & (particles[2]);
//        springs.push_back(mySpring);
//	
//	mySpring.distance		= (particles[1].pos-particles[3].pos).length();
//	mySpring.springiness	= 0.2f;
//	mySpring.particleA = & (particles[1]);
//	mySpring.particleB = & (particles[3]);
//	springs.push_back(mySpring);
//	
//    mySpring.distance		= (particles[2].pos-particles[4].pos).length();
//	mySpring.springiness	= 0.2f;
//	mySpring.particleA = & (particles[2]);
//	mySpring.particleB = & (particles[4]);
//	springs.push_back(mySpring);
//	
//    mySpring.distance		= (particles[3].pos-particles[0].pos).length();
//	mySpring.springiness	= 0.2f;
//	mySpring.particleA = & (particles[3]);
//	mySpring.particleB = & (particles[0]);
//	springs.push_back(mySpring);	
//    
//    mySpring.distance		= (particles[4].pos-particles[1].pos).length();
//	mySpring.springiness	= 0.2f;
//	mySpring.particleA = & (particles[4]);
//	mySpring.particleB = & (particles[1]);
//	springs.push_back(mySpring);
	
}

//--------------------------------------------------------------
void testApp::update(){

	// on every frame 
	// we reset the forces
	// add in any forces on the particle
	// perfom damping and
	// then update
	
	puppetSprings[10].distance = 180 + 50 * sin(ofGetElapsedTimef()*8);
	puppetSprings[9].distance = 180 + 50 * sin(ofGetElapsedTimef()*8 + PI);
	puppetSprings[3].distance = 40 + 60 * sin(ofGetElapsedTimef()*8);
    
	
	
	for (int i = 0; i < particles.size(); i++){
		particles[i].resetForce();
	}
	
	for (int i = 0; i < particles.size(); i++){
		particles[i].addForce(0,0.1f);
		//particles[i].addRepulsionForce(mouseX, mouseY, 300, 0.7f);
	}
	
	for (int i = 0; i < springs.size(); i++){
		springs[i].update();
	}
	for (int i = 0; i < invisibleSprings.size(); i++){
		invisibleSprings[i].update();
	}
	for (int i = 0; i < puppetSprings.size(); i++){
		puppetSprings[i].update();
	}
    
    
	for (int i = 0; i < particles.size(); i++){
		particles[i].bounceOffWalls();
		particles[i].addDampingForce();
		particles[i].update();
	}
}

//--------------------------------------------------------------
void testApp::draw(){
	
    ofSetColor(255);

	
	for (int i = 0; i < particles.size(); i++){
		particles[i].draw();
	}
	
	for (int i = 0; i < springs.size(); i++){
		springs[i].draw();
	}
	
    ofSetColor(20);
	
    for (int i = 0; i < invisibleSprings.size(); i++){
		invisibleSprings[i].draw();
	}
    for (int i = 0; i < puppetSprings.size(); i++){
		puppetSprings[i].draw();
	}
    
    
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
	particles[0].pos.set(mouseX, mouseY);
	/*particles.erase(particles.begin());
	particle myParticle;
	myParticle.setInitialCondition(x,y,0,0);
	particles.push_back(myParticle);*/
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
	particles[0].bFixed = true;
}

//--------------------------------------------------------------
void testApp::mouseReleased(){
	
	particles[0].bFixed = false;
}

