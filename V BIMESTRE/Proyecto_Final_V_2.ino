/*
 * Fundacion Kinal
 * Centro educativo tecnico laboral Kinal
 * Electronica
 * Grado: Quinto
 * Sección: EB5AV
 * Curso: Taller de electronica digital y reparación de computadoras I
 * Nombre: Luis Fernando Alvarado Ramirez
 * Carnet: 2022219
 * Proyecto: Proyecto Final.
*/
#include <Wire.h> 
#define circuito A0
#include <SoftwareSerial.h>
SoftwareSerial bt(4, 5); // RX, TX
float Sensibilidad=0.100; //sensibilidad en Voltios/Amperio para sensor de 5A
float lectura=0;
float raw_circuito=0;
double voltaje;
double R1;
double R1_multiplicacion;
unsigned int R1_multiplicacion1;
float R1_multiplicacion2;
const int sensorPin = A2;   // seleccionar la entrada para el sensor
int sensorValue;      // variable que almacena el valor raw (0 a 1023)
float value;        // variable que almacena el voltaje (0.0 a 25.0)
void setup()
{
pinMode(circuito,INPUT);
Serial.begin(9600);
bt.begin(9600); 
}
void loop()
{
 float I=get_corriente(200);//obtenemos la corriente promedio de 500 muestras 
 raw_circuito=analogRead(circuito);
 lectura=map(raw_circuito,0,1023,0,1023);
 voltaje= 5*lectura/1023;
 R1_multiplicacion1=10000*5;
 R1_multiplicacion2= voltaje*10000;
 R1_multiplicacion=R1_multiplicacion1-R1_multiplicacion2;
 R1= (R1_multiplicacion/voltaje)+10;
 sensorValue = analogRead(sensorPin);        // realizar la lectura
 value = fmap(sensorValue, 0, 1023, 0.0, 25.0);   // cambiar escala a 0.0 - 25.0
  Serial.print("Voltaje: ");
  Serial.println(value);              // mostrar el valor por serial
  delay(1000);
  Serial.print("Resistencia: ");
  Serial.println(R1);
  Serial.print("Corriente: ");
  Serial.println(I,3); 
  delay(500);
  bt.print(value);
  bt.print(";");
  bt.print(I);
  bt.print(";");
  bt.print(R1);
  bt.println(";");
}
//Funcion Sensor de corriente.
float get_corriente(int n_muestras)
{
float voltajeSensor;
float corriente=0;
for(int i=0;i<n_muestras;i++)
{
voltajeSensor = analogRead(A1) * (5.0 / 1023.0);////lectura del sensor
corriente=corriente+(voltajeSensor-2.5)/Sensibilidad; //Ecuación  para obtener la corriente
}
corriente=corriente/n_muestras;
return(corriente);
}
float fmap(float x, float in_min, float in_max, float out_min, float out_max)
{
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}
