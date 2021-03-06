#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup() {
	
	ofSetVerticalSync(true);
	ofSetLogLevel(OF_LOG_NOTICE);
    
    ofEnableAlphaBlending();

	ofBackgroundHex(0x333333);
    bgImage.loadImage("bg.png");
   

    
    loadColors();
    sortByCategory = false;
//    bool mousePressed = false;
    
    ofTrueTypeFont::setGlobalDpi(72);

    myFont.loadFont("GothamHTF-Bold.otf", 29, true, true, true);
    myFontMed.loadFont("GothamHTF-Bold.otf", 18, true, true, true);
    myFontSmall.loadFont("GothamHTF-Bold.otf", 14, true, true, true);

    myFont.setLineHeight(28.0f);
    myFontSmall.setLineHeight(18.0f);
	myFontMed.setLetterSpacing(.95);

    
  //  myFont.loadFont("GothamHTF-Bold.otf", 32, true, true, true);
    
    typeString = "hiyoooo";
    
    // load NYTimes data
    dataString = fileLoader.loadFromUrl("http://localhost/algo/algo-dummy_data.txt");
    //dataString = fileLoader.loadFromUrl("http://localhost/algo/algo-NYTimes_API_data.php");
    
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
    numCategoriesStart = 20;
    numCategories = 20;
    
    radius = 17;
    
    unitRadius = 110;

    xShift = 0;
    yShift = 20;
    
    saved = 0;
    trash = 0;
    
	box2d.init();
	box2d.setFPS(30.0);
    box2d.registerGrabbing();
    box2d.setGravity(0,0);
    box2d.createBounds(0,0,ofGetWidth()+1000,ofGetHeight());
		

    
    for(int i=0; i<numCategoriesStart; i++) {
   //     resetAttractionPoints(numCategories);
        catHasArticles[i] = false;
    }
   
    // add email/circles to world
	for (int i=0; i < numEmailsStart; i++) {
       if(nestedResults[i].size() > 0) {    
            if(indexForCategory(nestedResults[i][CATEGORY]) > -1){
              //  addEmail(i%numCategories);
                addEmail(indexForCategory(nestedResults[i][CATEGORY]), i);
                
                // keeping track of which articles actually have articles in them
                catHasArticles[indexForCategory(nestedResults[i][CATEGORY])] = true;
            }
        }
    }
    
    for (int i=0; i<emails.size(); i++) {
        emails[i].setInitialConditions();
    }
    
    //now keep track of reverse (what index is for current category)
    for(int i=0; i<numCategoriesStart; i++) {
        if(catHasArticles[i] == true){
            categoriesWithArticles.push_back(i);
            currentCategoryKeys[i] = categoriesWithArticles.size() -1;
        }
        else {
            currentCategoryKeys[i] = -1;
        }
    }
    
    
    for(int i=0; i<numCategoriesStart; i++) {
        cout << currentCategoryKeys[i] << "\n";
    }

    numCategories = categoriesWithArticles.size();
    
    for (int i = 0; i < numCategories ; i++) {
         resetAttractionPoints(numCategories);
    }
    ;
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
        emails[i].checkHovering(mouseX, mouseY, isClickedOn);
        emails[i].update();
    }
    
    // store number of categories to compare against
    oldNumCategories = numCategories;

    countReleased();
    

}


//--------------------------------------------------------------
void testApp::draw() {

    ofBackgroundHex(0x333333);

    ofNoFill();
    ofSetColor(255, 255, 255);
    
    bgImage.draw(0,0);
    
  //  myFont.drawString(typeString, 100, 100);

    
    ofFill();

    // draw "pegs" at different category attraction points
//	for (int i=0; i<numCategories; i++) {
//        ofSetHexColor(0x282828);
//        ofCircle(centerPoints[i].x, centerPoints[i].y, 8);
//    }
    
    for(int i=0; i < emails.size(); i++){
        emails[i].drawMePlease();
    }

    for(int i=0; i < emails.size(); i++){
        if(emails[i].isHovering && emails[i].isSaved == false) {
            emails[i].hoverTitle(myFontMed, myFontSmall);
        }
        if(emails[i].isSaved && emails[i].getPosition().x < emails[i].getRadius() + 5){
            emails[i].displaySavedTitle(myFontSmall);
        }
        if(emails[i].showSavedAb){
            emails[i].displaySavedAbstract(myFontSmall);
        }
    }

    
	ofSetHexColor(0x999999);
	
	string info = "";
	info += ofToString(emails.size())+"\n";
    myFont.drawString(info, ofGetWidth()-70, 47);	
    
    info = ofToString(saved) +"\n";
    myFont.drawString(info, ofGetWidth()-42, 46+29);

    info = ofToString(trash) +"\n";
    myFont.drawString(info, ofGetWidth()-64, 46+2*29);	
    
    info = ofToString(numCategories) +"\n";
    myFont.drawString(info, ofGetWidth()-82, 46+4*29-2);	
    
	
}

//--------------------------------------------------------------

void testApp::addEmail(int _whichCategory, int index){    
    
    float r = ofRandom(30, 50);		
    float rx = ofRandom(55, ofGetWidth()-55);		        
    float ry = ofRandom(10, ofGetHeight()-10);		        
    
       
    circle.setPhysics(.2, 0.05, .8);
    circle.setup(box2d.getWorld(), rx, ry, radius);
   
    
    circle.r = ofRandom(200,255);
    circle.g = ofRandom(100,200);
    circle.b = 0;
    
    circle.whichCategory = _whichCategory;
    
    circle.catName = nestedResults[index][CATEGORY];
    circle.title = nestedResults[index][TITLE];
    circle.abstract = nestedResults[index][ABSTRACT];
    circle.url = nestedResults[index][URL];
    circle.byline = nestedResults[index][BYLINE];
    circle.hasImg = nestedResults[index][HAS_IMG];
    circle.imgURL = nestedResults[index][IMG_URL];

    emails.push_back(circle);
   

}

//--------------------------------------------------------------


void testApp::assignDetailsInfo(int _i){
    

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
 //       emails[i].whichCategory = i % numCategories;
        emails[i].attractionPoint = centerPoints[currentCategoryKeys[emails[i].whichCategory]];
//        emails[i].attractionPoint.x = 400;
//        emails[i].attractionPoint.y = 400;
//        
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
	
    isClickedOn =  false;

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button) {
    isClickedOn = !isClickedOn;
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button) {
    isClickedOn =  false;
    
    for(int i=0; i<emails.size(); i++){
        if(ofDist(mouseX, mouseY, emails[i].getPosition().x, emails[i].getPosition().y) <= emails[i].getRadius()){
            emails[i].clickHold = !emails[i].clickHold;
        }
    }


}

//--------------------------------------------------------------
void testApp::resized(int w, int h){
}













