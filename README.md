# Traffic Light Simulation with ESP32

## Table of Contents
- [Project Description](#project-description)
- [Materials Needed](#materials-needed)
- [Hardware Setup](#hardware-setup)
- [Software Setup](#software-setup)
- [Code Overview](#code-overview)
- [Testing and Simulation](#testing-and-simulation)
- [Version Control and Submitting the Assignment](#version-control-and-submitting-the-assignment)
- [Conclusion](#conclusion)

## Project Description
This project implements a traffic light simulation system using an ESP32 microcontroller. The simulation includes red, yellow, and green LEDs to represent traffic lights, along with a push button that allows pedestrians to request a safe crossing. The system cycles through the traffic lights and accommodates pedestrian requests by turning on the red light when the button is pressed.

## Materials Needed
- ESP32 Development Board
- 3 LEDs (Red, Yellow, Green)
- 1 Push Button
- Resistors (e.g., 220Ω for each LED, 10kΩ for the button)
- Breadboard and Jumper Wires
- USB Cable (for programming the ESP32)

## Hardware Setup
### Step 1: Connect the LEDs
- **Red LED:** Connect the anode (long leg) of the red LED to GPIO 23 via a 220Ω resistor.
- **Yellow LED:** Connect the anode of the yellow LED to GPIO 22 via a 220Ω resistor.
- **Green LED:** Connect the anode of the green LED to GPIO 21 via a 220Ω resistor.
- **Common GND:** Connect the cathode (short leg) of all LEDs to GND on the ESP32.

### Step 2: Connect the Push Button
- **One side of the button:** Connect to GPIO 19 (for input).
- **Other side of the button:** Connect to GND.
- **10kΩ Pull-up Resistor:** Connect between GPIO 19 and 3.3V to prevent floating values.

### Wiring Recap:
- **Red LED →** GPIO 23 (via 220Ω resistor) → GND
- **Yellow LED →** GPIO 22 (via 220Ω resistor) → GND
- **Green LED →** GPIO 21 (via 220Ω resistor) → GND
- **Button →** GPIO 19 (with 10kΩ pull-up resistor)

## Software Setup
### Step 1: Install Arduino IDE
- Download and install the Arduino IDE (if not already installed).
- Install the ESP32 board package via `Tools > Board > Board Manager`.
- Select **ESP32 Dev Module** under `Tools > Board` and choose the correct COM port.

## Code Overview
The traffic lights operate in a timed sequence:
- **Red Light:** On for 5 seconds.
- **Yellow Light:** On for 2 seconds.
- **Green Light:** On for 3 seconds.
- The pedestrian button interrupts the sequence, allowing pedestrians to cross safely by turning the red light on.

### Code Implementation
```cpp
// Pin Definitions
const int redLightPin = 23;     // Red LED connected to GPIO 23
const int yellowLightPin = 22;  // Yellow LED connected to GPIO 22
const int greenLightPin = 21;   // Green LED connected to GPIO 21
const int buttonPin = 19;       // Pedestrian crossing button connected to GPIO 19

// Variables to store button state
int buttonState = 0;

void setup() {
  // Initialize LED pins as outputs
  pinMode(redLightPin, OUTPUT);
  pinMode(yellowLightPin, OUTPUT);
  pinMode(greenLightPin, OUTPUT);
  
  // Initialize the button pin as input
  pinMode(buttonPin, INPUT_PULLUP);  // Use internal pull-up resistor
  
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
