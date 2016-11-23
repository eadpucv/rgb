/*
    Taller del Color 2016
    Pedro Garretón - Herbert Spencer
    e[ad]
*/

// input addresses
const int analogInPin0 = 0;
const int analogInPin1 = 1;
const int analogInPin2 = 2;

// lightput addresses
const int lightR = 9;
const int lightG = 10;
const int lightB = 11;

// potenciometer values
int potR = 0;
int potG = 0;
int potB = 0;

// mapped lightput values
int lightRval = 0;
int lightGval = 0;
int lightBval = 0;

// switch for different modes
boolean transitionMode = true;

// normalized potenciometer values
float potRnorm = 0;
float potGnorm = 0;
float potBnorm = 0;

// color 1
int colR1 = 255;
int colG1 = 0;
int colB1 = 0;

// color 2
int colR2 = 0;
int colG2 = 255;
int colB2 = 255;

void setup() {
  // initialize serial communications at 9600 bps:
  Serial.begin(9600);
}

void loop() {

  // read potenciometer values:
  potR = analogRead(analogInPin0);
  potG = analogRead(analogInPin1);
  potB = analogRead(analogInPin2);

  if (transitionMode) {
    potRnorm = potR / 1024.0;
    potGnorm = potG / 1024.0;
    potBnorm = potB / 1024.0;

    lightRval = potRnorm * colR2 + (1 - potRnorm) * colR1;
    lightGval = potRnorm * colG2 + (1 - potRnorm) * colG1;
    lightBval = potRnorm * colB2 + (1 - potRnorm) * colB1;
  }
  else {
    // map values
    lightRval = map(potR, 0, 1023, 255, 0);
    lightGval = map(potG, 0, 1023, 255, 0);
    lightBval = map(potB, 0, 1023, 255, 0);
  }

  // write values
  analogWrite(lightR, lightRval);
  analogWrite(lightG, lightGval);
  analogWrite(lightB, lightBval);

  // debug();
}


void debug() {
  // print the results to the serial monitor:
  Serial.print("R = ");
  Serial.print(potR);
  //Serial.print("\t light = ");
  //Serial.print(lightputValue);
  Serial.print("\t G = ");
  Serial.print(potG);
  //Serial.print("\t light1 = ");
  //Serial.println(lightGval);
  Serial.print("\t B = ");
  Serial.println(potB);
  //Serial.print("\t light2 = ");
  //Serial.println(lightBval);
  delay(50);

}

