/*
 * Fundacion Kinal
 * Centro educativo tecnico laboral Kinal
 * Electronica
 * Grado: Quinto
 * Sección: A
 * Curso: Taller de electronica digital y reparación de computadoras I
 * Nombre: Profe Alejandro
 * Carnet: ---------
 * Proyecto: ADC + PWM
*/
#define Led 3
#define Potenciometro A0
unsigned int Brillo_Led=0;
unsigned int raw_Potenciometro=0;
void setup()
{
pinMode(Led,OUTPUT);
pinMode(Potenciometro,INPUT);
Serial.begin(9600);
}
void loop()
{
 raw_Potenciometro=analogRead(Potenciometro);
 Brillo_Led=map(raw_Potenciometro,0,1023,0,255);
 analogWrite(Led,Brillo_Led);
 delay(100);
 Serial.println(Brillo_Led);
}
