#pragma once

#include "ofMain.h"
#include "PCA9685.h"

 // set to -1 to not use the enable pin (its optional)

class testApp : public ofBaseApp{

public:

	void setup();
	void update();
	void draw();
	void runLights(float br[]);
    void makeNoise(void);
    float stevensLaw(float val);
    
    void testLights(void);

	int val;
	int valInc;


	float br[30];
    float noiseVal[30];
	unsigned char* pixels;
	int cellSize;
	float cellSizeFl;
	int numPixels;

    float noiseSpeedX, noiseSpeedY, noiseAmp, time, timeInc;

	
	int numBoards;

	PCA9685* pca; //initialize the class with number of boards



	
};
