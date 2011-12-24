#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup() {
	
    myFont.loadFont("GothamHTF-Bold.otf", 29, true, true, true);

	ofSetVerticalSync(true);
	ofBackgroundHex(0x333333);
	ofSetLogLevel(OF_LOG_NOTICE);
    
    loadColors();
    
    // load NYTimes data
    dataString = fileLoader.loadFromUrl("http://localhost/algo/algo-dummy_data.txt");

    result = ofSplitString(dataString, "!");

    for(int i = 0; i< result.size(); i++){
        if(tempResult.size() > 0){
            tempResult.clear();
        }
        tempResult = ofSplitString(result[i], "#");
        nestedResults.push_back(tempResult);
    }
    

//    for(int i=0; i< nestedResults[0].size(); i++){
//        cout << nestedResults[0][i] << "###\n";        
//    }

    

    
	numEmailsStart = 80;
    numCategories = 20;

    radius = 12;
    
    unitRadius = 80;

    xShift = 70;
    yShift = 10;
    
    saved = 0;
    trash = 0;
    
	box2d.init();
	box2d.setFPS(30.0);
    box2d.registerGrabbing();
    box2d.setGravity(-8,8);
    box2d.createBounds(0,0,ofGetWidth()+1000,ofGetHeight());
		

    
    for(int i=0; i<numCategories; i++) {
        resetAttractionPoints(numCategories);
    }
   
    // add email/circles to world
	for (int i=0; i < numEmailsStart; i++) {
        addEmail(i % numCategories);
        emails[i].setInitialConditions();
    }
    

    
    // sound stuff
    // 0 output channels, 
	// 2 input channels
	// 44100 samples per second
	// 256 samples per buffer
	// 4 num buffers (latency)
	
	soundStream.listDevices();
	
	//if you want to set a different device id 
	//soundStream.setDeviceID(0); //bear in mind the device id corresponds to all audio devices, including  input-only and output-only devices.
	
	int bufferSize = 256;
	
	
	left.assign(bufferSize, 0.0);
	right.assign(bufferSize, 0.0);
	volHistory.assign(400, 0.0);
	
	bufferCounter	= 0;
	drawCounter		= 0;
	smoothedVol     = 0.0;
	scaledVol		= 0.0;
    
	soundStream.setup(this, 0, 2, 44100, bufferSize, 4);
    

    
}


//--------------------------------------------------------------


void testApp::update() {

//    cout << emails[0].isSettled << "\n";

    innerRingRadius = unitRadius;
    defaultRingRadius = 2.5 * unitRadius;
    outerRingRadius = 2.8 * unitRadius;

	
    //update world
	box2d.update();	
    
	// change attraction points for different categories if number changed (and apply to emails)
    if(oldNumCategories != numCategories){
        resetAttractionPoints(numCategories);
        applyNewAttractionPoints(numCategories);
    }

    // update emails
    for(int i=0; i < emails.size(); i++){
        emails[i].update();
    }
    
    // store number of categories to compare against
    oldNumCategories = numCategories;

    countReleased();



    // sound stuff
    //lets scale the vol up to a 0-1 range 
	scaledVol = ofMap(smoothedVol, 0.0, 0.17, 0.0, 1.0, true);
    
	//lets record the volume into an array
	volHistory.push_back( scaledVol );
	
	//if we are bigger the the size we want to record - lets drop the oldest value
	if( volHistory.size() >= 400 ){
		volHistory.erase(volHistory.begin(), volHistory.begin()+1);
	}   

    cout << int(scaledVol*100) << "\n";
    
    numCategories =int(scaledVol*100) + 1;
}


//--------------------------------------------------------------
void testApp::draw() {
    
    ofFill();

    // draw "pegs" at different category attraction points
	for (int i=0; i<numCategories; i++) {
        ofSetHexColor(0x282828);
        ofCircle(centerPoints[i].x, centerPoints[i].y, 4);
    }
    
    for(int i=0; i < emails.size(); i++){
        emails[i].drawMePlease();
    }
    
	// draw the ground
	box2d.drawGround();
	
	
    
	
	string info = "";
    info += "Current Volume: "+ofToString(numCategories)+"\n";
	ofSetHexColor(0x00bbbb);
	myFont.drawString(info, 40, 60);
	
    
	
}

//--------------------------------------------------------------

