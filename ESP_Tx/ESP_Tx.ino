#include <SoftwareSerial.h>
// Initiate custom serial ports at D1 (Rx) and D2 (Tx)
SoftwareSerial mySerial (D1,D2);


char command = '0';
void setup() 
{
  // Launch default and custom serial (mySerial) at 9600 baud
  Serial.begin(9600);
  mySerial.begin(9600);
}


void loop() 
{
  // Read input that user types into serial monitor then print the data to mySerial
  // mySerial then send the data to Uno's serial
//  if (Serial.available()>0)
//  {   
//    mySerial.print(char(Serial.read()));
//  }

  // initiate variable "command" that rotates between 1 to 5 and print it to mySerial
  if (command >= '5')
  {
    command = '1';
  }
  else
  {
    command++;
  }
  mySerial.println(command);
  delay(2000);
}
