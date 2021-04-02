EESchema Schematic File Version 4
LIBS:Z&T_Sensor-cache
EELAYER 26 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 10
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L core-rescue:ATMEGA2560-A IC1
U 1 1 560929CC
P 3900 4250
F 0 "IC1" H 3900 4350 40  0000 L BNN
F 1 "ATMEGA2560-A" H 4600 1400 40  0000 L BNN
F 2 "MyFootprint:ATMega_TQFP-100_14x14mm_P0.5mm" H 3900 4250 30  0000 C CIN
F 3 "" H 3900 4250 60  0000 C CNN
	1    3900 4250
	1    0    0    -1  
$EndComp
Text Label 5450 2650 0    60   ~ 0
SCK
Text Label 5450 2850 0    60   ~ 0
MISO
Text Label 5450 2750 0    60   ~ 0
MOSI
Wire Wire Line
	3750 7150 3750 7200
Wire Wire Line
	4050 1200 4050 1350
Wire Wire Line
	3750 1200 3750 1350
Wire Wire Line
	3550 1350 3550 1250
Wire Wire Line
	1750 6850 1650 6850
Text Label 5250 5250 0    60   ~ 0
RX0
Text Label 5250 5350 0    60   ~ 0
TX0
Wire Wire Line
	9100 4550 9100 4250
Wire Wire Line
	9400 3500 9250 3500
Wire Wire Line
	9250 3500 9250 3450
Connection ~ 9250 3500
Wire Wire Line
	3950 7600 4050 7600
Wire Wire Line
	3750 1200 4050 1200
Wire Wire Line
	9250 3500 9100 3500
Wire Wire Line
	5200 2550 5800 2550
Wire Wire Line
	5200 3850 5850 3850
Wire Wire Line
	5200 3950 5850 3950
Wire Wire Line
	5200 4050 5850 4050
Wire Wire Line
	6950 3450 6650 3450
Wire Wire Line
	5200 4450 6950 4450
Wire Wire Line
	6950 3450 6950 3700
Wire Wire Line
	6850 4350 6850 4050
Wire Wire Line
	6850 3550 6650 3550
Wire Wire Line
	6650 3700 6950 3700
Connection ~ 6950 3700
Wire Wire Line
	6950 3700 6950 3950
Wire Wire Line
	6650 3950 6950 3950
Connection ~ 6950 3950
Wire Wire Line
	6950 3950 6950 4450
Wire Wire Line
	6650 4050 6850 4050
Connection ~ 6850 4050
Wire Wire Line
	2600 2550 2200 2550
Wire Wire Line
	2600 2650 2200 2650
Wire Wire Line
	2600 2750 2200 2750
Wire Wire Line
	2600 2850 2400 2850
Wire Wire Line
	2400 2850 2400 2950
Wire Wire Line
	2400 2950 1600 2950
Wire Wire Line
	1600 2950 1600 2750
Wire Wire Line
	1600 2750 1650 2750
Wire Wire Line
	1650 2650 1550 2650
Wire Wire Line
	1500 2550 1650 2550
Wire Wire Line
	2600 2950 2600 3000
Wire Wire Line
	2600 3000 1550 3000
Wire Wire Line
	1550 2650 1550 3000
Wire Wire Line
	9400 4550 9400 4250
Wire Wire Line
	5200 2850 5800 2850
Wire Wire Line
	5200 2750 5800 2750
Wire Wire Line
	2850 7200 2700 7200
Text GLabel 2700 7200 0    50   Input ~ 0
V1
Wire Wire Line
	3950 7150 3950 7600
Wire Wire Line
	4050 7150 4050 7600
Text GLabel 2700 7400 0    50   Input ~ 0
V2
Wire Wire Line
	2700 7400 2850 7400
Text GLabel 2700 7600 0    50   Input ~ 0
V3
Wire Wire Line
	2700 7600 2850 7600
Wire Wire Line
	3850 7150 3850 7400
Wire Wire Line
	3650 900  3650 950 
Connection ~ 4050 1200
Wire Wire Line
	4050 900  4050 950 
Text GLabel 3500 1250 0    50   Input ~ 0
V1
Text GLabel 3600 950  0    50   Input ~ 0
V2
Text GLabel 4000 950  0    50   Input ~ 0
V3
Wire Wire Line
	3500 1250 3550 1250
Connection ~ 3550 1250
Wire Wire Line
	3550 1250 3550 1200
Wire Wire Line
	3600 950  3650 950 
Connection ~ 3650 950 
Wire Wire Line
	3650 950  3650 1350
Wire Wire Line
	4000 950  4050 950 
Connection ~ 4050 950 
Wire Wire Line
	4050 950  4050 1200
Text GLabel 2550 1100 0    50   Input ~ 0
RESET
$Comp
L Arduino-Pro-Mini-eagle-import:GND #GND?
U 1 0 5BBBB253
P 3650 7550
AR Path="/5BB1C5FF/5BBBB253" Ref="#GND?"  Part="1" 
AR Path="/5BBBB253" Ref="#GND06"  Part="1" 
F 0 "#GND06" H 3650 7550 50  0001 C CNN
F 1 "GND" H 3650 7550 59  0000 L BNN
F 2 "" H 3650 7550 50  0001 C CNN
F 3 "" H 3650 7550 50  0001 C CNN
	1    3650 7550
	1    0    0    -1  
$EndComp
Wire Wire Line
	3400 7200 3750 7200
Wire Wire Line
	3150 7200 3400 7200
