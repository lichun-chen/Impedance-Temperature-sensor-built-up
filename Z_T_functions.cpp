#include "Z_T_functions.h"
#include "Adafruit_MAX31855.h"
#include <SD.h>
#include <Arduino.h> // For the compatibility with Arduino Conventions.

//*******************************************Impedance Measurement Part*********************************************************************************************
//******************************************************************************************************************************************************************
// Switch change function of switch_calibration & switch_reference
void Z_T_functions_Class::SwiChoi_Z(int i, byte ADDRESS){
    int VAL[5] = {0,17,34,68,136}; // represent: off all, open S1A&S1B:560ohm, open S2A&S2B:1000ohm, open S3A&S3B:1500ohm, open S4A&S4B:2000ohm, 
    Wire.beginTransmission(ADDRESS); //transmit to device 
    byte val = VAL[i];
    Serial.println(val);
    Wire.write(val);
    Wire.endTransmission(); // stop transmitting
    delay(100);      
    return;
}

// Switch change function of Switch_resistors
void Z_T_functions_Class::Switch_Z(int j){
  digitalWrite(SS_Z, LOW); 
  shiftOut(MOSI_Z, SCLK_Z, MSBFIRST, j);
  digitalWrite(SS_Z, HIGH);
  delay(100);
  return;
}

// impedance measure function
void Z_T_functions_Class::impeTest(int calibOR_, int switchnum, int led){ 
    File file;
    String filename;
    filename_date(&filename);// get the filename based on the date
    Serial.println(filename);      
    file = SD.open(filename, FILE_WRITE);
     
    displaytime(file);
    switch(calibOR_){
      case 0: {
        Serial.print("Calibration sample_value:");  Serial.print("\t");  
        Serial.print(calibnum_Z[switchnum]);  Serial.print("\t");
        Serial.println(calibvalue_Z[switchnum]);   
        if(file){
          file.print("Calibration sample_value:"); file.print("\t");
          file.print(calibnum_Z[switchnum]); file.print("\t");
          file.println(calibvalue_Z[switchnum]);          
        } else {Serial.println("error opening file"); digitalWrite(LED4,HIGH);/* Turn on the LED4 as a sign of SD card fail */  return;}
        break;
      }
      case 1: {
        Serial.print("impedance sample_layer:");  Serial.print("\t");  
        Serial.print(samplenum_Z[switchnum]);  Serial.print("\t");
        Serial.println(level_Z[switchnum]);   
        if(file){
          file.print("impedance sample_layer:"); file.print("\t");
          file.print(samplenum_Z[switchnum]); file.print("\t");
          file.println(level_Z[switchnum]);          
        } else {Serial.println("error opening file"); digitalWrite(LED4,HIGH);/* Turn on the LED4 as a sign of SD card fail */  return;}
        break;
      }
    } 

    // test with the RFB = 560ohm first
    SwiChoi_Z(1, ADDRESS_SwiRFB);// 1,2,3,4 represent S1A&S1B:560ohm,S2A&S2B:1000ohm,S3A&S3B:1500ohm,S4A&S4B:2000ohm
    double gainfactor = gainfactor_560;
    double pshift = pshift_560;
    AD5933.setExtClock(false); //Write Bit D3 in control register 0x81.
    AD5933.resetAD5933(); //Set the reset Bit D4 in control register 0x81.
    AD5933.setStartFreq(start_frequency);//Write in start frequency register 0x82, 0x83, 0x84.
    //Cycles to ignore before a measurement is taken. Max is 511.
    AD5933.setSettlingCycles(cycles_base, cycles_multiplier);//Write in Number of setting time cycles register 0x8A, 0x8B.   
    AD5933.setStepSizeInHex(1);// Write in frequency increment register 0x85, 0x86, 0x87.
    AD5933.setNumofIncrement(2);// Write in number of increments register 0x88,0x89.
    AD5933.setPGA(GAIN_1);//Write the D8 bit to set PGA gain in control register 0x80,0=*5,1=*1.
    AD5933.setRange(RANGE_1);// write the bit D9 & D10 to set range no. in control register 0x80.
    AD5933.setCtrMode(STAND_BY); //set standby mode0
    AD5933.setCtrMode(INIT_START_FREQ); //initialize with start frequency
   
    int a=millis();
    while(((millis()-a)/1000-10)<set_time);//-10 is for let it wait until the AD5933 chip sets. MUST!   
    AD5933.setCtrMode(START_FREQ_SWEEP);//start frequency sweep  
    while ( (AD5933.getStatusReg() & 0x02) != 0x02 ); // Wait until measurement is complete. 

    int n=0;
    double Z_Val, phase;
//*********************************************Measure impedance for the 1st time to see whether the impedance is over 2200ohm or not **********************************************************
    //led SIGN
    digitalWrite(led, HIGH);
    delay(200);
    digitalWrite(led, LOW);

    AD5933.tempUpdate();
    AD5933.setCtrMode(REPEAT_FREQ);//Repeat frequency sweep, so we can retest the impedence in the certain time period. Otherwise the test result will maintain the same during the time period
    while ( (AD5933.getStatusReg() & 0x02) != 0x02 ); // Wait until measurement is complete. 

    int r_test, i_test;
    byte impData_test[4];    
    AD5933.blockRead(0x94, 4, impData_test);
    r_test = impData_test[0] * 16 * 16 + impData_test[1];
    i_test = impData_test[2] * 16 * 16 + impData_test[3];
    double magSq_test = AD5933.getMag(r_test, i_test);
    Z_Val = gainfactor / magSq_test-200;// -200 is because Vout has a resisticity of 200ohm   
    
    Serial.print("impedance_test_>2.2k or not : "); Serial.println(Z_Val);
    if(file){file.print("impedance_test_>2.2k or not : "); file.println(Z_Val);} 
    else {Serial.println("error opening file"); digitalWrite(LED4,HIGH);/* Turn on the LED4 as a sign of SD card fail */   return;}
//***********************************************************************************************************************************************************************************************
    if(Z_Val > 2200){
      AD5933.setCtrMode(POWER_DOWN);
      impeTest_over2200(file, led); 
    } else { 
              while(n<testnum) // we will measure the impedance testnum times
              {  
                //led SIGN
                digitalWrite(led, HIGH);
                delay(200);
                digitalWrite(led, LOW);
                
                AD5933.tempUpdate();
                AD5933.setCtrMode(REPEAT_FREQ);//Repeat frequency sweep, so we can retest the impedence in the certain time period. Otherwise the test result will maintain the same during the time period              
                while ( (AD5933.getStatusReg() & 0x02) != 0x02 ); // Wait until measurement is complete. 
                  
                int rComp, iComp;
                byte impData[4];    
                AD5933.blockRead(0x94, 4, impData);
                rComp = impData[0] * 16 * 16 + impData[1];
                iComp = impData[2] * 16 * 16 + impData[3];
                double magSq = AD5933.getMag(rComp, iComp);
                Z_Val = gainfactor / magSq-200;// -200 is because Vout has a resisticity of 200ohm
                phase =180*(atan2(iComp, rComp) - pshift)/3.1415926;    
                
                Serial.print(Z_Val); Serial.print("\t"); Serial.println(phase);
          
                if(file){
                  file.print(Z_Val); file.print("\t"); file.println(phase);   
                } else {Serial.println("error opening file"); digitalWrite(LED4,HIGH);/* Turn on the LED4 as a sign of SD card fail */   return;}
               
                n++;
              }
           } 

   file.close();
   AD5933.setCtrMode(POWER_DOWN);
   delay(100);
   return;
}

