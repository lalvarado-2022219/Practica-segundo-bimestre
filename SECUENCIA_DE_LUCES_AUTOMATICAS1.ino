/*
   Fundacion Kinal
   Centro educativo tecnico laboral Kinal
   Quinto perito
   Quinto electronica
   Codigo Tecnico: EB5AM / EB5AV 
   Curso: Taller de electronica digital y reparacion de computadoras I
   Proyecto: Leds carro fantastico
   Dev: Luis Fernando Alvarado Ramirez
   Fecha: 14 de abril
*/
#define LED1 2
#define LED2 3
#define LED3 4
#define LED4 5
#define LED5 6
#define LED6 7
#define LED7 8
#define LED8 9
#define LED9 10
#define LED10 11
#define SBI(pin)digitalWrite(pin, HIGH)
#define CBI(pin)digitalWrite(pin, LOW)
#define DLY(pin)delay(50)
#define OUT(pin)pinMode(pin,OUTPUT);
void setup()
{
OUT(LED1);
OUT(LED2);
OUT(LED3);
OUT(LED4);
OUT(LED5);
OUT(LED6);
OUT(LED7);
OUT(LED8);
OUT(LED9);
OUT(LED10);  
}
void loop()
{
SBI(LED1);
DLY(LED1);
CBI(LED1);
DLY(LED1);
SBI(LED2);
DLY(LED2);
CBI(LED2);
DLY(LED2);
SBI(LED3);
DLY(LED3);
CBI(LED3);
DLY(LED3);
SBI(LED4);
DLY(LED4);
CBI(LED4);
DLY(LED4);
SBI(LED5);
DLY(LED5);
CBI(LED5);
DLY(LED5);
SBI(LED6);
DLY(LED6);
CBI(LED6);
DLY(LED6);
SBI(LED7);
DLY(LED7);
CBI(LED7);
DLY(LED7);
SBI(LED8);
DLY(LED8);
CBI(LED8);
DLY(LED8);
SBI(LED9);
DLY(LED9);
CBI(LED9);
DLY(LED9);
SBI(LED10);
DLY(LED10);
CBI(LED10);
DLY(LED10);
SBI(LED9);
DLY(LED9);
CBI(LED9);
DLY(LED9);
SBI(LED8);
DLY(LED8);
CBI(LED8);
DLY(LED8);
SBI(LED7);
DLY(LED7);
CBI(LED7);
DLY(LED7);
SBI(LED6);
DLY(LED6);
CBI(LED6);
DLY(LED6);
SBI(LED5);
DLY(LED5);
CBI(LED5);
DLY(LED5);
SBI(LED4);
DLY(LED4);
CBI(LED4);
DLY(LED4);
SBI(LED3);
DLY(LED3);
CBI(LED3);
DLY(LED3);
SBI(LED2);
DLY(LED2);
CBI(LED2);
DLY(LED2);
}  