Connection ~ 3400 7200
$Comp
L Arduino-Pro-Mini-eagle-import:GND #GND?
U 1 0 5BBBB1B7
P 3400 7350
AR Path="/5BB1C5FF/5BBBB1B7" Ref="#GND?"  Part="1" 
AR Path="/5BBBB1B7" Ref="#GND05"  Part="1" 
F 0 "#GND05" H 3400 7350 50  0001 C CNN
F 1 "GND" H 3400 7350 59  0000 L BNN
F 2 "" H 3400 7350 50  0001 C CNN
F 3 "" H 3400 7350 50  0001 C CNN
	1    3400 7350
	1    0    0    -1  
$EndComp
Wire Wire Line
	3400 7200 3400 7250
$Comp
L Arduino-Pro-Mini-eagle-import:GND #GND?
U 1 0 5BBBB298
P 3950 7750
AR Path="/5BB1C5FF/5BBBB298" Ref="#GND?"  Part="1" 
AR Path="/5BBBB298" Ref="#GND07"  Part="1" 
F 0 "#GND07" H 3950 7750 50  0001 C CNN
F 1 "GND" H 3950 7750 59  0000 L BNN
F 2 "" H 3950 7750 50  0001 C CNN
F 3 "" H 3950 7750 50  0001 C CNN
	1    3950 7750
	1    0    0    -1  
$EndComp
Connection ~ 3950 7600
Wire Wire Line
	3150 7600 3950 7600
Wire Wire Line
	3950 7650 3950 7600
Wire Wire Line
	3150 7400 3650 7400
Wire Wire Line
	3650 7450 3650 7400
Connection ~ 3650 7400
Wire Wire Line
	3650 7400 3850 7400
$Comp
L Arduino-Pro-Mini-eagle-import:GND #GND?
U 1 0 5BC3B455
P 1650 6950
AR Path="/5BB1C5FF/5BC3B455" Ref="#GND?"  Part="1" 
AR Path="/5BC3B455" Ref="#GND01"  Part="1" 
F 0 "#GND01" H 1650 6950 50  0001 C CNN
F 1 "GND" H 1450 6950 59  0000 L BNN
F 2 "" H 1650 6950 50  0001 C CNN
F 3 "" H 1650 6950 50  0001 C CNN
	1    1650 6950
	1    0    0    -1  
$EndComp
$Comp
L Arduino-Pro-Mini-eagle-import:GND #GND?
U 1 0 5BC99A4F
P 800 1900
AR Path="/5BB1C5FF/5BC99A4F" Ref="#GND?"  Part="1" 
AR Path="/5BC99A4F" Ref="#GND02"  Part="1" 
F 0 "#GND02" H 800 1900 50  0001 C CNN
F 1 "GND" V 750 1900 59  0000 L BNN
F 2 "" H 800 1900 50  0001 C CNN
F 3 "" H 800 1900 50  0001 C CNN
	1    800  1900
	0    1    1    0   
$EndComp
$Comp
L Arduino-Pro-Mini-eagle-import:CAP0603-CAP C2
U 1 1 5BCA0BB1
P 1850 6850
F 0 "C2" V 1800 6750 59  0000 L CNN
F 1 "0.1uF" V 1800 6950 59  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric" H 1850 6850 50  0001 C CNN
F 3 "" H 1850 6850 50  0001 C CNN
	1    1850 6850
	0    1    1    0   
$EndComp
$Comp
L Arduino-Pro-Mini-eagle-import:CAP0603-CAP C3
U 1 1 5BCA0D26
P 2950 7200
F 0 "C3" V 2900 7150 59  0000 C CNN
F 1 "0.1uF" V 2900 7400 59  0000 C CNN
F 2 "Capacitor_SMD:C_0805_2012Metric" H 2950 7200 50  0001 C CNN
F 3 "" H 2950 7200 50  0001 C CNN
	1    2950 7200
	0    1    1    0   
$EndComp
$Comp
L Arduino-Pro-Mini-eagle-import:CAP0603-CAP C4
U 1 1 5BCA7698
P 2950 7400
F 0 "C4" V 2900 7350 59  0000 C CNN
F 1 "0.1uF" V 2900 7600 59  0000 C CNN
F 2 "Capacitor_SMD:C_0805_2012Metric" H 2950 7400 50  0001 C CNN
F 3 "" H 2950 7400 50  0001 C CNN
	1    2950 7400
	0    1    1    0   
$EndComp
$Comp
L Arduino-Pro-Mini-eagle-import:CAP0603-CAP C5
U 1 1 5BCA76DA
P 2950 7600
F 0 "C5" V 2900 7550 59  0000 C CNN
F 1 "0.1uF" V 2900 7800 59  0000 C CNN
F 2 "Capacitor_SMD:C_0805_2012Metric" H 2950 7600 50  0001 C CNN
F 3 "" H 2950 7600 50  0001 C CNN
	1    2950 7600
	0    1    1    0   
$EndComp
Wire Wire Line
	3000 850  3100 850 
$Comp
L Arduino-Pro-Mini-eagle-import:CAP0603-CAP C?
U 1 0 5BCB6639
P 2900 850
AR Path="/5BB1C5FF/5BCB6639" Ref="C?"  Part="1" 
AR Path="/5BCB6639" Ref="C1"  Part="1" 
F 0 "C1" H 2860 845 59  0000 R TNN
F 1 "0.1uF" H 2860 1035 59  0000 R TNN
F 2 "Capacitor_SMD:C_0805_2012Metric" H 2900 850 50  0001 C CNN
F 3 "" H 2900 850 50  0001 C CNN
	1    2900 850 
	0    -1   -1   0   
