const int potPin = A0; // Pin for the potentiometer
const int mosfetA = 2; // High-side MOSFET A
const int mosfetB = 3; // Low-side MOSFET B
const int mosfetC = 4; // High-side MOSFET C
const int mosfetD = 5; // Low-side MOSFET D
const int mosfetE = 6; // High-side MOSFET E
const int mosfetF = 7; // Low-side MOSFET F

// Frequency range in Hertz
const float minFrequency = 20.0; // Minimum frequency
const float maxFrequency = 80.0; // Maximum frequency

unsigned long lastStepTime = 0; // Stores the last time a phase change occurred
float stepDelay; // Time delay per phase change based on frequency
unsigned long Time = 5; // Delay

void setup() {
  // Set MOSFET pins as outputs
  pinMode(mosfetA, OUTPUT);
  pinMode(mosfetB, OUTPUT);
  pinMode(mosfetC, OUTPUT);
  pinMode(mosfetD, OUTPUT);
  pinMode(mosfetE, OUTPUT);
  pinMode(mosfetF, OUTPUT);

  // Start with all MOSFETs off
  digitalWrite(mosfetA, LOW);
  digitalWrite(mosfetB, LOW);
  digitalWrite(mosfetC, LOW);
  digitalWrite(mosfetD, LOW);
  digitalWrite(mosfetE, LOW);
  digitalWrite(mosfetF, LOW);
}

void loop() {
  // Read potentiometer value and map to frequency range
  int potValue = analogRead(potPin);
  float frequency = map(potValue, 0, 1023, minFrequency * 100, maxFrequency * 100) / 100.0;

  // Calculate the delay per phase step in milliseconds
  stepDelay = 1000.0 / (frequency * 6); // 6 steps per cycle

  // Check if it’s time to change the phase
  if (millis() - lastStepTime >= stepDelay) {
    lastStepTime = millis();
    cyclePhases(); // Cycle through the phases to drive the motor
  }
}

// Function to handle the 6-step phase sequence for 3-phase control
void cyclePhases() {
  static int step = 0;

  // Six-step commutation sequence for three-phase control
  switch (step) {
    case 0:
      digitalWrite(mosfetA, HIGH);
      digitalWrite(mosfetB, LOW);
      delay(Time);  
      break;
    case 1: 
      digitalWrite(mosfetC, HIGH);
      digitalWrite(mosfetD, LOW);
      delay(Time);  
      break;
    case 2: 
      digitalWrite(mosfetE, HIGH);
      digitalWrite(mosfetF, LOW);
      delay(Time);  
      break;
    case 3: 
      digitalWrite(mosfetA, LOW);
      digitalWrite(mosfetB, HIGH);
      delay(Time);  
      break;
    case 4: 
      digitalWrite(mosfetC, LOW);
      digitalWrite(mosfetD, HIGH);
      delay(Time);  
      break;
    case 5: 
      digitalWrite(mosfetE, LOW);
      digitalWrite(mosfetF, HIGH);
      delay(Time);  
      break;
  }

  // Move to the next step in the sequence
  step = (step + 1) % 6;
}
