//import libraries needed
#include <Wire.h>
#include <Adafruit_ADS1X15.h>

 //create necessary global variables
Adafruit_ADS1115 ads;         
const float multiplier = 0.1875F;
char dataStr[100] = "";
char buffer[7];

void setup() {
  // put your setup code here, to run once:
  //set up the baud rate for the arduino, matches python code
  Serial.begin(9600);
  //Serial.println("Setting Up ADC");

  //attempts to initialize the adc
  if (!ads.begin()) {
    Serial.println("Failed to initialize ADS.");
    while (1);
  }
  // Gain values you can set
  // ads.setGain(GAIN_TWOTHIRDS);  +/- 6.144V  1 bit = 0.1875mV (default)
  // ads.setGain(GAIN_ONE);        +/- 4.096V  1 bit = 0.125mV
  // ads.setGain(GAIN_TWO);        +/- 2.048V  1 bit = 0.0625mV
  //ads.setGain(GAIN_FOUR);       //+/- 1.024V  1 bit = 0.03125mV
  // ads.setGain(GAIN_EIGHT);      +/- 0.512V  1 bit = 0.015625mV
  //ads.setGain(GAIN_SIXTEEN);    //+/- 0.256V  1 bit = 0.0078125mV 
}

//start time 
double start_time = 0;
void loop() {
  //
  dataStr[0] = 0; //clean out string
  
  //github testing code
  int16_t adc0;
  float volts0;

  //read adc value
  adc0 = ads.readADC_SingleEnded(0);
  //convert adc value to actual voltage value
  volts0 = ads.computeVolts(adc0);
  //prints the start time
  Serial.print(start_time);
  Serial.print(" ");
  //increments the start time
  //currently it is set to run 10 times a second
  start_time+=0.1;
  //prints out the voltage
  Serial.println(volts0,6);
  
  //adc sampling at 10 times per second
  //can alter but must also alter the increment for the start_time
  delay(100);
}
