//
//  City.cpp
//  example_2_weatherList
//
//  Created by Gabriel Gianordoli on 9/19/14.
//
//

#include "City.h"

void City::setup(string _url, string _name){
    name = _name;
    parseData(_url);
}

void City::update(){
    
}

void City::draw(){

}

void City::parseData(string _url){
    ofxJSONElement response;
    
    /*--------------------------------------------------------------------------*/
    // Loading and displaying confirmation message
    /*--------------------------------------------------------------------------*/
    if (!response.open(_url)){
        cout << "Failed to parse JSON" << endl;
        
    }else{
        cout << "JSON loaded successfully" << endl;
        cout << "************************" << endl;
        
        // ofxJSON is doing all the heavy lifting of parsing the JSON
        // and allowing us to navigate through it:
        
        // City name is under response > current_observation > display_location > city
        cout << response["current_observation"]["display_location"]["city"].asString() << endl;
        
        // Current observation is under response > current_observation > temp_c or temp_f
        cout << "temperature in celsius now is: " << response["current_observation"]["temp_c"].asFloat() << endl;
        cout << "temperature in farenheit now is: " << response["current_observation"]["temp_f"].asFloat() << endl;
    }
    
    /*--------------------------------------------------------------------------*/
    // Loading weekday, and high and low temperature for each of the 10 days
    /*--------------------------------------------------------------------------*/
    
    // I know beforehand that there are 10 days, but it's always good to check!
    int nDays = response["forecast"]["simpleforecast"]["forecastday"].size();
    //    cout << nDays << endl;
    
    // Now looping through each day to get the high and low temperature values
    // Forecast day is an array, containing data for each day
    for(int i = 0; i < nDays; i++){
        
        
        // Somebody put QUOTES in the temperature response! So we need to load it
        // as a string first, and then convert it to float...
        
        // HIGH
        string thisHighString = response["forecast"]["simpleforecast"]["forecastday"][i]["high"]["fahrenheit"].asString();
        float thisHigh = ofToFloat(thisHighString);
        cout << thisHigh << endl;
        
        // LOW
        string thisLowString = response["forecast"]["simpleforecast"]["forecastday"][i]["low"]["fahrenheit"].asString();
        float thisLow = ofToFloat(thisLowString);
        cout << thisLow << endl;
        
        // Storing the data into our vectors
        highs.push_back(thisHigh);
        lows.push_back(thisLow);        
    }
}