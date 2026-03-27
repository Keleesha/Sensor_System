#include <LiquidCrystal_I2C.h>

#include <Wire.h>

#include <DHT.h>

#define DHTPIN 3
#define DHTTYPE DHT11

const int LED_temp = 13;
const int LED_humi = 12;
const float LIMIT_temp = 30.0;
const float LIMIT_humi = 60.0;

DHT dht(DHTPIN, DHTTYPE);

LiquidCrystal_I2C lcd(0x3F, 16, 2);



void setup() {
  pinMode(LED_temp, OUTPUT);

  pinMode(LED_humi, OUTPUT);

  dht.begin();

  lcd.init();

  lcd.backlight();


  lcd.setCursor(0,0); 

  lcd.print("Environment");

  lcd.setCursor(0,1);

  lcd.print("Booting up! :)");

  delay(2000);




}

void loop() {

  delay(2000);

  float humi = dht.readHumidity();
  
  float temp = dht.readTemperature();

  if(isnan(temp) || isnan(humi)){

    lcd.setCursor(0,0);

    lcd.print("ERROR! DHT11 read fail ");

    delay(3000);

    return;
  }
  lcd.setCursor(0,0);

  lcd.print("Temperature:"); 
  lcd.print(temp,1);
  lcd.print("C");

  lcd.setCursor(0,1);

  lcd.print("Humidity: ");
  lcd.print(humi,1);
  lcd.print("%");

  digitalWrite(LED_temp, temp > LIMIT_temp ? HIGH : LOW);
  digitalWrite(LED_humi, humi > LIMIT_humi ? HIGH : LOW);

  delay(2000);
}
