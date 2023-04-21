/*
   Fundacion Kinal
   Centro educativo tecnico laboral Kinal
   Quinto perito
   Quinto electronica
   Codigo Tecnico: EB5AM / EB5AV 
   Curso: Taller de electronica digital y reparacion de computadoras I
   Proyecto: Como leer un pulsador
   Dev: Profe. Alejandro Lopez Navas
   Fecha: 14 de abril
*/

//Librerias
#include <Keypad.h>    //Libreria que me permite usar el teclado matricial.

//Macros o directivas de preprocesador
#define filas_teclado 4   //cantidad de filas que posee el teclado matricial.
#define columnas_teclado 4 //cantidad de columnas que posee el teclado matricial.
#define f1_teclado 9 //pin2 conectado a la fila 1
#define f2_teclado 8  //pin3 conectado a la fila 2
#define f3_teclado 7  //pin4 conectado a la fila 3
#define f4_teclado 6  //pin5 conectado a la fila 4
#define c1_teclado 5  //pin6 conectado a la columna 1
#define c2_teclado 4  //pin7 conectado a la columna 2
#define c3_teclado 3  //pin8 conectado a la columna 3
#define c4_teclado 2  //pin9 conectado a la columna 
#define a 10
#define b 11
#define c 12
#define d 13
#define e A0
#define f A1
#define g A2


//Creo una matriz led con la disposicion fisica de las teclas
char keys[filas_teclado][columnas_teclado] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

//Arreglos en los que defino los pines a utilizar, tanto para las columnas como para las filas
byte pines_filas[filas_teclado] = {f1_teclado,f2_teclado,f3_teclado,f4_teclado};
byte pines_columnas[columnas_teclado] = {c1_teclado,c2_teclado,c3_teclado,c4_teclado};


//Creo el constructor para poder usar el teclado matricial.
Keypad teclado_profe = Keypad( makeKeymap(keys), pines_filas, pines_columnas, filas_teclado,columnas_teclado);

void setup() 
{
  int r;
  Serial.begin(9600);    //Inicio la comunicacion serial.
  Serial.println("Prueba del teclado matricial");   //Envio de mensaje
 pinMode(a, OUTPUT);
 pinMode(b, OUTPUT);
 pinMode(c, OUTPUT);
 pinMode(d, OUTPUT);
 pinMode(e, OUTPUT);
 pinMode(f, OUTPUT);
 pinMode(g, OUTPUT);
  digitalWrite(a,HIGH);
      digitalWrite(b,HIGH);
      digitalWrite(c,HIGH);
      digitalWrite(d,HIGH);
      digitalWrite(e,HIGH);
      digitalWrite(f,HIGH);
      digitalWrite(g,LOW);
 }

