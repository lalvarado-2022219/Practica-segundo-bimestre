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
  if(estado_boton==LOW)
  {
    digitalWrite(RELE,HIGH);
    digitalWrite(LED,LOW);
    
  }
   if(estado_boton==HIGH)
  {
    digitalWrite(RELE,LOW);
    digitalWrite(LED,HIGH);
  }
 
  }
