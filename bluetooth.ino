   
  const int motorA1  = 5;  
  const int motorA2  = 6;  
  const int motorB1  = 9; 
  const int motorB2  = 10;  
 
  const int bluein = 2;
  int perVolt;                 
  float voltage = 0.0;         
  int level;
  int i=0;
  int j=0;
  char state;
  int vSpeed=200;    

void setup() {
    pinMode(motorA1, OUTPUT);
    pinMode(motorA2, OUTPUT);
    pinMode(motorB1, OUTPUT);
    pinMode(motorB2, OUTPUT);  
    Serial.begin(9600);
}
 
void loop() {
    if(Serial.available() > 0){     
      state = Serial.read(); 
      Serial.println(state);  
    }
    if (state == 'F') {
 digitalWrite(motorA1,HIGH); 
 digitalWrite(motorA2, LOW);
 digitalWrite(motorB1,HIGH);      
 digitalWrite(motorB2, LOW); 
    }
    if (state == 'B') {
 digitalWrite(motorA2,HIGH); 
 digitalWrite(motorA1, LOW);
 digitalWrite(motorB2,HIGH);      
 digitalWrite(motorB1, LOW); 
    }
    else if (state == 'L') {
     digitalWrite(motorA1, HIGH);  
  digitalWrite(motorA2, LOW); 
    digitalWrite(motorB1,LOW); 
  digitalWrite(motorB2, LOW); 
    }
 
    else if (state == 'R') {
      digitalWrite(motorA1, LOW);   
  digitalWrite(motorA2,LOW); 
        digitalWrite(motorB1,HIGH);   
  digitalWrite(motorB2,LOW);    
    }
      //state='n';  
    else if (state == 'S'){
        analogWrite(motorA1, 0);  
  analogWrite(motorA2, 0); 
        analogWrite(motorB1, 0);  
  analogWrite(motorB2, 0);
    }
  
    
}

