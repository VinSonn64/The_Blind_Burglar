/*
  Button

 Turns on and off a light emitting diode(LED) connected to digital
 pin 13, when pressing a pushbutton attached to pin 2.


 The circuit:
 * LED attached from pin 13 to ground
 * pushbutton attached to pin 2 from +5V
 * 10K resistor attached to pin 2 from ground

 * Note: on most Arduinos there is already an LED on the board
 attached to pin 13.


 created 2005
 by DojoDave <http://www.0j0.org>
 modified 30 Aug 2011
 by Tom Igoe

 This example code is in the public domain.

 http://www.arduino.cc/en/Tutorial/Button
 */

// constants won't change. They're used here to
// set pin numbers, a Pin for each Button
const int buttonR = 7;
const int buttonFR = 6;
const int buttonFL = 5;
const int buttonL = 4;
const int buttonBL = 3;
const int buttonBR = 2;
const int buttonC = 1;


//If button is pressed, stops detecting
bool RPressed = false; 
bool LPressed = false;
bool FRPressed = false; 
bool FLPressed = false;
bool BRPressed = false; 
bool BLPressed = false;  
bool CPressed = false; 

//Sets direction of player
bool forward = false;
bool left = true;
bool right = true;
bool back = false;
 
void setup() {
pinMode(buttonR, INPUT);
pinMode(buttonFR, INPUT);
pinMode(buttonFL, INPUT);
pinMode(buttonL, INPUT);
pinMode(buttonBL, INPUT);
pinMode(buttonBR, INPUT);
pinMode(buttonC, INPUT);
}

void loop() {

if(digitalRead(buttonC) == HIGH) //Interact
{
  if(!CPressed){
  Keyboard.press(32);
  Keyboard.release(32);
  Serial.print("Interact");
  Serial.println();
  CPressed = true ;}
}

if(digitalRead(buttonBR) == HIGH) //Move Back
{
  if(!BRPressed){
  right = false;
  left = false;
  forward = false;
  back = true;
  Keyboard.press('w');
  Keyboard.release('w');
  Serial.print("Back");
  Serial.println();
  BRPressed = true ;}
}

if(digitalRead(buttonBL) == HIGH)//Move Back
{
  if(!BLPressed){
  left = false;
  right = false;
  forward = false;
  back = true;
  Keyboard.press('w');
  Keyboard.release('w');
  Serial.print("Back");
  Serial.println();
  BLPressed = true ;}
  
}

if(digitalRead(buttonR) == HIGH) //Move Right
{
  if(!RPressed){
  right = true;
  left = false;
  forward = false;
  back = false;
  Keyboard.press('a');
  Serial.print("Right");
  Serial.println();
  RPressed = true ;}
}

if(digitalRead(buttonL) == HIGH) //Move Left
{
  if(!LPressed){
  left = true;
  right = false;
  forward = false;
  back = false;
  Keyboard.press('d');
  Serial.print("Left");
  Serial.println();
  LPressed = true ;}
  
}

if(digitalRead(buttonFR) == HIGH) //If already moving right, continue right. Else move forward
{
  if(!FRPressed){
    FRPressed = true ;
  if(right)
    {
      Keyboard.press('a');
      Keyboard.release('a');
      Serial.print("Right");
      Serial.println();
    }

    else
    {
      left = false;
      right = false;
      forward = true;
      back = false;
      Keyboard.press('s');
      Keyboard.release('s');
      Serial.print("Forward");
      Serial.println();
      
    }
    }
}

if(digitalRead(buttonFL) == HIGH)//If already moving Left, continue right. Else move forward
{
   if(!FLPressed){
   FLPressed = true ;
  if(left)
    {
      Keyboard.press('d');
      Keyboard.release('d');
      Serial.print("Left");
      Serial.println();
     
    }
    
    else
    {
      left = false;
      right = false;
      forward = true;
      back = false;      
      Keyboard.press('s');
      Keyboard.release('s');
      Serial.print("Forward");
      Serial.println();
    }}
    
}

//Release from button and any key still pressed
if(digitalRead(buttonR) == LOW)
{
  RPressed = false;
  Keyboard.release('d');
}

if(digitalRead(buttonL) == LOW)
{
  LPressed = false;
  Keyboard.release('a');
}

if(digitalRead(buttonBR) == LOW)
{
  BRPressed = false;
  Keyboard.release('s');
}

if(digitalRead(buttonBL) == LOW)
{
  BLPressed = false;
  Keyboard.release('s');
}

if(digitalRead(buttonFR) == LOW)
{
      FRPressed = false;
      Keyboard.release('d');
      Keyboard.release('w');
}

if(digitalRead(buttonFL) == LOW)
{
      FLPressed = false;
      Keyboard.release('a');
      Keyboard.release('w');
}

if(digitalRead(buttonC) == LOW)
{
  CPressed = false;
  Keyboard.release(32);
}


}

