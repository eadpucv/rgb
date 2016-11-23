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
int colR1 = 0;
int colG1 = 255;
int colB1 = 0;

// color 2
int colR2 = 255;
int colG2 = 0;
int colB2 = 255;

// temporizer variables
int counter = 0;
int potRprev = 0;
int potGprev = 0;
int potBprev = 0;
int minDiff = 10;
int timeGap = 500;

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

    lightRval = ((potRnorm * colR2) + ((1 - potRnorm) * colR1)) * potGnorm;
    lightGval = ((potRnorm * colG2) + ((1 - potRnorm) * colG1)) * potGnorm;
    lightBval = ((potRnorm * colB2) + ((1 - potRnorm) * colB1)) * potGnorm;

    // timer
    if (abs((potR + potG + potB) - (potRprev + potGprev + potBprev)) < minDiff) {
      counter ++;
    } else {
      counter = 0;
    }

    if (counter > timeGap) {
      lightRval = colR1;
      lightGval = colG1;
      lightBval = colB1;
    }
    potRprev = potR;
    potGprev = potG;
    potBprev = potB;
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

  // debugLights();
  // debugNorms();
  debugTimer();
}

void debugLights() {
  // print the results to the serial monitor:

  Serial.print("R = ");
  Serial.print(lightRval);

  Serial.print("\t\t G = ");
  Serial.print(lightGval);

  Serial.print("\t\t B = ");
  Serial.println(lightBval);

  delay(50);
}

void debugNorms() {
  // print the results to the serial monitor:

  Serial.print("potRnorm = ");
  Serial.print(potRnorm);

  Serial.print("\t\t potGnorm = ");
  Serial.print(potGnorm);

  Serial.print("\t\t potBnorm = ");
  Serial.println(potBnorm);

  delay(50);
}

void debugTimer() {
  Serial.print("counter = ");
  Serial.println(counter);
}

