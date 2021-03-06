#include <SoftwareSerial.h>

SoftwareSerial mySerial(4,5);

int ledPin = 13; // LED
int Buzzer= 10; //Buzzer
int pirPin = 3;                 // PIR Out pin 
int pirStat = 0;                   // PIR status
void setup() {
 pinMode(ledPin, OUTPUT);
 pinMode(Buzzer,OUTPUT);     
 pinMode(pirPin, INPUT); 
 mySerial.begin(9600);    
 Serial.begin(9600);
}
void loop(){
 pirStat = digitalRead(pirPin); 
 if (pirStat == HIGH) {            // if motion detected
   digitalWrite(ledPin, HIGH); // turn LED ON
   digitalWrite(Buzzer,HIGH); //turn BUZZER ON
   Serial.println("Hey I got you!!!");
     SendMessage();
 } 
 else {
   digitalWrite(ledPin, LOW);// turn LED OFF if we have no motion
   digitalWrite(Buzzer,LOW);
 }
} 

void SendMessage()
{
  Serial.print("HELLO");
  mySerial.println("AT+CMGF=1");    //Sets the GSM Module in Text Mode
  delay(1000);  // Delay of 1000 milli seconds or 1 second
  mySerial.println("AT+CMGS=\"+917309488964\"\r"); // Replace x with mobile number
  delay(1000);
  mySerial.println("Be Alert!");// The SMS text you want to send
  delay(100);
   mySerial.println((char)26);// ASCII code of CTRL+Z
  delay(1000);
}
