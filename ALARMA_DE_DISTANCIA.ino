int p;
int k;
#define BUZZER 6
#define LED1 A2
#define LED2 A1
#define LED3 A0
#define LED4 13
#define LED5 12
#define LED6 11
#define LED7 10
#define LED8 9
#define LED9 8
#define LED10 7
#define LED11 A3


#include <LiquidCrystal_I2C.h>
#include <Wire.h> 
LiquidCrystal_I2C lcd(0x27,16,2);
void setup()
{
  lcd.init();
  lcd.backlight();
  Serial.begin(9600);
  pinMode(BUZZER,OUTPUT);
  pinMode(LED1,OUTPUT);
  pinMode(LED2,OUTPUT);
  pinMode(LED3,OUTPUT);
  pinMode(LED4,OUTPUT);
  pinMode(LED5,OUTPUT);
  pinMode(LED6,OUTPUT);
  pinMode(LED7,OUTPUT);
  pinMode(LED8,OUTPUT);
  pinMode(LED9,OUTPUT);
  pinMode(LED10,OUTPUT);
  pinMode(LED11,OUTPUT);
}
void loop()
{
  p=sensordistancia();
  k=sensordistancia();
 Serial.println(p);
 if(k>45)
 {
  digitalWrite(LED1,LOW);
  digitalWrite(LED2,LOW);
  digitalWrite(LED3,HIGH);
  digitalWrite(LED4,HIGH);
  digitalWrite(LED5,LOW);
  digitalWrite(LED6,LOW);
  digitalWrite(LED7,LOW);
  digitalWrite(LED8,LOW);
  digitalWrite(LED9,LOW);
  digitalWrite(LED10,LOW);
  delay(50);
  
 }
 if((k<45)&&(k>30))
 {
  digitalWrite(LED1,HIGH);
  digitalWrite(LED2,HIGH);
  digitalWrite(LED3,HIGH);
  digitalWrite(LED4,HIGH);
  digitalWrite(LED5,LOW);
  digitalWrite(LED6,LOW);
  digitalWrite(LED7,LOW);
  digitalWrite(LED8,LOW);
  digitalWrite(LED9,LOW);
  digitalWrite(LED10,LOW);
  delay(50);
 }
 if((k<30)&&(k>15))
 {
  digitalWrite(LED1,HIGH);
  digitalWrite(LED2,HIGH);
  digitalWrite(LED3,HIGH);
  digitalWrite(LED4,HIGH);
  digitalWrite(LED5,HIGH);
  digitalWrite(LED6,HIGH);
  digitalWrite(LED7,HIGH);
  digitalWrite(LED8,LOW);
  digitalWrite(LED9,LOW);
  digitalWrite(LED10,LOW);
  delay(50);
 }
 if((k<15)&&(k>5))
 {
  digitalWrite(LED1,HIGH);
  digitalWrite(LED2,HIGH);
  digitalWrite(LED3,HIGH);
  digitalWrite(LED4,HIGH);
  digitalWrite(LED5,HIGH);
  digitalWrite(LED6,HIGH);
  digitalWrite(LED7,HIGH);
  digitalWrite(LED8,HIGH);
  digitalWrite(LED9,HIGH);
  digitalWrite(LED10,LOW);
  digitalWrite(LED11,LOW);
  delay(50);
 }
 
 if(p>45)
 {
  lcd.setCursor(0,0);
  lcd.print("                ");
  lcd.setCursor(0,1);
  lcd.print("Fuera de alcance");
 }
 if((p<45)&&(p>30))
 {
  lcd.setCursor(0,0);
  lcd.print("  Persona/objeto        ");
  lcd.setCursor(0,1);
  lcd.print("   Acercandose           ");
 }
 if((p<30)&&(p>15))
 {
  lcd.setCursor(0,0);
  lcd.print("CUIDADO      ");
  lcd.setCursor(0,1);
  lcd.print("ESPACIO PRIVADO                       ");
  tone(BUZZER, 783.99, 5000);
  delay(5000);
 }
 if((p<15)&&(p>5))
 {
  lcd.setCursor(0,0);
  lcd.print(" INVADIENDO ");
  lcd.setCursor(0,1);
  lcd.print("ESPACIO PRIVADO   ");
  tone(BUZZER, 1046.50, 10000);
  delay(10000);
 }
}
int sensordistancia()
{
  int TRIGGER = 2;
int ECHO = 3 ;
long sensor;
long Distancia;
  pinMode(TRIGGER, OUTPUT);
  pinMode(ECHO, INPUT);
  digitalWrite(TRIGGER, LOW);
  digitalWrite(TRIGGER, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER, LOW);
  sensor=pulseIn(ECHO, HIGH);
  Distancia=sensor/59;
  delay(100);
  return Distancia;
  delay(200);
}
