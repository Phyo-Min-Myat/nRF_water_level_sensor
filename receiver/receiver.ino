#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

//create an RF24 object
RF24 radio(9, 8);  // CE, CSN

//address through which two modules communicate.
const byte address[6] = "00001";

void setup()
{
  while (!Serial);
    Serial.begin(9600);
  
  radio.begin();
  
  //set the address
  radio.openReadingPipe(0, address);
  
  //Set module as receiver
  radio.startListening();
  pinMode(5,OUTPUT);
}

void loop()
{
  //Read the data if available in buffer
  /*if (radio.available())
  {
    char text[32] = {0};
    radio.read(&text, sizeof(text));
    Serial.println(text);
  }*/
  if (radio.available())
  {
    char text1[32] = {0};
    radio.read(&text1, sizeof(text1));
    digitalWrite(5,HIGH);
    Serial.println(text1);
  } else {
    digitalWrite(5,LOW);
  }
}
