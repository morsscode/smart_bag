//serial communication library
#include <SoftwareSerial.h>
//define rx and tx input
SoftwareSerial Bluetooth(10, 12); // RX, TX
int VIB = A5;
//int for recieved data
int Data;
 
void setup() {
  //set up serial printing for testing 
  Bluetooth.begin(9600);
  Serial.begin(9600);
  // set up vibrator pin
  pinMode(VIB,OUTPUT);
 
}
 
void loop() {
  // do loop if bluetooth data recieved
  if (Bluetooth.available()){ 
    Data=Bluetooth.read();
    Serial.println(Data);
    Bluetooth.println(Data);
    //if get call then do the following vibration pattern
    if(Data=='1'){
       digitalWrite(VIB,0);
       Serial.println("call");
       Bluetooth.println("call");
       digitalWrite(VIB,1);
       delay(1500);
       digitalWrite(VIB,0);
       delay(500);
       digitalWrite(VIB,1);
       delay(1500);
       digitalWrite(VIB,0);
    }
   //if get text then do the followiing vibration pattern
    else if(Data=='0'){
       Serial.println("text!");
       Bluetooth.println("text");
       digitalWrite(VIB,1);
       delay(400);
       digitalWrite(VIB,0);
       delay(300);
       digitalWrite(VIB,1);
       delay(400);
       digitalWrite(VIB,0);
       delay(300);
       digitalWrite(VIB,1);
       delay(400);
       digitalWrite(VIB,0);
    }
    else{;}
  }
delay(100);
}
