#include "testApp.h"


//--------------------------------------------------------------
void testApp::setup(){	
	
	ofSetVerticalSync(true);
	ofSetFrameRate(60);
    
    //ofBackground(30,30,30);
    
    bg.loadImage("grass.jpg");
    bg.draw(0,0);
    scaleDivider = 1;
    
    r = ofRandom(230,255);
    g = ofRandom(180,220);
    b = 0;
    
	firstDelay = 1;
    lastTime = 0;
//    opacity = 255;
    
//   ofSetColor(r, g, b, opacity); 
    
    startNewFirework = false;
	
    float thetaAdjustment =  ofRandom(PI/2);

    
	for (int i = 0; i < 30; i++){
		particle myParticle;
        
        float vmagnitude = ofRandom(4, 12);
        float theta = ofRandom(3*PI/2, 2*PI) - thetaAdjustment;
		float vx = cos(theta)*vmagnitude;
		float vy = sin(theta)*vmagnitude;
        
		myParticle.setInitialCondition(300,300,vx, vy);
		// more interesting with diversity :)
		// uncomment this: 
		//myParticle.damping = ofRandom(0.01, 0.05);
		particles.push_back(myParticle);
	}
	
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
		particles[i].addForce(0,0.06);  // gravity
		particles[i].addDampingForce();
		particles[i].update();
	}
    
   
    
    if(ofGetElapsedTimef() - lastTime > firstDelay) {
        float newX = ofRandom(100, ofGetWidth()-100);
        float newY = ofRandom(100, ofGetHeight()-100);
        float thetaAdjustment =  ofRandom(PI/2);
        
        for (int i = 0; i < particles.size(); i++){
            float vmagnitude = ofRandom(4, 12);
            float theta = ofRandom(3*PI/2, 2*PI) - thetaAdjustment;
            float vx = cos(theta)*vmagnitude;
            float vy = sin(theta)*vmagnitude;
            
            particles[i].setInitialCondition(newX, newY,vx, vy);	
            
        }
        
        r = ofRandom(220,255);
        g =ofRandom(100,210);

        opacity = 255;
        
        firstDelay = ofRandom(1.5, 3);
        lastTime = ofGetElapsedTimef();
        scaleDivider = 1;
        
    }

}

//--------------------------------------------------------------
void testApp::draw(){
    
    bg.draw(0,0);
    ofEnableAlphaBlending();
//    ofSetColor(r, g, b, opacity);
    
    
     
    for (int i = 0; i < particles.size(); i++){
   //     particles[i].tempImg.resize(particles[i].origWidth/scaleDivider, particles[i].origHeight/scaleDivider);
        particles[i].draw();
	}
    
    scaleDivider += .005;

    ofDisableAlphaBlending();
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
    float thetaAdjustment =  ofRandom(PI/2);

	for (int i = 0; i < particles.size(); i++){
        float vmagnitude = ofRandom(4, 12);
        float theta = ofRandom(3*PI/2, 2*PI) - thetaAdjustment;
		float vx = cos(theta)*vmagnitude;
		float vy = sin(theta)*vmagnitude;
    
		particles[i].setInitialCondition(mouseX,mouseY,vx, vy);	
	
	}

    r = ofRandom(220,255);
    g =ofRandom(100,210);
    scaleDivider = 1;

}

//--------------------------------------------------------------
void testApp::mouseReleased(){
}
