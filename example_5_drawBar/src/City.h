//
//  City.h
//  example_5_drawBar
//
//  Created by Gabriel Gianordoli on 9/20/14.
//
//

#pragma once
#include "ofMain.h"
#include "ofxJSON.h"

class City{
public:
    void setup(string _url, string _name, int _i, int _numCities);
    void update();
    void draw(string _chartType, bool _drawValues);
    
    void parseData(string _url);
    void setLayout(ofPoint _chartPos, ofPoint _chartSize, float _highestTemp, float _lowestTemp);
    void drawLineChart(bool _drawValues);
    void drawAreaChart(bool _drawValues);
    void drawBarChart(bool _drawValues);
    
    string name;
    int cityIndex;
    int numCities;
    ofPoint chartPos;
    ofPoint chartSize;
    float highestTemp;
    float lowestTemp;
    
    // Let's create 2 lists:
    vector<float> highs;        // high temperature
    vector<float> lows;         // low temperature
    
    // Visuals:
    ofColor highColor;
    ofColor lowColor;
    
    // Interaction
    bool isVisible;
};