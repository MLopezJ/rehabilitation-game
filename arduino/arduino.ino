const int buttonPin = 2;   // the number of the pushbutton pin
const int ledPin =  13;   // the number of the LED pin
//debounce
int buttonState = 0;          // variable for reading the pin status
int lastButtonState = LOW;   // the previous reading from the input pin
int ledState = HIGH;  

unsigned long lastDebounceTime = 0;  // the last time the output pin was toggled
unsigned long debounceDelay = 50;    // the debounce time; increase if the output flickers

void setup() {
  Serial.begin(9600);
  pinMode(buttonPin, INPUT);    // declare pushbutton as input
  pinMode(ledPin, OUTPUT);

  digitalWrite(ledPin, ledState);
}

void loop(){
  int reading = digitalRead(buttonPin);  // read input value
  
  if (reading != lastButtonState) {
    // reset the debouncing timer
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {
    // whatever the reading is at, it's been there for longer than the debounce
    // delay, so take it as the actual current state:

    // if the button state has changed:
    if (reading != buttonState) {
      buttonState = reading;

      // only toggle the LED if the new button state is HIGH
      if (buttonState == HIGH) {
        ledState = !ledState;
        Serial.println("JUMP");
      }
    }
  }

  // set the LED:
  digitalWrite(ledPin, ledState);

  // save the reading. Next time through the loop, it'll be the lastButtonState:
  lastButtonState = reading;
}
