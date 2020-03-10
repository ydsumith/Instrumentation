# include <Wire.h>

int x=0;

#define PWMD 3 // Rear left

#define DIRD 2 // Rear left HIGH means FWD, LOW means BKWD

#define PWMC 5 // Rear right

#define DIRC 4 // Rear right LOW means FWD, HIGH means BKWD

#define PWMB 6 // Front left 

#define DIRB 7 // Front left LOW means FWD, HIGH means BKWD

#define PWMA 9 // Front right

#define DIRA 8 // Front right LOW means FWD, HIGH means BKWD



int speed1 = 150; int speed2 = 150; int delayval1 = 2000; int delayval2 = 200;



void setup() {

  pinMode(PWMA, OUTPUT);

  pinMode(DIRA, OUTPUT);

  pinMode(PWMB, OUTPUT);

  pinMode(DIRB, OUTPUT);

  pinMode(PWMC, OUTPUT);

  pinMode(DIRC, OUTPUT);

  pinMode(PWMD, OUTPUT);

  pinMode(DIRD, OUTPUT);


  Wire.begin(1);
  Wire.onReceive(receiveEvent);
  Serial.begin(9600);

}


void loop() 
{
  if (x=0)
  {
    sequence();
  }

  else if (x=1)
  {
    brake();
    delay(delayval2);
    forward(speed1);
    delay(delayval1);
  }

  else if (x=2)
  {
    brake();
    delay(delayval2);
    back(speed1);
    delay(delayval1);
  }

  else if (x=3)
  {
    brake();
    delay(delayval2);
    Right(speed1);
    delay(delayval1);
  }

  else if (x=4)
  {
    brake();
    delay(delayval2);
    Left(speed1);
    delay(delayval1);
  }

  else if (x=5)
  {
    brake();
    delay(delayval2);
    FR(speed1);
    delay(delayval1);
  }

  else if (x=6)
  {
    brake();
    delay(delayval2);
    FL(speed1);
    delay(delayval1);
  }

  else if (x=7)
  {
    brake();
    delay(delayval2);
    BL(speed1);
    delay(delayval1);
  }

  else if (x=8)
  {
    brake();
    delay(delayval2);
    BR(speed1);
    delay(delayval1);
  }
  


  Serial.println(x);

            
}



//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%//
                //Function to recieve values//
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%//
void receiveEvent(int bytes)
{
  x=Wire.read();
  Wire.endTransmission();
}


//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%//
                //Sequence for automatic movement of Mecanum Wheel//
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%//


void sequence()
{
      forward(speed1);   
      delay(delayval1); 
      brake();      
      delay(delayval2);
      back(speed1);    
      delay(delayval1); 
      brake();
      delay(delayval2);
      Left(speed1); 
      delay(delayval1);     
      brake();   
      delay(delayval2);
      Right(speed1);  
      delay(delayval1); 
      brake();   
      delay(delayval2);
      BR(speed2);    
      delay(delayval1);      
      brake();     
      delay(delayval2);
      FR(speed2);  
      delay(delayval1);
      brake(); 
      delay(delayval2); 
      FL(speed2);  
      delay(delayval1);
      brake(); 
      delay(delayval2);
      BL(speed2);  
      delay(delayval1);
      brake(); 
      delay(delayval2);
}


//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%//
                          //FUNCTIONS FOR MOVEMENT//
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%//

// Left
void Left(int speed) {

  digitalWrite(DIRA,LOW); // LOW means FWD, HIGH means BKWD

  digitalWrite(DIRB,HIGH); // LOW means FWD, HIGH means BKWD

  digitalWrite(DIRC,HIGH); // LOW means FWD, HIGH means BKWD

  digitalWrite(DIRD,HIGH); // HIGH means FWD, LOW means BKWD

  analogWrite(PWMA, speed);  analogWrite(PWMB, speed);  analogWrite(PWMC, speed);  analogWrite(PWMD, speed);

}


