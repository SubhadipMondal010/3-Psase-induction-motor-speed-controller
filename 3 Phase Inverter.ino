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


  if (currentDegree >= 15 && currentDegree < 165) {
    digitalWrite(mosfetA, HIGH);
  } else {
    digitalWrite(mosfetA, LOW);
  }

  if (currentDegree >= 130 && currentDegree < 290) {
    digitalWrite(mosfetB, HIGH);
  } else {
    digitalWrite(mosfetB, LOW);
  }

  if (currentDegree >= 250 || currentDegree < 50) {
    digitalWrite(mosfetC, HIGH);
  } else {
    digitalWrite(mosfetC, LOW);
  }

  





  if (currentDegree >= 195 && currentDegree < 345) {
    digitalWrite(mosfetD, HIGH);
  } else {
    digitalWrite(mosfetD, LOW);
  }

  if (currentDegree >= 310 || currentDegree < 110) {
    digitalWrite(mosfetE, HIGH);
  } else {
    digitalWrite(mosfetE, LOW);
  }

  if (currentDegree >= 70 && currentDegree < 230) {
    digitalWrite(mosfetF, HIGH);
  } else {
    digitalWrite(mosfetF, LOW);
  }
}
