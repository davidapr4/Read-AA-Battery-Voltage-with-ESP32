#include <Arduino.h>

const float referenceVolt = 3.3; // the default reference on a esp32 board

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(2,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int sensorValue = analogRead(2);
  float volts = (sensorValue / 4095.0) * referenceVolt;
  int mapVolts = map(volts * 100, 0, 33, 0, 100) / 10; 
  Serial.println(sensorValue);
  Serial.print("Voltage            : ");
  Serial.print(volts);
  Serial.print(" V");
  Serial.print(" | ");
  Serial.print(mapVolts);
  Serial.println(" %");
  delay(2000);
}