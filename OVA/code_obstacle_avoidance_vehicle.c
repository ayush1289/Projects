const int trigfront=11;
const int echofront=10;

const int trigright=13;
const int echoright=12;

const int trigleft=9;
const int echoleft=8;

long durationfront,distancefront,durationright,distanceright,durationleft,distanceleft;

void setup()
{
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  
  pinMode(trigfront,OUTPUT);
  pinMode(echofront,INPUT);
  
  pinMode(trigright,OUTPUT);
  pinMode(echoright,INPUT);
  
  pinMode(trigleft,OUTPUT);
  pinMode(echoleft,INPUT);
  
  Serial.begin(9600);
  
}

void loop()
{
  
   digitalWrite(trigfront,LOW);
  delayMicroseconds(2);
  digitalWrite(trigfront,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigfront,LOW);
  
   durationfront=pulseIn(echofront,HIGH);
   distancefront=(durationfront/2)/29.1;
  
  digitalWrite(trigright,LOW);
  delayMicroseconds(2);
  digitalWrite(trigright,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigright,LOW);
  
   durationright=pulseIn(echoright,HIGH);
   distanceright=(durationright/2)/29.1;
  
  digitalWrite(trigleft,LOW);
  delayMicroseconds(2);
  digitalWrite(trigleft,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigleft,LOW);
  
   durationleft=pulseIn(echoleft,HIGH);
   distanceleft=(durationleft/2)/29.1;
  
  
  digitalWrite(2,HIGH);
  digitalWrite(3,HIGH);
  
  if (distancefront>=10)
  {
  digitalWrite(6,HIGH);
  digitalWrite(7,LOW);

  digitalWrite(5,HIGH);
  digitalWrite(4,LOW);
  }
  else if (distanceright>=10)
  {
    digitalWrite(6,LOW);
    digitalWrite(7,LOW);
    digitalWrite(5,HIGH);
    digitalWrite(4,LOW);
  }
  else if (distanceleft>=10)
  {
     digitalWrite(6,HIGH);
    digitalWrite(7,LOW);
    digitalWrite(5,LOW);
    digitalWrite(4,LOW);
  }
  else
  {
    digitalWrite(6,LOW);
    digitalWrite(7,LOW);
    digitalWrite(5,LOW);
    digitalWrite(4,LOW);
  }
}