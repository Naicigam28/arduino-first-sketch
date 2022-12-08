
int RED_LED=10;
int YELLOW_LED=12;
int GREEN_LED=11;


void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(RED_LED, OUTPUT);
  pinMode(YELLOW_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  Serial.begin(9600);

}


void blink(int pin,int count){
  digitalWrite(pin, HIGH);
  delay(count);
  digitalWrite(pin, LOW);
}

// the loop function runs over and over again forever
void loop() {
  int flashSpeed = analogRead(A0)  ;
  
  blink(RED_LED,flashSpeed);
  blink(YELLOW_LED,flashSpeed);
  blink(GREEN_LED,flashSpeed);

}
