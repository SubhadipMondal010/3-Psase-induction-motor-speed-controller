const int potPin = A0; // Pin for the potentiometer
const int mosfetA = 2; // High-side MOSFET A
const int mosfetB = 3; // High-side MOSFET B
const int mosfetC = 4; // High-side MOSFET C
const int mosfetD = 5; // Low-side MOSFET A'
const int mosfetE = 6; // Low-side MOSFET B'
const int mosfetF = 7; // Low-side MOSFET C'

// Frequency range in Hertz
const float minFrequency = 20.0; // Minimum frequency
const float maxFrequency = 80.0; // Maximum frequency

unsigned long lastStepTime = 0; 
float stepDelay; 
unsigned long Time = 5; // Delay

void setup() {

  pinMode(mosfetA, OUTPUT);
  pinMode(mosfetB, OUTPUT);
  pinMode(mosfetC, OUTPUT);
  pinMode(mosfetD, OUTPUT);
  pinMode(mosfetE, OUTPUT);
  pinMode(mosfetF, OUTPUT);

 
  digitalWrite(mosfetA, LOW);
  digitalWrite(mosfetB, LOW);
  digitalWrite(mosfetC, LOW);
  digitalWrite(mosfetD, LOW);
  digitalWrite(mosfetE, LOW);
  digitalWrite(mosfetF, LOW);
}

void loop() {

  int potValue = analogRead(potPin);
  float frequency = map(potValue, 0, 1023, minFrequency * 100, maxFrequency * 100) / 100.0;

  stepDelay = 1000.0 / (frequency * 6); 
 
  if (millis() - lastStepTime >= stepDelay) {
    lastStepTime = millis();
    cyclePhases(); 
  }
}

void cyclePhases() {
  static int step = 0;

  switch (step) {
    case 0:
      digitalWrite(mosfetA, HIGH);
      digitalWrite(mosfetD, LOW);
      delay(Time);  
      break;
    case 1: 
      digitalWrite(mosfetB, HIGH);
      digitalWrite(mosfetE, LOW);
      delay(Time);  
      break;
    case 2: 
      digitalWrite(mosfetC, HIGH);
      digitalWrite(mosfetF, LOW);
      delay(Time);  
      break;
    case 3: 
      digitalWrite(mosfetA, LOW);
      digitalWrite(mosfetD, HIGH);
      delay(Time);  
      break;
    case 4: 
      digitalWrite(mosfetB, LOW);
      digitalWrite(mosfetE, HIGH);
      delay(Time);  
      break;
    case 5: 
      digitalWrite(mosfetC, LOW);
      digitalWrite(mosfetF, HIGH);
      delay(Time);  
      break;
  }

  step = (step + 1) % 6;
}
