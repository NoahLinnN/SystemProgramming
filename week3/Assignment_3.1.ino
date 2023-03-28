//metronome exercise
#define PIN_BUZZER 8
#define LED 7

void setup() {
  pinMode(LED, OUTPUT);
  pinMode(PIN_BUZZER, OUTPUT);
  Serial.begin(9600);

  //this value should always be different that the rest time (lower)
  int soundDuration = 250;

  while (true) {
    digitalWrite(LED, HIGH);
    tone(PIN_BUZZER, 440, soundDuration);
    digitalWrite(LED, LOW);
    delay(750);
  }
}

void loop() {
}