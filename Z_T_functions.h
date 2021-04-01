// Header File for Temperature Measurement & Impedance Measurement for Z&T_Sensor
// Author: Lichun Chen

#include<math.h> // for math functions
#include<Wire.h> // for I2C communications
#include<Arduino.h> // For access to hardware pins
#include <SD.h> // for SD Card
#include <SPI.h> // for SPI communications
#include "Adafruit_MAX31855.h"
#include "AD5933.h" // For AD5933 functions

#ifndef Z_T_functions_Head //Pre-Processing code to prevent from duplicate declaration.
#define Z_T_functions_Head

//*****************************Define The Impedance Measurement part************************************************************************************
//******************************************************************************************************************************************************
#define TWI_FREQ 400000L
#define cycles_base 511  //511 is the largest value
#define cycles_multiplier 4

// define the EN pin of TPSEN_Z (define as asigned in the KiCAD file)
#define TPSEN_Z 19

//define the address of calibration switch & reference switch (define as asigned in the KiCAD file)
#define ADDRESS_SwiCalib  0x44 // ADG729  10001(A1:0)(A0:0)
#define ADDRESS_SwiRFB  0x45 // ADG729  10001(A1:0)(A0:1)

//define the pin for multiplexer_resistors (define as asigned in the KiCAD file)
#define SS_Z 33
#define MOSI_Z 32
#define SCLK_Z 31

const int start_frequency = 4000; //Hz
//double gainfactor = 8845644.00; // gainfactor for 760 ohm reference
const double gainfactor_2k = 20657233.16; // gainfactor for 2000 ohm reference
const double gainfactor_560 = 6995959.34; // gainfactor for 560 ohm reference
const double pshift_2k = 1.61;
const double pshift_560 = 1.61;
const double set_time = 0.1;

//*****************************Define The Temperature Measurement part************************************************************************************************
//********************************************************************************************************************************************************************
//define pins for MAX31855 (define as asigned in the KiCAD file)
#define MAXDO   49
#define MAXCS   48
#define MAXCLK  47

//define EN pin for TPS2010_T (define as asigned in the KiCAD file)
#define TPSEN_T 42

//define pins for multiplexer_temperature (define as asigned in the KiCAD file)
#define SS_T   46
#define MOSI_T   45 //Master Out Slave In
#define SCLK_T  44

//***************************Define the pin of SDCard***********************************************************************************************************************
//**************************************************************************************************************************************************************************
#define SDCard_EN 11
#define SD_CS 10

//*****************************DEFINE LED PART******************************************************************************************************************************
//**************************************************************************************************************************************************************************
#define LED2 A0 // define as asigned in KiCAD
#define LED3 A1 // define as asigned in KiCAD
#define LED4 A2 // define as asigned in KiCAD
#define LED5 A3 // define as asigned in KiCAD

//***************************************************************************************************************************************************************************
//******************************************DEFINE Check Battery part********************************************************************************************************
// Power Monitor A/D conversions
#define AD_Batt 0.027832 // =5/1024*(47+10)/10, (R9 = 47k, R26 = 10k)
// Power Inputs
#define Batt_power A10 // define as asigned in KiCAD

//Power Levels
#define Batt_Medium     438 //(int)(1024/5)*(10/(47+10)*(12.2)  //60% charged
#define Batt_Low        424 //(int)(1024/5)*(10/(47+10)*(11.8)  //30% charged
#define Batt_Reseave    406 //(int)(1024/5)*(10/(47+10)*(11.3)  //10% charged

//***************************************************************************************************************************************************************************
//********************************************DEFINE RTC part********************************************************************************************************
#define ADDRESS_DS3231 0x68

//*****************************Define how many times of testing for each port***********************************************************************************************
//**************************************************************************************************************************************************************************
const int testnum = 10;

// Define the sample&level num for impedance measurement
const int calibnum_Z[5] = {0,1,2,3,4};
const int calibvalue_Z[5] = {0,560,1000,1500,2000};
const int samplenum_Z[16] = {1,1,1,1,1,1,1,1,2,2,2,2,2,2,2,2};
const int level_Z[16] = {1,2,3,4,5,6,7,8,1,2,3,4,5,6,7,8};

// Define the sample&level num for temperature measurement
const int samplenum_T[16] = {1,1,1,1,2,2,2,2,1,1,1,1,2,2,2,2};
const int level_T[16] = {1,2,3,4,1,2,3,4,1,2,3,4,1,2,3,4};

//********************************************Define The Z_T_functions_Class part********************************************************************************************
//***************************************************************************************************************************************************************************
class Z_T_functions_Class
{
  public:
  // Common functions used within a sketch

  //********************************************************Define the impedance measurement part****************************************************************************
  // Switch change function of switch_calibration & switch_reference
  void SwiChoi_Z (int, byte);
  // Switch change function of Switch_resistors
  void Switch_Z(int);
  // impedance measure function
  void impeTest(int, int, int);
  // impedance measure function when the 1st test is over 2200ohm
  void impeTest_over2200(File, int);

  //********************************************************Define the temperature measurement part***************************************************************************
  //Switch change function of switch_temperature 
  void Switch_T(int);
  // temperature measure function
  void tempTest(int, int, Adafruit_MAX31855);

  //********************************************************Define the RTC_DS3231 part***************************************************************************
  //set DS3231 time
  void setDS3231time(byte, byte, byte, byte, byte, byte, byte);
  // read time from DS3231
  void readDS3231time(byte*,byte*,byte*,byte*,byte*,byte*,byte*);
  // display time based on DS3231
  void displaytime(File);
  // define the filename based on DS3231date
  void filename_date(String*);
  
  //**************************************************************************************************************************************************************************
  // Constructors (Actually not frequently used)
  Z_T_functions_Class(){}
  //measure Batt
  void Batt_Volt();
  int Batt_analogread();
  
  private:
  //internal fucntions and variables used within the library
  
  // Convert normal decimal numbers to binary coded decimal
  byte decToBcd(byte val){return val + 6 * (val / 10); }
  // Convert binary coded decimal to normal decimal numbers
  byte bcdToDec(byte val){return val - 6 * (val >> 4); }
  
};

//extern Z_T_functions_Class Tfunctions;
#endif
