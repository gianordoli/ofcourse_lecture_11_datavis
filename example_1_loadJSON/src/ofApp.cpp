/*-------------------------------------------------------------
 [ofCourse] Lecture 11: Data Visualization
 Gabriel Gianordoli - github.com/gianordoli
 --------------------------------------------------------------*/

#include "ofApp.h"

void ofApp::setup(){

    // Comment this out... -------------------------
    ofBuffer file = ofBufferFromFile("api_key.txt");
    string apiKey = file;
    // ---------------------------------------------
    
    // ...and replace the apiKey variable with your own api key: --------------------------------
    string apiUrl = "http://api.wunderground.com/api/" + apiKey + "/conditions/forecast10day/q/NY/New_York.json";
    // ------------------------------------------------------------------------------------------
    
    // /conditions/ returns the current weather only
    // /forecast1oday/ returns forecast for: current day's periods + next 10 days
    // Paste the url into firefox to better visualize the JSON response!
    
    if (!response.open(apiUrl)){
        cout << "Failed to parse JSON" << endl;
        
    }else{
        cout << "JSON loaded successfully" << endl;
        cout << "************************" << endl;
        
        // ofxJSON is doing all the heavy lifting of parsing the JSON
        // and allowing us to navigate through it.
        
        // City name is under response > current_observation > display_location > city
        cout << response["current_observation"]["display_location"]["city"].asString() << endl;
        
        // Current observation is under response > current_observation > temp_c or temp_f
        cout << "temperature in celsius now is: " << response["current_observation"]["temp_c"].asFloat() << endl;
        cout << "temperature in farenheit now is: " << response["current_observation"]["temp_f"].asFloat() << endl;
    }
}


void ofApp::draw(){
    ofBackground(0);
}
