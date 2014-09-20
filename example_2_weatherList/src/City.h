//
//  City.h
//  example_2_weatherList
//
//  Created by Gabriel Gianordoli on 9/19/14.
//
//
#pragma once
#include "ofMain.h"
#include "ofxJSON.h"

class City{
public:
    void setup(string _url, string _name);
    void update();
    void draw();
    
    void parseData(string _url);
    
    string name;
    
    // Let's create 2 lists
    vector<float> highs;        // high temperature
    vector<float> lows;         // low temperature
};