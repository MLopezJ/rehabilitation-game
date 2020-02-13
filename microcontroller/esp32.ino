//Analog read pins
const int xPin = 34;
const int yPin = 35;
const int zPin = 32;


//to hold the caculated values
double x;
double y;
double z;

void setup(){
Serial.begin(115200);
}

void loop(){

//read the analog values from the accelerometer
x = analogRead(xPin);
y = analogRead(yPin);
z = analogRead(zPin);

/*
Serial.print("X: ");
Serial.println(x);
Serial.print("Y: ");
Serial.println(y);
Serial.print("Z: ");
Serial.println(z);
Serial.println("---------------");
*/

Serial.print("Y ");
Serial.println(y);

if (y <= 1500.00){
  Serial.println("JUMP");
}

delay(100);
}
