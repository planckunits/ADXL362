/*
 ADXL362_SimpleRead.ino -  Simple XYZ axis reading example
 for Analog Devices ADXL362 - Micropower 3-axis accelerometer
 go to https://www.analog.com/adxl362 for datasheet
 
 
 License: CC BY-SA 3.0: Creative Commons Share-alike 3.0. Feel free 
 to use and abuse this code however you'd like. If you find it useful
 please attribute, and SHARE-ALIKE!
 
 Created June 2012
 by Anne Mahaffey - hosted on https://github.com/annem/ADXL362

Connect SCLK, MISO, MOSI, and CSB of ADXL362 to
SCLK, MISO, MOSI, and DP 10 of Arduino 
(check http://arduino.cc/en/Reference/SPI for details)
 
*/ 

#include <SPI.h>
#include <ADXL362.h>


ADXL362 xl;

int temp;
int XValue, YValue, ZValue;

void setup(){
    Serial.begin(9600);
    xl.begin();                   // Setup SPI protocol, issue device soft reset
    xl.beginMeasure();            // Switch ADXL362 to measure mode  
    xl.checkAllControlRegs();     // Burst Read all Control Registers, to check for proper setup
	
    Serial.print("\n\nBegin Loop Function:\n");
}

void loop(){
    XValue = xl.readXData();
    YValue = xl.readYData();
    ZValue = xl.readZData();
    temp   = xl.readTemp();
  
    Serial.println();
    delay(100);                // Arbitrary delay to make serial monitor easier to observe
}


