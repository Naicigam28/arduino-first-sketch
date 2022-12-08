
int BUZZER_PIN=10;
int BUTTON_PIN=8;
    

void setup() {
  //Input or output?
  pinMode(BUZZER_PIN, OUTPUT);      
  pinMode(BUTTON_PIN, INPUT_PULLUP);   
  Serial.begin(9600);
}

void buzz(int state){
  Serial.println(state);
  if(state==1){
    digitalWrite (BUZZER_PIN, LOW);
  }
  else{
    digitalWrite (BUZZER_PIN, HIGH);
  }
  //digitalWrite (BUZZER_PIN, state);
  delay (500);
  // digitalWrite (BUZZER_PIN, state);
  // delay (500);
  return;
}

void loop() {
  int buttonState = digitalRead(BUTTON_PIN);
  //Serial.println(buttonState);
  buzz(buttonState);
}