$EndComp
Wire Wire Line
	5750 5050 5650 5050
Wire Wire Line
	5750 4950 5650 4950
Wire Wire Line
	5750 5150 5650 5150
Wire Wire Line
	5750 5450 5650 5450
$Comp
L Arduino-Pro-Mini-eagle-import:ARDUINO_SERIAL_PROGRAMPTH JP?
U 1 0 5BD09455
P 5950 5250
AR Path="/5BB1C5FF/5BD09455" Ref="JP?"  Part="1" 
AR Path="/5BD09455" Ref="JP1"  Part="1" 
F 0 "JP1" H 5750 5680 59  0000 L BNN
F 1 "FTDI Basic" V 5600 5100 59  0000 L BNN
F 2 "MyFootprint:1X06" H 5950 5250 50  0001 C CNN
F 3 "" H 5950 5250 50  0001 C CNN
	1    5950 5250
	-1   0    0    -1  
$EndComp
$Comp
L Arduino-Pro-Mini-eagle-import:RESISTOR0603-RES R?
U 1 0 5BD381E2
P 9400 4050
AR Path="/5BB1C5FF/5BD381E2" Ref="R?"  Part="1" 
AR Path="/5BD381E2" Ref="R2"  Part="1" 
F 0 "R2" H 9250 4109 59  0000 L BNN
F 1 "10K" H 9100 3950 59  0000 L BNN
F 2 "Resistor_SMD:R_0805_2012Metric" H 9400 4050 50  0001 C CNN
F 3 "" H 9400 4050 50  0001 C CNN
	1    9400 4050
	0    1    1    0   
$EndComp
$Comp
L Arduino-Pro-Mini-eagle-import:RESISTOR0603-RES R?
U 1 0 5BD381E9
P 9100 4050
AR Path="/5BB1C5FF/5BD381E9" Ref="R?"  Part="1" 
AR Path="/5BD381E9" Ref="R1"  Part="1" 
F 0 "R1" H 8950 4109 59  0000 L BNN
F 1 "10K" H 8800 3950 59  0000 L BNN
F 2 "Resistor_SMD:R_0805_2012Metric" H 9100 4050 50  0001 C CNN
F 3 "" H 9100 4050 50  0001 C CNN
	1    9100 4050
	0    1    1    0   
$EndComp
Wire Wire Line
	2050 6850 2600 6850
Wire Wire Line
	9100 3850 9100 3500
Wire Wire Line
	9400 3850 9400 3500
Text GLabel 9100 4550 3    50   Input ~ 0
SCL
Text GLabel 9400 4550 3    50   Input ~ 0
SDA
Text GLabel 6850 4250 0    50   Input ~ 0
SCL
Text GLabel 6950 4250 2    50   Input ~ 0
SDA
Wire Wire Line
	5200 4350 6850 4350
$Sheet
S 5800 2500 650  500 
U 5BCD5A00
F0 "clock-ISP schema" 50
F1 "clock-ISP.sch" 50
F2 "MISO" I L 5800 2850 50 
F3 "MOSI" I L 5800 2750 50 
F4 "GND" I R 6450 2650 50 
F5 "SCK" I L 5800 2650 50 
F6 "SCL_1" I R 6450 2850 50 
F7 "SDA_1" I R 6450 2950 50 
F8 "RESET" I R 6450 2750 50 
F9 "INTSQW" I L 5800 2550 50 
F10 "5V" I R 6450 2550 50 
$EndSheet
Text GLabel 6550 2750 2    50   Input ~ 0
RESET
Wire Wire Line
	6450 2550 6850 2550
Wire Wire Line
	6850 2550 6850 2400
Wire Wire Line
	6450 2650 6900 2650
Wire Wire Line
	6450 2750 6550 2750
Text GLabel 6550 2850 2    50   Input ~ 0
SCL
Text GLabel 6550 2950 2    50   Input ~ 0
SDA
Wire Wire Line
	6450 2850 6550 2850
Wire Wire Line
	6450 2950 6550 2950
$Sheet
S 10400 1300 500  400 
U 5BD8CA77
F0 "Power_Regulator" 50
F1 "Power_Regu.sch" 50
F2 "GND" I L 10400 1600 50 
F3 "Vbatt" I L 10400 1400 50 
F4 "5v" I L 10400 1500 50 
$EndSheet
Wire Wire Line
	10300 1400 10400 1400
Wire Wire Line
	10300 1750 10300 1600
Wire Wire Line
	10300 1600 10400 1600
$Sheet
S 6850 5450 650  400 
U 5BC6599D
F0 "Switch_LED" 50
F1 "Switches.sch" 50
F2 "SWITCH1" I L 6850 5550 50 
F3 "GND" I R 7500 5700 50 
F4 "SWITCH2" I L 6850 5650 50 
F5 "SWITCH3" I L 6850 5750 50 
F6 "5V" I R 7500 5600 50 
$EndSheet
Wire Wire Line
	7500 5700 7800 5700
Wire Wire Line
	7500 5600 7700 5600
Wire Wire Line
	7700 5600 7700 5550
