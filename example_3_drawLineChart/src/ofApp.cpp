/*-------------------------------------------------------------
 [ofCourse] Lecture 11: Data Visualization
 Gabriel Gianordoli - github.com/gianordoli
 --------------------------------------------------------------*/

#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    /*---------- DATA ----------*/

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
    
    // Actually loading the data by passing an url to the City object
    for (int i = 0; i < 5; i++) {
        City thisCity;
        thisCity.setup(apiUrl + citiesUrls[i], citiesNames[i], i, 5);
        allCities.push_back(thisCity);
    }
    
    // Getting highest and lowest
    // We need to know the numbers range!
    float highestTemp = -1000; // Anything will be higher than this, so we don't risk setting up a value
    float lowestTemp = 1000;   // In this case, anything will be lower
    for(int i = 0; i < allCities.size(); i++){
        // HIGH
        for(int j = 0; j < allCities[i].highs.size(); j++){
            if(allCities[i].highs[j] > highestTemp){
                highestTemp = allCities[i].highs[j];
            }
        }
        // LOW
        for(int j = 0; j < allCities[i].lows.size(); j++){
            if(allCities[i].lows[j] < lowestTemp){
                lowestTemp = allCities[i].lows[j];
            }
        }
    }
    cout << "The highest temperature is: " << highestTemp << endl;
    cout << "The lowest temperature is: " << lowestTemp << endl;
    
    /*--------- LAYOUT ---------*/
    ofPoint chartSize = ofPoint(ofGetWidth() * 0.7, ofGetHeight() * 0.7);
    ofPoint chartPos = ofPoint(ofGetWidth() * 0.15, ofGetHeight() * 0.15);
    
    for(int i = 0; i < allCities.size(); i++){
        allCities[i].setLayout(chartPos, chartSize, highestTemp, lowestTemp);
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(0);
    
//    ofNoFill();
//    ofRect(chartPos, chartSize.x, chartSize.y);

    for(int i = 0; i < allCities.size(); i++){
        allCities[i].draw("line");
    }
    
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
