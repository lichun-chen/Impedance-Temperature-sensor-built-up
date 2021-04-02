// Header File for AD5933 Library
// Author: Lichun Chen

#ifndef AD5933_Head // Pre-Processing code to prevent from duplicate declaration.
#define AD5933_Head

#include<math.h> // for math functions
#include<Wire.h> // for I2C communications
#include<Arduino.h> // For access to hardware pins

const int AD5933_ADR = 0x0D; // Device Serial Bus Address
const int BLOCK_READ_CODE = 0xA1; // Command Code for block read.

const int INIT_START_FREQ = 1; //1=1, defined values for Control Register
const int START_FREQ_SWEEP = 2; //2=10
const int INCR_FREQ = 3; //3=11
const int REPEAT_FREQ = 4; //4=100
const int POWER_DOWN = 10; //10=1010
const int STAND_BY = 11; //11=1011
const int TEMP_MEASURE = 9; //9=1001

const int RANGE_1 = 1; // constants for setting "range" (voltage amplitude to inject into subject)
const int RANGE_2 = 2;
const int RANGE_3 = 3;
const int RANGE_4 = 4;

const int GAIN_1 = 1; // constants for PGA gain inside
const int GAIN_5 = 5;

typedef uint8_t byte; // For the compatibility for Arduino Type Definitions

class AD5933_Class
{
public: 
	int delayTimeInit; // for setting delay time.

	double getTemperature();
  int getByte(int);
  bool blockRead(int, int, byte *);
  
	bool tempUpdate();
	bool resetAD5933();

	bool setExtClock(bool);
	bool setSettlingCycles(int, byte);

	bool setStartFreq(long);
	bool setStepSizeInHex(long);
	bool setNumofIncrement(byte);

	bool setCtrMode(byte);
	bool setCtrMode(byte, int);

	bool setPGA(byte);
	bool setPGA(byte, int);

	bool setRange(byte);
	bool setRange(byte, int);

  inline byte getStatusReg()
  {
    return (getByte(0x8F) & 0x07);// 0x07=111
  }

  inline double getMag(int cReal, int cImag)
  {
    return sqrt( ( square(cReal) + square(cImag)) );
  } 

private:	// Internal fucntions and variables used within the library

	static const byte Address_Ptr = 0xB0; 	// Address Pointer to read register values.
	double opClock; 						// Internal Variable for operating clock
	long incrHex;							// Internal Variable for hex value of increment
	byte numIncrement;						// Internal Variable for value of # of increment
	bool setByte(int, int); //int getByte(int);

};

extern AD5933_Class AD5933;

#endif
