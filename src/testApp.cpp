#include "testApp.h"


//--------------------------------------------------------------
void testApp::setup()
{
	

	//construct new PCA9685 object with the number of boards you're using
	numBoards = 2;
	pca = new PCA9685(numBoards);

	//on start-up, run through light test
	testLights();

	
    ofSetVerticalSync(false);
	

    noiseSpeedX = 0.01;
    noiseSpeedY = 0.01;
    noiseAmp = 4095;
    
    time = 0;
    timeInc = 0.1;

	

}


//--------------------------------------------------------------
void testApp::update()
{
	
//////////////////Prod Section //////////////////
    makeNoise();
    runLights(br);
    ofLog() << ofGetFrameRate() ;  
}


///////////////////////// NOISE ///////////////////////////////////
void testApp::makeNoise(void)
{
    for(int i = 0; i < 30; i++)
    {
        noiseVal[i] = abs(noiseAmp * ofNoise(time * noiseSpeedX*(i+10), time*noiseSpeedY*(10-i)));
       // ofLog() << "index: " << i << " || value: " << noiseVal[i];
    }
    time += timeInc;
}




////////////////////// RUN LIGHTS //////////////////////////////////
void testApp::runLights(float br[])
{
	int lightBright[16*numBoards];
	for(int i = 0; i <30; i++)
    {
    	lightBright[i] = noiseVal[i];
    	
    	//pca->setLED(i, br[i]);				//video only
    	//pca->setLED(i, noiseVal[i]);			//noise only
    	pca->setLED(i, lightBright[i]);			//video and noise
    	

    	//ofLog() << "channel: " << i << " value: " << noiseVal[i];
    }
}





//--------------------------------------------------------------
void testApp::draw(){
	
	
}


void testApp::testLights(void)
{
	for(int val = 1; val < 4096; val+=20)
	{
	    for(int i = 0; i < 16*numBoards; i++)
	    {
		    pca->setLED(i, val); 
		    ofLog() << "testing: " << i << "value: " << val;
	    }
	}
}