// impedance measure function when the 1st test is over 2200ohm
void Z_T_functions_Class::impeTest_over2200(File file, int led)
{ // test with the RFB = 2kohm
  SwiChoi_Z(4, ADDRESS_SwiRFB);// 1,2,3,4 represent S1A&S1B:560ohm,S2A&S2B:1000ohm,S3A&S3B:1500ohm,S4A&S4B:2000ohm  
  double gainfactor = gainfactor_2k;
  double pshift = pshift_2k;
  AD5933.setExtClock(false); //Write Bit D3 in control register 0x81.
  AD5933.resetAD5933(); //Set the reset Bit D4 in control register 0x81.
  AD5933.setStartFreq(start_frequency);//Write in start frequency register 0x82, 0x83, 0x84.
  //Cycles to ignore before a measurement is taken. Max is 511.
  AD5933.setSettlingCycles(cycles_base, cycles_multiplier);//Write in Number of setting time cycles register 0x8A, 0x8B.   
  AD5933.setStepSizeInHex(1);// Write in frequency increment register 0x85, 0x86, 0x87.
  AD5933.setNumofIncrement(2);// Write in number of increments register 0x88,0x89.
  AD5933.setPGA(GAIN_1);//Write the D8 bit to set PGA gain in control register 0x80,0=*5,1=*1.
  AD5933.setRange(RANGE_1);// write the bit D9 & D10 to set range no. in control register 0x80.
  AD5933.setCtrMode(STAND_BY); //set standby mode0
  AD5933.setCtrMode(INIT_START_FREQ); //initialize with start frequency
     
  int a=millis();
  while(((millis()-a)/1000-10)<set_time);//-10 is for let it wait until the AD5933 chip sets. MUST!   
  AD5933.setCtrMode(START_FREQ_SWEEP);//start frequency sweep
  while ( (AD5933.getStatusReg() & 0x02) != 0x02 ); // Wait until measurement is complete. 
  
  int n=0;
  double Z_Val, phase;
  while(n<testnum) // we will measure the impedance testnum times
  {  
      //led SIGN
      digitalWrite(led, HIGH);
      delay(200);
      digitalWrite(led, LOW);
                  
      AD5933.tempUpdate();
      AD5933.setCtrMode(REPEAT_FREQ);//Repeat frequency sweep, so we can retest the impedence in the certain time period. Otherwise the test result will maintain the same during the time period              
      while ( (AD5933.getStatusReg() & 0x02) != 0x02 ); // Wait until measurement is complete. 
                      
      int rComp, iComp;
      byte impData[4];    
      AD5933.blockRead(0x94, 4, impData);
      rComp = impData[0] * 16 * 16 + impData[1];
      iComp = impData[2] * 16 * 16 + impData[3];
      double magSq = AD5933.getMag(rComp, iComp);
      Z_Val = gainfactor / magSq;// No need to -200, because RFB is 2000ohm and is large enough
      phase =180*(atan2(iComp, rComp) - pshift)/3.1415926;    
                 
      Serial.print(Z_Val); Serial.print("\t"); Serial.println(phase);
            
      if(file){
         file.print(Z_Val); file.print("\t"); file.println(phase);   
      } else {Serial.println("error opening file"); digitalWrite(LED4,HIGH);/* Turn on the LED4 as a sign of SD card fail */  return;}
                
      n++;
  }
  return;
}
  
