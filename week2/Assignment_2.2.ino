#define LED_GREEN_PEDESTRIAN 2
#define LED_RED_PEDESTRIAN 4
#define BUTTON 5
#define LED_GREEN_CAR 6
#define LED_YELLOW_CAR 7
#define LED_RED_CAR 8
int buttonState = 0;

void pause(int ms) {
  uint32_t start = millis();
  while(millis() - start < ms)
  ;
}

void setup() {
  Serial.begin(9600);

  pinMode(LED_GREEN_PEDESTRIAN, OUTPUT);
  pinMode(LED_RED_PEDESTRIAN, OUTPUT);
  pinMode(LED_GREEN_CAR, OUTPUT);
  pinMode(LED_RED_CAR, OUTPUT);
  pinMode(BUTTON, INPUT_PULLUP);
}

void loop() {
  int buttonState = digitalRead(BUTTON);
  digitalWrite(LED_RED_PEDESTRIAN, HIGH);
  digitalWrite(LED_GREEN_CAR, HIGH);
  // if (buttonState == LOW) {
  //   digitalWrite(LED_RED_PEDESTRIAN, HIGH);
  //   Serial.println("button not pressed");
  // } else {
  //   Serial.println("button pressed");
  // }
  // //Turn on light
  // // digitalWrite(LEDNAME, HIGH);
  // //Turn off light
  // // digitalWrite(LEDNAME, LOW);

  // digitalWrite(LED_GREEN_PEDESTRIAN, HIGH);
  // digitalWrite(LED_RED_PEDESTRIAN, HIGH);
  // pause(5000);
  // digitalWrite(LED_GREEN_PEDESTRIAN, LOW);
  // digitalWrite(LED_RED_PEDESTRIAN, LOW);
  // pause(5000);
  // bool greenPedestrianIsOn = false;
  while (true) {
    int buttonState = digitalRead(BUTTON);
    while (buttonState == LOW) {
      digitalWrite(LED_GREEN_PEDESTRIAN, HIGH);
      digitalWrite(LED_RED_PEDESTRIAN, LOW);
      digitalWrite(LED_GREEN_CAR, LOW);
      digitalWrite(LED_RED_CAR, HIGH);
      Serial.println("button is pressed");
      int buttonState = digitalRead(BUTTON);
    }
    while (buttonState == HIGH) {
      digitalWrite(LED_RED_PEDESTRIAN, HIGH);
      digitalWrite(LED_GREEN_PEDESTRIAN, LOW);
      digitalWrite(LED_GREEN_CAR, HIGH);
      digitalWrite(LED_RED_CAR, LOW);
      Serial.println("button is not pressed");
      int buttonState = digitalRead(BUTTON);
    }
  }
}