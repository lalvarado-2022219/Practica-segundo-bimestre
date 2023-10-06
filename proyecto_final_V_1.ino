#include <SoftwareSerial.h>
SoftwareSerial bt(4, 5); // RX, TX
//Variable que determine el valor maximo del mapeo.
const int voltajeMax=25000;
//Variable que hace la lectura del sensor.
int lecturaDigital;
//variable que almacena el valor del voltaje.
float voltaje;
float Sensibilidad=0.185; //sensibilidad en Voltios/Amperio para sensor de 5Aç
float res;
void setup()
{
bt.begin(9600); 
Serial.begin(9600); 
}
void loop()
{
float I=get_corriente(200);//obtenemos la corriente promedio de 500 muestras 
lecturaDigital=analogRead(A0);
voltaje=map(lecturaDigital,0,1023,0,voltajeMax) / 1000.0;
imprimirVoltaje(voltaje);
Serial.println(I);
Serial.println(res);
delay(1000); 
res=voltaje/I;
bt.print(voltaje); //send distance to MIT App
bt.print(";");
bt.print(I); //send distance to MIT App 
bt.println(";");  
bt.print(res); //send distance to MIT App 
bt.println(";");  
}
//Función para la medida del voltaje.
void imprimirVoltaje(float v)
{
Serial.print("Lectura Sensor");
Serial.print(v);
Serial.println("V");
}
//Función para obtener muestras del valor de la corriente, para obtener un valor mas preciso.
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
