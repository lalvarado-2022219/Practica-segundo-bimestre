#include <LiquidCrystal.h>
#define RS 2
#define E 3
#define D4 4
#define D5 5
#define D6 6
#define D7 7
LiquidCrystal LCD(RS, E, D4, D5, D6, D7);


void setup()
{
  
  LCD.begin(16,2);
  LCD.print("Luis Alvarado");
  LCD.setCursor(0,1);
  LCD.print("2022219");
  
  
  
}
void loop()
{

  
  
}
