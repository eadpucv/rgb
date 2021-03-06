/*
    Taller del Color 2016
    Pedro Garretón - Herbert Spencer
    e[ad]
*/

// input addresses
const int analogInPin0 = 0;
const int analogInPin1 = 1;
const int analogInPin2 = 2;

// output addresses
const int outR = 9;
const int outG = 10;
const int outB = 11;

// potenciometer values
int potR = 0;
int potG = 0;
int potB = 0;

// mapped output values
int outRval = 0;
int outGval = 0;
int outBval = 0;

void setup() {
  // initialize serial communications at 9600 bps:
  Serial.begin(9600);
}

void loop() {

  // read potenciometer values:
  potR = analogRead(analogInPin0);
  potG = analogRead(analogInPin1);
  potB = analogRead(analogInPin2);

  // map values
  outRval = map(potR, 0, 1023, 255, 0);
  outGval = map(potG, 0, 1023, 255, 0);
  outBval = map(potB, 0, 1023, 255, 0);

  // write values
  analogWrite(outR, outRval);
  analogWrite(outG, outGval);
  analogWrite(outB, outBval);

  // debug();
}


void debug() {
  // print the results to the serial monitor:
  Serial.print("R = ");
  Serial.print(potR);
  //Serial.print("\t out = ");
  //Serial.print(outputValue);
  Serial.print("\t G = ");
  Serial.print(potG);
  //Serial.print("\t out1 = ");
  //Serial.println(outGval);
  Serial.print("\t B = ");
  Serial.println(potB);
  //Serial.print("\t out2 = ");
  //Serial.println(outBval);
  delay(50);
  
}

