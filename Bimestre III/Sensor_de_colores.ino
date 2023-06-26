/*
   Fundacion Kinal
   Centro educativo tecnico laboral Kinal
   Quinto perito
   Quinto electronica
   Codigo Tecnico: EB5AV 
   Curso: Taller de electronica digital y reparacion de computadoras I
   Proyecto: Sensor de colores
   Participantes: Luis Fernando Alvarado Ramirez, Pablo Alexander Canel Aguilon
   Carné: 2022219, 2022344
   Fecha: 30 de marzo
*/
#include <Wire.h> 
#include <Servo.h> 
#define pin_Servo 6
#define LDR A0
#define a 8
#define b 9
#define c 10
#define d 11
#define led_prueba A3
int led_rojo = 3;
int led_verde = 4;
int led_azul = 5;
int lectura;
int raw_circuito;
int tol = 8;
int resultado_rojo, resultado_verde,resultado_azul;
int sensor=2;
int motor;
Servo Servo_Luis;
void setup()
{
  Servo_Luis.attach(pin_Servo);
  attachInterrupt(digitalPinToInterrupt(2), Interrupcion_sensor, FALLING);
  
  pinMode(sensor,INPUT);
  for(int i=8; i<=11; i++)
  {
    pinMode(i,OUTPUT);
  }
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(led_prueba,OUTPUT);
  
  digitalWrite(3,LOW);
  digitalWrite(4,LOW);
  digitalWrite(5,LOW);
  digitalWrite(led_prueba,LOW);


  Serial.begin(9600);
  }
void loop()
  {
  digitalWrite(3,LOW);
  digitalWrite(4,LOW);
  digitalWrite(5,LOW);
  digitalWrite(led_prueba,LOW);
 bool lectura = digitalRead(sensor);
 
 digitalWrite(a,HIGH);
 digitalWrite(b,HIGH);
 digitalWrite(c,LOW);
 digitalWrite(d,LOW);
 delay(2);

 digitalWrite(a,LOW);
 digitalWrite(b,HIGH);
 digitalWrite(c,HIGH);
 digitalWrite(d,LOW);
 delay(2);

 digitalWrite(a,LOW);
 digitalWrite(b,LOW);
 digitalWrite(c,HIGH);
 digitalWrite(d,HIGH);
 delay(2);

 digitalWrite(a,HIGH);
 digitalWrite(b,LOW);
 digitalWrite(c,LOW);
 digitalWrite(d,HIGH);
 delay(2);
  
  if(motor==1)
  {
     Servo_Luis.write(180);
     delay(1000);
     Servo_Luis.write(0);
     delay(1000);
     motor=0;
  }
  }

void Interrupcion_sensor()
{


 digitalWrite(a,LOW); 
 digitalWrite(b,LOW);
 digitalWrite(c,LOW);
 digitalWrite(d,LOW);
  analogWrite(led_rojo,150);
  delay(50000);
  raw_circuito=analogRead(LDR);
  resultado_rojo=map(raw_circuito,0,1023,0,1023);
  digitalWrite(led_rojo,LOW);
  Serial.print("Rojo: ");
  Serial.println(resultado_rojo);
  delay(20000);

  
  digitalWrite(led_verde,HIGH);
  delay(50000);
  raw_circuito=analogRead(LDR);
  resultado_verde=map(raw_circuito,0,1023,0,1023);
  digitalWrite(led_verde,LOW);
  Serial.print("Verde: ");
  Serial.println(resultado_verde);
  delay(20000);
  
  analogWrite(led_azul,180);
  delay(50000);
  raw_circuito=analogRead(LDR);
  resultado_azul=map(raw_circuito,0,1023,0,1023);
  digitalWrite(led_azul,LOW);
  Serial.print("Azul: ");
  Serial.println(resultado_azul);
  delay(20000);

   
  if(( resultado_verde>resultado_rojo)&&(resultado_verde>resultado_azul))
  {
  
    motor = 1;
    digitalWrite(led_prueba,HIGH);
  }
  else{
   
    motor = 0;
  }
  
   
  
  
  
 
 
 
   }
