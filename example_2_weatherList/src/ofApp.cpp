/*-------------------------------------------------------------
 [ofCourse] Lecture 11: Data Visualization
 Gabriel Gianordoli - github.com/gianordoli
 --------------------------------------------------------------*/

#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    // Comment this out... -------------------------
    ofBuffer file = ofBufferFromFile("api_key.txt");
    string apiKey = file;
    // ---------------------------------------------
    
    // ...and replace the apiKey variable with your own api key: --------------------------------
    string apiUrl = "http://api.wunderground.com/api/" + apiKey + "/conditions/forecast10day/q/";
    // ------------------------------------------------------------------------------------------
    
    string citiesUrls[5] = {"NY/New_York.json",
                           "CA/san_francisco.json",
                           "China/shanghai.json",
                           "Mexico/mexico_city.json",
                           "Brazil/sao_paulo.json"};

    string citiesNames[5] = {"New York", "San Francisco","Shanghai", "Mexico City", "Sao Paulo"};
    
    for (int i = 0; i < 5; i++) {
        City thisCity;
        thisCity.setup(apiUrl + citiesUrls[i], citiesNames[i]);
        allCities.push_back(thisCity);
    }
    
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
