/* 
 * Fundacion Kinal
 * Centro educativo tecnico laboral Kinal
 * Perito en electonica
 * Quinto perito
 * EB5AM / EB5AV
 * Taller de electronica digital y reparacion de computadoras
 * Nombre: Profe Alejandro Lopez
 * Fecha: 04/05/2023
 * Proyecto: ServoMotor
 */


//Libreria
#include <Servo.h> //libreria que me permite usar el servo

//Directivas de preprocesador
#define pin_Servo 6
#define pin_Servo_1 5
#define pin_Servo_2 3
#define pin_Servo_3 9

//Constructor
Servo Servo_profeAlejandro;  //mi servo
Servo Servo_profeAlejandro_1;
Servo Servo_profeAlejandro_2;
Servo Servo_profeAlejandro_3;
void setup()
{
  
  Servo_profeAlejandro.attach(pin_Servo);
  Servo_profeAlejandro_1.attach(pin_Servo_1);
   Servo_profeAlejandro_2.attach(pin_Servo_2);
    Servo_profeAlejandro_3.attach(pin_Servo_3);

}

void loop()
{
  

     Servo_profeAlejandro.write(180);
     Servo_profeAlejandro_1.write(180);
     Servo_profeAlejandro_2.write(180);
      Servo_profeAlejandro_3.write(180);
    delay(2000);
    Servo_profeAlejandro.write(0);
    Servo_profeAlejandro_1.write(0);
    Servo_profeAlejandro_2.write(0);
    Servo_profeAlejandro_3
    
    .write(0);
    delay(2000);
    
    
  
 
}
