#define LED_GREEN 2
#define LED_YELLOW 3
#define LED_RED 4

void pause(int ms) {
  uint32_t start = millis();
  while(millis() - start < ms)
  ;
}

void setup() {
  Serial.begin(9600);

  pinMode(LED_GREEN, OUTPUT);
  pinMode(LED_YELLOW, OUTPUT);
  pinMode(LED_RED, OUTPUT);
}

void loop() {
  //Turn on light
  // digitalWrite(LEDNAME, HIGH);
  //Turn off light
  // digitalWrite(LEDNAME, LOW);

  digitalWrite(LED_GREEN, HIGH);
  digitalWrite(LED_YELLOW, HIGH);
  digitalWrite(LED_RED, HIGH);
  pause(5000);   
  digitalWrite(LED_GREEN, LOW);  
  digitalWrite(LED_YELLOW, LOW); 
  digitalWrite(LED_RED, LOW); 
  pause(5000);  

}