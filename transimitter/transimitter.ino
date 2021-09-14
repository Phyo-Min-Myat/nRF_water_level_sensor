#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

//create an RF24 object
RF24 radio(9, 8);  // CE, CSN

//address through which two modules communicate.
const byte address[6] = "00001";

void setup()
{
  radio.begin();
  
  //set the address
  radio.openWritingPipe(address);
  
  //Set module as transmitter
  radio.stopListening();
  pinMode(5,INPUT_PULLUP);
  pinMode(2,OUTPUT);
}
void loop()
{
  //Send message to receiver
  /*const char text[] = "Hello World";
  radio.write(&text, sizeof(text));
  
  delay(1000);*/
  int sensorState = digitalRead(5);
  const char text1[] = "HIGH";
  if(sensorState == LOW){
    digitalWrite(2,HIGH);
    radio.write(&text1, sizeof(text1));
  } else {
    digitalWrite(2,LOW);
  }
  /*int sensorState = digitalRead(5);
  if(sensorState == LOW){
    digitalWrite(2,HIGH);
  } else {
    digitalWrite(2,LOW);
  }*/
}
