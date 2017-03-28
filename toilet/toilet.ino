int p_switch =3;//input number
int pump=10;    //input number
int tap=11;     //input number
int pictogram=2;//input number
int counter=0;
int attempt=0;

unsigned long x;

void pump_on(int x)
{digitalWrite(pump,LOW);
delay(x);
 }

void pump_off(int x)
{digitalWrite(pump,HIGH);
delay(x);}

void tap_on(int x)
{digitalWrite(tap,LOW);
delay(x);}

void tap_off(int x)
{digitalWrite(tap,HIGH);
delay(x);}

void priming()

{ Serial.println("priming");   
  delay(100);
    pump_on(2000);
    tap_on(5000);
    pump_off(100);
  tap_off(100);
  }
int toilet_state()
{  
if(digitalRead(pictogram)==0)
{delay(2000);
return 0;}
else 
{
delay(2000);
return 1;}  }//healthy

void p_achieved(){Serial.println("Pressure achieved");
}

void setup(){
  Serial.begin(9600);
  pinMode(p_switch, INPUT_PULLUP);//pressure switch 0 low pressure
  pinMode(pump,OUTPUT);//LOW ENERGISED relay 1
  pinMode(tap,OUTPUT);//LOW ENERGISED  relay 2
  pinMode(pictogram,INPUT);//
  attachInterrupt(p_switch,p_achieved, RISING);
  pump_off(10);
  tap_off(10);
}

void loop()
{
  Serial.print(" pressure switch  ");
  Serial.print(digitalRead(p_switch));
  Serial.print(" ,attempt  ");
  Serial.println(attempt);
  
  if (digitalRead(p_switch)==0 & toilet_state()==0 & attempt==0)
  {
    priming();
    if (digitalRead(p_switch)==0) {attempt=1;}
    }
    
  else if(toilet_state()==1)
    {attempt=0;
  Serial.println("Toilet healthy");}
  
    
  else if(digitalRead(p_switch)==0 & toilet_state()==0 & attempt==1)
    {attempt=1;
  Serial.println("failed to prime");}
    
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
