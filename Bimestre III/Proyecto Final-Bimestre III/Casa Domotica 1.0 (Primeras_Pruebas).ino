//Librerias.
#include <LiquidCrystal_I2C.h>

//Directivas de preprocesador.
char valor;
String estado;
int usuario=0;

//Constructores.
LiquidCrystal_I2C lcd(0x27,16,2);  

//Configuraciones.
void setup() {
//Inicio la comunicación Serial.
Serial.begin(9600); 
//Inicializo la lcd.
lcd.init();
//Enciendo la luz del fondo.
lcd.backlight();
//Posiciono el Cursor, en la columna 6, fila 1
lcd.setCursor(6,0);
lcd.print("Casa");
//Posiciono el Cursor, en la columna 4, fila 2
lcd.setCursor(4,1);
lcd.print("Domotica");
delay(2000);
lcd.clear();
 
}

void loop() {
//Si el usuario, vale 1, ya se puede acceder a las funciones de la Casa.
if(usuario==1)
{
//Si el dato entrante via bluetooth, es 1, se activara el primer relay, activando el bombillo.
if(valor == '1')
{
Serial.println("El bombillo 1, ha sido activado.");
}
//Si el dato entrante via bluetooth, es 2, se desactivara el primer relay, desactivando el bombillo.
if(valor == '2')
{
Serial.println("El bombillo 1, ha sido desactivado.");
}

}
//Si el puerto serie (Bluetooth) está disponible
if (Serial.available())
{
//Lee el dato entrante via Bluetooth
valor = Serial.read(); 
//Si el dato entrante es una A
if (valor == 'A')  
{
//Llama la función que muestra el mensaje en la pantalla LCD
texto();  
}
}
//Función del mensaje entrante.
}
void texto()
{
delay(30);
while (Serial.available())
{
//Lee el dato entrante y lo almacena en una variable tipo char
char c = Serial.read();  
//Crea una cadena tipo String con los datos entrates
estado += c;            
}
//Se verifica que la cadena tipo String tenga un largo mayor a cero
if (estado.length() > 0)   
{
//Muestra el mensaje en la pantalla LCD
Serial.println(estado);    

//Si la contraseña es correcta.
if(estado == String("CASADOMOTICA1"))
{
//Se cambia el valor del usuario a 1, quiere decir que ingreso a la casa.
usuario=1;
//Se imrpime en el monitor serial, que la contraseña es correcta.
Serial.println("La contraseña que ha ingresado, es correcta");
//Se imrpime en el lcd, que la contraseña es correcta.
lcd.setCursor(1,0);
lcd.print("La contrasena");
lcd.setCursor(2,1);
lcd.print("es correcta");
delay(1500);
lcd.clear();
lcd.setCursor(3,0);
lcd.print("Bienvenido");
delay(1500);
 
}
//Si la contraseña no es correcta.
else{
//Se cambia el valor del usuario a 0, quiere decir que el ingreso no fue posible.
usuario=0;
//Se imrpime en el monitor serial, que la contraseña es incorrecta.
Serial.println("La contraseña que ha ingresado, es incorrecta");
Serial.println("reintentelo de nuevo");
//Se imrpime en el lcd, que la contraseña es incorrecta.
lcd.setCursor(1,0);
lcd.print("La contrasena");
lcd.setCursor(2,1);
lcd.print("es incorrecta");
delay(1500);
lcd.clear();
lcd.setCursor(3,0);
lcd.print("Reintentelo");
delay(1500);
}
    
//Limpia la variable para posteriormente leer nuevos datos
estado = "";      
}
}
