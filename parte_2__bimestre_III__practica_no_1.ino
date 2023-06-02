//Librerias
#include <Ticker.h>
#include <OneWire.h>                
#include <DallasTemperature.h>  
//Directivas de Preprocesador
#define Led_Luis 2  
#define SENSOR 3
void isr_led(void); 
void isr_sensor(void);
volatile static bool estado_led;
volatile static bool estado_sensor;
Ticker isr_accion_led(isr_led, 250); 
Ticker isr_accion_sensor(isr_sensor, 1000);
OneWire ourWire(2);                //Se establece el pin 2  como bus OneWire
DallasTemperature sensors(&ourWire); //Se declara una variable u objeto para nuestro sensor
//Configuraciones
void setup() {
Serial.begin(9600);
pinMode(Led_Luis,OUTPUT);
digitalWrite(Led_Luis,LOW);
isr_accion_led.start();
isr_accion_sensor.start();
sensors.begin();
estado_led = LOW;
}
//Ciclo que se repite constantemente
void loop() {
isr_accion_led.update();
isr_accion_sensor.update();
}
//Interrupcion
void isr_led(void)
{
sensors.requestTemperatures();   //Se envía el comando para leer la temperatura
float tempC= sensors.getTempCByIndex(0); //Se obtiene la temperatura en ºC
float tempF= sensors.getTempFByIndex(0); //Se obtiene la temperatura en ºF
estado_led = digitalRead(Led_Luis); //leo el estado digital del pin que estoy usando como salida.
digitalWrite(Led_Luis, !estado_led);
Serial.println(tempC);
}
void isr_sensor(void)
{
pinMode(SENSOR,INPUT);
bool HOLA = digitalRead(SENSOR);
if(HOLA==HIGH)
{
Serial.println("EL SENSOR ESTA ACTIVO");
}
if(HOLA==LOW)
{
Serial.println("EL SENSOR ESTA DESACTIVADO");
}
}
