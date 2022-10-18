#include <Wire.h>
#include <LiquidCrystal_I2C.h>
// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27, 16, 2);

const int trig = 11;
const int echo = 12;
//GND of LCD Display was connected to GND of Arduino
//VCC of LCD Display was connected to 5V
//SCL of LCD Display was connected to A5
//SDA of LCD was connected to A4
const int LED1 = 2;
const int LED2 = 3;
const int LED3 = 4;
const int LED4 = 5;
#define BUZ 8

int duration = 0;
int distance = 0;
void setup() {
  // put your setup code here, to run once:
  //initialize the LCD
  lcd.begin();
  Serial.begin(9600); //initialize serial monitor

  //turn ON Backlight
  lcd.backlight();

  lcd.clear();// To clear the screen after every run.
  lcd.setCursor(0,1);
  lcd.print("Hi there!");
  delay(500);
  //create and search for characters already created in Hex to add to my codes.

  
  
  pinMode(trig , OUTPUT);
  pinMode(echo , INPUT);
 
  pinMode(LED1 , OUTPUT);
  pinMode(LED2 , OUTPUT);
  pinMode(LED3 , OUTPUT);
  pinMode(LED4 , OUTPUT);
  pinMode(BUZ , OUTPUT);
 
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(trig , HIGH);
  delayMicroseconds(1000);
  digitalWrite(trig , LOW);
  

  duration = pulseIn(echo , HIGH);
  distance = (duration/2) / 28.5 ;
  Serial.println(distance);
 

  if ( distance <= 5 )
  {
    digitalWrite(LED1, HIGH);
  digitalWrite(BUZ, HIGH);
  delay(500);
  digitalWrite(BUZ, LOW);
  lcd.clear();
  lcd.print("Don't walk here!");
  lcd.setCursor(0,1);
  lcd.print("Go to your left");
  delay(1000);
  }
  else
  {
    digitalWrite(LED1, LOW);
    lcd.clear();
  }
  if ( distance <= 10 )
  {
    digitalWrite(LED2, HIGH);
    digitalWrite(BUZ,HIGH);
    delay(20);
    digitalWrite(BUZ,LOW);
    lcd.setCursor(0,0); //to set the cursor to the first line and letter
  lcd.print("PROHIBITED AREA!"); //To print on the LCD Display
  }
  else
  {
    digitalWrite(LED2, LOW);
  }
  if ( distance <= 15 )
  {
    digitalWrite(LED3, HIGH);
  }
  else
  {
    digitalWrite(LED3, LOW);
  }
  if ( distance <= 20 )
  {
    digitalWrite(LED4, HIGH);
  }
  else
  {
    digitalWrite(LED4, LOW);
  }
}
