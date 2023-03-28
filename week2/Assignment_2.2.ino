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
  pinMode(LED_YELLOW_CAR, OUTPUT);
  pinMode(LED_RED_CAR, OUTPUT);
  pinMode(BUTTON, INPUT_PULLUP);
  int buttonState = digitalRead(BUTTON);

  // at the start of the program, the traffic light for the car is green and the one for the pedestrians is green
  digitalWrite(LED_RED_PEDESTRIAN, HIGH);
  digitalWrite(LED_GREEN_CAR, HIGH);

  while (true) {
    if (buttonState == LOW) {
      // when a pedestrian pressed the button, the car traffic light switches to yellow immidiately, and then to red after 2 seconds
      //after two seconds, the pedestrian light switches to green
      Serial.println("pedestrian wants to cross the road");
      digitalWrite(LED_GREEN_CAR, LOW);
      digitalWrite(LED_YELLOW_CAR, HIGH);
      delay(2000);
      digitalWrite(LED_YELLOW_CAR, LOW);
      digitalWrite(LED_RED_CAR, HIGH);
      delay(2000);
      digitalWrite(LED_GREEN_PEDESTRIAN, HIGH);
      digitalWrite(LED_RED_PEDESTRIAN, LOW);
      //pedestrians get 5 seconds to cross
      delay(5000);
      //green pedestrian light starts to blink at a 250ms interval (250ms on, 250ms off) for five times
      for (int i = 1; i <= 11; i++) {
        if (i % 2 == 0) {
          digitalWrite(LED_GREEN_PEDESTRIAN, LOW);
        } else {
          digitalWrite(LED_GREEN_PEDESTRIAN, HIGH);
        }
        delay(250);
      }
      //one second later, the red car light turns green again (and the pedestrian light turns red)
      delay(1000);
      digitalWrite(LED_GREEN_PEDESTRIAN, LOW);
      digitalWrite(LED_RED_PEDESTRIAN, HIGH);
      digitalWrite(LED_GREEN_CAR, HIGH);
      digitalWrite(LED_RED_CAR, LOW);
    } else {
      Serial.println("button not pressed");
    }
    buttonState = digitalRead(BUTTON);
  }
}

void loop() {
}