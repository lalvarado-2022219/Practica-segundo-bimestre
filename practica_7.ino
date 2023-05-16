#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <OneWire.h>                
#include <DallasTemperature.h>
#include <Adafruit_NeoPixel.h>
#include <Servo.h>
#define BUZZER 4
#define Cantidad_Leds 7
#define pin_Led A0
#define R 9
#define B 11
#define G 10
#define RELE1 A1
#define RELE2 A2
#define SERVO 5
#define INTERRUPTOR1 6
#define INTERRUPTOR2 7
#define INTERRUPTOR3 12
#define pin_Servo 5
LiquidCrystal_I2C lcd(0x27,16,2);
OneWire ourWire(2);                
DallasTemperature sensors(&ourWire); 
Adafruit_NeoPixel anillo(Cantidad_Leds,pin_Led, NEO_GRB + NEO_KHZ800);
const int RadarPin = 3;
int push_lee1;
int push_lee2;
int push_lee3;
int estado_RELE1;
int estado_RELE2;
int estado_SERVO;
int estadoAnterior1;
int estadoAnterior2;
int estadoAnterior3;
Servo Servo_Luis;
byte F[] = {
  B11111,
  B10001,
  B10001,
  B10001,
  B10011,
  B10001,
  B10001,
  B11111
};
byte NADA[] = {
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000
};
byte presencia_detectada[] = {
  B00000,
  B01010,
  B10001,
  B01110,
  B01110,
  B00100,
  B11111,
  B00100
};
byte presencia_sin_detectar[] = {
  B00000,
  B00000,
  B00000,
  B01110,
  B01110,
  B00100,
  B11111,
  B00100
};
byte APAGADA1[] = {
  B00000,
  B01110,
  B10001,
  B10001,
  B10001,
  B01110,
  B00000,
  B01110
};
byte ENCENDIDA1[] = {
  B00000,
  B01110,
  B11111,
  B11111,
  B11111,
  B01110,
  B00000,
  B01110
};
byte APAGADA2[] = {
  B00000,
  B01110,
  B10001,
  B10001,
  B10001,
  B01110,
  B00000,
  B01110
};
byte ENCENDIDA2[] = {
  B00000,
  B01110,
  B11111,
  B11111,
  B11111,
  B01110,
  B00000,
  B01110
};
byte PUERTA_CERRADA[] = {
  B11111,
  B10001,
  B10001,
  B10001,
  B10011,
  B10001,
  B10001,
  B11111
};
byte PUERTA_ABIERTA[] = {
  B11111,
  B10001,
  B10001,
  B10001,
  B10001,
  B10001,
  B10001,
  B11111
};
enum colores
{
   rojo, 
   verde,
   nada,
};



//Funciones

