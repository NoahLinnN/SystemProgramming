// digital pin 2 has a pushbutton attached to it. Give it a name:
int pushButton = 2;

// variables will change:
int buttonState = 0;  // variable for reading the pushbutton status

void setup() {
  Serial.begin(300);
  // initialize the LED pin as an output:
  pinMode(LED_BUILTIN, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(USER_BTN, INPUT_PULLUP);
}

void loop() {
  int buttonState = digitalRead(USER_BTN);

  // check if the pushbutton is pressed. If it is, the buttonState is LOW:
  if (buttonState == LOW) {
    // turn LED on:
    digitalWrite(LED_BUILTIN, HIGH);
    Serial.println("lisa");
  } else {
    // turn LED off:
    digitalWrite(LED_BUILTIN, LOW);
  }

  // print out the state of the button:
  // Serial.println(buttonState);
  delay(100);  // delay in between reads for stability
}


