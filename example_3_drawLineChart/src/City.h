//
//  City.h
//  example_3_drawLineChart
//
//  Created by Gabriel Gianordoli on 9/19/14.
//
//
#pragma once
#include "ofMain.h"
#include "ofxJSON.h"

class City{
public:
    void setup(string _url, string _name, int _i, int _numCities);
    void update();
    void draw(string _chartType);
    
    void parseData(string _url);
    void setLayout(ofPoint _chartPos, ofPoint _chartSize, float _highestTemp, float _lowestTemp);
    void drawLineChart();
    
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
    
    //Visuals:
    ofColor highColor;
    ofColor lowColor;
};