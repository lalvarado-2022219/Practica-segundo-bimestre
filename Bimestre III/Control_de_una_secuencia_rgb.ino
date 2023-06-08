/*
 * Fundacion Kinal
 * Centro educativo tecnico laboral Kinal
 * Electronica
 * Grado: Quinto
 * Sección: EB5AV
 * Curso: Taller de electronica digital y reparación de computadoras I
 * Nombre: Luis Fernando Alvarado Ramirez
 * Carnet: 2022219
 * Proyecto: Control de una secuencia de colores rgb
*/
#define Led_Rojo 9
#define Led_Verde 10
#define Led_Azul 11
#define Potenciometro A0
int speedSECUENCIA=0;
int DELAY=0;
void setup()
{
pinMode(Led_Rojo,OUTPUT);
pinMode(Led_Verde,OUTPUT);
pinMode(Led_Azul,OUTPUT);
pinMode(Potenciometro,INPUT);
Serial.begin(9600);
}
void loop()
{ DELAY=analogRead(Potenciometro);
  speedSECUENCIA = map(DELAY, 0, 1023, 100, 1000);
  analogWrite(Led_Rojo, 174);
  analogWrite(Led_Verde, 92);
  analogWrite(Led_Azul, 230);
  delay(speedSECUENCIA);
  analogWrite(Led_Rojo, 255);
  analogWrite(Led_Verde, 255);
  analogWrite(Led_Azul, 255);
  delay(speedSECUENCIA);
  analogWrite(Led_Rojo, 0);
  analogWrite(Led_Verde, 255);
  analogWrite(Led_Azul, 255);
  delay(speedSECUENCIA);
    analogWrite(Led_Rojo, 189);
  analogWrite(Led_Verde, 174);
  analogWrite(Led_Azul, 20);
  delay(speedSECUENCIA);
    analogWrite(Led_Rojo, 255);
  analogWrite(Led_Verde, 87);
  analogWrite(Led_Azul, 35);
  delay(speedSECUENCIA);
   
 
    Serial.println(speedSECUENCIA);
  
  
}
