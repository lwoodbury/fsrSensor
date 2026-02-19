/*
Simple fsr analog sensor
This uses pin 13 which is PWM enabled (i.e. we can do 'analogWrite')
on a micro, but not on an Uno for example
Luke Woodbury 19th Feb 2026
*/

const int analogInPin = A0; 
const int LEDpin = 13; 

int sensorValue = 0;

void setup() {
  // initialize serial communications at 9600 bps
  // comment out all the serial stuff for speed once you are set
  Serial.begin(9600);
  pinMode(LEDpin, OUTPUT);
}

void loop() {
  sensorValue = analogRead(analogInPin);
  
  // print the results to the Serial Monitor:
  Serial.print("sensor = ");
  Serial.print(sensorValue);

  sensorValue = map(sensorValue, 0, 1023, 0, 255);
  analogWrite(LEDpin, sensorValue);
  
  // wait 2 milliseconds before the next loop for the analog-to-digital
  // converter to settle after the last reading:
  delay(2);
}
