

/*
PWM.h

 Mimics the fade example but with an extra parameter for frequency. It should dim but with a flicker 
 because the frequency has been set low enough for the human eye to detect. This flicker is easiest to see when 
 the LED is moving with respect to the eye and when it is between about 20% - 60% brighness. The library 
 allows for a frequency range from 1Hz - 2MHz on 16 bit timers and 31Hz - 2 MHz on 8 bit timers. When 
 SetPinFrequency()/SetPinFrequencySafe() is called, a bool is returned which can be tested to verify the 
 frequency was actually changed.
 
 This example runs on mega and uno.
 */


int32_t frequency = 1;  // Set the frequency(HZ), can work with 10Hz to 300kHz aprox
#include <PWM.h>
#define outputEnable 4  //Pin the enable A6275's led's outputs
#define clk 9 //Pin who makes the clk signal for A627
#define latchEnable 8 //Pin enable the A6275's latches (when is high) 
#define serialDataOut 2 //Point to A6275's serialDataIn pin


void setup() {
  InitTimersSafe(); 
  Serial.begin(9600);
  bool success = SetPinFrequencySafe(9, frequency);

  int sensorValue = analogRead(A4);

  if(success) {
    //When arduino's led "L" is high, means success
    pinMode(13, OUTPUT);
    digitalWrite(13, HIGH);
    Serial.println("SetPinFrequencySafe: Success");
  }
}

void loop() {
  sensorValue = analogRead(A4); //Change A4 value, change the duty cycle
  
  pwmWrite(9, sensorValue / 4);  //pin 9 is the output clk pin
  delay(30);
}
