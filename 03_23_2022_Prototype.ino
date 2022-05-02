#include <Wire.h>
#include <Adafruit_ADS1X15.h>

 
Adafruit_ADS1115 ads;         
const float multiplier = 0.1875F;
char dataStr[100] = "";
char buffer[7];

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  //Serial.println("Setting Up ADC");

  if (!ads.begin()) {
    Serial.println("Failed to initialize ADS.");
    while (1);
  }
  // Descomentar el que interese
  // ads.setGain(GAIN_TWOTHIRDS);  +/- 6.144V  1 bit = 0.1875mV (default)
  // ads.setGain(GAIN_ONE);        +/- 4.096V  1 bit = 0.125mV
  // ads.setGain(GAIN_TWO);        +/- 2.048V  1 bit = 0.0625mV
  //ads.setGain(GAIN_FOUR);       //+/- 1.024V  1 bit = 0.03125mV
  // ads.setGain(GAIN_EIGHT);      +/- 0.512V  1 bit = 0.015625mV
  //ads.setGain(GAIN_SIXTEEN);    //+/- 0.256V  1 bit = 0.0078125mV 
}
double start_time = 0;
void loop() {
  //
  dataStr[0] = 0; //clean out string
  
  //github testing code
  int16_t adc0;
  float volts0;

  adc0 = ads.readADC_SingleEnded(0);
  volts0 = ads.computeVolts(adc0);
  Serial.print(start_time);
  Serial.print(" ");
  start_time+=0.1;
  Serial.println(volts0,6);
  
  delay(100);
}
