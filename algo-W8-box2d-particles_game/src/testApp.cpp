#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup() {
	
	ofSetVerticalSync(true);
	ofBackgroundHex(0x111130);
	ofSetLogLevel(OF_LOG_NOTICE);
    
    ofEnableAlphaBlending();
    
    
    ofTrueTypeFont::setGlobalDpi(72);
    
    myFont.loadFont("GothamHTF-Bold.otf", 29, true, true, true);

    
    
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
    
    allFinished = false;
    introMessage = true;

    
    
	numEmailsStart = 5;
    numCategories = 5;

    radius = 40;
    
    unitRadius = 160;

    xShift = 00;
    yShift = 00;
    
    saved = 0;
    trash = 0;
    
	box2d.init();
	box2d.setFPS(30.0);
    box2d.registerGrabbing();
    box2d.setGravity(0,0);
    box2d.createBounds(0,0,ofGetWidth(),ofGetHeight());
		

    
    for(int i=0; i<numCategories; i++) {
        resetAttractionPoints(numCategories);
    }
   
    // add email/circles to world
	for (int i=0; i < numEmailsStart; i++) {
        addEmail(i % numCategories);
        emails[i].setInitialConditions();
    }
    

    
    
}


//--------------------------------------------------------------


void testApp::update() {

    innerRingRadius = unitRadius;
    defaultRingRadius = 2.5 * unitRadius;
    outerRingRadius = 2.8 * unitRadius;
    
    if(ofGetElapsedTimef()>8){
        introMessage = false;
    }

	
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
    
    gravity.x = sin(ofGetElapsedTimef())*10-1;
    gravity.y = cos(ofGetElapsedTimef())*10;
    

    
    box2d.setGravity(gravity.x,gravity.y);
    
    // update emails
    for(int i=0; i < emails.size(); i++){
        if(emails[i].isSaved) {
            allFinished = false;
        }
        else {
            allFinished = true;
        }
    }

}


//--------------------------------------------------------------
void testApp::draw() {
    
    ofFill();

    // draw "pegs" at different category attraction points
	for (int i=0; i<numCategories; i++) {
        ofSetHexColor(0x282828);
        ofCircle(centerPoints[i].x, centerPoints[i].y, 8);
    }
    
    for(int i=0; i < emails.size(); i++){
        emails[i].drawMePlease();
    }
    
	// draw the ground
	box2d.drawGround();
	
	
    
	
//	string info = "";
//	info += "Total Unread: "+ofToString(emails.size())+"\n";
//	info += "Total Saved: "+ ofToString(saved) +"\n\n";
//	info += "Total Trashed: "+ ofToString(trash) + "\n";
//	info += "Number of categories: "+ofToString(numCategories)+"\n";
	ofSetHexColor(0x00bbbb);

	
    
    if (introMessage){
        myFont.drawString("Sort the kittens by dragging them to their homes!", 200, 60);
    }

    
    if (allFinished){
        myFont.drawString("Great work! You brought all the kittens back home!", 200, 60);
    }
    
}

//--------------------------------------------------------------

void testApp::addEmail(int _whichCategory){    
    
    float r = ofRandom(30, 50);		
    float rx = ofRandom(400, ofGetWidth()-400);		        
    float ry = ofRandom(400, ofGetHeight()-400);		        
    
       
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
        
        emails[i].r = paletteColors[emails[i].whichCategory].r;
        emails[i].g = paletteColors[emails[i].whichCategory].g;
        emails[i].b = paletteColors[emails[i].whichCategory].b;
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
void testApp::keyReleased(int key) {
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ) {
	
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button) {

    for(int i=0; i< emails.size(); i++){
        if(ofDist(mouseX, mouseY, emails[i].getPosition().x, emails[i].getPosition().y)<radius){
            emails[i].isSettled = true;
        }
    }

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