//*******************************************Temperature Measurement Part*********************************************************************************************
//********************************************************************************************************************************************************************
//Switch change function of switch_temperature 
void Z_T_functions_Class::Switch_T(int j){
  digitalWrite(SS_T, LOW); 
  shiftOut(MOSI_T, SCLK_T, MSBFIRST, j);  
  digitalWrite(SS_T, HIGH);
  delay(100);
  return;
}

// temperature measure function
void Z_T_functions_Class::tempTest(int switchnum, int led, Adafruit_MAX31855 thermocouple){ 
  File file;
  String filename;
  filename_date(&filename);// get the filename based on the date
  Serial.println(filename);      
  file = SD.open(filename, FILE_WRITE);
  
  displaytime(file);
  Serial.print("temperature sample_layer:");
  Serial.print("\t");
  Serial.print(samplenum_T[switchnum]);
  Serial.print("\t");
  Serial.println(level_T[switchnum]);

  if(file){
    file.print("temperature sample_layer:");
    file.print("\t");
    file.print(samplenum_T[switchnum]);
    file.print("\t");
    file.println(level_T[switchnum]);
  } else {Serial.println("error opening file"); digitalWrite(LED4,HIGH);/* Turn on the LED4 as a sign of SD card fail */  return;}
  
  int n=0;
  double T_Val;
  
  while(n<testnum)// we will measure the temperature testnum times
  {
    //led SIGN
     digitalWrite(led, HIGH);
     delay(200);
     digitalWrite(led, LOW);
      
    T_Val=thermocouple.readFarenheit();
    Serial.println(T_Val);

    if(file){
       file.println(T_Val);    
    } else {Serial.println("error opening file"); digitalWrite(LED4,HIGH);/* Turn on the LED4 as a sign of SD card fail */   return;}
      
    n++;
  }

  file.close();
  delay(100); 
  return;
}

//**********************************Measure Battery voltage*********************************************************************************************
//******************************************************************************************************************************************************

// battery voltage measurement function 
int Z_T_functions_Class::Batt_analogread(){
  int Batt = analogRead(Batt_power);
  return Batt;
}

// measure the battery voltage and write the voltage into the SD card
void Z_T_functions_Class::Batt_Volt(){
  File file;
  String filename;
  filename_date(&filename);// get the filename based on the date
  Serial.println(filename);      
  file = SD.open(filename, FILE_WRITE);
  
  uint16_t Batt = analogRead(Batt_power);
  float volt_Batt= float(Batt*AD_Batt);

  displaytime(file);
  Serial.print("Batt_Volt:");
  Serial.print("\t");
  Serial.print(Batt);
  Serial.print("\t");
  Serial.println(volt_Batt);
  if(file){
     file.print("Batt_Volt:");
     file.print("\t");
     file.print(Batt);
     file.print("\t");
     file.println(volt_Batt);    
    } else {Serial.println("error opening file"); digitalWrite(LED4,HIGH);/* Turn on the LED4 as a sign of SD card fail */   return;} 

  file.close();
  delay(100);
  return;
}