$Sheet
S 7600 2600 500  450 
U 5CAD23DC
F0 "SD_Card" 50
F1 "microsd.sch" 50
F2 "CLK" I L 7600 2700 50 
F3 "DO" I L 7600 2900 50 
F4 "DI" I L 7600 2800 50 
F5 "CS" I L 7600 3000 50 
F6 "5V" I R 8100 2750 50 
F7 "GND" I R 8100 2850 50 
F8 "SD_EN" I R 8100 2950 50 
$EndSheet
Wire Wire Line
	7600 2700 7400 2700
Wire Wire Line
	7600 2800 7400 2800
Wire Wire Line
	7600 2900 7400 2900
Wire Wire Line
	7600 3000 7400 3000
Wire Wire Line
	5200 2950 5400 2950
Text Label 5400 2950 0    50   ~ 0
SD_CS
Text Label 7400 3000 2    50   ~ 0
SD_CS
Text Label 7400 2900 2    60   ~ 0
MISO
Text Label 7400 2800 2    60   ~ 0
MOSI
Text Label 7400 2700 2    60   ~ 0
SCK
Text GLabel 3100 850  2    50   Input ~ 0
DTR
Text GLabel 5650 5450 0    50   Input ~ 0
DTR
$Sheet
S 5400 6100 650  400 
U 5CB730E5
F0 "led" 50
F1 "LEDS.sch" 50
F2 "LED1" I L 5400 6150 50 
F3 "LED2" I L 5400 6250 50 
F4 "LED3" I L 5400 6350 50 
F5 "LED4" I L 5400 6450 50 
F6 "GND" I R 6050 6300 50 
$EndSheet
Wire Wire Line
	5200 6150 5400 6150
Wire Wire Line
	5200 6250 5400 6250
Wire Wire Line
	5200 6350 5400 6350
Wire Wire Line
	5200 6450 5400 6450
Wire Wire Line
	10300 1050 10300 1400
$Comp
L Arduino-Pro-Mini-eagle-import:GND #GND?
U 1 0 5CC1B72F
P 10300 1850
AR Path="/5BB1C5FF/5CC1B72F" Ref="#GND?"  Part="1" 
AR Path="/5CC1B72F" Ref="#GND016"  Part="1" 
F 0 "#GND016" H 10300 1850 50  0001 C CNN
F 1 "GND" H 10200 1750 59  0000 L BNN
F 2 "" H 10300 1850 50  0001 C CNN
F 3 "" H 10300 1850 50  0001 C CNN
	1    10300 1850
	1    0    0    -1  
$EndComp
Wire Wire Line
	5200 1650 5400 1650
Text Label 5400 1650 0    50   ~ 0
EN
$Comp
L Mainboard-rescue:+12V #PWR011
U 1 1 5CCD914E
P 10300 1050
F 0 "#PWR011" H 10300 1000 20  0001 C CNN
F 1 "+12V" H 10300 1188 30  0000 C CNN
F 2 "" H 10300 1050 60  0000 C CNN
F 3 "" H 10300 1050 60  0000 C CNN
	1    10300 1050
	1    0    0    -1  
$EndComp
$Comp
L Arduino-Pro-Mini-eagle-import:GND #GND?
U 1 0 5CD300ED
P 7000 2650
AR Path="/5BB1C5FF/5CD300ED" Ref="#GND?"  Part="1" 
AR Path="/5CD300ED" Ref="#GND011"  Part="1" 
F 0 "#GND011" H 7000 2650 50  0001 C CNN
F 1 "GND" H 6900 2550 59  0000 L BNN
F 2 "" H 7000 2650 50  0001 C CNN
F 3 "" H 7000 2650 50  0001 C CNN
	1    7000 2650
	0    -1   -1   0   
$EndComp
$Comp
L Arduino-Pro-Mini-eagle-import:GND #GND?
U 1 0 5CD30542
P 7900 5700
AR Path="/5BB1C5FF/5CD30542" Ref="#GND?"  Part="1" 
AR Path="/5CD30542" Ref="#GND012"  Part="1" 
F 0 "#GND012" H 7900 5700 50  0001 C CNN
F 1 "GND" H 7800 5600 59  0000 L BNN
F 2 "" H 7900 5700 50  0001 C CNN
F 3 "" H 7900 5700 50  0001 C CNN
	1    7900 5700
	0    -1   -1   0   
$EndComp
$Sheet
S 1650 2350 550  450 
U 5CFC98A7
F0 "T_sensor" 50
F1 "T_Part.sch" 50
F2 "SYNC" I L 1650 2750 50 
F3 "DIN" I L 1650 2650 50 
F4 "SCLK" I L 1650 2550 50 
F5 "MISO" I R 2200 2550 50 
F6 "SS" I R 2200 2650 50 
F7 "SCK" I R 2200 2750 50 
F8 "5V" I L 1650 2450 50 
F9 "GND" I R 2200 2450 50 
$EndSheet
$Comp
L Arduino-Pro-Mini-eagle-import:GND #GND?
U 1 0 5CFCE962
P 2500 2450
AR Path="/5BB1C5FF/5CFCE962" Ref="#GND?"  Part="1" 
AR Path="/5CFCE962" Ref="#GND04"  Part="1" 
F 0 "#GND04" H 2500 2450 50  0001 C CNN
F 1 "GND" V 2600 2450 59  0000 L BNN
F 2 "" H 2500 2450 50  0001 C CNN
F 3 "" H 2500 2450 50  0001 C CNN
	1    2500 2450
	0    -1   -1   0   
$EndComp
Wire Wire Line
	2200 2450 2400 2450
