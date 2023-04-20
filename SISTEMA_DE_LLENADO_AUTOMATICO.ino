/*
   Fundacion Kinal
   Centro educativo tecnico laboral Kinal
   Quinto perito
   Quinto electronica
   Codigo Tecnico: EB5AM / EB5AV 
   Curso: Taller de electronica digital y reparacion de computadoras I
   Proyecto: SISTEMA_DE_LLENADO_AUTOMATICO
   Dev: Luis Fernando Alvarado Ramirez
   Fecha: 20 de abril de 2023
*/
#define lectura 2
#define RELE 3
#define LED 4
void setup()
{
  pinMode(lectura, INPUT);
  pinMode(RELE, OUTPUT);
  pinMode(LED, OUTPUT);
  
}
void loop()
{
  bool estado_boton = digitalRead(lectura);
  if(estado_boton==HIGH)
  {
    digitalWrite(RELE,LOW);
    digitalWrite(LED,HIGH);
    
  }
   if(estado_boton==LOW)
  {
    digitalWrite(RELE,HIGH);
    digitalWrite(LED,LOW);
  }
 
  }
