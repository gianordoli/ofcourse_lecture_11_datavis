//
//  City.cpp
//  example_5_drawBar
//
//  Created by Gabriel Gianordoli on 9/20/14.
//
//

#include "City.h"

void City::setup(string _url, string _name, int _i, int _numCities){
    name = _name;
    cityIndex = _i;
    parseData(_url);
    
    highColor.setHsb(ofMap(_i, 0, _numCities - 1, 0, 160),
                     255, 255);
    lowColor.setHsb(ofMap(_i, 0, _numCities - 1, 0, 160),
                    255, 200);
    
    isVisible = true;
}

void City::update(){
    
}

void City::draw(string _chartType, bool _drawValues){
    
    // Label
    ofPoint pos;
    pos.set(10, (cityIndex + 1) * 20);
    ofSetColor(highColor);
    ofDrawBitmapString("[" + ofToString(cityIndex + 1) + "] " + name, pos);
    
    // Chart
    if(isVisible){
        if (_chartType == "line"){
            drawLineChart(_drawValues);
        }else if(_chartType == "area"){
            drawAreaChart(_drawValues);
        }else if(_chartType == "bar"){
            drawBarChart(_drawValues);
        }
    }
}

void City::setLayout(ofPoint _chartPos, ofPoint _chartSize, float _highestTemp, float _lowestTemp){
    chartPos = _chartPos;
    chartSize = _chartSize;
    highestTemp = _highestTemp;
    lowestTemp = _lowestTemp;
}

void City::drawBarChart(bool _drawValues){
    
    ofFill();
    
    for(int i = 0; i < highs.size(); i++){
        
        ofPoint pos, size;

        size.x = 10;
        
        size.y = ofMap(highs[i] - lows[i],
                      0, highestTemp - lowestTemp,
                      0, chartSize.y);
        
        pos.x = ofMap(i,
                      0, highs.size()-1,
                      chartPos.x, chartPos.x + chartSize.x);

        pos.x += size.x * cityIndex;
        
        pos.y = ofMap(highs[i],
                      lowestTemp, highestTemp,
                      chartPos.y + chartSize.y, chartPos.y);

        ofSetColor(highColor);
        ofRect(pos, size.x, size.y);

        if(_drawValues){
            // TEXT: high
            ofSetColor(255);
            pos.x -= 5;
            ofDrawBitmapString(ofToString(highs[i]), pos);
            
            // TEXT: low
            pos.y = ofMap(lows[i],
                          lowestTemp, highestTemp,
                          chartPos.y + chartSize.y, chartPos.y);
            pos.y += 10;
            
            ofDrawBitmapString(ofToString(lows[i]), pos);
        }
    }
    
}

void City::drawAreaChart(bool _drawValues){

    ofFill();
    
    // HIGH
    ofSetColor(255);
    ofBeginShape();
    for(int i = 0; i < highs.size(); i++){
        ofPoint pos;
        pos.x = ofMap(i,
                      0, highs.size()-1,
                      chartPos.x, chartPos.x + chartSize.x);
        
        pos.y = ofMap(highs[i],
                      lowestTemp, highestTemp,
                      chartPos.y + chartSize.y, chartPos.y);
        ofVertex(pos);
        
        if(_drawValues){
            ofDrawBitmapString(ofToString(highs[i]), pos);
        }
    }
    
    // LOW
    for(int i = lows.size() - 1; i >= 0 ; i--){
        ofPoint pos;
        pos.x = ofMap(i,
                      0, lows.size()-1,
                      chartPos.x, chartPos.x + chartSize.x);
        
        pos.y = ofMap(lows[i],
                      lowestTemp, highestTemp,
                      chartPos.y + chartSize.y, chartPos.y);
        ofVertex(pos);
        
        if(_drawValues){
            ofDrawBitmapString(ofToString(lows[i]), pos);
        }
    }
    
    ofColor areaColor = highColor;
    areaColor.a = 100;
    ofSetColor(areaColor);

    ofEndShape(true);
}


void City::drawLineChart(bool _drawValues){
    
    
    ofNoFill();
    ofSetLineWidth(2);
    
    // HIGH
    ofSetColor(highColor);
    ofBeginShape();
    for(int i = 0; i < highs.size(); i++){
        ofPoint pos;
        pos.x = ofMap(i,
                      0, highs.size()-1,
                      chartPos.x, chartPos.x + chartSize.x);
        
        pos.y = ofMap(highs[i],
                      lowestTemp, highestTemp,
                      chartPos.y + chartSize.y, chartPos.y);
        ofVertex(pos);
        
        if(_drawValues){
            ofDrawBitmapString(ofToString(highs[i]), pos);
        }
    }
    ofEndShape();
    
    // LOW
    ofSetColor(lowColor);
    ofBeginShape();
    for(int i = 0; i < lows.size(); i++){
        ofPoint pos;
        pos.x = ofMap(i,
                      0, lows.size()-1,
                      chartPos.x, chartPos.x + chartSize.x);
        
        pos.y = ofMap(lows[i],
                      lowestTemp, highestTemp,
                      chartPos.y + chartSize.y, chartPos.y);
        ofVertex(pos);
        
        if(_drawValues){
            ofDrawBitmapString(ofToString(lows[i]), pos);
        }
    }
    ofEndShape();
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