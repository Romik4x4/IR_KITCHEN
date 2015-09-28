/*
 * IRremote: IRrecvDemo - demonstrates receiving IR codes with IRrecv
 * An IR detector/demodulator must be connected to the input RECV_PIN.
 * Version 0.1 July, 2009
 * Copyright 2009 Ken Shirriff
 * http://arcfn.com
 */

#include <IRremote.h>

#define DEBUG 1

#define K1  16724175
#define K2  116718055
#define K3  116743045
#define K4  116716015

#define Z1  16582903
#define Z2  116615543
#define Z3  116599223
#define Z4  116591063

#define  RECV_PIN 3

IRrecv irrecv(RECV_PIN);

decode_results results;

void setup()
{
  pinMode(A0,OUTPUT);
  pinMode(A1,OUTPUT);
  pinMode(A2,OUTPUT);
  pinMode(A3,OUTPUT);

  digitalWrite(A0,HIGH);
  digitalWrite(A1,HIGH);
  digitalWrite(A2,HIGH);
  digitalWrite(A3,HIGH);

  if (DEBUG) Serial.begin(9600);

  irrecv.enableIRIn(); 

}

void loop() {

  if (irrecv.decode(&results)) {  

    switch (results.value) {

    case K1: 
      if (digitalRead(A0) == HIGH) digitalWrite(A0,LOW); 
      else digitalWrite(A0,HIGH); 
      break;
    case K2: 
      if (digitalRead(A1) == HIGH) digitalWrite(A1,LOW); 
      else digitalWrite(A1,HIGH); 
      break;
    case K3: 
      if (digitalRead(A2) == HIGH) digitalWrite(A2,LOW); 
      else digitalWrite(A2,HIGH); 
      break;
    case K4: 
      if (digitalRead(A3) == HIGH) digitalWrite(A3,LOW); 
      else digitalWrite(A3,HIGH); 
      break;

    case Z1: 
      if (digitalRead(A0) == HIGH) digitalWrite(A0,LOW); 
      else digitalWrite(A0,HIGH); 
      break;
    case Z2: 
      if (digitalRead(A1) == HIGH) digitalWrite(A1,LOW); 
      else digitalWrite(A1,HIGH); 
      break;
    case Z3: 
      if (digitalRead(A2) == HIGH) digitalWrite(A2,LOW); 
      else digitalWrite(A2,HIGH); 
      break;
    case Z4: 
      if (digitalRead(A3) == HIGH) digitalWrite(A3,LOW); 
      else digitalWrite(A3,HIGH); 
      break;
    }

    irrecv.resume();
  }

}







