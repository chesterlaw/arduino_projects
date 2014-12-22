// A servo controlled by a potentiometer
#include <Servo.h>  // servo library

Servo servo1;  // servo control object
int sensorPin = 0; // The potentiometer is connected to analog pin 0
const int buzzerPin = 10; // designate buzzer pin
const int buttonPin = 2;  // pushbutton pin

void setup() {
  servo1.attach(9); //attach servo1 object to diginal pin 9
  Serial.begin(9600);
  pinMode(buzzerPin, OUTPUT);
  pinMode(buttonPin, INPUT);
}

void loop() {
  int sensorValue = analogRead(sensorPin); // get potentiometer value

  int degreesToRotate = sensorValue/1023.0 * 180; // potentiometer goes from 0 to 1023
  // Serial.println(degreesToRotate);

  int delayAmount = 0;
  servo1.write(degreesToRotate); // turn (between 0 and 180)
  delay(delayAmount); // refresh time

  // Buzzer
  int toneLength = 5;
  // Low C on 0 degrees, High C on reaching 180
  if (degreesToRotate == 0) {
    tone(buzzerPin, 262, toneLength);
  } else if (degreesToRotate == 180) {
    tone(buzzerPin, 523, toneLength);
  }

  // Button
  int buttonState = digitalRead(buttonPin);
  Serial.println(buttonState);

  if (buttonState == LOW) {
    tone(buzzerPin, 349, toneLength);    
  }
}
