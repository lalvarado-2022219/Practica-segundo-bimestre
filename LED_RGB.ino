/*
   Fundacion Kinal
   Centro educativo tecnico laboral Kinal
   Quinto perito
   Quinto electronica
   Codigo Tecnico: EB5AM / EB5AV 
   Curso: Taller de electronica digital y reparacion de computadoras I
   Proyecto: Led RGB
   Dev: Luis Fernando Alvarado Ramirez
   Fecha: 14 de abril
*/

#define LEDR 2
#define LEDG 3
#define LEDB 4
#define push1 5
#define push2 6
void setup()
{
pinMode(LEDR,OUTPUT);
pinMode(LEDG,OUTPUT);
pinMode(LEDB,OUTPUT);
pinMode(push1, INPUT);
pinMode(push2, INPUT);
}
void loop()
{
 bool estado_boton = digitalRead(push1);
 bool estado_boton1 = digitalRead(push2);
  if((estado_boton == HIGH) && (estado_boton1== LOW))
  {
digitalWrite(LEDR,HIGH);
delay(0);
digitalWrite(LEDR,LOW);
delay(0);
digitalWrite(LEDG,HIGH);
delay(0);
digitalWrite(LEDG,LOW);
delay(0);
 }
  if((estado_boton1 == HIGH)&&(estado_boton==LOW))
  {
digitalWrite(LEDG,HIGH);
delay(0);
digitalWrite(LEDG,LOW);
delay(0);
digitalWrite(LEDB,HIGH);
delay(0);
digitalWrite(LEDB,LOW);
delay(0);
}
 if((estado_boton1 == HIGH) && (estado_boton == HIGH))
  {
digitalWrite(LEDR,HIGH);
digitalWrite(LEDR,HIGH);
delay(0);
digitalWrite(LEDR,LOW);
delay(0);
digitalWrite(LEDB,HIGH);
digitalWrite(LEDB,HIGH);
delay(0);
digitalWrite(LEDB,LOW);
delay(0);
}
  if((estado_boton1 == LOW) && (estado_boton == LOW))
  {
    digitalWrite(LEDR,HIGH);
    digitalWrite(LEDR,HIGH);
    digitalWrite(LEDR,HIGH);
    delay(200);
    digitalWrite(LEDR,LOW);
    delay(200);
    digitalWrite(LEDG,HIGH);
    digitalWrite(LEDG,HIGH);
    digitalWrite(LEDG,HIGH);
    delay(200);
    digitalWrite(LEDG,LOW);
    delay(200);
    digitalWrite(LEDB,HIGH);
    digitalWrite(LEDB,HIGH);
    digitalWrite(LEDB,HIGH);
    delay(200);
    digitalWrite(LEDB,LOW);
    delay(200);
  }
  }
