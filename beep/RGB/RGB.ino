
int RED_LED=10;
int BLUE_LED=12;
int GREEN_LED=11;
int BUZZER_PIN=13;
int SOFT_RESET=9;
int RGB_PINS[3]={GREEN_LED,BLUE_LED,RED_LED};
float wait=10;
bool done=false;
int time_in_seconds=0;
void setup() {
  // initialize digital pin LED_BUILTIN as an output.

  
  pinMode(RED_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(BLUE_LED, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(SOFT_RESET, INPUT);
  digitalWrite (BUZZER_PIN, HIGH);  
  Serial.begin(9600);

}


void fadeOut(int led_pin){
  for (int i=255; i>=0; i--) {
    analogWrite(led_pin, i);
    delay(wait);
    time_in_seconds++;
    Serial.println(time_in_seconds);
  };
}
void fadeIn(int led_pin){
  for (int i=0; i<=255; i++) {
    analogWrite(led_pin, i);
    delay(wait);
    time_in_seconds++;
    Serial.println(time_in_seconds);
  };
}
void buzz(){
  
  digitalWrite (BUZZER_PIN, LOW);
  delay (500);
  digitalWrite (BUZZER_PIN, HIGH);
  delay (500);
  return;
}
// the loop function runs over and over again forever
void loop() {
  
  int reset=digitalRead(SOFT_RESET);
  if(!done){
    analogWrite(RED_LED, 0);
    fadeOut(GREEN_LED);
    fadeIn(GREEN_LED);
    fadeIn(BLUE_LED);
    fadeIn(RED_LED);
    fadeOut(GREEN_LED);
    fadeOut(BLUE_LED);
    buzz();
    done=true;
  }
  // if(reset==1){
  // done=false;  
  // }
  delay (1);
  

  
  
  

}
