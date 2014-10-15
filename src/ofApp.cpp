#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    cam.enableMouseInput();
    cam.enableMouseMiddleButton();
    image.loadImage("topography1.jpeg");
    light.enable();

    ofBackground(255);

    gui.setup();
    gui.add(noiseSeedValue.setup("noise Seed", 0.01, 0.001, 0.1));
    gui.add(noiseSeedValue2.setup("noise Seed", 0.01, 0.001, 0.1));

}

//--------------------------------------------------------------
void ofApp::update(){

    int particleCount = ofGetWidth() * 10;
    float posX0 = 593.2;
    float posY0 = 43.7;
    
    for ( int y=0;y<ofGetHeight();y+=2){
        for (int x =0; x<ofGetWidth(); x+=2) {
            float value = ofNoise(x*noiseSeedValue + posX0, y*noiseSeedValue2+posY0, ofGetElapsedTimef()/4*0.6);
            colors.push_back(ofColor(40,value*200, value*255));
            field_x.push_back(ofVec3f(x,y,value * 255));

        }
    }

}

//--------------------------------------------------------------
void ofApp::draw(){

    gui.draw();
    cam.begin();
    ofMesh mesh;
    mesh.setMode(OF_PRIMITIVE_POINTS);
    

    int forindex = 0;
    for (int i=0; i<field_x.size(); i++) {
        if (forindex > 2) {
            forindex = 0;
        }

        mesh.addVertex(field_x[i]);
        mesh.addColor(colors[i]);
//        mesh.addColor(0);
//        mesh.addIndex(i-1);
//        mesh.addIndex(i);
    }

    
    field_x.clear();
    colors.clear();
    
    
    mesh.draw();
    
    
    cam.end();
}


void ofApp::setNormals(ofMesh &mesh){
    int nV = mesh.getNumVertices();
    int nT = mesh.getNumIndices();
    
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
//    ok = false;

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
//    ok = true;
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
