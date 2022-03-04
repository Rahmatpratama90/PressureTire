/*
 * Reading pressure sensor + wireless transmit data
 * for GuidoBot
 * 
 * Using MPX5010DP and HC-12 on Arduino Mega
 * PROTOTYPE
 * 
 * references:
 * https://www.instructables.com/How-to-Read-MPX5010-Differential-Pressure-Sensor-W/
 * https://howtomechatronics.com/tutorials/arduino/arduino-and-hc-12-long-range-wireless-communication-module/
 */

#include <SoftwareSerial.h>
SoftwareSerial HC12(14,15); // HC-12 connected to TX Pin14, RX Pin15
int sensor_pin = A8;        //pressure sensor connected to PinA8

const float ADC_mV = 4.8828125;       // convesion multiplier from Arduino ADC value to voltage in mV
const float SensorOffset = 200.0;     // in mV taken from datasheet
const float sensitivity = 4.413;      // in mV/mmH2O taken from datasheet
const float mmh2O_cmH2O = 10;         // divide by this figure to convert mmH2O to cmH2O
const float mmh2O_kpa = 0.00981;      // convesion multiplier from mmH2O to kPa

float pressure_threshold = 32.0;   //normal car tire pressure in psi


void setup() {

  HC12.begin(9600);

}

void loop() {

  float input_sensor = analogRead(sensor_pin); //read from pressure sensor
  float sensorValue = ((input_sensor * ADC_mV - SensorOffset) / sensitivity * mmh2O_kpa)*0.145;     // result in psi
  
  if(sensorValue <= pressure_threshold){
    HC12.write("1");                          //if pressure is less than normal value, send signal to activate GuidoBot
  }

}
