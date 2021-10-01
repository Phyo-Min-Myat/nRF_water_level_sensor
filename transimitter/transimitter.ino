#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

#define high_sw     2
#define low_sw      4
#define high_led    3
#define low_led     5
#define water_sense 6

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
  pinMode(high_sw,INPUT_PULLUP);
  pinMode(low_sw,INPUT_PULLUP);
  pinMode(water_sense,INPUT_PULLUP);
  pinMode(high_led,OUTPUT);
  pinMode(low_led,OUTPUT);
}
void loop()
{
  //Send message to receiver
  /*const char text[] = "Hello World"; 
  radio.write(&text, sizeof(text));
  
  delay(1000);*/

  //switch stage send wireless test
  /*int sensorState = digitalRead(high_sw); 
  const char text1[] = "HIGH";
  if(sensorState == LOW){
    digitalWrite(high_led,HIGH);
    radio.write(&text1, sizeof(text1));
  } else {
    digitalWrite(high_led,LOW);
  }*/

  //switch test
  /*int sensorState = digitalRead(5); 
  if(sensorState == LOW){
    digitalWrite(2,HIGH);
  } else {
    digitalWrite(2,LOW);

    
  if(upsensorState == LOW){
    digitalWrite(high_led,HIGH);
  }else{
    digitalWrite(high_led,LOW);
  }
  }*/

  //two switch test
  int upsensorState    = digitalRead(high_sw);
  int lowsensorState   = digitalRead(low_sw);
  int watersensorState = digitalRead(water_sense);
  
 if(lowsensorState == HIGH && upsensorState == HIGH){
    digitalWrite(high_led, HIGH);
 }
 if(lowsensorState == LOW && upsensorState == LOW){
  digitalWrite(high_led, LOW);
 }
  
}
