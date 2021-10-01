#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

#define speaker 2
#define ok_led 3
#define er_led 4
#define wer_led 5
#define motor 6

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
  pinMode(speaker,OUTPUT);
  pinMode(ok_led,OUTPUT);
  pinMode(er_led,OUTPUT);
  pinMode(wer_led,OUTPUT);
  pinMode(motor,OUTPUT);
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
    digitalWrite(motor,HIGH);
    Serial.println(text1);
  } else {
    digitalWrite(motor,LOW);
  }
  /*digitalWrite(speaker,HIGH);
  digitalWrite(ok_led,HIGH);
  digitalWrite(er_led,HIGH);
  digitalWrite(wer_led,HIGH);
  digitalWrite(motor,HIGH);
  delay(100);*/
}
