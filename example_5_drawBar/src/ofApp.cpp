/*-------------------------------------------------------------
 [ofCourse] Lecture 11: Data Visualization
 Gabriel Gianordoli - github.com/gianordoli
 --------------------------------------------------------------*/

#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    //    ofEnableBlendMode(OF_BLENDMODE_ADD);
    //    ofEnableBlendMode(OF_BLENDMODE_SCREEN);
    
    
    /*---------- DATA ----------*/
    
    // Comment this out... -------------------------
    ofBuffer file = ofBufferFromFile("api_key.txt");
    string apiKey = file;
    // ---------------------------------------------
    
    // ...and replace the apiKey variable with your own api key: --------------------------------
    string apiUrl = "http://api.wunderground.com/api/" + apiKey + "/conditions/forecast10day/q/";
    // ------------------------------------------------------------------------------------------
    
    string citiesUrls[NUM_CITIES] = {"NY/New_York.json",
        "CA/san_francisco.json",
        "China/shanghai.json",
        "Mexico/mexico_city.json",
        "Brazil/sao_paulo.json"};
    
    string citiesNames[NUM_CITIES] = {"New York", "San Francisco","Shanghai", "Mexico City", "Sao Paulo"};
    
    // Actually loading the data by passing an url to the City object
    for (int i = 0; i < NUM_CITIES; i++) {
        City thisCity;
        thisCity.setup(apiUrl + citiesUrls[i], citiesNames[i], i, NUM_CITIES);
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
    
    drawValues = true;
    
    chartType = 0;
}

//--------------------------------------------------------------
void ofApp::update(){
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(0);
    
    //    ofNoFill();
    //    ofRect(chartPos, chartSize.x, chartSize.y);
    ofSetColor(255);
    ofDrawBitmapString("Press space to toggle values visibility.\nPress numbers from 0 to " + ofToString(NUM_CITIES) + " to toggle city visibility.\nTo alternate chart types, press LEFT and RIGHT arrow keys.", 20, ofGetHeight() * 0.93);
    
    
    for(int i = 0; i < allCities.size(); i++){
        switch (chartType) {
            case 0:
                allCities[i].draw("line", drawValues);
                break;

            case 1:
                allCities[i].draw("area", drawValues);
                break;
                
            default:
                allCities[i].draw("bar", drawValues);
                break;
        }
    }
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
//    cout << key << endl;
    
    // Show/hide values
    if(key == ' '){
        drawValues = (drawValues == true) ? (false) : (true);
    
    // Show/hide cities
    }else if(key >= 49 && key < 49 + NUM_CITIES){
        int nCity = key - 49;
        // A short switch!
        allCities[nCity].isVisible = (allCities[nCity].isVisible == true) ? (false) : (true);
    
    // Change chart type
    }else if(key == OF_KEY_LEFT || OF_KEY_RIGHT){
        if (key == OF_KEY_LEFT) {
            chartType --;
        }else if(key == OF_KEY_RIGHT){
            chartType ++;
        }
        if(chartType < 0){
            chartType = 2;
        }else if (chartType > 2){
            chartType = 0;
        }
    }
    
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
