/*
   Fundacion Kinal
   Centro educativo tecnico laboral Kinal
   Quinto perito
   Quinto electronica
   Codigo Tecnico: EB5AV 
   Curso: Taller de electronica digital y reparacion de computadoras I
   Proyecto: contador aro
   Dev: Luis Fernando Alvarado Ramirez
   Fecha: 28 de abril
*/
int k;
int i;
int hola;
int j;
int variable;

#define RELE A0
#define LED 4

#define lectura 12
#define a 6
#define b 7
#define c 13
#define d 11
#define e 10
#define f 8
#define g 9

void setup ()
{
  
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
 
  pinMode(a, OUTPUT);
  pinMode(b, OUTPUT);
  pinMode(c, OUTPUT);
  pinMode(d, OUTPUT);
  pinMode(e, OUTPUT);
  pinMode(f, OUTPUT);
  pinMode(g, OUTPUT);
  pinMode(RELE, OUTPUT);
  pinMode(lectura, INPUT);
  digitalWrite(RELE,HIGH);
  digitalWrite(a, HIGH);
   digitalWrite(b, HIGH);
   digitalWrite(c, HIGH);
   digitalWrite(d, HIGH);
   digitalWrite(e, HIGH);
   digitalWrite(f, HIGH);
   digitalWrite(g, LOW);
  
}
void loop()
{ 
  
  if(hola==10)
  {
     digitalWrite(RELE,LOW);
  }
  
  
 k=sensordistancia();
  j=contadores();
Serial.println(hola);
 if(hola==1)
 {
   digitalWrite(a, LOW);
   digitalWrite(b, HIGH);
   digitalWrite(c, HIGH);
   digitalWrite(d, LOW);
   digitalWrite(e, LOW);
   digitalWrite(f, LOW);
   digitalWrite(g, LOW);
   
   
 }
   if(hola==2)
 {
   digitalWrite(a, HIGH);
   digitalWrite(b, HIGH);
   digitalWrite(c, LOW);
   digitalWrite(d, HIGH);
   digitalWrite(e, HIGH);
   digitalWrite(f, LOW);
   digitalWrite(g, HIGH);
   
 }
   if(hola==3)
 {
   digitalWrite(a, HIGH);
   digitalWrite(b, HIGH);
   digitalWrite(c, HIGH);
   digitalWrite(d, HIGH);
   digitalWrite(e, LOW);
   digitalWrite(f, LOW);
   digitalWrite(g, HIGH);
   
 }
     if(hola==4)
 {
   digitalWrite(a, LOW);
   digitalWrite(b, HIGH);
   digitalWrite(c, HIGH);
   digitalWrite(d, LOW);
   digitalWrite(e, LOW);
   digitalWrite(f, HIGH);
   digitalWrite(g, HIGH);
   
 }
      if(hola==5)
 {
   digitalWrite(a, HIGH);
   digitalWrite(b, LOW);
   digitalWrite(c, HIGH);
   digitalWrite(d, HIGH);
   digitalWrite(e, LOW);
   digitalWrite(f, HIGH);
   digitalWrite(g, HIGH);
   
 }
       if(hola==6)
 {
   digitalWrite(a, HIGH);
   digitalWrite(b, LOW);
   digitalWrite(c, HIGH);
   digitalWrite(d, HIGH);
   digitalWrite(e, HIGH);
   digitalWrite(f, HIGH);
   digitalWrite(g, HIGH);
   
 }
       if(hola==7)
 {
   digitalWrite(a, HIGH);
   digitalWrite(b, HIGH);
   digitalWrite(c, HIGH);
   digitalWrite(d, LOW);
   digitalWrite(e, LOW);
   digitalWrite(f, LOW);
   digitalWrite(g, LOW);
   
 }
       if(hola==8)
 {
   digitalWrite(a, HIGH);
   digitalWrite(b, HIGH);
   digitalWrite(c, HIGH);
   digitalWrite(d, HIGH);
   digitalWrite(e, HIGH);
   digitalWrite(f, HIGH);
   digitalWrite(g, HIGH);
   
 }
         if(hola==9)
 {
   digitalWrite(a, HIGH);
   digitalWrite(b, HIGH);
   digitalWrite(c, HIGH);
   digitalWrite(d, HIGH);
   digitalWrite(e, LOW);
   digitalWrite(f, HIGH);
   digitalWrite(g, HIGH);
   
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
  if((estado_boton==HIGH)&&(hola==0))
  {
    
    hola= i++;
    
   
    
    
  }
  if((estado_boton==HIGH)&&(hola==0))
  {
    
    hola= i++;
    
   
    
    
  }
  if((estado_boton==HIGH)&&(hola==0))
  {
    
    hola= i++;
   
    
    
  }
  if((estado_boton==HIGH)&&(hola==0))
  {
    
    hola= i++;
   
    
    
  }
  if((estado_boton==HIGH)&&(hola==0))
  {
    
    hola= i++;
   
    
    
  }
  if((estado_boton==HIGH)&&(hola==0))
  {
    
    hola= i++;
   
    
    
  }
  if((estado_boton==HIGH)&&(hola==0))
  {
    
    hola= i++;
   
    
    
  }
  if((estado_boton==HIGH)&&(hola==0))
  {
    
    hola= i++;
   
    
    
  }
  if((estado_boton==HIGH)&&(hola==0))
  {
    
    hola= i++;
   
    
    
  }}
    
