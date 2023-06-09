/*
 * Fundacion Kinal
 * Centro educativo tecnico laboral Kinal
 * Electronica
 * Grado: Quinto
 * Sección: EB5AV
 * Curso: Taller de electronica digital y reparación de computadoras I
 * Nombre: Luis Fernando Alvarado Ramirez
 * Carnet: 2022219
 * Proyecto: ohmnimetro
*/
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2); 
#include <LiquidCrystal.h>
#define RS 2
#define E 3
#define D4 4
#define D5 5
#define D6 6
#define D7 7
LiquidCrystal LCD(RS, E, D4, D5, D6, D7);
#define circuito A0
float lectura=0;
float raw_circuito=0;
double voltaje;
double R1;
double R1_multiplicacion;
unsigned int R1_multiplicacion1;
float R1_multiplicacion2;
void setup()
{
pinMode(circuito,INPUT);
Serial.begin(9600);
LCD.begin(16,2);
}
void loop()
{
 lcd.setCursor(6,0);
 lcd.write("HOLA");
 raw_circuito=analogRead(circuito);
 lectura=map(raw_circuito,0,1023,0,1023);
 voltaje= 5*lectura/1023;
 R1_multiplicacion1=10000*5;
 R1_multiplicacion2= voltaje*10000;
 R1_multiplicacion=R1_multiplicacion1-R1_multiplicacion2;
 R1= (R1_multiplicacion/voltaje)+10;
 Serial.println(R1);
 LCD.setCursor(0,0);
 LCD.print("El valor de R1");
 LCD.setCursor(0,1);
 LCD.print("es de:");
 LCD.print(R1);
 delay(200);
}