$Comp
L Arduino-Pro-Mini-eagle-import:GND #GND?
U 1 0 5CFFE558
P 8700 2850
AR Path="/5BB1C5FF/5CFFE558" Ref="#GND?"  Part="1" 
AR Path="/5CFFE558" Ref="#GND014"  Part="1" 
F 0 "#GND014" H 8700 2850 50  0001 C CNN
F 1 "GND" H 8600 2750 59  0000 L BNN
F 2 "" H 8700 2850 50  0001 C CNN
F 3 "" H 8700 2850 50  0001 C CNN
	1    8700 2850
	0    -1   -1   0   
$EndComp
Wire Wire Line
	8100 2750 8600 2750
Wire Wire Line
	8600 2750 8600 2700
Wire Wire Line
	8100 2850 8600 2850
$Comp
L Arduino-Pro-Mini-eagle-import:GND #GND?
U 1 0 5D3250F1
P 5500 3650
AR Path="/5BB1C5FF/5D3250F1" Ref="#GND?"  Part="1" 
AR Path="/5D3250F1" Ref="#GND08"  Part="1" 
F 0 "#GND08" H 5500 3650 50  0001 C CNN
F 1 "GND" H 5400 3550 59  0000 L BNN
F 2 "" H 5500 3650 50  0001 C CNN
F 3 "" H 5500 3650 50  0001 C CNN
	1    5500 3650
	1    0    0    -1  
$EndComp
NoConn ~ 5650 5050
NoConn ~ 5650 5150
$Comp
L Arduino-Pro-Mini-eagle-import:GND #GND?
U 1 0 5D3518A4
P 5550 4950
AR Path="/5BB1C5FF/5D3518A4" Ref="#GND?"  Part="1" 
AR Path="/5D3518A4" Ref="#GND09"  Part="1" 
F 0 "#GND09" H 5550 4950 50  0001 C CNN
F 1 "GND" H 5450 4850 59  0000 L BNN
F 2 "" H 5550 4950 50  0001 C CNN
F 3 "" H 5550 4950 50  0001 C CNN
	1    5550 4950
	0    1    1    0   
$EndComp
$Comp
L Arduino-Pro-Mini-eagle-import:GND #GND?
U 1 0 5D361BF9
P 6350 6400
AR Path="/5BB1C5FF/5D361BF9" Ref="#GND?"  Part="1" 
AR Path="/5D361BF9" Ref="#GND010"  Part="1" 
F 0 "#GND010" H 6350 6400 50  0001 C CNN
F 1 "GND" H 6250 6300 59  0000 L BNN
F 2 "" H 6350 6400 50  0001 C CNN
F 3 "" H 6350 6400 50  0001 C CNN
	1    6350 6400
	1    0    0    -1  
$EndComp
Wire Wire Line
	6350 6300 6050 6300
Wire Wire Line
	2700 850  2550 850 
Wire Wire Line
	9850 1500 9950 1500
Wire Wire Line
	9950 1700 9950 1500
Connection ~ 9950 1500
Wire Wire Line
	9950 1500 10400 1500
Wire Wire Line
	9950 2000 9950 2150
$Comp
L Arduino-Pro-Mini-eagle-import:GND #GND?
U 1 0 5BDC003E
P 9950 2750
AR Path="/5BB1C5FF/5BDC003E" Ref="#GND?"  Part="1" 
AR Path="/5BDC003E" Ref="#GND015"  Part="1" 
F 0 "#GND015" H 9950 2750 50  0001 C CNN
F 1 "GND" H 9850 2650 59  0000 L BNN
F 2 "" H 9950 2750 50  0001 C CNN
F 3 "" H 9950 2750 50  0001 C CNN
	1    9950 2750
	1    0    0    -1  
$EndComp
$Comp
L Arduino-Pro-Mini-eagle-import:RESISTOR0603-RES R3
U 1 1 5BDC010A
P 9950 2350
F 0 "R3" V 9897 2418 59  0000 L CNN
F 1 "330" V 10002 2418 59  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric" H 9950 2350 50  0001 C CNN
F 3 "" H 9950 2350 50  0001 C CNN
	1    9950 2350
	0    1    1    0   
$EndComp
Wire Wire Line
	9950 2550 9950 2650
Wire Wire Line
	8100 2950 8350 2950
Text Label 8350 2950 0    50   ~ 0
SD_EN
Text Label 5400 3050 0    50   ~ 0
SD_EN
Wire Wire Line
	5400 3050 5200 3050
$Comp
L Z&T_Sensor-rescue:TPS2010-Z&T_Seonsor-rescue TPS1
U 1 1 5BD9DB74
P 1100 3000
F 0 "TPS1" H 1100 2950 50  0000 C CNN
F 1 "TPS2010" H 1100 3050 50  0000 C CNN
F 2 "MyFootprint:TPS2010_SOIC-8-N8_3.9x4.9mm_P1.27mm" H 1100 3000 50  0001 C CNN
F 3 "" H 1100 3000 50  0001 C CNN
	1    1100 3000
	-1   0    0    -1  
$EndComp
$Comp
L Arduino-Pro-Mini-eagle-import:GND #GND?
U 1 0 5BDDC40D
P 2000 3450
AR Path="/5BB1C5FF/5BDDC40D" Ref="#GND?"  Part="1" 
AR Path="/5BDDC40D" Ref="#GND03"  Part="1" 
F 0 "#GND03" H 2000 3450 50  0001 C CNN
F 1 "GND" H 1907 3372 59  0000 L BNN
F 2 "" H 2000 3450 50  0001 C CNN
F 3 "" H 2000 3450 50  0001 C CNN
	1    2000 3450
	-1   0    0    -1  
