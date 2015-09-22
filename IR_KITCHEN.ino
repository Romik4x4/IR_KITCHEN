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

IRrecv irrecv(RECV_PIN);

decode_results results;

void setup()
{
  pinMode(A0,OUTPUT);
  
  pinMode(PORT1,OUTPUT); digitalWrite(PORT1,LOW);
  pinMode(PORT2,OUTPUT); digitalWrite(PORT2,LOW);
  pinMode(PORT3,OUTPUT); digitalWrite(PORT3,LOW);
  pinMode(PORT4,OUTPUT); digitalWrite(PORT4,LOW);
  
  digitalWrite(A0,HIGH);
  
  if (DEBUG) Serial.begin(9600);

  irrecv.enableIRIn(); 
}

void loop() {

  if (irrecv.decode(&results)) {  
   
    if (DEBUG) Serial.println(results.value);
   
   switch(results.value) {     
    case Z1: digitalWrite(A0,LOW);  delay(200); digitalWrite(A0,HIGH); break;
    case Z2: digitalWrite(A0,LOW);  delay(200); digitalWrite(A0,HIGH);break;
    case Z3: digitalWrite(A0,LOW);  delay(200); digitalWrite(A0,HIGH);break;
    case Z4: digitalWrite(A0,LOW);  delay(200); digitalWrite(A0,HIGH);break;
    case K1: digitalWrite(A0,LOW);  delay(200); digitalWrite(A0,HIGH);break;
    case K2: digitalWrite(A0,LOW);  delay(200); digitalWrite(A0,HIGH);break;
    case K3: digitalWrite(A0,LOW);  delay(200); digitalWrite(A0,HIGH);break;
    case K4: digitalWrite(A0,LOW);  delay(200); digitalWrite(A0,HIGH);break;      
   }
    
    irrecv.resume();
  }
  
}

