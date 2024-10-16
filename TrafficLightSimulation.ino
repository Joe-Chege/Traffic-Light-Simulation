#include <Arduino.h>

// Pin Definitions
const int redLightPin = 12;      // Red LED connected to GPIO 12
const int yellowLightPin = 14;   // Yellow LED connected to GPIO 14
const int greenLightPin = 34;    // Green LED connected to GPIO 34
const int buttonPin = 19;        // Pedestrian crossing button connected to GPIO 19

// Variables to store button state
int buttonState = 0;

void setup() {
  // Initialize LED pins as outputs
  pinMode(redLightPin, OUTPUT);
  pinMode(yellowLightPin, OUTPUT);
  pinMode(greenLightPin, OUTPUT);
  
  // Initialize the button pin as input with internal pull-up
  pinMode(buttonPin, INPUT_PULLUP);

  // Start with red light on
  digitalWrite(redLightPin, HIGH);
  digitalWrite(yellowLightPin, LOW);
  digitalWrite(greenLightPin, LOW);
}

void loop() {
  // Check if the button is pressed
  buttonState = digitalRead(buttonPin);

  if (buttonState == LOW) {
    // Pedestrian button pressed, activate pedestrian crossing sequence
    pedestrianCrossing();
  } else {
    // Normal traffic light sequence
    trafficLightSequence();
  }
}

// Function to handle normal traffic light sequence
void trafficLightSequence() {
  // Red light for 5 seconds
  digitalWrite(redLightPin, HIGH);
  digitalWrite(yellowLightPin, LOW);
  digitalWrite(greenLightPin, LOW);
  delay(5000);

  // Green light for 3 seconds
  digitalWrite(redLightPin, LOW);
  digitalWrite(yellowLightPin, LOW);
  digitalWrite(greenLightPin, HIGH);
  delay(3000);

  // Yellow light for 2 seconds
  digitalWrite(redLightPin, LOW);
  digitalWrite(yellowLightPin, HIGH);
  digitalWrite(greenLightPin, LOW);
  delay(2000);
}

// Function to handle pedestrian crossing when button is pressed
void pedestrianCrossing() {
  // Turn on the red light for pedestrian crossing
  digitalWrite(redLightPin, HIGH);
  digitalWrite(yellowLightPin, LOW);
  digitalWrite(greenLightPin, LOW);
  
  // Wait 5 seconds for pedestrians to cross
  delay(5000);
  
  // Return to normal traffic light sequence
}
