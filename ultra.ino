#define trigPin1 2                                   
#define echoPin1 4
#define led 10
long duration, distance, UltraSensor1, UltraSensor2,x; //we'll use these variable to store and generate data

void setup()
{
Serial.begin (9600);                             
pinMode(trigPin1, OUTPUT);                       
pinMode(echoPin1, INPUT);                        
pinMode(led,OUTPUT);
}
void loop() 
{
  
SonarSensor(trigPin1, echoPin1);              
UltraSensor1 = distance;                                            
Serial.print("distance measured by the first sensor: ");
Serial.print("\n");
Serial.print(UltraSensor1);
Serial.println(" cm");
if(UltraSensor1>15)
{x=UltraSensor1-15;
Serial.print("distance exceded by:");
Serial.print(x);
Serial.print("\n");}
if(UltraSensor1>15)
{
  digitalWrite(led, HIGH);
  Serial.println("message 4 alert");
  }
delay(1000);
 digitalWrite(led, LOW);
 Serial.println("everything is all right");
}

void SonarSensor(int trigPinSensor,int echoPinSensor)
{
digitalWrite(trigPinSensor, LOW);
delayMicroseconds(2);
digitalWrite(trigPinSensor, HIGH);
delayMicroseconds(10);
digitalWrite(trigPinSensor, LOW);

duration = pulseIn(echoPinSensor, HIGH);
distance= (duration/2) / 29.1;   
}

