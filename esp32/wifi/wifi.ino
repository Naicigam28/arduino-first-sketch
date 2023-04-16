#include <WiFi.h>
#include "DHT.h"
#define DHTPIN 2
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

const char* ssid = "Dirkse";
const char* password = "7U6@4!mu";
const int bluePin = 5;
const int redPin = 18;
void setup(){
    Serial.begin(115200);
    pinMode (bluePin, OUTPUT);
    pinMode (redPin, OUTPUT);
    dht.begin();
    digitalWrite (bluePin, HIGH);
    digitalWrite (redPin, HIGH);      
    delay(1000);


    WiFi.mode(WIFI_STA); //Optional
    WiFi.begin(ssid, password);
    Serial.println("\nConnecting");

    while(WiFi.status() != WL_CONNECTED){
        Serial.print(".");
        delay(100);
    }
   
      
    Serial.println("\nConnected to the WiFi network");
    Serial.print("Local ESP32 IP: ");
    Serial.println(WiFi.localIP());

if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3D for 128x64
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }
  delay(2000);
  display.clearDisplay();

  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 10);
  // Display static text
 
}

void loop(){
  float humi  = dht.readHumidity();
  // read temperature as Celsius
  float tempC = dht.readTemperature();
  // read temperature as Fahrenheit
  
  digitalWrite (redPin, LOW); 
  digitalWrite (bluePin, LOW);   
  if(WiFi.status() == WL_CONNECTED) 
  {
    digitalWrite (bluePin, HIGH);	// turn on the LED    
  }
  else{
    digitalWrite (redPin, HIGH);     
  }
if (isnan(humi) || isnan(tempC)) {
    Serial.println("Failed to read from DHT sensor!");
  } else {
    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.setCursor(0, 10);
    display.print("Humidity: ");
    display.print(humi);
    display.print("%\n");
    display.print("Temperature: ");
    display.print(tempC);
    display.print("C");
    display.display();     
  }  
  delay(1000);
  
}