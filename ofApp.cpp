#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofSetWindowTitle("openframeworks");

	ofBackground(239);
	ofSetColor(39);
}
//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {

	for (int x = 60; x < ofGetWidth(); x += 120) {

		for (int y = 60; y < ofGetHeight(); y += 120) {

			this->draw_coffee(ofPoint(x, y));
		}
	}
}

//--------------------------------------------------------------
void ofApp::draw_coffee(ofPoint point) {

	ofPushMatrix();
	ofTranslate(point);

	int radius = 50;

	ofBeginShape();
	for (int deg = 0; deg <= 180; deg += 1) {

		ofVertex(radius * cos(deg * DEG_TO_RAD), radius * sin(deg * DEG_TO_RAD));
	}

	for (float x = -radius; x < radius; x += 1) {

		int y = ofMap(ofNoise((point.x + x) * 0.01 + ofGetFrameNum() * 0.03, point.y * 0.008), 0, 1, 0, -30);
		ofVertex(x, y);
	}
	ofEndShape(true);

	ofPopMatrix();
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}