$EndComp
Wire Wire Line
	2179 3250 2600 3250
Wire Wire Line
	1500 2550 1500 3050
$Comp
L Z&T_Sensor-rescue:TPS2010-Z&T_Seonsor-rescue TPS2
U 1 1 5BE04DC1
P 7800 3500
F 0 "TPS2" H 7800 3450 50  0000 C CNN
F 1 "TPS2010" H 7800 3550 50  0000 C CNN
F 2 "MyFootprint:TPS2010_SOIC-8-N8_3.9x4.9mm_P1.27mm" H 7800 3500 50  0001 C CNN
F 3 "" H 7800 3500 50  0001 C CNN
	1    7800 3500
	-1   0    0    -1  
$EndComp
$Comp
L Arduino-Pro-Mini-eagle-import:GND #GND?
U 1 0 5BE1792B
P 8250 3500
AR Path="/5BB1C5FF/5BE1792B" Ref="#GND?"  Part="1" 
AR Path="/5BE1792B" Ref="#GND013"  Part="1" 
F 0 "#GND013" H 8250 3500 50  0001 C CNN
F 1 "GND" H 8150 3400 59  0000 L BNN
F 2 "" H 8250 3500 50  0001 C CNN
F 3 "" H 8250 3500 50  0001 C CNN
	1    8250 3500
	-1   0    0    1   
$EndComp
Wire Wire Line
	8100 3650 8250 3650
Wire Wire Line
	8250 3650 8250 3600
$Sheet
S 5850 3350 800  800 
U 5BB27FAF
F0 "Z_sensor" 50
F1 "Z_Part.sch" 50
F2 "SCL" I R 6650 3550 50 
F3 "SDA" I R 6650 3450 50 
F4 "SYNC" I L 5850 3850 50 
F5 "DIN" I L 5850 3950 50 
F6 "SCLK" I L 5850 4050 50 
F7 "SCLcalib" I R 6650 4050 50 
F8 "SDAcalib" I R 6650 3950 50 
F9 "5V" I L 5850 3450 50 
F10 "GND" I L 5850 3550 50 
F11 "SDArfb" I R 6650 3700 50 
F12 "SCLrfb" I R 6650 3800 50 
$EndSheet
Wire Wire Line
	5500 3550 5850 3550
Wire Wire Line
	5850 3450 5650 3450
Wire Wire Line
	5650 3450 5650 3250
Wire Wire Line
	5650 3250 7350 3250
Wire Wire Line
	5200 2650 5800 2650
$Comp
L Arduino-Pro-Mini-eagle-import:LED LED1
U 1 1 5BDEA5AB
P 9950 1800
F 0 "LED1" H 9850 1850 59  0000 L CNN
F 1 "LED" H 9900 1650 59  0000 L CNN
F 2 "microsd:CHIP-LED0805" H 9950 1800 50  0001 C CNN
F 3 "" H 9950 1800 50  0001 C CNN
	1    9950 1800
	1    0    0    -1  
$EndComp
Wire Wire Line
	800  3300 700  3300
Wire Wire Line
	700  3300 700  3450
Wire Wire Line
	700  3450 800  3450
Wire Wire Line
	700  3150 800  3150
Wire Wire Line
	2179 3250 2179 3600
Wire Wire Line
	1400 3300 1550 3300
Wire Wire Line
	1400 3450 1550 3450
Wire Wire Line
	1550 3450 1550 3300
Wire Wire Line
	800  3600 700  3600
Wire Wire Line
	700  3600 700  3450
Connection ~ 700  3450
Wire Wire Line
	700  3300 700  3150
Connection ~ 700  3300
Connection ~ 700  3150
Wire Wire Line
	700  3150 700  2450
Wire Wire Line
	700  2450 1650 2450
Wire Wire Line
	1700 3350 1700 3300
Wire Wire Line
	1700 3300 1550 3300
Connection ~ 1550 3300
Wire Wire Line
	1500 3050 2600 3050
Wire Wire Line
	2000 3150 2000 3350
Wire Wire Line
	1400 3150 2000 3150
Wire Wire Line
	7500 4100 7350 4100
Wire Wire Line
	7350 4100 7350 3950
Wire Wire Line
	7500 3950 7350 3950
Connection ~ 7350 3950
Wire Wire Line
	7350 3950 7350 3800
Wire Wire Line
	7500 3800 7350 3800
Connection ~ 7350 3800
Wire Wire Line
	7350 3800 7350 3650
Wire Wire Line
	7500 3650 7350 3650
Connection ~ 7350 3650
Wire Wire Line
	7350 3650 7350 3250
Wire Wire Line
	8100 4100 8100 4550
Wire Wire Line
	8100 3800 8300 3800
Wire Wire Line
	8550 3800 8550 3950
Wire Wire Line
	8100 3950 8300 3950
Wire Wire Line
	8300 3950 8300 3800
Connection ~ 8300 3800
Wire Wire Line
	8300 3800 8550 3800
$Comp
L Mainboard-rescue:+5V #PWR10
U 1 1 5BE1DF34
P 9850 1500
F 0 "#PWR10" H 10050 1450 50  0001 C CNN
F 1 "+5V" H 9841 1669 50  0000 C CNN
F 2 "" H 9850 1500 50  0001 C CNN
F 3 "" H 9850 1500 50  0001 C CNN
	1    9850 1500
	1    0    0    -1  
