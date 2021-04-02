
#include "AD5933.h"
#include <Arduino.h> // For the compatibility with Arduino Conventions.

AD5933_Class AD5933;

//Function to get the contents of a register address via I2C
int AD5933_Class::getByte(int address) {

  int rxByte;

  if ( !setByte(Address_Ptr, address))
    return false;
  Wire.requestFrom(AD5933_ADR, 1); // Request the value of the written address.

  if (1 <= Wire.available()) { // If the MCU get the value,
    rxByte = Wire.read(); // Read the value.
  }
  else {
    rxByte = -1; // Returns -1 if fails.
  }
  return rxByte;
}

// Function to write values to an I2C address
bool AD5933_Class::setByte(int address, int value) // variables are "address & value" OR "command code & address"
{
  Wire.beginTransmission(AD5933_ADR); // Begin I2C Transmission.
  Wire.write(address); // Write Address
  Wire.write(value); // Write Value
  int i2cReturn = Wire.endTransmission(); // Terminate the transmission.

  if (i2cReturn)
  {
    return false;
  }
  else
  {
    return true;
  }
}

// Reads a block of data from the AD5933
bool AD5933_Class::blockRead(int address, int num2Read, byte *toSave)
{
  if ( !AD5933.setByte(Address_Ptr, address) )
    return false;
  if ( !AD5933.setByte(BLOCK_READ_CODE, num2Read) )
    return false;

  for (byte t1 = 0; t1 < num2Read; t1++)
  {
    Wire.requestFrom(AD5933_ADR, 1); // Request the value of the written address.

    if (1 <= Wire.available()) { // If the MCU get the value,
      toSave[t1] = Wire.read(); // Read the value.
    }
    else {
      toSave[t1] = -1; // Returns -1 if fails.
      return false;

    }
  }
  return true;
}

//Gets the temperature of the AD5933
double AD5933_Class::getTemperature() {

	if ( tempUpdate() == false )
		return -1;

	int tTemp[2];
	long tTempVal;
	double cTemp;

	tTemp[0] = getByte(0x92);
	tTemp[1] = getByte(0x93);
	tTempVal = (tTemp[0] % (12 * 16)) * 16 * 16 + tTemp[1];
	if (bitRead(tTemp[0], 5) == 0)
	{
		// Positive Formula
		cTemp = (double)tTempVal / 32;
	}
	else
	{
		// Negative Formula
		cTemp = (tTempVal - 16384.0) / 32;
	}
	return cTemp;
}

//Updates temperature information without writing to a variable
bool AD5933_Class::tempUpdate() {

	if (setCtrMode(TEMP_MEASURE) == false)
	{
		return false;
	}

	while ( (getStatusReg() & 0x01) != 0x01)
	{
		; // Wait Until Get Vaild Temp. Measurement.
	}

	return true;
}

//Sets the Reset Bit (D4) in control register 0x81. Place the AD5933 into the standby mode
bool AD5933_Class::resetAD5933() {
	int temp = (getByte(0x81) & 0x08); // Read 0x81 with retrieving D3, 0x08=1000
  /* a&b运算, a,b均转换为二进制之后，“&”(即“与”)表示对应位均为1时，结果为1 */
	return setByte(0x81, (temp | 0x10)); // Set D4 as 1 (Reset Bit), 0x10=10000
  /* a|b运算, a,b均转换为二进制之后，“|”(即“或”)表示对应位有一个为1就为1 */
}

// Enable or disable external clock
bool AD5933_Class::setExtClock(bool swt) {
	byte t1;
	if ( swt )
	{
		t1 = 0x08; // Use external clock, 0x08=1000, D3=1 in 0x81 means using external clock.
		opClock = 16000000; // Frequency of external clock is 16MHz
	}
	else
	{
		t1 = 0x00; // Use internal clock
		opClock = 16776000; // Frequency of internal clock is 16.776MHZ
	}
	return setByte(0x81, t1); // Write control register 0x81.
}

//Write in Number of setting time cycles register
bool AD5933_Class::setSettlingCycles(int cycles, byte mult) 
{

	if (cycles > 0x1FF || !(mult == 1 || mult == 2 || mult == 4) ){
	  //0X1FF=111111111, which has nine "1".  "||" means "OR"
		return false;
	}
	int lowerHex = cycles % 256;//取转换为二进制后的后8位
	int upperHex = ((cycles - (long)lowerHex) >> 8) % 2;//get value of D8
	byte t1; // Parsing upper and lower bits. Byte has 8 bits
	
	t1--; // Enhanced Code for setting t1. To make t1 has 7 bits 
	upperHex |= (t1 << 1);  // t1 is for D9, D10. The upperHex just accounts for D8. Thus, the value after left-shifting t1 accounts for D9, D10.
	// Thus, this above writes bits for D9, D10.
	
	bool t2, t3;
	t2 = setByte(0x8A, upperHex);
	t3 = setByte(0x8B, lowerHex);
	if ( t2 && t3 ) // Checking if successful.
		return true;  // Succeed!
	else
	{
		return false;
	}
}

