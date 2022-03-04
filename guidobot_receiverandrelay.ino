/*
 * Receive data wireless + activate GuidoBot
 * for GuidoBot
 * 
 * Using HC-12 and relay module on Arduino Mega. Relay connected to GuidoBot
 * PROTOTYPE
 * 
 * references:
 * https://howtomechatronics.com/tutorials/arduino/arduino-and-hc-12-long-range-wireless-communication-module/
 * https://howtomechatronics.com/tutorials/arduino/control-high-voltage-devices-arduino-relay-tutorial/
 */

#include <SoftwareSerial.h>
SoftwareSerial HC12(14,15); // HC-12 connected to TX Pin 14, RX Pin 15
int relay_pin = 7;          // Relay control connected to Pin7

void setup() {
  
  HC12.begin(9600);
  pinMode(relay_pin, OUTPUT);  //set relay pin as output
  digitalWrite(relay_pin, LOW);

}

void loop() {
  while(HC12.available()){
    char received_data = HC12.read(); //read byte from HC12 if data exist
    if(received_data = "1"){
      digitalWrite(relay_pin, HIGH); //if received "1" (tire pressure under normal), turn on relay
    }
  }

}