// Right
void Right(int speed) {

  digitalWrite(DIRA,HIGH); // LOW means FWD, HIGH means BKWD

  digitalWrite(DIRB,LOW); // LOW means FWD, HIGH means BKWD

  digitalWrite(DIRC,LOW); // LOW means FWD, HIGH means BKWD

  digitalWrite(DIRD,LOW); // HIGH means FWD, LOW means BKWD

  analogWrite(PWMA, speed);  analogWrite(PWMB, speed);  analogWrite(PWMC, speed);  analogWrite(PWMD, speed);

}


// Forward
void forward(int speed) { 

  digitalWrite(DIRA, LOW); // LOW means FWD, HIGH means BKWD

  digitalWrite(DIRB, LOW); // LOW means FWD, HIGH means BKWD

  digitalWrite(DIRC, LOW); // LOW means FWD, HIGH means BKWD

  digitalWrite(DIRD, HIGH); // HIGH means FWD, LOW means BKWD

  analogWrite(PWMA, speed);  analogWrite(PWMB, speed);  analogWrite(PWMC, speed);  analogWrite(PWMD, speed);

}


// Backward
void back(int speed) {

  digitalWrite(DIRA, HIGH); // LOW means FWD, HIGH means BKWD

  digitalWrite(DIRB, HIGH); // LOW means FWD, HIGH means BKWD

  digitalWrite(DIRC, HIGH); // LOW means FWD, HIGH means BKWD

  digitalWrite(DIRD, LOW); // HIGH means FWD, LOW means BKWD

  analogWrite(PWMA, speed);  analogWrite(PWMB, speed);  analogWrite(PWMC, speed);  analogWrite(PWMD, speed);

}


// Brake
void brake() 

{

  digitalWrite(DIRA, LOW);  digitalWrite(DIRB, LOW);  digitalWrite(DIRC, LOW);  digitalWrite(DIRD, LOW);

  analogWrite(PWMA, 0);  analogWrite(PWMB, 0);  analogWrite(PWMC, 0);  analogWrite(PWMD, 0);

}


// Backward right
void BR(int speed)

{

  digitalWrite(DIRA,LOW); // LOW means FWD, HIGH means BKWD

  digitalWrite(DIRB,LOW); // LOW means FWD, HIGH means BKWD

  digitalWrite(DIRC,LOW); // LOW means FWD, HIGH means BKWD

  digitalWrite(DIRD,HIGH); // HIGH means FWD, LOW means BKWD

  analogWrite(PWMA,0);  analogWrite(PWMB,speed);  analogWrite(PWMC,speed);  analogWrite(PWMD,0);

}


// Forward right
void FR(int speed)

{

  digitalWrite(DIRA,HIGH); // LOW means FWD, HIGH means BKWD

  digitalWrite(DIRB,HIGH); // LOW means FWD, HIGH means BKWD

  digitalWrite(DIRC,LOW); // LOW means FWD, HIGH means BKWD

  digitalWrite(DIRD,LOW); // HIGH means FWD, LOW means BKWD

  analogWrite(PWMA,speed);  analogWrite(PWMB,0);  analogWrite(PWMC,0);  analogWrite(PWMD,speed);

}

// Forward left
void FL(int speed)

{

  digitalWrite(DIRA,LOW); // LOW means FWD, HIGH means BKWD

  digitalWrite(DIRB,HIGH); // LOW means FWD, HIGH means BKWD

  digitalWrite(DIRC,HIGH); // LOW means FWD, HIGH means BKWD

  digitalWrite(DIRD,HIGH); // HIGH means FWD, LOW means BKWD

  analogWrite(PWMA,0);  analogWrite(PWMB,speed);  analogWrite(PWMC,speed);  analogWrite(PWMD,0);

}

// Backward left
void BL(int speed)

{

  digitalWrite(DIRA,LOW); // LOW means FWD, HIGH means BKWD

  digitalWrite(DIRB,LOW); // LOW means FWD, HIGH means BKWD

  digitalWrite(DIRC,LOW); // LOW means FWD, HIGH means BKWD

  digitalWrite(DIRD,HIGH); // HIGH means FWD, LOW means BKWD

  analogWrite(PWMA,speed);  analogWrite(PWMB,0);  analogWrite(PWMC,0);  analogWrite(PWMD,speed);

}
