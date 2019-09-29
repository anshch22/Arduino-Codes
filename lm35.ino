#for body temperature sensing

int temPin = A1;                   // Temp sensor pin wire connected to analog pin 1
float RawTemp;                        // holds incoming raw temp data
float TEMP;                         // holds temperature in F

void setup(){
  Serial.begin(115200);             // we agree to talk fast!
}

void loop(){

  //Calculates temperature from lm35

  RawTemp = analogRead(temPin);
  float mv = (RawTemp/1023.0)*5000;
  float celcius = mv/10;
  TEMP = (celcius*9/5) + 32;
  Serial.print("Temperature is   ");
  Serial.println(TEMP);
  delay(1000);
 
}
