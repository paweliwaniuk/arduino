#include <Servo.h> 
#define forward 30
#define reverse 60
#define start 7 // start switch, starts to move if HIGH
#define limit 2 //wall switch, moving revers if HIGH 
unsigned long current, elapse=0, finish, delta;
Servo myservo;

void setup() 
{ 
  pinMode(start,INPUT_PULLUP);
  pinMode(limit,INPUT_PULLUP);
  myservo.attach(9);
  Serial.begin(9600);
  
  } 

void loop() {
   while(digitalRead(start)==LOW)
   {Serial.println("Waiting for start button to press");
 //delay(1000);
 }
   myservo.write(forward);
   current=millis();
   Serial.print("Current= ");
   Serial.println(current);
  while(digitalRead(limit)==LOW)
   {Serial.println("Moving forward");
 //delay(1000);
 } 
   
   if (digitalRead(limit)==1)
   {finish=millis();
   Serial.println(finish);
   delta=finish-current;
    myservo.write(reverse);
    Serial.println("reversing for ");
    /*Serial.print("C= ");
    Serial.println(current);
    Serial.print("f= ");
    Serial.println(finish);*/
    Serial.println(delta);  //time to the wall
    delay(delta);
    myservo.detach();
    elapse=millis();
    
    Serial.print("servo stopped after ");
    Serial.println(elapse-finish);
    delay(15000);
    
       }
   
  } 

