
#include <Servo.h> 
  int dtime = 10;
  int tol = 50;

Servo horizontal; 
int servoh = 30;   

int servohLimitHigh = 70;
int servohLimitLow = 10;

// 65 degrees MAX
Servo vertical;   
int servov = 30;    

int servovLimitHigh = 70;
int servovLimitLow = 10;


// LDR pin connections
//  name  = analogpin;
int ldrlt = 2; //LDR top left 
int ldrrt = 3; //LDR top rigt
int ldrld = 0; //LDR down left 
int ldrrd = 1; //LDR down rigt 

void setup()
{
  Serial.begin(9600);

  horizontal.attach(9); 
  vertical.attach(10);
  horizontal.write(10);
  vertical.write(10);
  
  delay(1000);
}

void loop() 
{
  int lt = analogRead(ldrlt); // top left
  int rt = analogRead(ldrrt); // top right
  int ld = analogRead(ldrld); // down left
  int rd = analogRead(ldrrd); // down rigt
  


  
  int avt = ((lt + rt)/2);   // average value top
  int avd = ((ld + rd) /2)+2; //  average value down
  int avl = ((lt + ld) /2);// average value left
  int avr = ((rt + rd) / 2)+2; // average value right

  int dvert = avt - avd; // check the diffirence of up and down
  int dhoriz = avl - avr;// check the diffirence og left and rigt
  
//  
  Serial.print(avl);
  Serial.print("left   ");
  Serial.println(avr);
  Serial.println("right   ");
  Serial.println(avt);
  Serial.println("top");
  Serial.println(avd);
  Serial.println("down");
delay(500);


  if (avt > avd)
  {
    servov=servov+10;
     if (servov > servovLimitHigh) 
     { 
      servov = servovLimitHigh;
     }
  }
  else if (avt < avd)
  {
    servov=servov-10;
    if (servov < servovLimitLow)
  {
    servov = servovLimitLow;
  }
  }
  vertical.write(servov);
 
if (avl > avr)
  {
    servoh=servoh-10;
    if (servoh < servohLimitLow)
    {
    servoh = servohLimitLow;
    }
  }
  else if (avl < avr)
  {
    servoh=servoh+10;
     if (servoh > servohLimitHigh)
     {
     servoh = servohLimitHigh;
     }
  }

  
  horizontal.write(servoh);
  
   delay(300);

}
