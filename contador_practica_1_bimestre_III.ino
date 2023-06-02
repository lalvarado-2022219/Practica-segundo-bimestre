#define primer_numero  4
#define segundo_numero 5
#define tercer_numero  6
#define cuarto_numero  7 
#define primer_numero1  8
#define segundo_numero1 9
#define tercer_numero1  10
#define cuarto_numero1  11
int Pulsador_1=2;
int Pulsador_2=3;
volatile  int z;
volatile  int Q;
void setup()
{
pinMode(Pulsador_1,INPUT);
pinMode(Pulsador_2,INPUT);
attachInterrupt(digitalPinToInterrupt(2), Interrupcion_Pulsador_1, RISING);
attachInterrupt(digitalPinToInterrupt(3), Interrupcion_Pulsador_2, FALLING);
Serial.begin(9600);
for(int i=4; i<=11; i++)
{
  pinMode(i,OUTPUT);
}
  
}
void loop()
{
switch(Q){//DECENAS
  case 0:
  digitalWrite(primer_numero,LOW); 
  digitalWrite(segundo_numero,LOW); 
  digitalWrite(tercer_numero,LOW); 
  digitalWrite(cuarto_numero,LOW); 
  break;
  case 1:
  digitalWrite(primer_numero,LOW); 
  digitalWrite(segundo_numero,LOW); 
  digitalWrite(tercer_numero,LOW); 
  digitalWrite(cuarto_numero,HIGH); 
  break;
  case 2:
  digitalWrite(primer_numero,LOW); 
  digitalWrite(segundo_numero,LOW); 
  digitalWrite(tercer_numero,HIGH); 
  digitalWrite(cuarto_numero,LOW); 
  break;
  case 3:
  digitalWrite(primer_numero,LOW); 
  digitalWrite(segundo_numero,LOW); 
  digitalWrite(tercer_numero,HIGH); 
  digitalWrite(cuarto_numero,HIGH); 
  break;
  case 4:
  digitalWrite(primer_numero,LOW); 
  digitalWrite(segundo_numero,HIGH); 
  digitalWrite(tercer_numero,LOW); 
  digitalWrite(cuarto_numero,LOW); 
  break;
  case 5:
  digitalWrite(primer_numero,LOW); 
  digitalWrite(segundo_numero,HIGH); 
  digitalWrite(tercer_numero,LOW); 
  digitalWrite(cuarto_numero,HIGH); 
  break;
}
switch(z){//UNIDADES
   case 0:
  digitalWrite(primer_numero1,LOW); 
  digitalWrite(segundo_numero1,LOW); 
  digitalWrite(tercer_numero1,LOW); 
  digitalWrite(cuarto_numero1,LOW); 
  break;

  case 1:
  digitalWrite(primer_numero1,HIGH); 
  digitalWrite(segundo_numero1,LOW); 
  digitalWrite(tercer_numero1,LOW); 
  digitalWrite(cuarto_numero1,LOW); 
  break;
   case 2:
  digitalWrite(primer_numero1,LOW); 
  digitalWrite(segundo_numero1,HIGH); 
  digitalWrite(tercer_numero1,LOW); 
  digitalWrite(cuarto_numero1,LOW); 
  break;
 case 3:
  digitalWrite(primer_numero1,HIGH); 
  digitalWrite(segundo_numero1,HIGH); 
  digitalWrite(tercer_numero1,LOW); 
  digitalWrite(cuarto_numero1,LOW); 
  break;
 case 4:
  digitalWrite(primer_numero1,LOW); 
  digitalWrite(segundo_numero1,LOW); 
  digitalWrite(tercer_numero1,HIGH); 
  digitalWrite(cuarto_numero1,LOW); 
  break;
 case 5:
  digitalWrite(primer_numero1,HIGH); 
  digitalWrite(segundo_numero1,LOW); 
  digitalWrite(tercer_numero1,HIGH); 
  digitalWrite(cuarto_numero1,LOW); 
  break;
   case 6:
  digitalWrite(primer_numero1,LOW); 
  digitalWrite(segundo_numero1,HIGH); 
  digitalWrite(tercer_numero1,HIGH); 
  digitalWrite(cuarto_numero1,LOW); 
  break;
 case 7:
  digitalWrite(primer_numero1,HIGH); 
  digitalWrite(segundo_numero1,HIGH); 
  digitalWrite(tercer_numero1,HIGH); 
  digitalWrite(cuarto_numero1,LOW); 
  break;
   case 8:
  digitalWrite(primer_numero1,LOW); 
  digitalWrite(segundo_numero1,LOW); 
  digitalWrite(tercer_numero1,LOW); 
  digitalWrite(cuarto_numero1,HIGH); 
  break;
   case 9:
  digitalWrite(primer_numero1,HIGH); 
  digitalWrite(segundo_numero1,LOW); 
  digitalWrite(tercer_numero1,LOW); 
  digitalWrite(cuarto_numero1,HIGH); 
  break;
}

}
void Interrupcion_Pulsador_1()
{
if(z<10)
{
 z++;
}
if(z>=10)
{
 z=0;
 Q++;
}
if((Q>4)&&(z>0))
{
 Q=0;
 z=0;
}
}
void Interrupcion_Pulsador_2()
{
 if(z>=0)
 {
  z--;
 }
 if(z<0)
 {
  z=9;
  Q--;
 }
 if(Q<0)
 {
  z=0;
  Q=5;
 }
   }
