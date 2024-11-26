const int mosfetA = 2; // High-side MOSFET A
const int mosfetB = 3; // High-side MOSFET B
const int mosfetC = 4; // High-side MOSFET C
const int mosfetD = 5; // Low-side MOSFET A'
const int mosfetE = 6; // Low-side MOSFET B'
const int mosfetF = 7; // Low-side MOSFET C'


const float degreeToMs = 20.0 / 360.0; 

unsigned long startTime;

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

 
  startTime = millis();
}

void loop() {

  unsigned long elapsedTime = millis() - startTime;

 
  if (elapsedTime >= 20) {
    elapsedTime = 0;
    startTime = millis();
  }


  float currentDegree = (elapsedTime / degreeToMs);


  if (currentDegree >= 20 && currentDegree < 160) {
    digitalWrite(mosfetA, HIGH);
  } else {
    digitalWrite(mosfetA, LOW);
  }

  if (currentDegree >= 140 && currentDegree < 280) {
    digitalWrite(mosfetB, HIGH);
  } else {
    digitalWrite(mosfetB, LOW);
  }

  if (currentDegree >= 260 || currentDegree < 40) {
    digitalWrite(mosfetC, HIGH);
  } else {
    digitalWrite(mosfetC, LOW);
  }

  





  if (currentDegree >= 200 && currentDegree < 340) {
    digitalWrite(mosfetD, HIGH);
  } else {
    digitalWrite(mosfetD, LOW);
  }

  if (currentDegree >= 320 || currentDegree < 100) {
    digitalWrite(mosfetE, HIGH);
  } else {
    digitalWrite(mosfetE, LOW);
  }

  if (currentDegree >= 80 && currentDegree < 220) {
    digitalWrite(mosfetF, HIGH);
  } else {
    digitalWrite(mosfetF, LOW);
  }
}
