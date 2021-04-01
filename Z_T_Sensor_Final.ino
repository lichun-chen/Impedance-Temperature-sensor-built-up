//*******************************************************************************************************************************************
#include "AD5933.h"
#include "Adafruit_MAX31855.h"
#include <Wire.h>
#include <SD.h>
#include <SPI.h>
#include "Z_T_functions.h"

//*******************************************************************************************************************************************
//******************************************DEFINE Z&T measurement part**********************************************************************
Adafruit_MAX31855 THERMOcouple(MAXCLK, MAXCS, MAXDO);
Z_T_functions_Class Z_T_func;

//*******************************************************************************************************************************************
//******************************************DEFINE ADG725 code*******************************************************************************
int pinoff=128;//code to turn off all the switches of ADG725 (16 ports)
int SWITCHnum = 0;
int CALIBnum = 1;

//*******************************************************************************************************************************************
//******************************************DEFINE Battery part******************************************************************************
int BATT_VOLT = 0;

//*******************************************************************************************************************************************
//*******************************************************************************************************************************************
void setup()
{
  Wire.begin();        // join i2c bus (address optional for master)   
  Serial.begin(9600);
  while (!Serial) delay(1); // wait for Serial on Leonardo/Zero, etc

  //set the pins for LEDS
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  pinMode(LED5, OUTPUT);
  digitalWrite(LED2, LOW);
  digitalWrite(LED3, LOW);
  digitalWrite(LED4, LOW);
  digitalWrite(LED5, LOW);
  
  //set pin mode for multiplexers_resistors
  pinMode(SS_Z, OUTPUT);
  pinMode(SCLK_Z, OUTPUT); 
  pinMode(MOSI_Z, OUTPUT);
  //set the pin mode for multiplexer_temperature
  pinMode(SS_T, OUTPUT);
  pinMode(SCLK_T, OUTPUT); 
  pinMode(MOSI_T, OUTPUT);
  
  //SD Card Initialization
  pinMode(SDCard_EN,OUTPUT);// enable voltage converter (define as asigned in the KiCAD file)
  digitalWrite(SDCard_EN, HIGH);// enable voltage converter (define as asigned in the KiCAD file)
  pinMode(SD_CS,OUTPUT); 
  //SD card can be only initialized once, multiple initializations result to failure. so must leave this part in the setup function, not in the loop function.
  if (!SD.begin(SD_CS))
    { // if the SD card is not put right, then do nothing
      Serial.println("SD Card Initialization Failed!"); 
      digitalWrite(LED4,HIGH); // Turn on the LED4 as a sign for SD card failed.
    }

  //set TPS2010 EN pin
  pinMode(TPSEN_Z, OUTPUT);
  pinMode(TPSEN_T, OUTPUT);
  //TUEN OFF THE TPS2010 SWITCH at the setup beginning
  digitalWrite(TPSEN_Z, HIGH); // LOW turns on the power; High turns off the power
  digitalWrite(TPSEN_T, HIGH); // LOW turns on the power; High turns off the power
  
  delay(100);
}
//*****************************************************************************************************************************************************
void loop()
{
  // GET THE VOLTAGE OF THE BATTERY AT THE BEGINNING OF EACH LOOP
  BATT_VOLT = Z_T_func.Batt_analogread();
  if (BATT_VOLT < Batt_Low) // if the battery is low then do nothing
  {delay(1800000); /*delay 30mins */ }
  else {     
      //****************************************************************************************************************************************************
      //Turn on TPS2010 switch. set the EN pin for TPSEN_Z, TPSEN_T
      digitalWrite(TPSEN_Z, LOW); // LOW turns on the power; High turns off the power
      digitalWrite(TPSEN_T, LOW); // LOW turns on the power; High turns off the power
              
      //close all switch pins of ADG729 before measurement
      Z_T_func.SwiChoi_Z(0, ADDRESS_SwiCalib);// close all switch pins of impedance calibration
      Z_T_func.SwiChoi_Z(0, ADDRESS_SwiRFB);// close all switch pins of RFB resistor
      //close all switch pins of ADG725 (16 ports) before measurement
      Z_T_func.Switch_Z(pinoff);
      Z_T_func.Switch_T(pinoff);
  
      // set the initial time here:only run this part once
      // NOTE: This part must be put after the function of an I2C device (ADG729 here), otherwise the clock will not work
      // DS3231 seconds, minutes, hours, day, date, month, year
      //Z_T_func.setDS3231time(30,57,17,1,25,8,19); 
            
      //Turn off all the LEDS befores measurement. start measuring impedance&temperature SIGN
      digitalWrite(LED2,LOW);
      digitalWrite(LED3,LOW);
      digitalWrite(LED4,LOW);
      digitalWrite(LED5,LOW);
      //************************************Measure Battery ***********************************************************************************************
      Z_T_func.Batt_Volt();
      //************************************Measure Impedance***********************************************************************************************    
      // start measure the calibration resistors
      for (CALIBnum = 1; CALIBnum <5; CALIBnum ++){
          Z_T_func.SwiChoi_Z(CALIBnum, ADDRESS_SwiCalib);
          Z_T_func.impeTest(0,CALIBnum, LED2);//LED2 will blink when it is measuring
      }
      //close all pins of calibration ports
      Z_T_func.SwiChoi_Z(0, ADDRESS_SwiCalib); // close all switch pins of impedance calibration
              
      // start measure impedance with different switchnum.
      for (SWITCHnum = 0; SWITCHnum < 16; SWITCHnum ++) {  
          Z_T_func.Switch_Z(SWITCHnum);
          Z_T_func.impeTest(1, SWITCHnum, LED2);//LED2 will blink when it is measuring
      }
      //close all pins of switch_resistor
      Z_T_func.Switch_Z(pinoff);
              
      delay(100);//delay 0.1s
      //***********************************Measure Temperature**********************************************************************************************
      // start measure temperature with different switchnum.
      for (SWITCHnum = 0; SWITCHnum <8 ; SWITCHnum ++) {
          Z_T_func.Switch_T(SWITCHnum);
          Z_T_func.tempTest(SWITCHnum, LED2, THERMOcouple); // LED2 will blink when it is measuring
      }
      //close all pins of switch_temperature
      Z_T_func.Switch_T(pinoff);
              
      delay(100);//delay 0.1s
      //****************************************************************************************************************************************************
      //TUEN OFF THE TPS2010 SWITCH AFTER MEASUREMENT
      digitalWrite(TPSEN_Z, HIGH); // LOW turns on the power; High turns off the power
      digitalWrite(TPSEN_T, HIGH); // LOW turns on the power; High turns off the power
      
      delay(1800000); //delay 30mins
       
  }
}