$EndComp
$Comp
L Mainboard-rescue:+5V #PWR9
U 1 1 5BE1E25A
P 9250 3450
F 0 "#PWR9" H 9450 3400 50  0001 C CNN
F 1 "+5V" H 9241 3619 50  0000 C CNN
F 2 "" H 9250 3450 50  0001 C CNN
F 3 "" H 9250 3450 50  0001 C CNN
	1    9250 3450
	1    0    0    -1  
$EndComp
$Comp
L Mainboard-rescue:+5V #PWR8
U 1 1 5BE1E3AA
P 8600 2700
F 0 "#PWR8" H 8800 2650 50  0001 C CNN
F 1 "+5V" H 8591 2869 50  0000 C CNN
F 2 "" H 8600 2700 50  0001 C CNN
F 3 "" H 8600 2700 50  0001 C CNN
	1    8600 2700
	1    0    0    -1  
$EndComp
$Comp
L Mainboard-rescue:+5V #PWR7
U 1 1 5BE1E3E0
P 8550 3950
F 0 "#PWR7" H 8750 3900 50  0001 C CNN
F 1 "+5V" H 8542 4118 50  0000 C CNN
F 2 "" H 8550 3950 50  0001 C CNN
F 3 "" H 8550 3950 50  0001 C CNN
	1    8550 3950
	-1   0    0    1   
$EndComp
$Comp
L Mainboard-rescue:+5V #PWR5
U 1 1 5BE2DE88
P 6850 2400
F 0 "#PWR5" H 7050 2350 50  0001 C CNN
F 1 "+5V" H 6841 2569 50  0000 C CNN
F 2 "" H 6850 2400 50  0001 C CNN
F 3 "" H 6850 2400 50  0001 C CNN
	1    6850 2400
	1    0    0    -1  
$EndComp
$Comp
L Mainboard-rescue:+5V #PWR6
U 1 1 5BE2E01C
P 7700 5550
F 0 "#PWR6" H 7900 5500 50  0001 C CNN
F 1 "+5V" H 7691 5719 50  0000 C CNN
F 2 "" H 7700 5550 50  0001 C CNN
F 3 "" H 7700 5550 50  0001 C CNN
	1    7700 5550
	1    0    0    -1  
$EndComp
$Comp
L Mainboard-rescue:+5V #PWR2
U 1 1 5BE2E1C0
P 3550 1200
F 0 "#PWR2" H 3750 1150 50  0001 C CNN
F 1 "+5V" H 3541 1369 50  0000 C CNN
F 2 "" H 3550 1200 50  0001 C CNN
F 3 "" H 3550 1200 50  0001 C CNN
	1    3550 1200
	1    0    0    -1  
$EndComp
$Comp
L Mainboard-rescue:+5V #PWR3
U 1 1 5BE2E211
P 3650 900
F 0 "#PWR3" H 3850 850 50  0001 C CNN
F 1 "+5V" H 3641 1069 50  0000 C CNN
F 2 "" H 3650 900 50  0001 C CNN
F 3 "" H 3650 900 50  0001 C CNN
	1    3650 900 
	1    0    0    -1  
$EndComp
$Comp
L Mainboard-rescue:+5V #PWR4
U 1 1 5BE2E238
P 4050 900
F 0 "#PWR4" H 4250 850 50  0001 C CNN
F 1 "+5V" H 4041 1069 50  0000 C CNN
F 2 "" H 4050 900 50  0001 C CNN
F 3 "" H 4050 900 50  0001 C CNN
	1    4050 900 
	1    0    0    -1  
$EndComp
$Comp
L Mainboard-rescue:+5V #PWR1
U 1 1 5BE2E35C
P 1700 3350
F 0 "#PWR1" H 1900 3300 50  0001 C CNN
F 1 "+5V" H 1600 3400 50  0000 C CNN
F 2 "" H 1700 3350 50  0001 C CNN
F 3 "" H 1700 3350 50  0001 C CNN
	1    1700 3350
	-1   0    0    1   
$EndComp
Wire Wire Line
	2600 1650 2550 1650
Wire Wire Line
	2550 1650 2550 850 
Wire Wire Line
	2600 1950 2300 1950
Wire Wire Line
	2300 1950 2300 1650
Wire Wire Line
	900  1900 1100 1900
Wire Wire Line
	1400 2000 1100 2000
Wire Wire Line
	1100 2000 1100 1900
Connection ~ 1100 1900
Wire Wire Line
	1100 1900 1400 1900
$Comp
L Arduino-Pro-Mini-eagle-import:CAP0603-CAP C64
U 1 1 5C0C65C2
P 1250 1650
F 0 "C64" V 1200 1550 59  0000 L CNN
F 1 "22pF" V 1200 1750 59  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric" H 1250 1650 50  0001 C CNN
F 3 "" H 1250 1650 50  0001 C CNN
	1    1250 1650
	0    1    1    0   
$EndComp
$Comp
L Arduino-Pro-Mini-eagle-import:CAP0603-CAP C65
U 1 1 5C0C677B
P 1250 2250
F 0 "C65" V 1200 2150 59  0000 L CNN
F 1 "22pF" V 1200 2350 59  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric" H 1250 2250 50  0001 C CNN
F 3 "" H 1250 2250 50  0001 C CNN
	1    1250 2250
	0    1    1    0   
