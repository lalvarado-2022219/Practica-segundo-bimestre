#include <Wire.h>  
#include <PCF8574.h>  
PCF8574 expansor_PCF(0x27);
PCF8574 expansor_PCF1(0x26);
#define PCF8574_HIGH LOW  //Negacion utilizada para encender un puerto del expansor PCF8574
#define PCF8574_LOW HIGH  //Negacion utilizada para apagar un puerto del expansor PCF8574
#define LED0 0    //puerto 0 del expansor
#define LED1 1    //puerto 1 del expansor
#define LED2 2    //puerto 2 del expansor
#define LED4 4    //puerto 4 del expansor
#define LED5 5    //puerto 5 del expansor
#define LED6 6    //puerto 6 del expansor
#define LED7 7    //puerto 7 del expansor
#define Led_arduino1 2
#define Led_arduino2 3
#define Led_arduino3 4
#define Led_arduino4 5
#define Led_arduino5 6
#define Led_arduino6 7
#define Led_arduino7 8
#define Led_arduino8 9
String inf_recibida;
long x;
int n=25;
String departamentos0 [] = {"Peten","Izabal","Alta Verapaz","Quiche","Huehuetenango","Escuintla","San marcos","Jutiapa","Baja Verapaz","Santa Rosa","Zacapa",
"Suchitepequez","Chiquimula","Guatemala","Jalapa","Chimaltenango","Quetzaltenango","El progreso","Retalhuleu","Solola","Totonicapan","Sacatepequez"};
void setup()
{
Serial.begin(9600);
for(int l=2; l<=9; l++)
{
pinMode(l,OUTPUT);
}

Wire.begin(); 
expansor_PCF.begin();
expansor_PCF1.begin();
}
void loop()
{
 x=random(0,21);
 while (Serial.available() > 0)
{
 inf_recibida = Serial.readStringUntil('\r\n'); //Voy a guardar en el string todo el texto antes de encontrar el caracter delimitador
 Serial.print("La cadena de texto recibida es: "); //Envio al monitor serial el texto entre comillas
 Serial.println(inf_recibida); //Envio al monitor serial el string guardado
 
 switch(n){
 case 0: if(inf_recibida==String("Flores")){  expansor_PCF.write(0,PCF8574_HIGH); Serial.println("Resupuesta correcta"); }
  else{if(inf_recibida!=String("stop")){
  Serial.println("Resupuesta incorrecta");
  tono();
  n=25;
 }}
 break;

 case 1: if(inf_recibida==String("Puerto barrios")){ Serial.println("Resupuesta correcta"); expansor_PCF.write(1,PCF8574_HIGH); }else{if(inf_recibida!=String("stop")){
  Serial.println("Resupuesta incorrecta");
  tono();
  n=25;
 }}
 break;

 case 2: if(inf_recibida==String("Coban")){ Serial.println("Resupuesta correcta"); expansor_PCF.write(2,PCF8574_HIGH); }else{if(inf_recibida!=String("stop")){
  Serial.println("Resupuesta incorrecta");
  tono();
  n=25;
 }}
 break;

 case 3: if(inf_recibida==String("Santa cruz del quiche")){ Serial.println("Resupuesta correcta"); expansor_PCF.write(4,PCF8574_HIGH); }else{if(inf_recibida!=String("stop")){
  Serial.println("Resupuesta incorrecta");
  tono();
  n=25;
 }}
 break;

 case 4: if(inf_recibida==String("Huehuetenango")){ Serial.println("Resupuesta correcta"); expansor_PCF.write(5,PCF8574_HIGH); }else{if(inf_recibida!=String("stop")){
  Serial.println("Resupuesta incorrecta");
  tono();
  n=25;
 }}
 break;

 case 5: if(inf_recibida==String("Escuintla")){ Serial.println("Resupuesta correcta"); expansor_PCF.write(6,PCF8574_HIGH); }else{if(inf_recibida!=String("stop")){
  Serial.println("Resupuesta incorrecta");
  tono();
  n=25;
 }}
 break;

 case 6: if(inf_recibida==String("San marcos")){ Serial.println("Resupuesta correcta"); expansor_PCF.write(7,PCF8574_HIGH); }else{if(inf_recibida!=String("stop")){
  Serial.println("Resupuesta incorrecta");
  tono();
  n=25;
 }}
 break;

 case 7: if(inf_recibida==String("Jutiapa")){ Serial.println("Resupuesta correcta"); expansor_PCF1.write(0,PCF8574_HIGH); }else{if(inf_recibida!=String("stop")){
  Serial.println("Resupuesta incorrecta");
  tono();
  n=25;
 }}
 break;

 case 8: if(inf_recibida==String("Salama")){ Serial.println("Resupuesta correcta"); expansor_PCF1.write(1,PCF8574_HIGH); }else{if(inf_recibida!=String("stop")){
  Serial.println("Resupuesta incorrecta");
  tono();
  n=25;
 }}
 break;

 case 9: if(inf_recibida==String("Cuilapa")){ Serial.println("Resupuesta correcta"); expansor_PCF1.write(2,PCF8574_HIGH); }else{if(inf_recibida!=String("stop")){
  Serial.println("Resupuesta incorrecta");
  tono();
  n=25;
 }}
 break;

 case 10: if(inf_recibida==String("Zacapa")){ Serial.println("Resupuesta correcta"); expansor_PCF1.write(4,PCF8574_HIGH); }else{if(inf_recibida!=String("stop")){
  Serial.println("Resupuesta incorrecta");
  tono();
  n=25;
 }}
 break;

 case 11: if(inf_recibida==String("Mazatenango")){ Serial.println("Resupuesta correcta"); expansor_PCF1.write(5,PCF8574_HIGH); }else{if(inf_recibida!=String("stop")){
  Serial.println("Resupuesta incorrecta");
  tono();
  n=25;
 }}
 break;

 case 12: if(inf_recibida==String("Chiquimula")){ Serial.println("Resupuesta correcta"); expansor_PCF1.write(6,PCF8574_HIGH); }else{if(inf_recibida!=String("stop")){
  Serial.println("Resupuesta incorrecta");
  tono();
  n=25;
 }}
 break;

 case 13: if(inf_recibida==String("Guatemala")){ Serial.println("Resupuesta correcta"); expansor_PCF1.write(7,PCF8574_HIGH); }else{if(inf_recibida!=String("stop")){
  Serial.println("Resupuesta incorrecta");
  tono();
  n=25;
 }}
 break;

 case 14: if(inf_recibida==String("Jalapa")){ Serial.println("Resupuesta correcta"); digitalWrite(Led_arduino1,HIGH); }else{if(inf_recibida!=String("stop")){
  Serial.println("Resupuesta incorrecta");
  tono();
  n=25;
 }}
 break;

 case 15: if(inf_recibida==String("Chimaltenango")){ Serial.println("Resupuesta correcta"); digitalWrite(3,HIGH); }else{if(inf_recibida!=String("stop")){
  Serial.println("Resupuesta incorrecta");
  tono();
  n=25;
 }}
 break;

 case 16: if(inf_recibida==String("Quetzaltenango")){ Serial.println("Resupuesta correcta"); digitalWrite(4,HIGH); }else{if(inf_recibida!=String("stop")){
  Serial.println("Resupuesta incorrecta");
  tono();
  n=25;
 }}
 break;

 case 17: if(inf_recibida==String("Guastatoya")){ Serial.println("Resupuesta correcta"); digitalWrite(5,HIGH); }else{if(inf_recibida!=String("stop")){
  Serial.println("Resupuesta incorrecta");
  tono();
  n=25;
 }}
 break;

 case 18: if(inf_recibida==String("Retalhuleu")){ Serial.println("Resupuesta correcta"); digitalWrite(6,HIGH); }else{if(inf_recibida!=String("stop")){
  Serial.println("Resupuesta incorrecta");
  tono();
  n=25;
 }}
 break;

 case 19: if(inf_recibida==String("Solola")){ Serial.println("Resupuesta correcta"); digitalWrite(7,HIGH); }else{if(inf_recibida!=String("stop")){
  Serial.println("Resupuesta incorrecta");
  tono();
  n=25;
 }}
 break;
 
 case 20: if(inf_recibida==String("Totonicapan")){ Serial.println("Resupuesta correcta"); digitalWrite(8,HIGH); }else{if(inf_recibida!=String("stop")){
  Serial.println("Resupuesta incorrecta");
  tono();
  n=25;
 }}
 break;

 case 21: if(inf_recibida==String("Antigua guatemala")){ Serial.println("Resupuesta correcta"); digitalWrite(9,HIGH); }else{if(inf_recibida!=String("stop")){
  Serial.println("Resupuesta incorrecta");
  tono();
  n=25;
 }}
 break;
 }


if(inf_recibida==String("stop"))
 {
 for( int f=0; f<=7; f++)
 {
 expansor_PCF.write(f,PCF8574_LOW); 
  expansor_PCF1.write(f,PCF8574_LOW); 
  }
  for(int u=2; u<=9; u++)
  {
   digitalWrite(u,LOW);
  }
 
 Serial.print("Cual es la cabecera departamental de ");
 Serial.println(departamentos0[x]);

switch(x){
  case 0: n=0; break;case 1: n=1; break; case 2: n=2; break;case 3: n=3; break;case 4: n=4; break;case 5: n=5; break;case 6: n=6; break;case 7: n=7; break;
  case 8: n=8; break;case 9: n=9; break;case 10: n=10; break;case 11: n=11; break;case 12: n=12; break;case 13: n=13; break;case 14: n=14; break;case 15: n=15; break;
  case 16: n=16; break;case 17: n=17; break;case 18: n=18; break;case 19: n=19; break;case 20: n=20; break;case 21: n=21; break;
 }
}}
}
void tono()
{
#define Buzzer 11
float si = 493.88;
float la= 440.00;
float sol = 392.00;
pinMode(Buzzer,OUTPUT);
tone(Buzzer, si, 400);
delay(500);
tone(Buzzer, la, 400);
delay(500);
tone(Buzzer, sol, 400);
delay(500);

tone(Buzzer, si, 400);
delay(500);
tone(Buzzer, la, 400);
delay(500);
tone(Buzzer, sol, 400);
delay(500);

tone(Buzzer, sol, 400);
delay(500);
tone(Buzzer, sol, 400);
delay(500);
tone(Buzzer, la, 400);
delay(500);
tone(Buzzer, la, 400);
delay(500);

tone(Buzzer, si, 400);
delay(500);
tone(Buzzer, la, 400);
delay(500);
tone(Buzzer, sol, 400);
delay(500);
}
