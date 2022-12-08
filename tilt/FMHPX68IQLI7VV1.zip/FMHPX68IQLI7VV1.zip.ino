
int tilt_sensor=10;
int GREEN_LED=8;
int RED_LED=9;
int BUZZER_PIN=7;
void setup() {
  // put your setup code here, to run once:
  pinMode(tilt_sensor,INPUT);
  pinMode(RED_LED,OUTPUT);
  pinMode(GREEN_LED,OUTPUT);  
  pinMode(BUZZER_PIN,OUTPUT);   
  Serial.begin(9600);


}
void buzz(){
  
  digitalWrite (BUZZER_PIN, LOW);
  delay (500);
  digitalWrite (BUZZER_PIN, HIGH);
  delay (500);
  return;
}
void loop() {
  int tilt_val=digitalRead(tilt_sensor);
  digitalWrite(GREEN_LED,LOW);
  digitalWrite(RED_LED,LOW);  
  digitalWrite (BUZZER_PIN, HIGH);
  //Serial.println(tilt_val);
  

  if(tilt_val==0){
    digitalWrite(RED_LED,LOW); 
    digitalWrite(GREEN_LED,HIGH);
  }
  else{
    digitalWrite(GREEN_LED,LOW);
    buzz();
    digitalWrite(RED_LED,HIGH);    
  }
  delay(1000);

}