void testApp::addEmail(int _whichCategory){    
    
    float r = ofRandom(30, 50);		
    float rx = ofRandom(55, ofGetWidth()-55);		        
    float ry = ofRandom(10, ofGetHeight()-10);		        
    
       
    circle.setPhysics(.2, 0.05, .8);
    circle.setup(box2d.getWorld(), rx, ry, radius);
   
    
    circle.r = ofRandom(200,255);
    circle.g = ofRandom(100,200);
    circle.b = 0;
    circle.whichCategory = _whichCategory;
    circle.attractionPoint = centerPoints[_whichCategory];
    
    emails.push_back(circle);
   

}

//--------------------------------------------------------------


void testApp::resetAttractionPoints(int numCategories) {

    centerPoints.clear();
    for(int i=0; i<numCategories; i++) {
        if(numCategories < 6) {    
            if(numCategories==1){
                tempPoint.x = ofGetWidth()/2+xShift;
                tempPoint.y = ofGetHeight()/2-yShift;
                centerPoints.push_back(tempPoint);
            }
            else {
                tempPoint.x = ofGetWidth()/2 + defaultRingRadius*cos(i*PI*2/numCategories)+xShift;
                tempPoint.y = ofGetHeight()/2 + defaultRingRadius*sin(i*PI*2/numCategories)-yShift;
                centerPoints.push_back(tempPoint);
                //if only one category move to middle
            }
        }
        // if more than 5 categories, make use of center of screen
        else if(numCategories<9){
            if(i > 0){
                tempPoint.x = ofGetWidth()/2 + defaultRingRadius*cos(i*PI*2/(numCategories-1))+xShift;
                tempPoint.y = ofGetHeight()/2 + defaultRingRadius*sin(i*PI*2/(numCategories-1))-yShift;
            }
            else {
                tempPoint.x = ofGetWidth()/2+xShift;
                tempPoint.y = ofGetHeight()/2-yShift;
            }
            centerPoints.push_back(tempPoint);
        }
        else if(numCategories<14){
            if(i > 2){
                tempPoint.x = ofGetWidth()/2 + defaultRingRadius*cos(i*PI*2/(numCategories-3))+xShift;
                tempPoint.y = ofGetHeight()/2 + defaultRingRadius*sin(i*PI*2/(numCategories-3))-yShift;
            }
            else {
                tempPoint.x = ofGetWidth()/2 + innerRingRadius*cos(i*PI*2/(3))+xShift;
                tempPoint.y = ofGetHeight()/2 + innerRingRadius*sin(i*PI*2/(3))-yShift;
            }
            centerPoints.push_back(tempPoint);
        }

        else {
            if(i > 4){
                tempPoint.x = ofGetWidth()/2 + outerRingRadius*cos(i*PI*2/(numCategories-5))+xShift;
                tempPoint.y = ofGetHeight()/2 + outerRingRadius*sin(i*PI*2/(numCategories-5))-yShift;
            }
            else {
                tempPoint.x = ofGetWidth()/2 + innerRingRadius*1.2*cos(i*PI*2/(5))+xShift;
                tempPoint.y = ofGetHeight()/2 + innerRingRadius*1.2*sin(i*PI*2/(5))-yShift;
            }
            centerPoints.push_back(tempPoint);
        }
    }
    
}


//--------------------------------------------------------------


void testApp::applyNewAttractionPoints(int numCategories) {
    
    for(int i=0; i<emails.size(); i++){
        emails[i].isSettled = false;
        emails[i].whichCategory = i % numCategories;
        emails[i].attractionPoint = centerPoints[emails[i].whichCategory];
        
        emails[i].r = paletteColors[emails[i].whichCategory%20].r;
        emails[i].g = paletteColors[emails[i].whichCategory%20].g;
        emails[i].b = paletteColors[emails[i].whichCategory%20].b;
    }
}


//--------------------------------------------------------------

