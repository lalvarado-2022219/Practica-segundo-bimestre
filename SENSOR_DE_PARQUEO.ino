/* 
 * Fundacion Kinal
 * Centro educativo tecnico laboral Kinal
 * Perito en electonica
 * Quinto perito
 * EB5AM / EB5AV
 * Taller de electronica digital y reparacion de computadoras
 * Nombre: Luis Fernando Alvarado Ramirez
 * Fecha: 11/05/2023
 * Proyecto: SENSOR DE PARQUEO
 */
int a;
#include <LiquidCrystal_I2C.h>
#include <Wire.h> 
LiquidCrystal_I2C lcd(0x27,16,2);
byte bloques[] = {
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111
};
byte nada[] = {
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  
};

void setup()
{
Serial.begin(9600);
lcd.init();
lcd.backlight();
lcd.createChar(0,bloques);
lcd.createChar(1,nada);

}
void loop()
{
 
 
a=sensordistancia();
Serial.println(a);
if((a<50)&&(a>40))
{
lcd.setCursor(6,0);
lcd.write(byte(0));
lcd.setCursor(5,0);
lcd.write(byte(0));
lcd.setCursor(4,0);
lcd.write(byte(0));
lcd.setCursor(3,0);
lcd.write(byte(1));
lcd.setCursor(2,0);
lcd.write(byte(1));
lcd.setCursor(1,0);
lcd.write(byte(1));
lcd.setCursor(0,0);
lcd.write(byte(1));
lcd.setCursor(9,0);
lcd.write(byte(0));
lcd.setCursor(10,0);
lcd.write(byte(0));
lcd.setCursor(11,0);
lcd.write(byte(0));
lcd.setCursor(12,0);
lcd.write(byte(1));
lcd.setCursor(13,0);
lcd.write(byte(1));
lcd.setCursor(14,0);
lcd.write(byte(1));
lcd.setCursor(15,0);
lcd.write(byte(1));
lcd.setCursor(7,0);
lcd.print("50");
lcd.setCursor(5,1);
lcd.print("LIBRE      ");
}
if((a<35)&&(a>25))
{
lcd.setCursor(6,0);
lcd.write(byte(0));
lcd.setCursor(5,0);
lcd.write(byte(0));
lcd.setCursor(4,0);
lcd.write(byte(0));
lcd.setCursor(3,0);
lcd.write(byte(0));
lcd.setCursor(2,0);
lcd.write(byte(0));
lcd.setCursor(1,0);
lcd.write(byte(1));
lcd.setCursor(0,0);
lcd.write(byte(1));
lcd.setCursor(9,0);
lcd.write(byte(0));
lcd.setCursor(10,0);
lcd.write(byte(0));
lcd.setCursor(11,0);
lcd.write(byte(0));
lcd.setCursor(12,0);
lcd.write(byte(0));
lcd.setCursor(13,0);
lcd.write(byte(0));
lcd.setCursor(14,0);
lcd.write(byte(1));
lcd.setCursor(15,0);
lcd.write(byte(1));
lcd.setCursor(7,0);
lcd.print("30");
lcd.setCursor(5,1);
lcd.print("CUIDADO");
  delay(10);
}
if(a<10)
{
lcd.setCursor(6,0);
lcd.write(byte(0));
lcd.setCursor(5,0);
lcd.write(byte(0));
lcd.setCursor(4,0);
lcd.write(byte(0));
lcd.setCursor(3,0);
lcd.write(byte(0));
lcd.setCursor(2,0);
lcd.write(byte(0));
lcd.setCursor(1,0);
lcd.write(byte(0));
lcd.setCursor(0,0);
lcd.write(byte(0));
lcd.setCursor(9,0);
lcd.write(byte(0));
lcd.setCursor(10,0);
lcd.write(byte(0));
lcd.setCursor(11,0);
lcd.write(byte(0));
lcd.setCursor(12,0);
lcd.write(byte(0));
lcd.setCursor(13,0);
lcd.write(byte(0));
lcd.setCursor(14,0);
lcd.write(byte(0));
lcd.setCursor(15,0);
lcd.write(byte(0));
lcd.setCursor(7,0);
lcd.print("10");
lcd.setCursor(0,1);
lcd.print("      ALTO         ");
delay(10);
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
