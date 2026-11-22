//Lab 1a - Changes made for my own branch
//This branch is used to practice Git and Github collaboration
#include <Arduino.h>

// Student name: kieran doherty
// Student number: 26058421

//Set what the led pin is at
int ledPin = 23;
//Set what the button pin is at
int buttonPin = 22;

//Store the current state
//High means the led is on, low means the led is off
int ledState = HIGH;
int buttonState = LOW;
//Stores the previous reading of the button state
int lastButtonReading = LOW;

// Store the time when the button reading last changed
// unsigned long is used because millis() returns a large number
unsigned long lastTime = 0;
// The button must stay in the same state for more than 50 milliseconds before we accept the reading
int debounceDelay = 50;

//This runs when the ESP32 starts
void setup()
{
    // Set the LED pin as an OUTPUT because we want to control it
    pinMode(ledPin, OUTPUT);
    // Set the button pin as an INPUT with an internal pull-down resistor
    // This means the button normally reads LOW
    // When pressed, it should read HIGH
    pinMode(buttonPin, INPUT_PULLDOWN);

    //Set the starting state of the led
    digitalWrite(ledPin, ledState);
}

//Loop runs repeadly when switched on
void loop()
{
    // Read the current state of the button
    // The result will be either HIGH or LOW
    int reading = digitalRead(buttonPin);

    // Check if the button reading has changed since the previous loop
    if (reading != lastButtonReading)
    {
        // Record the current time when a change is detected
        // millis() tells us how many milliseconds have passed since startup
        lastTime = millis();
    }

    // Check if more than 50 milliseconds have passed
    // This helps prevent incorrect readings caused by button bouncing
    if ((millis() - lastTime) > debounceDelay)
    {
        // Check if the stable button reading is different from the button state we previously stored
        if (reading != buttonState)
        {
            //Updates button state to new reading
            buttonState = reading;

            //oNLY DO SOMETHING IF THE BUTTON IS PRESSED
            if (buttonState == HIGH)
            {
                //Change led state to the opposite of what it currently is
                ledState = !ledState;
                // Send the new LED state to the physical LED
                digitalWrite(ledPin, ledState);
            }
        }
    }

    lastButtonReading = reading;
}
