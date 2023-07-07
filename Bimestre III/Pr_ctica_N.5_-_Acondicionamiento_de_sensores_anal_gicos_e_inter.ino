//Librerias
#include <LedControl.h>
#include <Ticker.h>
//Directivas de preprocesador.
int adc, cover;
int seg;
volatile static bool estado_mq2;
//Interrupciones ISR
void isr_mq2(void); 
//Constructores
LedControl lc=LedControl(11,13,10,1);
Ticker isr_accion_mq2(isr_mq2, 2000);
//Configuraciones
void setup()
{
Serial.begin(9600);
lc.shutdown(0,false);
lc.setIntensity(0,4);
lc.clearDisplay(0);
isr_accion_mq2.start(); 
}
void loop()
{
isr_accion_mq2.update();
}
//Funcion para el copo de nieve
void copo_funcion()
{
//Constructor de la figura del copo de nieve.
byte copo[8]=
{
B00101000,
B10010010,
B01010100,
B10111010,
B00010000,
B10111010,
B01010100,
B10010010,
};
//Encendido del copo de nieve, en la matriz led 8X8.
for(int i=0; i<8;i++)
{
lc.setRow(0,i,copo[i]);
}}
//Funcion para la llama
void llama_funcion()
{
//Constructor de la figura de la llama.  
byte llama[8]=
{
B00010000,
B00101000,
B01000100,
B10000010, 
B10000010,
B10000010,
B01000100,
B00111000,
};  
//Encendido de la llama, en la matriz led 8X8.
for(int i=0; i<8;i++)
{
lc.setRow(0,i,llama[i]);
}}
//Interrupcion del sensor de humo, cada 2 segundos, actualizara su valor.
void isr_mq2(void)
{
adc=analogRead(A0);
cover = map(adc,0,1024,0,100);
Serial.print("adc:");
Serial.print(adc);
Serial.println("   porcentaje:");
Serial.println(cover);
Serial.println(adc);
//si el valor del sensor es mayor a 100, quiere decir que esta detectando gas, humo, etc.
if(adc>100)
{
if(seg==0)
{
parpadeo();}
if(seg==1)
{
llama_funcion();
}
}
//si el valor del sensor es menor a 100, quiere decir que no esta detectando nada.
else{
copo_funcion();
seg=0;
}
}
//Funcion para hacer la animacion de parpadeo.
void parpadeo()
{
llama_funcion();
delay(1000);  
lc.clearDisplay(0);
delay(1000);
llama_funcion();
delay(1000);  
lc.clearDisplay(0);
delay(1000);
llama_funcion();
delay(1000);  
seg=1;
}