//********************************************************Define the RTC_DS3231 part***************************************************************************
//******************************************************************************************************************************************************
//set DS3231 time
void Z_T_functions_Class::setDS3231time(byte second0, byte minute0, byte hour0, byte dayOfWeek, byte dayOfMonth, byte month0, byte year0)
{
  // sets time and date data to DS3231 
  Wire.beginTransmission(ADDRESS_DS3231);
  // set next input to start at the seconds register (00h). 
  //the register pointer is set autimatically point to the next register in DS3231
  Wire.write(0x00); 
  Wire.write(decToBcd(second0)); // set seconds
  Wire.write(decToBcd(minute0)); // set minutes
  Wire.write(decToBcd(hour0)); // set hours
  Wire.write(decToBcd(dayOfWeek)); // set day of week (1=Sunday, 7=Saturday)
  Wire.write(decToBcd(dayOfMonth)); // set date (1 to 31)
  Wire.write(decToBcd(month0)); // set month
  Wire.write(decToBcd(year0)); // set year (0 to 99)
  Wire.endTransmission();
  return;
}

// read time from DS3231
void Z_T_functions_Class::readDS3231time(byte *second, byte *minute,byte *hour,byte *dayOfWeek,byte *dayOfMonth,byte *month,byte *year)
{
  Wire.beginTransmission(ADDRESS_DS3231);
  // set next input to start at the seconds register (00h). 
  //the register pointer is set autimatically point to the next register in DS3231
  Wire.write(0x00); 
  Wire.endTransmission();
  Wire.requestFrom(ADDRESS_DS3231, 7);
  // request seven bytes of data from DS3231 starting from register 00h
  *second = bcdToDec(Wire.read() & 0x7f); //*p和var指的是var的内容；p和&var指的是var的地址
  *minute = bcdToDec(Wire.read());
  *hour = bcdToDec(Wire.read() & 0x3f);
  *dayOfWeek = bcdToDec(Wire.read());
  *dayOfMonth = bcdToDec(Wire.read());
  *month = bcdToDec(Wire.read());
  *year = bcdToDec(Wire.read());
  return;
}

// display time based on DS3231
void Z_T_functions_Class::displaytime(File _file)
{
  byte second, minute, hour, dayOfWeek, dayOfMonth, month, year;
  // retrieve data from DS3231
  readDS3231time(&second, &minute, &hour, &dayOfWeek, &dayOfMonth, &month,&year); // & gives Address of Variable. 
  // send it to the serial monitor
  Serial.print(hour, DEC);// convert the byte variable to a decimal number when displayed
  Serial.print(":");
  //if (minute<10){Serial.print("0");}
  Serial.print(minute, DEC);
  Serial.print(":");
  //if (second<10){Serial.print("0");}
  Serial.print(second, DEC);
  Serial.print("\t");
  Serial.print(month, DEC);
  Serial.print("\t");
  Serial.print(dayOfMonth, DEC);
  Serial.print("\t");
  Serial.print(year, DEC);
  Serial.print("\t");
  /* No need for this project, better to skip this to save space in the SD card
  switch(dayOfWeek){
  case 1: Serial.println("Sunday"); break;
  case 2: Serial.println("Monday"); break;
  case 3: Serial.println("Tuesday"); break;
  case 4: Serial.println("Wednesday"); break;
  case 5: Serial.println("Thursday"); break;
  case 6: Serial.println("Friday"); break;
  case 7: Serial.println("Saturday"); break;
  }
  */
  Serial.println("\t");

  // write it to the SD card  
  if (_file){
    _file.print(hour, DEC);
    // convert the byte variable to a decimal number when displayed
    _file.print(":");
    //if (minute<10){_file.print("0");  }
    _file.print(minute, DEC);
    _file.print(":");
    //if (second<10){_file.print("0");}
    _file.print(second, DEC);
    _file.print("\t");
    _file.print(month, DEC);
    _file.print("\t");
    _file.print(dayOfMonth, DEC);
    _file.print("\t");
    _file.print(year, DEC);
    _file.print("\t");
    }else {
    // if the file didn't open, print an error:
    Serial.println("error opening file");
    digitalWrite(LED4,HIGH);/* Turn on the LED4 as a sign of SD card fail */  
    return;
  }
  return;
}

  
// define the filename based on DS3231date
void Z_T_functions_Class::filename_date(String *_filename)
{
  byte second, minute, hour, dayOfWeek, dayOfMonth, month, year;
  // retrieve data from DS3231
  readDS3231time(&second, &minute, &hour, &dayOfWeek, &dayOfMonth, &month,&year); // & gives Address of Variable. 

  if (month<10){*_filename = "0"+String(month)+String(year)+".txt";} //*p和var指的是var的内容；p和&var指的是var的地址
  else{*_filename = String(month)+String(year)+".txt";} //*p和var指的是var的内容；p和&var指的是var的地址
  return;
}













  
