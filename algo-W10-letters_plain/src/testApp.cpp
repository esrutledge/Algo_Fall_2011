#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofSetFrameRate(60);
    myFont.loadFont("GothamHTF-Bold.otf", 80, true,true,true);
//    letter = 'R';
//    testChar = myFont.getCharacterAsPoints(letter);
//    
//    letterOutlines.push_back(testChar);
    
}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
    
    for(int j = 0; j < letterOutlines.size(); j++) {   
    
        ofPolyline line;
        
        for(int k = 0; k < 1; k++){
            //if( k!= 0)ofNextContour(true) ;
            for(int i = 0; i < (int)letterOutlines[j].getOutline()[k].size(); i++){
                ofPoint pos;
                pos.x = letterOutlines[j].getOutline()[k].getVertices()[i].x;
                pos.y = letterOutlines[j].getOutline()[k].getVertices()[i].y;
                
                line.addVertex(pos);
            }
        }
    
        // connect last point to first point
        ofPoint pos;
        pos.x = letterOutlines[j].getOutline()[0].getVertices()[0].x;
        pos.y = letterOutlines[j].getOutline()[0].getVertices()[0].y;
        line.addVertex(pos);

        
        ofPolyline lineResampled = line.getResampledBySpacing(10);
        
        
        ofSetColor(255);
        
        ofPushMatrix();
        ofTranslate(100 + 80*(j%10), 200 + int(j/10)*100);
        
        lineResampled.draw();
        for (int i = 0; i < lineResampled.getVertices().size(); i++){
            
            ofCircle(lineResampled.getVertices()[i].x, lineResampled.getVertices()[i].y, 3);
        }
        
        
        ofPopMatrix();
    }
    
    

}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
        typedLetters.push_back(key);
        cout << char(key);
        testChar = myFont.getCharacterAsPoints(char(key));
    
        letterOutlines.push_back(testChar);
    
    cout << letterOutlines.size();
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

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
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}