//Muestra todo el anillo de un solo color
void setColor(int color);
void setup()
{
 anillo.begin();
 Serial.begin(9600);
 lcd.init();
 lcd.backlight();
 sensors.begin();
 lcd.createChar(0,F);
 lcd.createChar(2,presencia_detectada);
 lcd.createChar(1,presencia_sin_detectar);
 lcd.createChar(3,NADA);
 lcd.createChar(4,APAGADA1);
 lcd.createChar(5,ENCENDIDA1);
 lcd.createChar(6,APAGADA2);
 lcd.createChar(7,ENCENDIDA2);
 pinMode(RadarPin,INPUT);  
 pinMode(BUZZER,OUTPUT); 
 pinMode(R,OUTPUT);
 pinMode(G,OUTPUT);
 pinMode(B,OUTPUT);
 pinMode(RELE1,OUTPUT);
 pinMode(RELE2,OUTPUT); 
 pinMode(INTERRUPTOR1,INPUT);
 pinMode(INTERRUPTOR2,INPUT); 
 pinMode(INTERRUPTOR3,INPUT);
 Servo_Luis.attach(pin_Servo);
 Servo_Luis.write(0);

 
}
void loop()
{
  
Serial.println(estado_RELE1);
lcd.setCursor(8,0);
lcd.write(byte(3));
lcd.setCursor(8,1);
lcd.write(byte(3));
int value = digitalRead(RadarPin);
sensors.requestTemperatures();   
float tempC= sensors.getTempCByIndex(0);
float tempF= sensors.getTempFByIndex(0);
lcd.setCursor(0,0);
lcd.print("F");
lcd.setCursor(1,0);
lcd.print("=");
lcd.setCursor(2,0);
lcd.print(tempF);
//Imprime los grados centigrados en la segunda fila
lcd.setCursor(0,1);
lcd.print("C");
lcd.setCursor(1,1);
lcd.print("=");
lcd.setCursor(2,1);
lcd.print(tempC);
lcd.setCursor(11,0);
lcd.write(byte(1));
lcd.setCursor(13,0);
lcd.write(byte(4));
lcd.setCursor(15,0);
lcd.write(byte(6));
lcd.setCursor(11,1);
lcd.write(byte(0));
noTone(BUZZER);

if(value==HIGH)
{
lcd.clear();
lcd.setCursor(0,0);
lcd.print("PRESENCIA ");
lcd.setCursor(0,1);
lcd.print("DETECTADA ");
lcd.setCursor(11,0);
tone(BUZZER,1046.50);
lcd.write(byte(1));
delay(500);
lcd.setCursor(11,0);
lcd.write(byte(2));
delay(500);
setColor(rojo);
delay(200);
}
else{
  
  setColor(verde);
}
if((tempC<21)&&(tempC>15))
{
analogWrite(R,255);
analogWrite(B,210);
analogWrite(G,0);
}
if((tempC<25)&&(tempC>21))
{
analogWrite(R,0);
analogWrite(B,0);
analogWrite(G,255);
}
if((tempC<45)&&(tempC>25))
{
analogWrite(R,255);
analogWrite(B,0);
analogWrite(G,0);
}
//INTERRUPTORES COMO MEMORIA
push_lee1 = digitalRead(INTERRUPTOR1);
push_lee2 = digitalRead(INTERRUPTOR2);
push_lee3 = digitalRead(INTERRUPTOR3);
if((push_lee1==1)&&(estadoAnterior1==0))
{estado_RELE1 = 1-estado_RELE1;
 delay(10);
}
if((push_lee2==1)&&(estadoAnterior2==0))
{estado_RELE2 = 1-estado_RELE2;
 delay(10);
}
  if((push_lee3==1)&&(estadoAnterior3==0))
{estado_SERVO = 1-estado_SERVO;

}
estadoAnterior1=push_lee1;
estadoAnterior2=push_lee2;
estadoAnterior3=push_lee3;
if(estado_RELE1==1)
{


digitalWrite(RELE1,LOW);
lcd.clear();
lcd.setCursor(0,0);
lcd.print("BOMBILLO 1 ");
lcd.setCursor(0,1);
lcd.print("ACTIVADO");
lcd.setCursor(13,0);
lcd.write(byte(4));
delay(300);
lcd.setCursor(13,0);
lcd.write(byte(5));
delay(300);
delay(1000);


 
}
  else{
    digitalWrite(RELE1,HIGH);
  }
  if(estado_RELE2==1)
{

 digitalWrite(RELE2,LOW);
 lcd.clear();
lcd.setCursor(0,0);
lcd.print("BOMBILLO 2 ");
lcd.setCursor(0,1);
lcd.print("ACTIVADO");
lcd.setCursor(13,0);
lcd.write(byte(6));
delay(300);
lcd.setCursor(13,0);
lcd.write(byte(7));
delay(300);
delay(1000);

}
  else{
    digitalWrite(RELE2,HIGH);
    
  }
  if(estado_SERVO==1)
{
Servo_Luis.write(90);
lcd.clear();
lcd.setCursor(0,0);
lcd.print("PUERTA ");
lcd.setCursor(0,1);
lcd.print("ABIERTA");
lcd.setCursor(11,1);
lcd.write(byte(0));
delay(300);
lcd.setCursor(11,1);
lcd.write(byte(3));
delay(300);
delay(1000);

}
  else{
    Servo_Luis.write(0);
  }




}
//FUNCION COLORES
void setColor(int color)
{
switch(color)
{
case(rojo):
{
for(int i =0; i<25; i++)
{
anillo.setPixelColor(i,anillo.Color(255,0,0));
anillo.show();  //muestro el color en el led
} 
break;
}
//VERDE    
case(verde):
{
for(int i =0; i<25; i++)
{
anillo.setPixelColor(i,anillo.Color(124,252,0));
anillo.show();  //muestro el color en el led
}
break;
}
case(nada):
{
for(int i =0; i<25; i++)
{
anillo.setPixelColor(i,anillo.Color(0,0,0));
anillo.show();  //muestro el color en el led
}
break;
}
}
}
                                                                                                                                                                                          