// Sets the start frequency for a frequency sweep in hertz
bool AD5933_Class::setStartFreq(long startFreq) {
	long freqHex = startFreq / (opClock / pow(2, 29)); // based on datasheet,pow(2,29)=2^29=0x20000000
	if (freqHex > 0xFFFFFF) //0xFFFFFF=111111111111111111111111(24个1)
	{
		return false;
	}

	int lowerHex = freqHex % 256;//% 是求余数运算符
	int midHex = ((freqHex - (long)lowerHex) >> 8) % 256;
  /* "a>>8"c语言中的右移运算符，将a的值转换为二进制，然后向右移动8位（即去掉后面8位）*/
	int upperHex = freqHex >> 16;
 
	bool t2, t3, t4;
	t2 = setByte(0x82, upperHex);
	t3 = setByte(0x83, midHex);
	t4 = setByte(0x84, lowerHex);
	if (t2 && t3 && t4)
		return true; // succeed!
	else
	{
		return false;
	}
}

// Write in frequency increment register 0x85, 0x86, 0x87
bool AD5933_Class::setStepSizeInHex(long freqHex) {

	if (freqHex > 0xFFFFFF) // FFFFFF=111111111111111111111111
	{
		return false;
	}

	int lowerHex = freqHex % 256;
	int midHex = ((freqHex - (long)lowerHex) >> 8) % 256;
	int upperHex = freqHex >> 16;

	bool t2, t3, t4;
	t2 = setByte(0x85, upperHex);
	t3 = setByte(0x86, midHex);
	t4 = setByte(0x87, lowerHex);
	if (t2 && t3 && t4)
	{
		incrHex = freqHex;
		return true; // Succeed!
	}
	else
	{
		return false;
	}

}

// Sets the number of frequency increments in a frequency sweep
bool AD5933_Class::setNumofIncrement(byte num) {

	if (num > 0x1FF + 1)//check whether the num is larger than 511, 1FF=511
	{
		return false;
	}

	int lowerHex = num % 256;
	int upperHex = (num >> 8) % 2; // Parsing number for register input.

	bool t2, t4;
	t2 = setByte(0x88, upperHex);
	t4 = setByte(0x89, lowerHex);
	if (t2 && t4)
	{
		numIncrement = num + 1;
		return true; // Succeed!
	}
	else
	{
		return false;
	}
}


//set range no. in control register 0x80
bool AD5933_Class::setRange(byte rangeToSet) {
	return setRange(rangeToSet, getByte(0x80));
}
//set range no. in control register 0x80
bool AD5933_Class::setRange(byte rangeToSet, int ctrReg) {

	ctrReg &= 0xF9; // Clear D9 & D10 to modify, 0xF9=11111001

	switch (rangeToSet) {

	case RANGE_1:
		ctrReg |= 0x00;
		//Serial.println("Changed to RANGE_1");
		break;

	case RANGE_2:
		ctrReg |= 0x06;
		//Serial.println("Changed to RANGE_2");
		break;

	case RANGE_3:
		ctrReg |= 0x04;
		//Serial.println("Changed to RANGE_3");
		break;

	case RANGE_4:
		ctrReg |= 0x02;
		//Serial.println("Changed to RANGE_4");
		break;
    
		return false; // return the signal of fail if there is not valid parameter.
		break;
	}
	return setByte(0x80, ctrReg); // return signal depends on the result of setting control register.

}

//set the PGA Gain
bool AD5933_Class::setPGA(byte pgaGain){
	return setPGA(pgaGain, getByte(0x80));
}
//set the PGA Gain
bool AD5933_Class::setPGA(byte pgaGain, int ctrReg) {

	ctrReg &= 0xFE; // Clear D8 to modify, 0xFE=11111110 (D8-D15)

	switch (pgaGain) {

	case GAIN_1:
		ctrReg |= 0x01;
		break;

	case GAIN_5:
		ctrReg |= 0x00;
		break;
    
		return false; // return the signal of fail if there is not valid parameter.
		break;
	}
	return setByte(0x80, ctrReg); // return signal depends on the result of setting control register.
}

// set control mode
bool AD5933_Class::setCtrMode(byte modetoSet) {
	return setCtrMode(modetoSet, getByte(0x80));
}
// set control mode
bool AD5933_Class::setCtrMode(byte modetoSet, int ctrReg) {

	ctrReg &= 0x0F; // Get the last 4 digits. 0x0F=1111. '&=' 转换为二进制后进行按位“AND”操作
	switch (modetoSet)
	{
	case INIT_START_FREQ://D15,D14,D13,D12=0001
		ctrReg |= 0x10;// 0x10=00010000, '|=' 转换为二进制后进行按位“OR”操作, set D12, initialize with start frequency
		break;
	case START_FREQ_SWEEP://D15,D14,D13,D12=0010
		ctrReg |= 0x20;// 0x20=00100000, set D13, start frequency sweep
		break;
	case INCR_FREQ://D15,D14,D13,D12=0011
		ctrReg |= 0x30;// 0x30=00110000, set D12 & D13, increment frequency
		break;
	case REPEAT_FREQ://D15,D14,D13,D12=0100
		ctrReg |= 0x40;// 0x40=01000000, set D14, repeat frequency
		break;
	case POWER_DOWN://D15,D14,D13,D12=1010
		ctrReg |= 0xA0;// 0xA0=10100000, set D13 & D15, Power-down mode
		break;
	case STAND_BY://D15,D14,D13,D12=1011
		ctrReg |= 0xB0;// 0xB0=10110000, set D12, D13, D15, Standby mode
		break;
	case TEMP_MEASURE://D15,D14,D13,D12=1001
		ctrReg |= 0x90;// 0x90=10010000, set D12, D15, Measure temperature
		break;
	default:
		return false; // return the signal of fail if there is not valid parameter.
		break;
	}
	return setByte(0x80, ctrReg); // return signal depends on the result of setting control register.

}
