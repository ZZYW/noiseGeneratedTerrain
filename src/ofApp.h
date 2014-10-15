#pragma once

#include "ofMain.h"
#include "ofxGui.h"

class ofApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    void setNormals(ofMesh &mesh);
    
    vector<ofVec3f> field_x;
    vector<ofVec3f> field_y;
    vector<ofColor> colors;
    ofEasyCam cam;
    
    //GUI
    ofxFloatSlider noiseSeedValue;
    ofxFloatSlider noiseSeedValue2;
    ofxPanel gui;
    
    ofImage image;
    ofMesh mesh;
    ofLight light;
    
};
