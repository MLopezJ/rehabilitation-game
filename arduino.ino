int inPin = 2;   // Input pin for the pushbutton
int val = 0;     // variable for reading the pin status

void setup() {
  Serial.begin(9600);
  pinMode(inPin, INPUT);    // declare pushbutton as input
}

void loop(){
  val = digitalRead(inPin);  // read input value
  if (val != HIGH) {         // check if the input is HIGH (button released)
    Serial.println("JUMP");
  }
}
