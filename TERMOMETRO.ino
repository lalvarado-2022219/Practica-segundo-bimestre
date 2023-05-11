/* 
 * Fundacion Kinal
 * Centro educativo tecnico laboral Kinal
 * Perito en electonica
 * Quinto perito
 * EB5AM / EB5AV
 * Taller de electronica digital y reparacion de computadoras
 * Nombre: Luis Fernando Alvarado Ramirez
 * Fecha: 11/05/2023
 * Proyecto: TERMOMETRO
 */

//Librerias
#include <LiquidCrystal_I2C.h>
#include <Wire.h> 
#include <OneWire.h>                
#include <DallasTemperature.h>
LiquidCrystal_I2C lcd(0x27,16,2);
#define LEDR A3
#define LEDA 3
#define LEDV A0

//Se crea el codigo para el caracter de grados
byte F[] = {
  B11100,
  B10100,
  B11100,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000
};
 
//Constructores
OneWire ourWire(5);                //Se establece el pin 2  como bus OneWire
DallasTemperature sensors(&ourWire); //Se declara una variable u objeto para nuestro sensor

void setup() {
pinMode(LEDR, OUTPUT);
pinMode(LEDA, OUTPUT);
pinMode(LEDV, OUTPUT);

lcd.init();
lcd.backlight();
delay(1000);
Serial.begin(9600);

sensors.begin();   //Se inicia el sensor
lcd.createChar(0,F);//Se crea el caracter de grados
}
 
void loop() {
sensors.requestTemperatures();   //Se envía el comando para leer la temperatura
float tempC= sensors.getTempCByIndex(0); //Se obtiene la temperatura en ºC
float tempF= sensors.getTempFByIndex(0); //Se obtiene la temperatura en ºF
Serial.print("Temperatura");
Serial.print(tempC);
Serial.println(" C");
Serial.print("Temperatura");
Serial.print(tempF);
Serial.println(" F");
delay(100);
//Imprime los grados Farenheit en la primera fila
lcd.setCursor(0,0);
lcd.write(byte(0));//Imprime el caracter de grados en la primera columna y primera fila
lcd.setCursor(1,0);
lcd.print("F");
lcd.setCursor(2,0);
lcd.print("=");
lcd.setCursor(3,0);
lcd.print(tempF);
//Imprime los grados centigrados en la segunda fila
lcd.setCursor(0,1);
lcd.write(byte(0));
lcd.setCursor(1,1);
lcd.print("C");
lcd.setCursor(2,1);
lcd.print("=");
lcd.setCursor(3,1);
lcd.print(tempC);
if(tempC>30)
{
  digitalWrite(LEDR, HIGH);
  digitalWrite(LEDA, LOW);
  digitalWrite(LEDV, LOW);
}
if(tempC<15)
{
  digitalWrite(LEDV, HIGH);
  digitalWrite(LEDR, LOW);
  digitalWrite(LEDA, LOW);
}
if((tempC<30)&&(tempC>15))
{
   digitalWrite(LEDA, HIGH);
   digitalWrite(LEDR, LOW);
   digitalWrite(LEDV, LOW);
   
}
  }
