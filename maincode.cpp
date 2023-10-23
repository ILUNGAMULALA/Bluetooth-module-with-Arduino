#include <SoftwareSerial.h>
int led1 = 8;
int led2 = 9;

char incomingMessage; 
SoftwareSerial bluetooth(2, 3);

void setup()
{
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT); 
  Serial.begin(9600);
  bluetooth.begin(9600);
}

void loop() 
{
unsigned long start = millis();

  if (bluetooth.available()) {
      incomingMessage = bluetooth.read(); 
      Serial.println(incomingMessage); 
    
  if (incomingMessage == '0'){
    digitalWrite(led1,HIGH);
    digitalWrite(led2,HIGH);
    Serial.print(incomingMessage);
    }
  else if (incomingMessage == '1'){
    digitalWrite(led1,LOW);
    digitalWrite(led2,LOW);
    Serial.print(incomingMessage);
  };
  if (incomingMessage == '2'){
    digitalWrite(led1,LOW);
    digitalWrite(led2,HIGH);
    Serial.print(incomingMessage);
  };
  while (incomingMessage == '3' and millis()-start < 10000){
    digitalWrite(led1,LOW);
    digitalWrite(led2,LOW);
    delay(500);
    digitalWrite(led1,HIGH);
    digitalWrite(led2,HIGH);
    Serial.print(incomingMessage);
    delay(500);
 }
 };
}
