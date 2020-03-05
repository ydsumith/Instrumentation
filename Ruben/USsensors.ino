int trig1=3;
int echo1=5;
int trig2=6;
int echo2=9;
int trig3=10;
int echo3=11;


void setup() 
{
  Serial.begin (9600);           // starts communication between arduino and computer
  pinMode(trig1, OUTPUT);      
  pinMode(echo1, INPUT);       
  pinMode(trig2, OUTPUT);      
  pinMode(echo2, INPUT); 
  pinMode(trig3, OUTPUT);      
  pinMode(echo3, INPUT); 
}

void loop()
{
  // Ultrasound sensor 1
  Serial.println("New Measurements");
  digitalWrite(trig1,LOW);   // trigger is off
  delayMicroseconds(2);         // leaves trigger off for 2 microseconds
  digitalWrite(trig1, HIGH);  // trigger is on (sends ultrasonic sound wave)
  delayMicroseconds(10);        // trigger stays at high for 10 microseconds
  digitalWrite(trig1, LOW);   // turns trigger off (no ultrasonic sound wave)
  float duration1 = pulseIn(echo1, HIGH);  // measures the pulse (time it takes from HIGH to LOW)


  float distance1 = (duration1/2)*0.0343;     // equation used to calculate distance 
  Serial.println("Sensor 1:");
  Serial.println(distance1);
  delay(1000);

  // Ultrasound sensor 2
  digitalWrite(trig2,LOW);   // trigger is off
  delayMicroseconds(2);         // leaves trigger off for 2 microseconds
  digitalWrite(trig2, HIGH);  // trigger is on (sends ultrasonic sound wave)
  delayMicroseconds(10);        // trigger stays at high for 10 microseconds
  digitalWrite(trig2, LOW);   // turns trigger off (no ultrasonic sound wave)
  float duration2 = pulseIn(echo2, HIGH);  // measures the pulse (time it takes from HIGH to LOW)

  float distance2 = (duration2/2)*0.0343;
  Serial.println("Sensor 2:");
  Serial.println(distance2);
  delay(1000);

  // Ultrasound sensor 3
  digitalWrite(trig3,LOW);   // trigger is off
  delayMicroseconds(2);         // leaves trigger off for 2 microseconds
  digitalWrite(trig3, HIGH);  // trigger is on (sends ultrasonic sound wave)
  delayMicroseconds(10);        // trigger stays at high for 10 microseconds
  digitalWrite(trig3, LOW);   // turns trigger off (no ultrasonic sound wave)
  float duration3 = pulseIn(echo3, HIGH);  // measures the pulse (time it takes from HIGH to LOW)

  float distance3 = (duration3/2)*0.0343; 
  Serial.println("Sensor 3:");
  Serial.println(distance3);
  delay(1000);
  
  delay(500);

  
}
