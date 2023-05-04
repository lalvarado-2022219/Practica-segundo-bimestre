#define BUZZER 4
int k;
void setup()
{
 pinMode(BUZZER, OUTPUT);
  Serial.begin(9600);
}
void loop()
{
  k=sensordistancia();
 if((k>=5)&&(k<12))
 {
  tone(BUZZER, 493.88,700);
  delay(800);
 }
  if((k>=12)&&(k<19))
 {
  tone(BUZZER, 440,700);
  delay(800);
 }
  if((k>=19)&&(k<26))
 {
  tone(BUZZER, 392,700);
  delay(800);
 }
   if((k>=26)&&(k<33))
 {
  tone(BUZZER, 349.23,700);
  delay(800);
 }
    if((k>=33)&&(k<40))
 {
  tone(BUZZER, 329.63,700);
  delay(800);
 }
     if((k>=40)&&(k<47))
 {
  tone(BUZZER, 293.66,700);
  delay(800);
 }
      if((k>=47)&&(k<54))
 {
  tone(BUZZER, 261.63,700);
  delay(800);
 }
 
}
int sensordistancia()
{
  int TRIGGER = 2;
int ECHO = 3 ;
long sensor;
long Distancia;
  pinMode(TRIGGER, OUTPUT);
  pinMode(ECHO, INPUT);
  digitalWrite(TRIGGER, LOW);
  digitalWrite(TRIGGER, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER, LOW);
  sensor=pulseIn(ECHO, HIGH);
  Distancia=sensor/59;
  delay(100);
  return Distancia;
  delay(200);
}
