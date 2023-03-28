// Make the internal LED (LED_BUILTIN) blink in the following pattern: 
// on for 0.1 seconds; off for 0.2 seconds, on for 0.2 seconds, off for 0.4 seconds 
// The LED should be on respectively 0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9
// and 1.0 seconds. Keep repeating this.

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  int a = 1;
  for (int i = 0; i < 10; i++) {
    digitalWrite(LED_BUILTIN, HIGH);  // turn the LED on (HIGH is the voltage level)
    delay(a*100);                     // wait for a second
    digitalWrite(LED_BUILTIN, LOW);   // turn the LED off by making the voltage LOW
    delay(a*200);
    a++;
  }
}