// Juraj Bazelides | 25076876

// adds Arduino functions
#include <Arduino.h>  

// defines on which pins the LED and button are connected
#define LED_PIN 23     
#define BUTTON_PIN 22  

// current LED state, starts on
bool ledState = true;  

// runs once at start
void setup()  
{
  // defines that LED is an output and button is an input (HIGH when released, LOW when pressed), sets the LED to the current state
  pinMode(LED_PIN, OUTPUT);           
  pinMode(BUTTON_PIN, INPUT_PULLUP);  
  digitalWrite(LED_PIN, ledState);    
}
// runs loop forever
void loop()  
{
  // check if button is pressed
  if (digitalRead(BUTTON_PIN) == LOW)  
  {
    // wait out button bounce
    delay(50);        
    // still pressed, so it's an actual press                   
    if (digitalRead(BUTTON_PIN) == LOW)  
    {
      // flip the state (on <-> off)
      ledState = !ledState;            
      // update the LED 
      digitalWrite(LED_PIN, ledState);  
      // wait until the button is released
      while (digitalRead(BUTTON_PIN) == LOW)  
      {
        delay(10);
      }
      // wait out bounce on release
      delay(50);  
    }
  }
}