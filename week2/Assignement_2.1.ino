#define LED 2
#define BUTTON 3

int buttonState = 0;

void pause(int ms) {
  uint32_t start = millis();
  while(millis() - start < ms)
  ;
}

void setup() {
  Serial.begin(9600);

  pinMode(LED,OUTPUT);
  pinMode(BUTTON, INPUT);
}

void loop() {
  buttonState = digitalRead(BUTTON);
  Serial.println(buttonState);

  //if button is pressed
  if (buttonState == LOW) {
    digitalWrite(LED, LOW);
  } else {
    digitalWrite(LED, HIGH);
    pause(100);   
    digitalWrite(LED, LOW);  
    pause(100);                    
  }

}