void testApp::keyPressed(int key) {
	
//	if(key == 'c') {
//		addEmail();
//    }
//	
	
	
	if(key == 't') ofToggleFullscreen();

    
    if(key == 'm'){
        numCategories++;
        for(int i=0; i < emails.size(); i++){
            emails[i].timeStamp = ofGetElapsedTimef();
        }
    }
    if(key == 'n'){
        if(numCategories > 1){
            numCategories--;   
            for(int i=0; i < emails.size(); i++){
                emails[i].timeStamp = ofGetElapsedTimef();
            }
        }
        
    }
    
    if(key == 'a'){
        xShift-=10;
        resetAttractionPoints(numCategories);
        applyNewAttractionPoints(numCategories);
        cout << xShift << ", " << yShift << "\n";
    }
    if(key == 's'){
        xShift+=10;
        resetAttractionPoints(numCategories);
        applyNewAttractionPoints(numCategories);
        cout << xShift << ", " << yShift << "\n";
    }
    if(key == 'w'){
        yShift+=10;
        resetAttractionPoints(numCategories);
        applyNewAttractionPoints(numCategories);
        cout << xShift << ", " << yShift << "\n";
    }
    if(key == 'z'){
        yShift-=10;
        resetAttractionPoints(numCategories);
        applyNewAttractionPoints(numCategories);
        cout << xShift << ", " << yShift << "\n";
    }
    
    if(key == 'o'){
        unitRadius-=10;
        resetAttractionPoints(numCategories);
        applyNewAttractionPoints(numCategories);
        cout << "unit radius: " << unitRadius << "\n";
    }
    if(key == 'p'){
        unitRadius+=10;
        resetAttractionPoints(numCategories);
        applyNewAttractionPoints(numCategories);
        cout << "unit radius: " << unitRadius << "\n";
    }

}

//--------------------------------------------------------------
void testApp::countReleased() {
    saved = 0;
    trash = 0;
    
    for(int i=0; i< emails.size(); i++){
        if (emails[i].isSaved) saved++;
        if (emails[i].isTrash) trash++;        
    }
    
}

//--------------------------------------------------------------


void testApp::loadColors() {
    
    
    paletteColors[0].set(237, 0, 140); 
	paletteColors[1].set(185, 27, 150);
	paletteColors[2].set(105, 82, 164);
	paletteColors[3].set(129, 135, 187);
	paletteColors[4].set(46, 90, 153);
	paletteColors[5].set(88, 132, 195);
	paletteColors[6].set(0, 173, 239);
	paletteColors[7].set(47, 112, 154);
    paletteColors[8].set(0, 147, 157);
    paletteColors[9].set(95, 181, 146);
    paletteColors[10].set(0, 153, 73);
    paletteColors[11].set(120, 191, 69);
    paletteColors[12].set(186, 212, 50);
    paletteColors[13].set(255, 243, 63);
    paletteColors[14].set(255, 209, 2);
    paletteColors[15].set(251, 171, 30);
    paletteColors[16].set(241, 139, 33);
    paletteColors[17].set(243, 110, 35);
    paletteColors[18].set(240, 64, 41);
    paletteColors[19].set(240, 64, 41);

}


//--------------------------------------------------------------

int testApp::indexForCategory(string catString) {
    if(catString == "Sports") {
        return 0;
    }
    else if(catString == "World") {
        return 1;        
    }
    else if(catString == "Business Day") {
        return 2;        
    }
    else if(catString == "U.S.") {
        return 3;        
    }
    else if(catString == "Education") {
        return 4;        
    }
    else if(catString == "Health") {
        return 5;        
    }
    else if(catString == "Technology") {
        return 6;        
    }
    else if(catString == "Theater") {
        return 7;        
    }
    else if(catString == "N.Y. / Region") {
        return 8;        
    }
    else if(catString == "Opinion") {
        return 9;        
    }
    else if(catString == "Business") {
        return 10;        
    }
    else if(catString == "Movies") {
        return 11;        
    }
    else if(catString == "Magazine") {
        return 12;        
    }
    else if(catString == "Fashion & Style") {
        return 13;        
    }
    else if(catString == "Books") {
        return 14;        
    }
    else if(catString == "Arts") {
        return 15;        
    }
    else if(catString == "Real Estate") {
        return 16;        
    }
    else if(catString == "Science") {
        return 17;        
    }
    else if(catString == "T:Style") {
        return 18;        
    }
    else if(catString == "Corrections") {
         return 19;       
    }
    else {
        return -1;
    }

}


//--------------------------------------------------------------
void testApp::audioIn(float * input, int bufferSize, int nChannels){	
	
	float curVol = 0.0;
	
	// samples are "interleaved"
	int numCounted = 0;	
    
	//lets go through each sample and calculate the root mean square which is a rough way to calculate volume	
	for (int i = 0; i < bufferSize; i++){
		left[i]		= input[i*2]*0.5;
		right[i]	= input[i*2+1]*0.5;
        
		curVol += left[i] * left[i];
		curVol += right[i] * right[i];
		numCounted+=2;
	}
	
	//this is how we get the mean of rms :) 
	curVol /= (float)numCounted;
	
	// this is how we get the root of rms :) 
	curVol = sqrt( curVol );
	
	smoothedVol *= 0.93;
	smoothedVol += 0.07 * curVol;
	
	bufferCounter++;
	
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













