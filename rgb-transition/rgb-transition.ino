/*
    Taller del Color 2016
    Pedro Garretón - Herbert Spencer
    e[ad]
*/

// input addresses
const int analogInPin0 = 0;
//const int analogInPin1 = 1;
//const int analogInPin2 = 2;

// lightput addresses
const int lightR = 9;
const int lightG = 10;
const int lightB = 11;

// potenciometer values
int potR = 0;
//int potG = 0;
//int potB = 0;

// mapped lightput values
int lightRval = 0;
int lightGval = 0;
int lightBval = 0;

// false = rgb perillas | true = modo transición entre 2 colores

// normalized potenciometer values
float potRnorm = 0;
//float potGnorm = 0;
//float potBnorm = 0;

// color 1 - origin
int colR1 = 255;
int colG1 = 255;
int colB1 = 0;

// color 2 - destiny
int colR2 = 0;
int colG2 = 155;
int colB2 = 255;

// temporizer variables
int counter = 0;
int potRprev = 0;
//int potGprev = 0;
//int potBprev = 0;
int minDiff = 40;
int timeGap = 500;

void setup() {
  // initialize serial communications at 9600 bps:
  Serial.begin(9600);
}

void loop() {

  // read potenciometer values:
  potR = analogRead(analogInPin0);
  //potG = analogRead(analogInPin1);
  //potB = analogRead(analogInPin2);


  potRnorm = potR / 1023.0;
  //potGnorm = potG / 1023.0;
  //potBnorm = potB / 1023.0;

  lightRval = (potRnorm * colR2) + ((1 - potRnorm) * colR1);
  lightGval = (potRnorm * colG2) + ((1 - potRnorm) * colG1);
  lightBval = (potRnorm * colB2) + ((1 - potRnorm) * colB1);

  // timer
  if (abs(potR - potRprev) < minDiff) {
    counter ++;
  } else if (abs(potR - potRprev) > minDiff) {
    counter = 0;
  }

  if (counter > timeGap) {
    lightRval = colR1;
    lightGval = colG1;
    lightBval = colB1;
  }
  
  potRprev = potR;
  //potGprev = potG;
  //potBprev = potB;




// write values
analogWrite(lightR, lightRval);
analogWrite(lightG, lightGval);
analogWrite(lightB, lightBval);

// debugPots();
// debugLights();
// debugNorms();

}

void debugLights() {
  // print the results to the serial monitor:

  Serial.print("R = ");
  Serial.print(lightRval);

  Serial.print("\t G = ");
  Serial.print(lightGval);

  Serial.print("\t B = ");
  Serial.println(lightBval);

  delay(50);
}

void debugNorms() {
  // print the results to the serial monitor:

  Serial.print("potRnorm = ");
  Serial.print(potRnorm);

  //Serial.print("\t potGnorm = ");
  //Serial.print(potGnorm);

  //Serial.print("\t potBnorm = ");
  //Serial.print(potBnorm);

  Serial.print("\t counter = ");
  Serial.println(counter);

  delay(50);
}

void debugPots() {
  // print the results to the serial monitor:

  Serial.print("potR = ");
  Serial.print(potR);

  //Serial.print("\t potG = ");
  //Serial.print(potG);

  //Serial.print("\t potB = ");
  //Serial.print(potB);

  Serial.print("\t counter = ");
  Serial.println(counter);

  delay(50);
}