$EndComp
$Comp
L Arduino-Pro-Mini-eagle-import:GND #GND?
U 1 0 5C0D845D
P 800 1650
AR Path="/5BB1C5FF/5C0D845D" Ref="#GND?"  Part="1" 
AR Path="/5C0D845D" Ref="#GND017"  Part="1" 
F 0 "#GND017" H 800 1650 50  0001 C CNN
F 1 "GND" V 750 1650 59  0000 L BNN
F 2 "" H 800 1650 50  0001 C CNN
F 3 "" H 800 1650 50  0001 C CNN
	1    800  1650
	0    1    1    0   
$EndComp
Wire Wire Line
	900  1650 1150 1650
$Comp
L Arduino-Pro-Mini-eagle-import:GND #GND?
U 1 0 5C0E14EC
P 800 2250
AR Path="/5BB1C5FF/5C0E14EC" Ref="#GND?"  Part="1" 
AR Path="/5C0E14EC" Ref="#GND018"  Part="1" 
F 0 "#GND018" H 800 2250 50  0001 C CNN
F 1 "GND" V 750 2250 59  0000 L BNN
F 2 "" H 800 2250 50  0001 C CNN
F 3 "" H 800 2250 50  0001 C CNN
	1    800  2250
	0    1    1    0   
$EndComp
Wire Wire Line
	900  2250 1150 2250
Wire Wire Line
	1450 2250 1750 2250
Wire Wire Line
	1450 1650 1750 1650
$Comp
L Mainboard-rescue:CRYSTAL X2
U 1 1 5C156429
P 1750 1950
F 0 "X2" V 1697 2083 60  0000 L CNN
F 1 "CRYSTAL" V 1803 2083 60  0000 L CNN
F 2 "Crystal:Crystal_SMD_SeikoEpson_MA506-4Pin_12.7x5.1mm" H 1750 1950 60  0001 C CNN
F 3 "" H 1750 1950 60  0000 C CNN
	1    1750 1950
	0    1    1    0   
$EndComp
Connection ~ 1750 1650
Wire Wire Line
	1750 1650 2300 1650
Connection ~ 1750 2250
Wire Wire Line
	1750 2250 2600 2250
$Comp
L Arduino-Pro-Mini-eagle-import:RESISTOR0603-RES R?
U 1 0 5C6251DD
P 1600 3900
AR Path="/5BB1C5FF/5C6251DD" Ref="R?"  Part="1" 
AR Path="/5C6251DD" Ref="R6"  Part="1" 
F 0 "R6" V 1700 3950 59  0000 L BNN
F 1 "100K" V 1600 3950 59  0000 L BNN
F 2 "Resistor_SMD:R_0805_2012Metric" H 1600 3900 50  0001 C CNN
F 3 "" H 1600 3900 50  0001 C CNN
	1    1600 3900
	0    -1   -1   0   
$EndComp
$Comp
L Arduino-Pro-Mini-eagle-import:RESISTOR0603-RES R?
U 1 0 5C64158C
P 8400 4850
AR Path="/5BB1C5FF/5C64158C" Ref="R?"  Part="1" 
AR Path="/5C64158C" Ref="R7"  Part="1" 
F 0 "R7" V 8500 4650 59  0000 L BNN
F 1 "100K" V 8400 4550 59  0000 L BNN
F 2 "Resistor_SMD:R_0805_2012Metric" H 8400 4850 50  0001 C CNN
F 3 "" H 8400 4850 50  0001 C CNN
	1    8400 4850
	0    -1   -1   0   
$EndComp
Connection ~ 8100 4550
Wire Wire Line
	5200 4550 8100 4550
Wire Wire Line
	8400 5050 8400 5150
Wire Wire Line
	8100 4550 8400 4550
Wire Wire Line
	8400 4550 8400 4650
$Comp
L Mainboard-rescue:+5V #PWR61
U 1 1 5C6690C4
P 8400 5150
F 0 "#PWR61" H 8600 5100 50  0001 C CNN
F 1 "+5V" H 8392 5318 50  0000 C CNN
F 2 "" H 8400 5150 50  0001 C CNN
F 3 "" H 8400 5150 50  0001 C CNN
	1    8400 5150
	-1   0    0    1   
$EndComp
Wire Wire Line
	1400 3600 1600 3600
Wire Wire Line
	1600 3700 1600 3600
Connection ~ 1600 3600
Wire Wire Line
	1600 3600 2179 3600
$Comp
L Mainboard-rescue:+5V #PWR60
U 1 1 5C686309
P 1600 4200
F 0 "#PWR60" H 1800 4150 50  0001 C CNN
F 1 "+5V" H 1500 4250 50  0000 C CNN
F 2 "" H 1600 4200 50  0001 C CNN
F 3 "" H 1600 4200 50  0001 C CNN
	1    1600 4200
	-1   0    0    1   
$EndComp
Wire Wire Line
	1600 4100 1600 4200
Wire Wire Line
	5200 5250 5750 5250
Wire Wire Line
	5200 5350 5750 5350
Wire Wire Line
	5200 4650 6550 4650
Wire Wire Line
	5200 5650 6850 5650
Wire Wire Line
	6550 5550 6850 5550
Wire Wire Line
	6550 4650 6550 5550
Wire Wire Line
	6850 5750 5200 5750
Text GLabel 2600 3650 0    50   Input ~ 0
ADBATT
Wire Wire Line
	6850 3550 6850 3800
Wire Wire Line
	6650 3800 6850 3800
Connection ~ 6850 3800
Wire Wire Line
	6850 3800 6850 4050
$EndSCHEMATC