void loop() 
{
  int r;
  
  char tecla = teclado_profe.getKey();  //Obtengo la tecla que presione


  //Si alguna tecla ha sido presionada
  if(tecla)
  {
    Serial.print("La tecla presionada es: ");   //Envio el mensaje
    Serial.println(tecla);    //Muestro por la terminal la tecla presionada
  tecla=tecla;
    r=tecla;

Serial.println(r);
    bool estado_tecla = digitalRead(r);
    
    if(r==49)
    {
      digitalWrite(a,LOW);
      digitalWrite(b,HIGH);
      digitalWrite(c,HIGH);
      digitalWrite(g,LOW);
      digitalWrite(f,LOW);
      digitalWrite(e,LOW);
      digitalWrite(d,LOW);
      delay(500);
      digitalWrite(a,HIGH);
      digitalWrite(b,HIGH);
      digitalWrite(c,HIGH);
      digitalWrite(g,LOW);
      digitalWrite(f,HIGH);
      digitalWrite(e,HIGH);
      digitalWrite(d,HIGH);;
    }
    if(r==50)
    {
      digitalWrite(a,HIGH);
      digitalWrite(b,HIGH);
      digitalWrite(c,LOW);
      digitalWrite(g,HIGH);
      digitalWrite(f,LOW);
      digitalWrite(e,HIGH);
      digitalWrite(d,HIGH);
      delay(500);
      digitalWrite(a,HIGH);
      digitalWrite(b,HIGH);
      digitalWrite(c,HIGH);
      digitalWrite(g,LOW);
      digitalWrite(f,HIGH);
      digitalWrite(e,HIGH);
      digitalWrite(d,HIGH);;
    }
     if(r==51)
    {
      digitalWrite(a,HIGH);
      digitalWrite(b,HIGH);
      digitalWrite(c,HIGH);
      digitalWrite(d,HIGH);
      digitalWrite(e,LOW);
      digitalWrite(f,LOW);
      digitalWrite(g,HIGH);
      delay(500);
      digitalWrite(a,HIGH);
      digitalWrite(b,HIGH);
      digitalWrite(c,HIGH);
      digitalWrite(g,LOW);
      digitalWrite(f,HIGH);
      digitalWrite(e,HIGH);
      digitalWrite(d,HIGH);;
    }
    if(r==52)
    {
      digitalWrite(a,LOW);
      digitalWrite(b,HIGH);
      digitalWrite(c,HIGH);
      digitalWrite(d,LOW);
      digitalWrite(e,LOW);
      digitalWrite(f,HIGH);
      digitalWrite(g,HIGH);
      delay(500);
      digitalWrite(a,HIGH);
      digitalWrite(b,HIGH);
      digitalWrite(c,HIGH);
      digitalWrite(g,LOW);
      digitalWrite(f,HIGH);
      digitalWrite(e,HIGH);
      digitalWrite(d,HIGH);;
    }
     if(r==53)
    {
      digitalWrite(a,HIGH);
      digitalWrite(b,LOW);
      digitalWrite(c,HIGH);
      digitalWrite(d,HIGH);
      digitalWrite(e,LOW);
      digitalWrite(f,HIGH);
      digitalWrite(g,HIGH);
      delay(500);
      digitalWrite(a,HIGH);
      digitalWrite(b,HIGH);
      digitalWrite(c,HIGH);
      digitalWrite(g,LOW);
      digitalWrite(f,HIGH);
      digitalWrite(e,HIGH);
      digitalWrite(d,HIGH);;
    }
    if(r==54)
    {
      digitalWrite(a,HIGH);
      digitalWrite(b,LOW);
      digitalWrite(c,HIGH);
      digitalWrite(d,HIGH);
      digitalWrite(e,HIGH);
      digitalWrite(f,HIGH);
      digitalWrite(g,HIGH);
      delay(500);
      digitalWrite(a,HIGH);
      digitalWrite(b,HIGH);
      digitalWrite(c,HIGH);
      digitalWrite(g,LOW);
      digitalWrite(f,HIGH);
      digitalWrite(e,HIGH);
      digitalWrite(d,HIGH);;
    }
    if(r==55)
    {
      digitalWrite(a,HIGH);
      digitalWrite(b,HIGH);
      digitalWrite(c,HIGH);
      digitalWrite(d,LOW);
      digitalWrite(e,LOW);
      digitalWrite(f,LOW);
      digitalWrite(g,LOW);
      delay(500);
      digitalWrite(a,HIGH);
      digitalWrite(b,HIGH);
      digitalWrite(c,HIGH);
      digitalWrite(g,LOW);
      digitalWrite(f,HIGH);
      digitalWrite(e,HIGH);
      digitalWrite(d,HIGH);;
    }
    if(r==56)
    {
      digitalWrite(a,HIGH);
      digitalWrite(b,HIGH);
      digitalWrite(c,HIGH);
      digitalWrite(d,HIGH);
      digitalWrite(e,HIGH);
      digitalWrite(f,HIGH);
      digitalWrite(g,HIGH);
      delay(500);
      digitalWrite(a,HIGH);
      digitalWrite(b,HIGH);
      digitalWrite(c,HIGH);
      digitalWrite(g,LOW);
      digitalWrite(f,HIGH);
      digitalWrite(e,HIGH);
      digitalWrite(d,HIGH);;
    }
    if(r==57)
    {
      digitalWrite(a,HIGH);
      digitalWrite(b,HIGH);
      digitalWrite(c,HIGH);
      digitalWrite(d,HIGH);
      digitalWrite(e,LOW);
      digitalWrite(f,HIGH);
      digitalWrite(g,HIGH);
      delay(500);
      digitalWrite(a,HIGH);
      digitalWrite(b,HIGH);
      digitalWrite(c,HIGH);
      digitalWrite(g,LOW);
      digitalWrite(f,HIGH);
      digitalWrite(e,HIGH);
      digitalWrite(d,HIGH);;
    }
    if(r==65)
    {
      digitalWrite(a,HIGH);
      digitalWrite(b,HIGH);
      digitalWrite(c,HIGH);
      digitalWrite(d,LOW);
      digitalWrite(e,HIGH);
      digitalWrite(f,HIGH);
      digitalWrite(g,HIGH);
      delay(500);
      digitalWrite(a,HIGH);
      digitalWrite(b,HIGH);
      digitalWrite(c,HIGH);
      digitalWrite(g,LOW);
      digitalWrite(f,HIGH);
      digitalWrite(e,HIGH);
      digitalWrite(d,HIGH);;
    }
    if(r==66)
    {
      digitalWrite(a,LOW);
      digitalWrite(b,LOW);
      digitalWrite(c,HIGH);
      digitalWrite(d,HIGH);
      digitalWrite(e,HIGH);
      digitalWrite(f,HIGH);
      digitalWrite(g,HIGH);
      delay(500);
      digitalWrite(a,HIGH);
      digitalWrite(b,HIGH);
      digitalWrite(c,HIGH);
      digitalWrite(g,LOW);
      digitalWrite(f,HIGH);
      digitalWrite(e,HIGH);
      digitalWrite(d,HIGH);;
    }
    if(r==67)
    {
      digitalWrite(a,LOW);
      digitalWrite(b,LOW);
      digitalWrite(c,LOW);
      digitalWrite(d,HIGH);
      digitalWrite(e,HIGH);
      digitalWrite(f,LOW);
      digitalWrite(g,HIGH);
      delay(500);
      digitalWrite(a,HIGH);
      digitalWrite(b,HIGH);
      digitalWrite(c,HIGH);
      digitalWrite(g,LOW);
      digitalWrite(f,HIGH);
      digitalWrite(e,HIGH);
      digitalWrite(d,HIGH);;
    }
    if(r==68)
    {
      digitalWrite(a,LOW);
      digitalWrite(b,HIGH);
      digitalWrite(c,HIGH);
      digitalWrite(d,HIGH);
      digitalWrite(e,HIGH);
      digitalWrite(f,LOW);
      digitalWrite(g,HIGH);
      delay(500);
      digitalWrite(a,HIGH);
      digitalWrite(b,HIGH);
      digitalWrite(c,HIGH);
      digitalWrite(g,LOW);
      digitalWrite(f,HIGH);
      digitalWrite(e,HIGH);
      digitalWrite(d,HIGH);;
    }
    if(r==42)
    {
      digitalWrite(a,HIGH);
      digitalWrite(b,LOW);
      digitalWrite(c,LOW);
      digitalWrite(d,HIGH);
      digitalWrite(e,HIGH);
      digitalWrite(f,HIGH);
      digitalWrite(g,HIGH);
      delay(500);
      digitalWrite(a,HIGH);
      digitalWrite(b,HIGH);
      digitalWrite(c,HIGH);
      digitalWrite(g,LOW);
      digitalWrite(f,HIGH);
      digitalWrite(e,HIGH);
      digitalWrite(d,HIGH);;
    }
    if(r==35)
    {
      digitalWrite(a,HIGH);
      digitalWrite(b,LOW);
      digitalWrite(c,LOW);
      digitalWrite(d,LOW);
      digitalWrite(e,HIGH);
      digitalWrite(f,HIGH);
      digitalWrite(g,HIGH);
      delay(500);
      digitalWrite(a,HIGH);
      digitalWrite(b,HIGH);
      digitalWrite(c,HIGH);
      digitalWrite(g,LOW);
      digitalWrite(f,HIGH);
      digitalWrite(e,HIGH);
      digitalWrite(d,HIGH);;
    }
      
  }}
