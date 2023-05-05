/*
   Fundacion Kinal
   Centro educativo tecnico laboral Kinal
   Quinto perito
   Quinto electronica
   Codigo Tecnico: EB5AM / EB5AV 
   Curso: Taller de electronica digital y reparacion de computadoras I
   Proyecto: contador aforo con animacion
   Dev: Luis Fernando Alvarado Ramirez
   Fecha: 5 de mayo de 2023
*/
#include <LiquidCrystal.h>
int k;
int i;
int hola;
int j;
int variable;
int l;
int c;
int p;
int s;
int u;
#define RELE A0
#define LED 4
#define lectura 5
#define RS 6
#define E 7
#define D4 8
#define D5 9
#define D6 10
#define D7 11
#define BUZZER 12
byte NORMAL[] = {
  B01110,
  B01110,
  B01110,
  B00100,
  B11111,
  B00100,
  B01010,
  B10001
};
byte HOLA[] = {
   B01110,
  B01110,
  B01110,
  B10101,
  B01110,
  B00100,
  B01010,
  B01010
};
LiquidCrystal LCD(RS, E, D4, D5, D6, D7);
void setup()
{
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
  LCD.begin(16,2);
  LCD.print("Luis Alvarado");
  LCD.setCursor(0,1);
  LCD.print("2022219");
  pinMode(BUZZER, OUTPUT);
  pinMode(lectura, INPUT);
  digitalWrite(RELE,HIGH);
  LCD.createChar(0,NORMAL);
  LCD.createChar(1,HOLA);

  
  
  
  
}
void loop()
{
 
  

  
  
 k=sensordistancia();
 j=contadores();
Serial.println(u);
 for(c=1; c<=15; c++)
 {
 if(hola==c)
 {
  LCD.clear();
  LCD.setCursor(4,0);
  LCD.print("PERSONAS: ");
  LCD.setCursor(7,1);
  LCD.print(c);
   
 }
 }
  if(hola==16)
 {
  tone(BUZZER,987.77,700);
  delay(1000);
  LCD.clear();
  LCD.setCursor(0,0);
  LCD.print("LIMITE");
  LCD.setCursor(0,1);
  LCD.print("ALCANZADO!");
  delay(100);
  while(p<=10)
  {
  LCD.setCursor(9,1);
  LCD.print("!");
  delay(100);
  LCD.setCursor(9,1);
  LCD.print(" ");
  delay(100);
  LCD.setCursor(11,1);
  delay(0);
  LCD.write(byte(0));
  delay(200);
  LCD.setCursor(11,1);
  LCD.write(byte(1));
  delay(200);
 
  
   
  }}
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

int contadores()
{if((k>=6)&&(k<=10))
  {
  for(k; k<=10; k++)
  {
    digitalWrite(LED, HIGH);
 }
 }
  else{
    digitalWrite(LED, LOW);
  }
 bool estado_boton =digitalRead(lectura);
  if((estado_boton==HIGH)&&(hola==0))
  {
    
    hola= i++;
 }
  if(estado_boton==LOW)
  {
    hola=0;
  }
 for(l=1; l<=16; l++)
 {
  if((estado_boton==HIGH)&&(hola==0))
  {
    
    hola= i++;
    
 }
  u=hola+2;
 }}
  
