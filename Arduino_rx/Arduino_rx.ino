
void setup() 
{
  //Serial Begin at 9600 Baud 
  Serial.begin(9600);
}

void loop() 
{
  if (Serial.available() > 0)
  {
    
    // Read data from ESP's serial:
    char command = Serial.read();
    if (command == '1')
    {
      Serial.println("GO STRAIGHT!");
    } 
    else if (command == '2') 
    {
       Serial.println("GO BACK!");
    } 
    else if (command == '3') 
    {
       Serial.println("GO LEFT!");
    } 
    else if (command == '4') 
    {
       Serial.println("GO RIGHT!");
    } 
    else if (command == '5') 
    {
       Serial.println("STOP!");
    }
  }
}
