// white goes to X7:3 K6_state input
// yellow goes to X7:2 p_switch input

int p_switch =2;//input number change to 3 later
int pump=4;    //output number relay 1 on PCB
int tap=7;     //output number relay 2 on PCB
//int counter=0;
int attempt=0;
int K6_state=6;//input number change to 2 later
unsigned long x;

void reset_timing()
{digitalWrite(pump,HIGH);
Serial.println("R1 on/off");
delay(1000);
digitalWrite(pump,LOW);
delay(1000);
digitalWrite(tap,HIGH);
Serial.println("photocel on/off");
delay(1000);
digitalWrite(tap,LOW);
delay(5000);
}

void prime()
{attempt=attempt+1;
Serial.print("Attempt: ");
Serial.println(attempt);
Serial.println("priming");
delay(1000);
reset_timing();}


void setup(){
  Serial.begin(9600);
  pinMode(p_switch, INPUT);//pressure switch 0 low pressure
  pinMode(pump,OUTPUT);//HIGH ENERGISED relay 1
  pinMode(tap,OUTPUT);//HIGH ENERGISED  relay 2
  pinMode(K6_state,INPUT);//
  digitalWrite(tap,LOW);
  digitalWrite(pump,LOW);
  //attachInterrupt(p_switch,p_achieved, RISING);
}

void loop()
{
  Serial.print(" pressure switch  ");
  Serial.print(digitalRead(p_switch));
  Serial.print(" ,attempt  ");
  Serial.println(attempt);
  Serial.println("main loop");
  delay(2000);
  if (digitalRead(p_switch)==1 & digitalRead(K6_state)==1 & attempt<3)// 
  {    prime();  
delay(2000);  }
    
  else if ( digitalRead(p_switch)==0)
    {attempt=0;
      Serial.println("Toilet healthy and primed");
      delay(2000);
    }
  
  else if (digitalRead(p_switch)== 1 & digitalRead(K6_state)==0)
    { attempt=0;
       Serial.println("LOOU");
     delay(2000);}
     }
  
  
  /* TOILET STATE 
  int toilet_state()
{int counter = 0;
for (x=0;x<15;x++)
    {counter=counter+digitalRead(pictogram);
    delay(200);}
    if (counter<8 & counter>4)
     {
   Serial.println("LOOU");
 return 0;}//unhealthy
      else{
      Serial.println(" ok ");
    return 1;}}//healthy
*/
