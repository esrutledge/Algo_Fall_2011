#include "testApp.h"


//--------------------------------------------------------------
void testApp::setup(){	
	
	ofSetVerticalSync(true);
	ofSetFrameRate(60);
    
    ofBackground(30,30,30);
    
    r = ofRandom(230,255);
    g = ofRandom(180,220);
    b = 0;
    
	firstDelay = 1;
    lastTime = 0;
    opacity = 255;
    
    theta = 0;
    
    ofSetColor(r, g, b, opacity); 
    
    startNewFirework = false;
	
	for (int i = 0; i < 1000; i++){
		particle myParticle;
        
        float vmagnitude = 4;
        theta += PI/20;
        float vx = cos(theta)*(vmagnitude+i/40);
        float vy = sin(theta)*(vmagnitude+i/200);
        
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
        float newY = ofRandom(50, ofGetHeight()-200);
        
        for (int i = 0; i < particles.size(); i++){
            float vmagnitude = 4;
            theta += PI/20;
            float vx = cos(theta)*(vmagnitude+i/40);
            float vy = sin(theta)*(vmagnitude+i/200);
            
            //cout <<  pow(-1.0, i) << "\n";
            
            particles[i].setInitialCondition(newX, newY, vx, vy);	
            
        }
        
        r = ofRandom(220,255);
        g =ofRandom(100,210);

        opacity = 255;
        
        firstDelay = ofRandom(.8, 3);
        lastTime = ofGetElapsedTimef();
        
    }

}

//--------------------------------------------------------------
void testApp::draw(){
    
    ofEnableAlphaBlending();
    opacity = opacity - 2;

    ofSetColor(r, g, b, opacity);
    
	for (int i = 0; i < particles.size(); i++){
		particles[i].draw();
	}

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
	for (int i = 0; i < particles.size(); i++){
        float vmagnitude = 4;
        theta += PI/20;
        float vx = cos(theta)*(vmagnitude+i/40);
        float vy = sin(theta)*(vmagnitude+i/200);

    
		particles[i].setInitialCondition(mouseX,mouseY,vx, vy);	

        lastTime = ofGetElapsedTimef();
        opacity = 255;
	}

    r = ofRandom(220,255);
    g =ofRandom(100,210);


}

//--------------------------------------------------------------
void testApp::mouseReleased(){
}
