//Analog read pins
const int xPin = 0;
const int yPin = 1;
const int zPin = 2;

//The minimum and maximum values that came from
//the accelerometer while standing still
//You very well may need to change these
int minVal = 265;
int maxVal = 402;
int angle = 0;

//to hold the caculated values
double x;
double y;
double z;

void setup(){
Serial.begin(9600);
}

void loop(){

//read the analog values from the accelerometer
int xRead = analogRead(xPin);
int yRead = analogRead(yPin);
int zRead = analogRead(zPin);
x = analogRead(xPin);
y = analogRead(yPin);
z = analogRead(zPin);
// show x, y and z-values
/*
Serial.print(" x = ");
Serial.print(x);
Serial.print("  y = ");
Serial.print(y);
Serial.print("  z = ");
Serial.print(z);*/
// show angle
//Serial.print(" X angle = ");
//Serial.println(constrain(map(y,349,281,0,90),0,90));
//Serial.println(constrain(map(x,349,281,0,90),0,90));

angle = constrain(map(x,349,281,0,90),0,90);
/*
Serial.print("Angle ");
Serial.println(angle);
*/
//Serial.println(angle);
if (angle <= 65 and angle >= 50){
  Serial.println("JUMP");
}

delay(100);
}

/*

//convert read values to degrees -90 to 90 – Needed for atan2
int xAng = map(xRead, minVal, maxVal, -90, 90);
int yAng = map(yRead, minVal, maxVal, -90, 90);
int zAng = map(zRead, minVal, maxVal, -90, 90);

//Caculate 360deg values like so: atan2(-yAng, -zAng)
//atan2 outputs the value of -π to π (radians)
//We are then converting the radians to degrees
x = RAD_TO_DEG * (atan2(-yAng, -zAng) + PI);
y = RAD_TO_DEG * (atan2(-xAng, -zAng) + PI);
z = RAD_TO_DEG * (atan2(-yAng, -xAng) + PI);

//Output the caculations
Serial.print("x: ");
Serial.print(x);
Serial.print(" | y: ");
Serial.print(y);
Serial.print(" | z: ");
Serial.println(z);

delay(1000);//just here to slow down the serial output – Easier to read


}*/
