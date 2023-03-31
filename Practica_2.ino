/*
* Fundacion Kinal
* Centro Educativo laboral Kinal
* Perito en Electronica
* Quinto Perito
* Seccion: A
* Curso: Taller de electronica digital y reparacion de computadoras
* Alumno: Luis Fernando Alvarado Ramirez
* Carne:2022219
* Peoyecto: Cátalogo de productos
* */
#define AVANCE 2
#define RETROCESO 3
int i=0;
int variable;
int variable1;
int variable2;
struct PRODUCTO_1
  
{
  int STOCK1;
  int RESERVA1;
  char* PRECIO_UNITARIO1;
  char* NOMBRE_PRODUCTO1;
};
PRODUCTO_1 PR1;
struct PRODUCTO_2
{
  int STOCK2;
  int RESERVA2;
  char* PRECIO_UNITARIO2;
  char* NOMBRE_PRODUCTO2;
};
PRODUCTO_2 PR2;
struct PRODUCTO_3
{
  int STOCK3;
  int RESERVA3;
  char* PRECIO_UNITARIO3;
  char* NOMBRE_PRODUCTO3;
};
PRODUCTO_3 PR3;
struct PRODUCTO_4
{
  int STOCK4;
  int RESERVA4;
  char* PRECIO_UNITARIO4;
  char* NOMBRE_PRODUCTO4;
};
PRODUCTO_4 PR4;
void setup()
{
  PR1.STOCK1;
  PR1.RESERVA1;
  PR1.PRECIO_UNITARIO1;
  PR1.NOMBRE_PRODUCTO1;
  
  
  PR2.STOCK2;
  PR2.RESERVA2;
  PR2.PRECIO_UNITARIO2;
  PR2.NOMBRE_PRODUCTO2;
  
  PR3.STOCK3;
  PR3.RESERVA3;
  PR3.PRECIO_UNITARIO3;
  PR3.NOMBRE_PRODUCTO3;
  
  
  PR4.STOCK4;
  PR4.RESERVA4;
  PR4.PRECIO_UNITARIO4;
  PR4.NOMBRE_PRODUCTO4;
  Serial.begin(9600);
  
}
  void loop ()
  
  {
   
bool estado_boton = digitalRead(AVANCE);
bool estado_boton1 = digitalRead(RETROCESO);    
if(estado_boton==HIGH)
{
i++;
variable=i;
variable2=i;
if(variable==1)
{
  delay(300);
PR1.STOCK1=100;
PR1.RESERVA1=200;
PR1.PRECIO_UNITARIO1="5Q";
PR1.NOMBRE_PRODUCTO1="Lays";
Serial.println("STOCK DEL PRODUCTO 1:");
Serial.println(PR1.STOCK1);
Serial.println("RESERVA DEL PRODUCTO 1:");
Serial.println(PR1.RESERVA1);
Serial.println("PRECIO DEL PRODUCTO 1:");  
Serial.println(PR1.PRECIO_UNITARIO1);
Serial.println("NOMBRE DEL PRODUCTO 1:");
Serial.println(PR1.NOMBRE_PRODUCTO1);
Serial.println("    ");
Serial.println("    ");  

}
  
  if(variable==2)
{
    delay(300);
PR2.STOCK2=50;
PR2.RESERVA2=100;
PR2.PRECIO_UNITARIO2="5Q";
PR2.NOMBRE_PRODUCTO2="Coca Cola";
Serial.println("STOCK DEL PRODUCTO 2:");    
Serial.println(PR2.STOCK2);
Serial.println("RESERVA DEL PRODUCTO 2:");    
Serial.println(PR2.RESERVA2);
Serial.println("PRECIO DEL PRODUCTO 2:");    
Serial.println(PR2.PRECIO_UNITARIO2);
Serial.println("NOMBRE DEL PRODUCTO 2:");
Serial.println(PR2.NOMBRE_PRODUCTO2);
Serial.println("    ");
Serial.println("    ");    
}

  
  if(variable==3)
{
    delay(300);
PR3.STOCK3=200;
PR3.RESERVA3=500;
PR3.PRECIO_UNITARIO3="1Q";
PR3.NOMBRE_PRODUCTO3="TORTRIX";
Serial.println("STOCK DEL PRODUCTO 3:");
Serial.println(PR3.STOCK3);
Serial.println("RESERVA DEL PRODUCTO 3:");    
Serial.println(PR3.RESERVA3);
Serial.println("PRECIO DEL PRODUCTO 3:");    
Serial.println(PR3.PRECIO_UNITARIO3);
Serial.println("NOMBRE DEL PRODUCTO 3:");
Serial.println(PR3.NOMBRE_PRODUCTO3);
Serial.println("    ");
Serial.println("    ");    
}

  if(variable==4)
{
    delay(300);
PR4.STOCK4=50;
PR4.RESERVA4=75;
PR4.PRECIO_UNITARIO4="5Q";
PR4.NOMBRE_PRODUCTO4="DORITO";
Serial.println("STOCK DEL PRODUCTO 4:");    
Serial.println(PR4.STOCK4);
Serial.println("RESERVA DEL PRODUCTO 4:");    
Serial.println(PR4.RESERVA4);
Serial.println("PRECIO DEL PRODUCTO 4:");    
Serial.println(PR4.PRECIO_UNITARIO4);
Serial.println("NOMBRE DEL PRODUCTO 4:");    
Serial.println(PR4.NOMBRE_PRODUCTO4);
Serial.println("    ");
Serial.println("    ");    
}    
  
 if(variable2==5)
  {
    variable2=0;
    i=variable2;
    
    
    
    
  }  
    
    
    
    
    
} 
  

 if(estado_boton1==LOW)
{
  i--;
   variable=i;
    variable1=i;
  delay(100);
  
 if(variable==1)
{
  delay(300);
PR1.STOCK1=100;
PR1.RESERVA1=200;
PR1.PRECIO_UNITARIO1="5Q";
PR1.NOMBRE_PRODUCTO1="Lays";
Serial.println("STOCK DEL PRODUCTO 1:");
Serial.println(PR1.STOCK1);
Serial.println("RESERVA DEL PRODUCTO 1:");
Serial.println(PR1.RESERVA1);
Serial.println("PRECIO DEL PRODUCTO 1:");  
Serial.println(PR1.PRECIO_UNITARIO1);
Serial.println("NOMBRE DEL PRODUCTO 1:");
Serial.println(PR1.NOMBRE_PRODUCTO1);
Serial.println("    ");
Serial.println("    ");   
}
  
  if(variable==2)
{
    delay(300);
PR2.STOCK2=50;
PR2.RESERVA2=100;
PR2.PRECIO_UNITARIO2="5Q";
PR2.NOMBRE_PRODUCTO2="Coca Cola";
Serial.println("STOCK DEL PRODUCTO 2:");    
Serial.println(PR2.STOCK2);
Serial.println("RESERVA DEL PRODUCTO 2:");    
Serial.println(PR2.RESERVA2);
Serial.println("PRECIO DEL PRODUCTO 2:");    
Serial.println(PR2.PRECIO_UNITARIO2);
Serial.println("NOMBRE DEL PRODUCTO 2:");
Serial.println(PR2.NOMBRE_PRODUCTO2);
Serial.println("    ");
Serial.println("    ");    
}

  
  if(variable==3)
{
    delay(300);
PR3.STOCK3=200;
PR3.RESERVA3=500;
PR3.PRECIO_UNITARIO3="1Q";
PR3.NOMBRE_PRODUCTO3="TORTRIX";
Serial.println("STOCK DEL PRODUCTO 3:");
Serial.println(PR3.STOCK3);
Serial.println("RESERVA DEL PRODUCTO 3:");    
Serial.println(PR3.RESERVA3);
Serial.println("PRECIO DEL PRODUCTO 3:");    
Serial.println(PR3.PRECIO_UNITARIO3);
Serial.println("NOMBRE DEL PRODUCTO 3:");
Serial.println(PR3.NOMBRE_PRODUCTO3);
Serial.println("    ");
Serial.println("    ");    
}

  if(variable==4)
{
    delay(300);
PR4.STOCK4=50;
PR4.RESERVA4=75;
PR4.PRECIO_UNITARIO4="5Q";
PR4.NOMBRE_PRODUCTO4="DORITO";
Serial.println("STOCK DEL PRODUCTO 4:");    
Serial.println(PR4.STOCK4);
Serial.println("RESERVA DEL PRODUCTO 4:");    
Serial.println(PR4.RESERVA4);
Serial.println("PRECIO DEL PRODUCTO 4:");    
Serial.println(PR4.PRECIO_UNITARIO4);
Serial.println("NOMBRE DEL PRODUCTO 4:");    
Serial.println(PR4.NOMBRE_PRODUCTO4);
Serial.println("    ");
Serial.println("    ");    
}    
   
   
  }
    
  if(variable1==0)
  {
    variable1=5;
    i=variable1;  }
  
  
 
    
    
    
  
 }

    
    
