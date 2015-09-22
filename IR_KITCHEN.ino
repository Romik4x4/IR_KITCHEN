/*
 * IRremote: IRrecvDemo - demonstrates receiving IR codes with IRrecv
 * An IR detector/demodulator must be connected to the input RECV_PIN.
 * Version 0.1 July, 2009
 * Copyright 2009 Ken Shirriff
 * http://arcfn.com
 */

#include <IRremote.h>

#define DEBUG 0

#define K1  16724175
#define K2  16718055
#define K3  16743045
#define K4  16716015

#define Z1  16582903
#define Z2  16615543
#define Z3  16599223
#define Z4  16591063

#define  RECV_PIN 3

#define PORT1  4
#define PORT2  5
#define PORT3  6
#define PORT4  7

int port[4] = { 
  PORT1,PORT2,PORT3,PORT4 };
int but[8] = { 
  K1,K2,K3,K4,Z1,Z2,Z3,Z4 };

IRrecv irrecv(RECV_PIN);

decode_results results;

void setup()
{
  pinMode(A0,OUTPUT);

  for(int i=0;i<4;i++) {
    pinMode(port[i],OUTPUT); 
    digitalWrite(port[i],LOW);
  }

  digitalWrite(A0,HIGH);

  if (DEBUG) Serial.begin(9600);

  irrecv.enableIRIn(); 
}

void loop() {

  if (irrecv.decode(&results)) {  

    if (DEBUG) Serial.println(results.value);

    for (int i=0;i<8;i++) {
      if (results.value == but[i]) { 
        if (digitalRead(port[i] == HIGH)) digitalWrite(port[i],LOW); 
        else digitalWrite(port[i],HIGH);
      }
    }

    irrecv.resume();
  }

}




